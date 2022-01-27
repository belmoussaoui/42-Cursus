#include <stdio.h>
#include "ft_printf.h"
#include <stddef.h>

int	main(void)
{
	int a = 0;
	int b = 0;
	printf("-> undefined!\n");

	ft_printf("%010.2s\n", 0);
	printf("%010.2s\n", 0);
	printf("\n");
	
	ft_printf("%-0100.20s:)\n", "alhambra");
	printf("%-0100.20s:)\n", "alhambra");
	printf("\n");
	
	ft_printf("%030.5s!\n", "->almeria");
	printf("%030.5s!\n", "->almeria");
	printf("\n");
	
	printf("-> no undefined\n");
	// to check :-(
	
	ft_printf("%7.7s%7.7s\n", "hello", "world");
	printf("%7.7s%7.7s\n", "hello", "world");
	printf("\n");

	ft_printf("%-10.5s.\n", (char*) NULL);
	printf("%-10.5s.\n", (char*) NULL);
	printf("\n");

	a = ft_printf("%-100.20s.\n", "alhambra");
	b = printf("%-100.20s.\n", "alhambra");
	printf("%d =? %d\n\n", a, b);

	a = ft_printf("%30.5s!\n", "->almeria");
	b = printf("%30.5s!\n", "->almeria");
	printf("%d =? %d\n\n", a, b);

	a = ft_printf("%--4s %s %------------------9s of %s of %-5s\n", "for", "the", "goooood", "aaall", "us");
	b = printf("%--4s %s %------------------9s of %s of %-5s\n", "for", "the", "goooood", "aaall", "us");
	printf("%d =? %d\n\n", a, b);
	a = ft_printf("%--4.1s %s %------------------9.3s of %s of %-5.7s\n", "for", "the", "goooood", "aaall", "us");
	b = printf("%--4.1s %s %------------------9.3s of %s of %-5.7s\n", "for", "the", "goooood", "aaall", "us");
	printf("%d =? %d\n\n", a, b);

	a = ft_printf("%30c!\n", 'X');
	b = printf("%30c!\n", 'X');
	printf("%d =? %d\n\n", a, b);

	a = ft_printf("%-2c!\n", 'X');
	b = printf("%-2c!\n", 'X');
	printf("%d =? %d\n\n", a, b);

	a = ft_printf("%-5p!\n", 0);
	b = printf("%-5p!\n", 0);
	printf("%d =? %d\n\n", a, b);

	a = ft_printf("%-05x!\n", 0);
	b = printf("%-05x!\n", 0);
	printf("%d =? %d\n\n", a, b);

	a = ft_printf("%-05.3x!\n", 10);
	b = printf("%-05.3x!\n", 10);
	printf("%d =? %d\n\n", a, b);

	a = ft_printf("%-5p!\n", 10);
	b = printf("%-5p!\n", 10);
	printf("%d =? %d\n\n", a, b);
	return (0);
}