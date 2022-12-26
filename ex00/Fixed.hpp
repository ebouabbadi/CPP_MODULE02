/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:47:52 by ebouabba          #+#    #+#             */
/*   Updated: 2022/12/26 10:44:36 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

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
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif