/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:09:50 by ebouabba          #+#    #+#             */
/*   Updated: 2022/12/21 15:32:20 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int value;
    static const int n_fractional_bits = 8;

public:
    Fixed();
    Fixed(const int v);
    Fixed(const float v);
    Fixed(const Fixed &copy);
    Fixed &operator=(const Fixed &old_obj);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
    int toInt(void) const;
    float toFloat(void) const;
    /*-------------- comparison operators -------------*/
    bool operator<(const Fixed &c) const;
    bool operator>(const Fixed &c) const;
    bool operator>=(const Fixed &c) const;
    bool operator<=(const Fixed &c) const;
    bool operator==(const Fixed &c) const;
    bool operator!=(const Fixed &c) const;
    /*-------------- arithmetic operators -------------*/
    Fixed operator+(const Fixed &c);
    Fixed operator-(const Fixed &c);
    Fixed operator*(const Fixed &c);
    Fixed operator/(const Fixed &c);
    /*-------------- increment/decrement ---------------*/
    Fixed &operator++(void);
    Fixed operator++(int);
    Fixed &operator--(void);
    Fixed operator--(int);
    /*-------------- static member function ------------*/
    static Fixed &min(Fixed &c1, Fixed &c2);
    static const Fixed &min(const Fixed &c1, const Fixed &c2);
    static Fixed &max(Fixed &c1, Fixed &c2);
    static const Fixed &max(const Fixed &c1, const Fixed &c2);
};
std::ostream &operator<<(std::ostream &output, const Fixed &fixed);

#endif