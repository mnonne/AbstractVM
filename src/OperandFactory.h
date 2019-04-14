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

class OperandFactory {

public:
	static OperandFactory*	getInstance();
	IOperand const*			createOperand(eOperandType type, std::string const value) const;

private:
	OperandFactory();
	OperandFactory(const OperandFactory&);
	OperandFactory& operator=(OperandFactory&);

	IOperand const*	createInt8(std::string const value) const;

	static OperandFactory* m_instance;
};


#endif //ABSTRACTVM_OPERANDFACTORY_H
