/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <aminadzh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 17:26:00 by aminadzh          #+#    #+#             */
/*   Updated: 2019/04/14 17:26:00 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "OperandFactory.h"
#include "Operand.h"
#include "OperandSizeException.h"
#include <iostream>
#include <limits>

OperandFactory* OperandFactory::m_instance = 0;

OperandFactory::OperandFactory() {}

OperandFactory::funPtrs OperandFactory::m_creators[] = {
		&OperandFactory::createInt8,
		&OperandFactory::createInt16,
		&OperandFactory::createInt32,
		&OperandFactory::createFloat,
		&OperandFactory::createDouble
};

OperandFactory*
OperandFactory::getInstance() {
	if (!m_instance)
		m_instance = new OperandFactory();
	return m_instance;
}

IOperand const *OperandFactory::createOperand(eOperandType type, std::string const value) const {
	return (this->*(m_creators[type]))(value);
}

IOperand const *OperandFactory::createInt8(std::string const& value) const {
	try
	{
		int64_t val = std::stoll(value);
		if (val > INT8_MAX)
			throw OperandSizeException("Overflow of Int8");
		else if (val < INT8_MIN)
			throw OperandSizeException("Underflow of Int8");
		return new Operand<int8_t>(val);
	}
	catch(const std::out_of_range& e)
	{
		std::string msg = value + " is out of Int8 range";
		throw OperandSizeException(msg.data());
	}
}

IOperand const *OperandFactory::createInt16(std::string const& value) const {
	try
	{
		int64_t val = std::stoll(value);
		if (val > INT16_MAX)
			throw OperandSizeException("Overflow of Int16");
		else if (val < INT16_MIN)
			throw OperandSizeException("Underflow of Int16");
		return new Operand<int16_t>(val);
	}
	catch(const std::out_of_range& e)
	{
		std::string msg = value + " is out of Int16 range";
		throw OperandSizeException(msg.data());
	}
}

IOperand const *OperandFactory::createInt32(std::string const& value) const {
	try
	{
		int64_t val = std::stoll(value);
		if (val > INT32_MAX)
			throw OperandSizeException("Overflow of Int32");
		else if (val < INT32_MIN)
			throw OperandSizeException("Underflow of Int32");
		return new Operand<int32_t>(val);
	}
	catch(const std::out_of_range& e)
	{
		std::string msg = value + " is out of Int32 range";
		throw OperandSizeException(msg.data());
	}
}

IOperand const *OperandFactory::createFloat(std::string const& value) const {
	try
	{
		float val = std::stof(value);
		return new Operand<float>(val);
	}
	catch (std::out_of_range& e)
	{
		std::string msg = value + " is out of Float range";
		throw OperandSizeException(msg.data());
	}
}

IOperand const *OperandFactory::createDouble(std::string const& value) const {
	try
	{
		double val = std::stod(value);
		return new Operand<double>(val);
	}
	catch (std::out_of_range& e)
	{
		std::string msg = value + " is out of Double range";
		throw OperandSizeException(msg.data());
	}
}
