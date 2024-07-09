/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <jmanuelmigoya@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:12:58 by migmanu           #+#    #+#             */
/*   Updated: 2024/07/09 11:57:27 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

bool is_valid_characters(const std::string &line);

bool is_valid_date(const std::string &date);

int is_valid_nbr(const std::string &nbr);

bool is_valid_line(const std::string &line);
