/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:39:18 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/27 14:12:40 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char **)
{
    Array<int> numbers(MAX_VAL);
    int *mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    // SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete[] mirror; //

    Array<int> a(10);
    for (unsigned int i = 0; i < a.getSize(); i++)
        a[i] = i;
    std::cout << "a: ";
    for (unsigned int i = 0; i < a.getSize(); i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    Array<int> b(a);
    std::cout << "b: ";
    for (unsigned int i = 0; i < b.getSize(); i++)
        std::cout << b[i] << " ";
    std::cout << std::endl;

    Array<int> c;
    c = b;
    std::cout << "c: ";
    for (unsigned int i = 0; i < c.getSize(); i++)
        std::cout << c[i] << " ";
    std::cout << std::endl;
    c[7] = 2;

    
    std::cout << "c[7] = 2;" << std::endl;
    
    
    std::cout << "b: ";
    for (unsigned int i = 0; i < b.getSize(); i++)
        std::cout << b[i] << " ";
    std::cout << std::endl;

    
    std::cout << "c: ";
    for (unsigned int i = 0; i < c.getSize(); i++)
        std::cout << c[i] << " ";
    std::cout << std::endl;
    return 0;
}