/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackException.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <aminadzh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 16:54:00 by aminadzh          #+#    #+#             */
/*   Updated: 2019/05/11 16:54:00 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "StackException.h"

StackException::StackException() :
	std::logic_error("Invalid operand on stack")
{

}

StackException::StackException(const StackException &rhs) :
	std::logic_error(rhs.what())
{
	
}

StackException::~StackException()
{

}

StackException::StackException(const char *msg) :
	std::logic_error(msg)
{

}
