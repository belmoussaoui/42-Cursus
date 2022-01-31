# ft_printf
https://elearning.intra.42.fr/uploads/document/document/13/Ressources_externes.pdf

https://www.cplusplus.com/reference/cstdio/printf/

https://www.menie.org/georges/embedded/small_printf_source_code.html
## Fonction variadique
une fonction variadique est une fonction qui peut prendre un nombre de paramétres indéfinis

**comment crééer une fonction variadique ?**
```C
# include <stdarg.h>

void	ft_name(char *param1, ...)
{
	va_list	args;
	int		value;

	va_start(args, format);
	...
		value = va_arg(args, int);
	...
	va_end(args);
}
```

**un array de fonctions**
http://www.java2s.com/Code/C/Function/Arrayoffunctionpointer.htm

## Tests
* [Tripouille/printfTester](https://github.com/Tripouille/printfTester)
* [paulo-santana/ft_printf_tester](https://github.com/paulo-santana/ft_printf_tester)
