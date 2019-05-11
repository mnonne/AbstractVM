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
std::exception(),
m_info("Invalid operation on stack")
{

}

StackException::StackException(const StackException &rhs)
{
	//TODO: this
}

StackException::~StackException()
{

}

const StackException& StackException::operator=(const StackException &rhs)
{
	return StackException();
	//TODO: this
}

StackException::StackException(const char *msg) :
m_info(msg)
{

}

const char* StackException::getInfo() const
{
	return m_info;
}
