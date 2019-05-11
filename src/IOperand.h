/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <aminadzh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:17:00 by aminadzh          #+#    #+#             */
/*   Updated: 2019/04/14 15:17:00 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOPERAND_H
# define IOPERAND_H

#include <string>

enum eOperandType {
	Int8, Int16, Int32, Float, Double
};

class IOperand {

public:
	virtual int getPrecision(void) const = 0;
	virtual eOperandType getType(void) const = 0;

	virtual IOperand const*	operator+(IOperand const& rhs) const = 0;
	virtual IOperand const* operator-(IOperand const& rhs) const = 0;
	virtual IOperand const* operator*(IOperand const& rhs) const = 0;
	virtual IOperand const* operator/(IOperand const& rhs) const = 0;
	virtual IOperand const* operator%(IOperand const& rhs) const = 0;

	virtual std::string const & toString(void) const = 0;
	virtual ~IOperand() {}
};

#endif