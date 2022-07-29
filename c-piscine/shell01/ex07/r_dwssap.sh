cat /etc/passwd | sed '/^#/d' | sed -n 'n;p' | cut -d ':' -f 1 | tail -r | rev | sed -n "$FT_LINE1,$FT_LINE2 p" | tr "\n" ", " | sed 's/, */, /g' | sed 's/. $/./' | tr -d "\n"
