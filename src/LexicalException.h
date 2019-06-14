/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LexicalException.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <aminadzh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 18:07:00 by aminadzh          #+#    #+#             */
/*   Updated: 2019/05/19 18:07:00 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ABSTRACTVM_LEXICALEXCEPTION_H
#define ABSTRACTVM_LEXICALEXCEPTION_H

#include <stdexcept>

class LexicalException : public std::exception
{
public:
	LexicalException();
	LexicalException(const LexicalException& rhs);
	virtual ~LexicalException();
	LexicalException& operator= (const LexicalException& rhs);
	LexicalException(const char* msg);

	virtual const char* what() const noexcept override;

private:
	const char* m_Info;
};


#endif //ABSTRACTVM_LEXICALEXCEPTION_H
