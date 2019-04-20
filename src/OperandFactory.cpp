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

OperandFactory::OperandFactory() {}

OperandFactory::funPtrs OperandFactory::m_creators[] = {
		&OperandFactory::createInt8
};

OperandFactory&
OperandFactory::getInstance() {
	static OperandFactory instance;
	return instance;
}

IOperand const *OperandFactory::createOperand(eOperandType type, std::string const value) const {
	return (this->*(m_creators[type]))(value);
}

IOperand const *OperandFactory::createInt8(std::string const& value) const {
	int8_t val = std::stoi(value);
	return new Operand<int8_t>(val);
}

