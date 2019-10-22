#FT_LINE1=347;FT_LINE2=13433445;
cat /etc/passwd | grep -v "^#" | awk "(NR %2 != $FT_LINE1 % 2)" | cut -d ":" -f1 |rev | sort -r | awk "((NR >= $FT_LINE1) && (NR <= $FT_LINE2))"  | sed 's/$/,/g' | tr "\n" " " | sed 's/, $/./g'
