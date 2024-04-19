/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:20:04 by avon-ben          #+#    #+#             */
/*   Updated: 2024/02/09 17:20:06 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP_
# define SCALAR_HPP_

# include <string>

class Scalar {
	public:
		~Scalar();

		static void convert(const std::string& literal);
	private:
		Scalar();
		Scalar(const Scalar& other);
		Scalar& operator=(const Scalar& other);
};

#endif