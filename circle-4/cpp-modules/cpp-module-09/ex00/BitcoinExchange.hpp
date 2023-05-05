/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <bel-mous@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 02:17:22 by bel-mous          #+#    #+#             */
/*   Updated: 2023/05/05 18:08:11 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
private:
	std::map <std::string, double> data;
	std::string database_name;
public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &other);
	BitcoinExchange& operator=(BitcoinExchange const &other);
	void read_database_csv();
	void evaluate(std::string date, std::string value);
};

#endif