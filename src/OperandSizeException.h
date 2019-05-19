//
// Created by alim on 21.04.19.
//

#ifndef ABSTRACTVM_OPERANDSIZEEXCEPTION_H
#define ABSTRACTVM_OPERANDSIZEEXCEPTION_H

#include <stdexcept>

class OperandSizeException : public std::exception {
public:
	OperandSizeException();
	OperandSizeException(const OperandSizeException& rhs);
	virtual ~OperandSizeException();
	const OperandSizeException& operator= (const OperandSizeException& rhs);
	OperandSizeException(const char* msg);

	virtual const char* what() const _NOEXCEPT override ;

private:
	const char* m_Info;
};


#endif //ABSTRACTVM_OPERANDSIZEEXCEPTION_H
