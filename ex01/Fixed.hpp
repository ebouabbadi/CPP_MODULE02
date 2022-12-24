/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:23:28 by ebouabba          #+#    #+#             */
/*   Updated: 2022/12/21 14:39:28 by ebouabba         ###   ########.fr       */
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
};
std::ostream &operator<<(std::ostream &output, const Fixed &fixed);

#endif