/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackException.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <aminadzh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 16:54:00 by aminadzh          #+#    #+#             */
/*   Updated: 2019/05/11 16:54:00 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ABSTRACTVM_STACKEXCEPTION_H
#define ABSTRACTVM_STACKEXCEPTION_H

#include <stdexcept>

class StackException : public std::logic_error
{
public:
	StackException();
	StackException(const StackException& rhs);
	virtual ~StackException();
	const StackException& operator=(const StackException& rhs) = delete;
	StackException(const char* msg);
};


#endif //ABSTRACTVM_STACKEXCEPTION_H
