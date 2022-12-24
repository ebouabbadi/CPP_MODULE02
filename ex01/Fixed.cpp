/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:06:19 by ebouabba          #+#    #+#             */
/*   Updated: 2022/12/21 15:48:03 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    value = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int v)
{
    std::cout << "Int constructor called" << std::endl;
    value = v << n_fractional_bits;
}

Fixed::Fixed(const float v)
{
    std::cout << "Float constructor called" << std::endl;
    value = roundf(v * pow(2, n_fractional_bits));
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed &Fixed::operator=(const Fixed &old_obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->value = old_obj.value;
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->value);
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

std::ostream &operator<<(std::ostream &output, const Fixed &fixed)
{
    output << fixed.toFloat();
    return (output);
}

int Fixed::toInt(void) const
{
    return (this->value >> n_fractional_bits);
}

float Fixed::toFloat(void) const
{
    return (((float)value / pow(2, n_fractional_bits)));
}