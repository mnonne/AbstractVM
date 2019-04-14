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

#include "IOperand.h"

template<typename T>
class Operand : public IOperand {

public:
	Operand() {}
	Operand(T value)
	{
	}
	virtual ~Operand() {}

	virtual eOperandType getType(void) const
	{
		return m_type;
	}

	std::string const& toString(void) const {

	}

private:
	T m_value;
	eOperandType m_type;
};

#endif