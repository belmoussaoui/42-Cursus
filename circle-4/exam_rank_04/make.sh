gcc main.c -Wall -Werror -Wextra -o microshell
./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my microshell