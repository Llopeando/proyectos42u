#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

#include <stdlib.h>
#include <stdio.h>

int arr_id[5000];

int sockfd = 0, maxfd = 0, gid = 0;
int connfd;
fd_set current_socket, socket_read, socket_write;

char *message = NULL;
char send_buffer[100], recv_buffer[1001];
char *arr_str[5000];

int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

void send_to_all(int except) {
	for (int fd = 3; fd <= maxfd; fd++) {
		if (FD_ISSET(fd, &socket_write) && fd != except) {
			send(fd, send_buffer, strlen(send_buffer), 0);
			if (message) {
				send(fd, message, strlen(message), 0);
			}
		}
	}
}

int main(int argc, char **argv) {
	if (argc != 2) {
		write(2, "Wrong number of arguments\n", strlen("Wrong number of arguments\n"));
		exit(1);
	}

	struct sockaddr_in servaddr, cli;
	socklen_t len = sizeof(cli);

	// socket create and verification 
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		write(2, "Fatal error\n", strlen("Fatal error\n"));
		close(sockfd);
		exit(1);
	}
	bzero(&servaddr, sizeof(servaddr));

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(argv[1]));

	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) { 
		write(2, "Fatal error\n", strlen("Fatal error\n"));
		close(sockfd);
		exit(1); 
	}
	if (listen(sockfd, 100) < 0) {
		write(2, "Fatal error\n", strlen("Fatal error\n"));
		close(sockfd);
		exit(1);
	}
	maxfd = sockfd;
	FD_ZERO(&current_socket);
	FD_SET(sockfd, &current_socket);

	int clientid = 0;
	while (1) {
		socket_read = socket_write = current_socket;
		if (select(maxfd + 1, &socket_read, &socket_write, NULL, NULL) <= 0) {
			continue;
		}
		if (FD_ISSET(sockfd, &socket_read)) {
			connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
			if (connfd < 0) {
				write(2, "Fatal error\n", strlen("Fatal error\n"));
				close(sockfd);
				exit(1);
			}
			arr_id[connfd] = clientid++;
			FD_SET(connfd, &current_socket);
			maxfd = connfd > maxfd ? connfd : maxfd;
			sprintf(send_buffer, "server: client %d just arrived\n", arr_id[connfd]);
			send_to_all(connfd);
			arr_str[connfd] = NULL;
			continue;
		}
		for (int fd = 3; fd <= maxfd; fd++) {
			if (FD_ISSET(fd, &socket_read) && fd != sockfd) {
				int ret = recv(fd, recv_buffer, sizeof(recv_buffer), 0);
				if (ret <= 0) {
					FD_CLR(fd, &current_socket);
					sprintf(send_buffer, "server: client %d just left\n", arr_id[fd]);
					send_to_all(fd);
					close(fd);
					if (arr_str[fd] != NULL)
						free(arr_str[fd]);
					break;
				} else {
					recv_buffer[ret] = '\0';
					arr_str[fd] = str_join(arr_str[fd], recv_buffer);
					message = NULL;
					while (extract_message(&arr_str[fd], &message)) {
						sprintf(send_buffer, "client %d: ", arr_id[fd]);
						send_to_all(fd);
						free(message);
						message = NULL;
					}
				}
			}
		}
	}
}