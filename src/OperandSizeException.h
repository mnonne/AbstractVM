//
// Created by alim on 21.04.19.
//

#ifndef ABSTRACTVM_OPERANDSIZEEXCEPTION_H
#define ABSTRACTVM_OPERANDSIZEEXCEPTION_H

#include <stdexcept>

class OperandSizeException : public std::out_of_range {
public:
	OperandSizeException();
	OperandSizeException(const OperandSizeException& rhs);
	virtual ~OperandSizeException();
	const OperandSizeException& operator= (const OperandSizeException& rhs) = delete;
	OperandSizeException(const char* msg);
};


#endif //ABSTRACTVM_OPERANDSIZEEXCEPTION_H
