/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 00:32:20 by alex              #+#    #+#             */
/*   Updated: 2023/06/09 00:49:02 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <locale>

int main (int argc, char *argv[])
{
    std::locale loc;
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for(int i = 1; i < argc; i++)
        {
            std::string str(argv[i]);
            for (std::string::size_type j = 0; j < str.length(); j++)
                std::cout << std::toupper(str[j], loc);
        }
        std::cout << std::endl;
    }
    return (0);
}