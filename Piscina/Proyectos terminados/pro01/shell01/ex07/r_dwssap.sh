#!/bin/sh
cat /etc/passwd | grep -v '\#' | sed '1!n;d' | cut -d':' -f1 | rev | sort -r | sed -n " $FT_LINE1, $FT_LINE2 p" | paste -s -d "," - | sed 's/,/, /g' | sed 's/$/./' | tr -d '\n' | sort -r
