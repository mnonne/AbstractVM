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
	m_Info("Invalid operation on stack")
{

}

StackException::StackException(const StackException &rhs)
{
	m_Info = rhs.what();
}

StackException::~StackException()
{

}

const StackException& StackException::operator=(const StackException &rhs)
{
	m_Info = rhs.what();
	return *this;
}

StackException::StackException(const char *msg) :
	m_Info(msg)
{

}

const char *StackException::what() const noexcept
{
	return m_Info;
}
