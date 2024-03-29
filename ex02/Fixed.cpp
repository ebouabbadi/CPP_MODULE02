/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:09:41 by ebouabba          #+#    #+#             */
/*   Updated: 2022/12/26 16:23:11 by ebouabba         ###   ########.fr       */
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
    value = v << bits;
}

Fixed::Fixed(const float v)
{
    std::cout << "Float constructor called" << std::endl;
    value = roundf(v * pow(2, bits));
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
    return (this->value >> bits);
}

float Fixed::toFloat(void) const
{
    return (((float)value / pow(2, bits)));
}

/******************** comparison operators **********************/

bool Fixed::operator<(Fixed c)
{
    bool A = this->value < c.value;
    return (A);
}

bool Fixed::operator>(Fixed c)
{
    bool A = this->value > c.value;
    return (A);
}

bool Fixed::operator>=(Fixed c)
{
    bool A = this->value >= c.value;
    return (A);
}

bool Fixed::operator<=(Fixed c)
{
    bool A = this->value <= c.value;
    return (A);
}

bool Fixed::operator==(Fixed c)
{
    bool A = this->value == c.value;
    return (A);
}

bool Fixed::operator!=(Fixed c)
{
    bool A = this->value != c.value;
    return (A);
}

/********************** arithmetic operators **********************/

Fixed Fixed::operator+(Fixed c)
{
    Fixed resultat;
    resultat.value = this->value + c.value;
    return resultat;
}

Fixed Fixed::operator-(Fixed c)
{
    Fixed resultat;
    resultat.value = this->value - c.value;
    return resultat;
}

Fixed Fixed::operator*(Fixed c)
{
    Fixed resultat;
    resultat.value = roundf((this->value * c.value) >> bits);
    return resultat;
}

Fixed Fixed::operator/(Fixed c)
{
    Fixed resultat;
    resultat.value = roundf((this->value / c.value));
    return resultat;
}

/********************* increment / decrement *********************/

Fixed Fixed::operator++(void) /*pre-increment*/
{
    this->value++;
    return *this;
}

Fixed Fixed::operator++(int) /*post-increment*/
{
    Fixed count;
    count = *this;
    this->value++;
    return count;
}

Fixed Fixed::operator--(void) /*pre-decrement*/
{
    this->value--;
    return *this;
}

Fixed Fixed::operator--(int) /*post-decrement*/
{
    Fixed count;
    count = *this;
    this->value--;
    return count;
}

/************************ static member function *********************/

Fixed &Fixed::min(Fixed &c1, Fixed &c2)
{
    if (c1.value < c2.value)
        return c1;
    return c2;
}

Fixed &Fixed::max(Fixed &c1, Fixed &c2)
{
    if (c1.value > c2.value)
        return c1;
    return c2;
}

const Fixed &Fixed::min(const Fixed &c1, const Fixed &c2)
{
    if (c1.value < c2.value)
        return c1;
    return c2;
}

const Fixed &Fixed::max(const Fixed &c1, const Fixed &c2)
{
    if (c1.value > c2.value)
        return c1;
    return c2;
}