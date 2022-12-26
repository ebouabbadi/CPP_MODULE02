/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:23:28 by ebouabba          #+#    #+#             */
/*   Updated: 2022/12/26 15:18:13 by ebouabba         ###   ########.fr       */
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
    static const int bits = 8;

public:
    Fixed();                                /*default constructor*/
    Fixed(const Fixed &copy);               /*copy constructor*/
    Fixed &operator=(const Fixed &old_obj); /*copy assignment operator overload*/
    ~Fixed();                               /*destructor*/
    Fixed(const int v);
    Fixed(const float v);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    int toInt(void) const;
    float toFloat(void) const;
};
std::ostream &operator<<(std::ostream &output, const Fixed &fixed);

#endif