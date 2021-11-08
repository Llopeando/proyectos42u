# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    table.pl                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ullorent <ullorent@student.42urduliz.      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/30 11:27:06 by ullorent          #+#    #+#              #
#    Updated: 2021/06/30 11:27:53 by ullorent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/usr/bin/perl

use warnings;
use strict;

die "program x y density" unless (scalar(@ARGV) == 3);
my ($x, $y, $density) = @ARGV;

print "$y.ox\n";
for (my $i = 0; $i < $y; $i++) 
{
	for (my $j = 0; $j < $x; $j++) 
	{
		if (int(rand($y) * 2) < $density) 
		{
			print "o";
		}
		else 
		{
			print ".";
		}
	}
print "\n";
}
