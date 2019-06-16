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

class LexicalException : public std::invalid_argument
{
public:
	LexicalException();
	LexicalException(const LexicalException& rhs);
	virtual ~LexicalException();
	LexicalException& operator= (const LexicalException& rhs) = delete;
	LexicalException(const char* msg);
};


#endif //ABSTRACTVM_LEXICALEXCEPTION_H
