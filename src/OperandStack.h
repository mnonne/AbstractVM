/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandStack.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <aminadzh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 16:32:00 by aminadzh          #+#    #+#             */
/*   Updated: 2019/05/11 16:32:00 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ABSTRACTVM_OPERANDSTACK_H
#define ABSTRACTVM_OPERANDSTACK_H

#include "IOperand.h"
#include <deque>
#include <string>

class OperandStack {
public:
	OperandStack();
	~OperandStack();
	//TODO: coplean form

	void push(const IOperand* operand);
	void dump() const;
	void pop();
	void compare(const IOperand* operand) const;
private:
	std::string getOperandPrecision(const IOperand* operand) const;
	std::deque<const IOperand*> m_stack;
};


#endif //ABSTRACTVM_OPERANDSTACK_H
