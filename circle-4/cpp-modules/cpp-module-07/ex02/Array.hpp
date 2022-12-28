/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:39:39 by bel-mous          #+#    #+#             */
/*   Updated: 2022/12/27 14:13:16 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
class Array
{
private:
	unsigned int size;
	T *data;

public:
	Array() : size(0), data(nullptr) {}

	Array(unsigned int n) : size(n), data(new T[n]) {}

	Array(const Array &other) : size(other.size), data(new T[other.size])
	{
		for (unsigned int i = 0; i < size; i++)
			data[i] = other.data[i];
	}

	Array &operator=(const Array &other)
	{
		if (this != &other)
		{
			if (this->data != NULL)
				delete[] data;
			size = other.size;
			data = new T[size];
			for (unsigned int i = 0; i < size; i++)
				data[i] = other.data[i];
		}
		return *this;
	}

	~Array()
	{
		delete[] data;
	}

	T &operator[](unsigned int index)
	{
		if (index >= size || size == 0)
			throw std::out_of_range("Index out of bounds");
		return data[index];
	}

	unsigned int getSize() const
	{
		return size;
	}
};