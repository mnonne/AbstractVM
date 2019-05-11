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

class StackException : public std::exception
{
public:
	StackException();
	StackException(const StackException& rhs);
	virtual ~StackException();
	const StackException& operator=(const StackException& rhs);
	StackException(const char* msg);

	const char* getInfo() const;

private:
	const char* m_info;

};


#endif //ABSTRACTVM_STACKEXCEPTION_H
