/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandStack.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <aminadzh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 16:32:00 by aminadzh          #+#    #+#             */
/*   Updated: 2019/05/11 16:32:00 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "OperandStack.h"
#include "StackException.h"
#include <iostream>
#include <sstream>

OperandStack::OperandStack()
{

}

OperandStack::~OperandStack()
{

}

void OperandStack::push(const IOperand *operand)
{
	m_stack.emplace_back(operand);
}

void OperandStack::dump() const
{
	if (m_stack.size() < 1)
		throw StackException("Dump on empty stack");
	for (int i = 0; i < m_stack.size(); ++i)
		std::cout << m_stack[i]->toString() << std::endl;
}

void OperandStack::pop()
{
	if (m_stack.size() < 1)
		throw StackException("Pop on empty stack");
	m_stack.pop_back();
}

void OperandStack::compare(const IOperand *operand) const
{
	if (m_stack.back()->getType() != operand->getType() || m_stack.back()->toString() != operand->toString())
	{
		std::string prc1 = getOperandPrecision(m_stack.back());
		std::string prc2 = getOperandPrecision(operand);
		std::stringstream msg;
		msg << std::string("Assertion of ") << m_stack.back()->toString() << " of type " <<
			getOperandPrecision(m_stack.back()) << " with " << operand->toString() <<
			" of type " <<  getOperandPrecision(operand);
		throw StackException(msg.str().data());
	}
}

std::string OperandStack::getOperandPrecision(const IOperand *operand) const
{
	switch (operand->getType())
	{
		case Int8 :
			return std::string("Int8");
		case Int16 :
			return std::string("Int16");
		case Int32:
			return std::string("Int32");
		case Float:
			return std::string("Float");
		case Double:
			return std::string("Double");
	}
}
