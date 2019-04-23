//
// Created by alim on 21.04.19.
//

#include "OperandSizeException.h"

OperandSizeException::OperandSizeException() :
std::exception(),
m_info("Operand size overflow of underflow")
{

}

OperandSizeException::OperandSizeException(const OperandSizeException &rhs) {
	//TODO: implement this
}

OperandSizeException::~OperandSizeException() {

}

const OperandSizeException& OperandSizeException::operator=(const OperandSizeException &rhs) {
//	return OperandSizeException();
//TODO: implement this
}

OperandSizeException::OperandSizeException(const char *msg) :
m_info(msg)
{

}

const char *OperandSizeException::what() const _GLIBCXX_USE_NOEXCEPT {
	return m_info;
}

