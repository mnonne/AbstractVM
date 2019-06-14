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

	virtual const char* what() const noexcept override;

private:
	const char* m_Info;

};


#endif //ABSTRACTVM_STACKEXCEPTION_H
