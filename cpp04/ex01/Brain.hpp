/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalp <yalp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 17:05:30 by yalp              #+#    #+#             */
/*   Updated: 2025/09/19 16:25:19 by yalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <string>

class Brain
{
	public:
	std::string ideas[100];
	Brain();
	~Brain();
	Brain(Brain& other);
	Brain& operator=(Brain& other);
};

#endif