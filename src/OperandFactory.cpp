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
#include <iostream>

OperandFactory* OperandFactory::m_instance = 0;

OperandFactory::OperandFactory() {

}

OperandFactory*
OperandFactory::getInstance() {
	if (!m_instance)
		m_instance = new OperandFactory();
	return m_instance;
}

IOperand const *OperandFactory::createOperand(eOperandType type, std::string const value) const {
	switch (type) {
		case Int8:
			return createInt8(value);
		default:
			throw std::logic_error("Inapropriate type");
			break;
	}
}

IOperand const *OperandFactory::createInt8(std::string const value) const {
	int8_t val = std::stoi(value);
	return new Operand<int8_t>(val);
}

