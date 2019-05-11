/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <aminadzh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:37:00 by aminadzh          #+#    #+#             */
/*   Updated: 2019/04/14 15:37:00 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_H
# define OPERAND_H

#include <iostream>

#include "IOperand.h"
#include "OperandSizeException.h"
#include <exception>
#include <iomanip>
#include <sstream>

template<typename T>
class Operand : public IOperand {

public:
	Operand() {}
	Operand(T value)
	{
		const std::type_info& tp = typeid(T);
		std::ostringstream strs;
		m_value = value;
		if (tp == typeid(int8_t))
			strs << static_cast<int16_t>(m_value);
		else
			strs << m_value;
		m_strVal = strs.str();
	}
	virtual ~Operand() {}

	virtual int getPrecision(void) const override
	{
		return getType();
	}

	virtual eOperandType getType(void) const override
	{
		const std::type_info& tp = typeid(T);
		if (tp == typeid(int8_t))
			return Int8;
		else if (tp == typeid(int16_t))
			return Int16;
		else if (tp == typeid(int32_t))
			return Int32;
		else if (tp == typeid(float))
			return Float;
		else if (tp == typeid(double))
			return Double;
		else
			throw std::invalid_argument("Unhandled type");
	}

	virtual IOperand const*	operator+(IOperand const& rhs) const override
	{
		std::istringstream strs(rhs.toString());
		std::ostringstream ostr;
		eOperandType newType = compareOperand(rhs);
		if (newType < Float) {
			int64_t oldVal;
			strs >> oldVal;
			int64_t newVal = m_value + oldVal;
			ostr << newVal;
			return FACTORY.createOperand(newType, ostr.str());
		}
		else
		{
			double oldVal;
			strs >> oldVal;
			double newVal = m_value + oldVal;
			ostr << newVal;
			return FACTORY.createOperand(newType, ostr.str());
		}
	}

	virtual IOperand const* operator-(IOperand const& rhs) const override
	{
		std::istringstream strs(rhs.toString());
		std::ostringstream ostr;
		eOperandType newType = compareOperand(rhs);
		if (newType < Float) {
			int64_t oldVal;
			strs >> oldVal;
			int64_t newVal = m_value - oldVal;
			ostr << newVal;
			return FACTORY.createOperand(newType, ostr.str());
		}
		else
		{
			double oldVal;
			strs >> oldVal;
			double newVal = m_value - oldVal;
			ostr << newVal;
			return FACTORY.createOperand(newType, ostr.str());
		}
	}

	virtual IOperand const* operator*(IOperand const& rhs) const override
	{
		std::istringstream strs(rhs.toString());
		std::ostringstream ostr;
		eOperandType newType = compareOperand(rhs);
		if (newType < Float) {
			int64_t oldVal;
			strs >> oldVal;
			int64_t newVal = m_value * oldVal;
			ostr << newVal;
			return FACTORY.createOperand(newType, ostr.str());
		}
		else
		{
			double oldVal;
			strs >> oldVal;
			double newVal = m_value * oldVal;
			ostr << newVal;
			return FACTORY.createOperand(newType, ostr.str());
		}
	}

	virtual IOperand const* operator/(IOperand const& rhs) const override
	{
		std::istringstream strs(rhs.toString());
		std::ostringstream ostr;
		eOperandType newType = compareOperand(rhs);
		if (newType < Float) {
			int64_t oldVal;
			strs >> oldVal;
			if (oldVal == 0)
				throw OperandSizeException("Division by zero"); //TODO: another exception
			int64_t newVal = m_value / oldVal;
			ostr << newVal;
			return FACTORY.createOperand(newType, ostr.str());
		}
		else
		{
			double oldVal;
			strs >> oldVal;
			double newVal = m_value / oldVal;
			ostr << newVal;
			return FACTORY.createOperand(newType, ostr.str());
		}
	}

	virtual IOperand const* operator%(IOperand const& rhs) const override
	{
		std::ostringstream ostr;
		eOperandType newType = compareOperand(rhs);
		if (newType < Float) {
			int64_t oldVal = std::stoll(m_strVal);
			int64_t rhsVal = std::stoll(rhs.toString());
			if (rhsVal == 0)
				throw OperandSizeException("Modulo by zero"); //TODO: another exception
			int64_t newVal = oldVal % rhsVal;
			ostr << newVal;
			return FACTORY.createOperand(newType, ostr.str());
		}
		else
		{
			throw OperandSizeException("Modulo by floating point"); //TODO: another exception
		}
	}

	std::string const& toString(void) const override
	{
		return m_strVal;
	}

	eOperandType const compareOperand(IOperand const& op) const
	{
		return (getPrecision() > op.getPrecision()) ? getType() : op.getType();
	}

private:
	T m_value;
	std::string m_strVal;
};

#endif