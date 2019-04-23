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
#include <exception>
#include <iomanip>
#include <sstream>

template<typename T>
class Operand : public IOperand {

public:
	Operand() {}
	Operand(T value)
	{
		m_value = value;
		m_strVal = std::to_string(m_value);
	}
	virtual ~Operand() {}

	virtual int getPrecision(void) const override {
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

	virtual IOperand const*	operator+(IOperand const& rhs) const override {
		eOperandType newType = compareOperand(rhs);
		if (newType < Float) {
			int64_t newVal = m_value + std::stoll(rhs.toString());
			return FACTORY.createOperand(newType, std::to_string(newVal));
		}
		else
		{
			double newVal = m_value + std::stod(rhs.toString());
			return FACTORY.createOperand(newType, std::to_string(newVal));
		}
	}

	std::string const& toString(void) const override {
		return m_strVal;
	}

	eOperandType const compareOperand(IOperand const& op) const {
		return (getPrecision() > op.getPrecision()) ? getType() : op.getType();
	}

private:
	T m_value;
	std::string m_strVal;
};

#endif