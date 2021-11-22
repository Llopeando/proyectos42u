clang -Wall -Werror -Wextra ft_printf.c -o ft_printf
./ft_printf > yy
cat -e yy > y
clang -Wall -Werror -Wextra -D REAL -o printf
./printf | cat -e > r
diff -y --suppress-common-lines r y
rm -rf yy y r ft_printf printf