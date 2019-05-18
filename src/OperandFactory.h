/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <aminadzh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 17:26:00 by aminadzh          #+#    #+#             */
/*   Updated: 2019/04/14 17:26:00 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTVM_OPERANDFACTORY_H
#define ABSTRACTVM_OPERANDFACTORY_H

#include "IOperand.h"
#include <memory>

#define FACTORY OperandFactory::getInstance()

class OperandFactory {

public:
	OperandFactory(const OperandFactory&) = delete;
	OperandFactory& operator=(OperandFactory&) = delete;

	static OperandFactory*	getInstance();
	IOperand const*			createOperand(eOperandType type, std::string const value) const;

private:
	OperandFactory();

	IOperand const*	createInt8(std::string const& value) const;
	IOperand const*	createInt16(std::string const& value) const;
	IOperand const* createInt32(std::string const& value) const;
	IOperand const* createFloat(std::string const& value) const;
	IOperand const* createDouble(std::string const& value) const;

	static OperandFactory* m_instance;
	typedef IOperand const* (OperandFactory::*funPtrs)(std::string const& value) const;
	static funPtrs m_creators[];
};

#endif //ABSTRACTVM_OPERANDFACTORY_H
