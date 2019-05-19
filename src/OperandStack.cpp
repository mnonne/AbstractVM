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
#include "OperandSizeException.h"
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
		throw StackException("Assertion failed");
}

void OperandStack::add()
{
	if (m_stack.size() < 2)
		throw StackException("Stack size is less than 2");
	auto op1 = m_stack.back();
	auto op2 = m_stack[m_stack.size() - 2];
	auto result = *op1 + *op2;
	m_stack.pop_back();
	m_stack.pop_back();
	m_stack.emplace_back(result);
}

void OperandStack::sub()
{
	if (m_stack.size() < 2)
		throw StackException("Stack size is less than 2");
	auto op1 = m_stack.back();
	auto op2 = m_stack[m_stack.size() - 2];
	auto result = *op2 - *op1;
	m_stack.pop_back();
	m_stack.pop_back();
	m_stack.emplace_back(result);
}

void OperandStack::mul()
{
	if (m_stack.size() < 2)
		throw StackException("Stack size is less than 2");
	auto op1 = m_stack.back();
	auto op2 = m_stack[m_stack.size() - 2];
	auto result = *op1 * *op2;
	m_stack.pop_back();
	m_stack.pop_back();
	m_stack.emplace_back(result);
}

void OperandStack::div()
{
	if (m_stack.size() < 2)
		throw StackException("Stack size is less than 2");
	auto op1 = m_stack.back();
	auto op2 = m_stack[m_stack.size() - 2];
	auto result = *op2 / *op1;
	m_stack.pop_back();
	m_stack.pop_back();
	m_stack.emplace_back(result);
}

void OperandStack::mod()
{
	if (m_stack.size() < 2)
		throw StackException("Stack size is less than 2");
	auto op1 = m_stack.back();
	auto op2 = m_stack[m_stack.size() - 2];
	auto result = *op2 % *op1;
	m_stack.pop_back();
	m_stack.pop_back();
	m_stack.emplace_back(result);
}

void OperandStack::print() const
{
	if (m_stack.back()->getType() != Int8)
		throw StackException("Non printable");
	int8_t ch = std::stoi(m_stack.back()->toString());
	std::cout << ch << std::endl;
}

size_t OperandStack::size() const
{
	return m_stack.size();
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
