/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_operands2.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <aminadzh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 15:12:00 by aminadzh          #+#    #+#             */
/*   Updated: 2019/05/11 15:12:00 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdio>
#include <stdint.h>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../src/OperandFactory.h"
#include "../src/OperandSizeException.h"

class OperandsFixture2 : public  ::testing::Test {
public:
	OperandsFixture2() :
	int8map{
			{FACTORY->createOperand(Int8, "42"), 42},
			{FACTORY->createOperand(Int8, "24"), 24},
			{FACTORY->createOperand(Int8, "100"), 100},
			{FACTORY->createOperand(Int8, "-4"), -4}
	},
	int16map{
			{FACTORY->createOperand(Int16, "255"), 255},
			{FACTORY->createOperand(Int16, "2555"), 2555},
			{FACTORY->createOperand(Int16, "0"), 0},
			{FACTORY->createOperand(Int16, "-22255"), -22255}
	},
	int32map{
			{FACTORY->createOperand(Int32, "66"), 66},
			{FACTORY->createOperand(Int32, "-666"), -666},
			{FACTORY->createOperand(Int32, "6666"), 6666},
			{FACTORY->createOperand(Int32, "6"), 6}
	},
	floatmap{
			{FACTORY->createOperand(Float, "42.42"), 42.42f},
			{FACTORY->createOperand(Float, "2.42"), 2.42f},
			{FACTORY->createOperand(Float, "-42.42"), -42.42f},
			{FACTORY->createOperand(Float, "-2.42"), -2.42f}
	},
	doublemap{
			{FACTORY->createOperand(Double, "42.424"), 42.424},
			{FACTORY->createOperand(Double, "42.424"), 42.424},
			{FACTORY->createOperand(Double, "-42.424"), -42.424},
			{FACTORY->createOperand(Double, "-2.424"), -2.424}
	}
	{}

	virtual ~OperandsFixture2() {}

protected:
	virtual void SetUp() {}

	std::map<const IOperand*, int8_t> int8map;
	std::map<const IOperand*, int16_t> int16map;
	std::map<const IOperand*, int32_t> int32map;
	std::map<const IOperand*, float> floatmap;
	std::map<const IOperand*, double> doublemap;
};

template <class T, class D>
void testOperandsMultiplication(T op1, D op2) {
	try {
		auto result = *op1->first * *op2->first;
		if (result->getType() == Int8) {
			int64_t expected = op1->second * op2->second;
			ASSERT_STREQ(result->toString().data(), std::to_string(expected).data());
		}
		else if (result->getType() == Int16) {
			int16_t expected = op1->second * op2->second;
			ASSERT_STREQ(result->toString().data(), std::to_string(expected).data());
		}
		else if (result->getType() == Int32) {
			int32_t expected = op1->second * op2->second;
			ASSERT_STREQ(result->toString().data(), std::to_string(expected).data());
		}
		else if (result->getType() == Float) {
			std::ostringstream strs;
			strs << op1->second * op2->second;
			ASSERT_STREQ(result->toString().data(), strs.str().data());
		}
		else if (result->getType() == Double) {
			std::ostringstream strs;
			strs << op1->second * op2->second;
			ASSERT_STREQ(result->toString().data(), strs.str().data());
		}
	}
	catch (OperandSizeException& e)
	{
		ASSERT_THROW(auto result = *op1->first * *op2->first;, OperandSizeException);
	}
}

template <class T, class D>
void testOperandsDivision(T op1, D op2) {
	try {
		auto result = *op1->first / *op2->first;
		if (op2->second != 0)
		{
			if (result->getType() == Int8) {
				int64_t expected = op1->second / op2->second;
				ASSERT_STREQ(result->toString().data(), std::to_string(expected).data());
			}
			else if (result->getType() == Int16) {
				int16_t expected = op1->second / op2->second;
				ASSERT_STREQ(result->toString().data(), std::to_string(expected).data());
			}
			else if (result->getType() == Int32) {
				int32_t expected = op1->second / op2->second;
				ASSERT_STREQ(result->toString().data(), std::to_string(expected).data());
			}
			else if (result->getType() == Float) {
				ASSERT_NEAR(std::stof(result->toString()), op1->second / op2->second, 0.1);
			}
			else if (result->getType() == Double) {
				ASSERT_NEAR(std::stof(result->toString()), op1->second / op2->second, 0.1);
			}
		}
	}
	catch (OperandSizeException& e)
	{
		ASSERT_THROW(auto result = *op1->first / *op2->first;, OperandSizeException);
	}
}

template <class T, class D>
void testOperandsModulo(T op1, D op2) {
	try {
		auto result = *op1->first % *op2->first;
//		if (result->getType() == Int8) {
//			int64_t expected = op1->second % op2->second;
//			ASSERT_STREQ(result->toString().data(), std::to_string(expected).data());
//		}
//		else if (result->getType() == Int16) {
//			int16_t expected = op1->second % op2->second;
//			ASSERT_STREQ(result->toString().data(), std::to_string(expected).data());
//		}
//		else if (result->getType() == Int32) {
//			int32_t expected = op1->second % op2->second;
//			ASSERT_STREQ(result->toString().data(), std::to_string(expected).data());
//		}
//		else if (result->getType() == Float) {
//			ASSERT_NEAR(std::stof(result->toString()), op1->second % op2->second, 0.1);
//		}
//		else if (result->getType() == Double) {
//			ASSERT_NEAR(std::stof(result->toString()), op1->second % op2->second, 0.1);
//		}
	}
	catch (OperandSizeException& e)
	{
		ASSERT_THROW(auto result = *op1->first % *op2->first;, OperandSizeException);
	}
}

//Multiplication tests
TEST_F(OperandsFixture2, MultiplicationInt8)
{
	for (auto it = int8map.begin(); it != int8map.end(); ++it)
	{
		for (auto it2 = int8map.begin(); it2 != int8map.end(); ++it2)
			testOperandsMultiplication(it, it2);
	}
	for (auto it = int8map.begin(); it != int8map.end(); ++it)
	{
		for (auto it2 = int16map.begin(); it2 != int16map.end(); ++it2)
			testOperandsMultiplication(it, it2);
	}
	for (auto it = int8map.begin(); it != int8map.end(); ++it)
	{
		for (auto it2 = int32map.begin(); it2 != int32map.end(); ++it2)
			testOperandsMultiplication(it, it2);
	}
	for (auto it = int8map.begin(); it != int8map.end(); ++it)
	{
		for (auto it2 = floatmap.begin(); it2 != floatmap.end(); ++it2)
			testOperandsMultiplication(it, it2);
	}
	for (auto it = int8map.begin(); it != int8map.end(); ++it)
	{
		for (auto it2 = doublemap.begin(); it2 != doublemap.end(); ++it2)
			testOperandsMultiplication(it, it2);
	}
}

TEST_F(OperandsFixture2, MultiplicationInt16)
{
	for (auto it = int16map.begin(); it != int16map.end(); ++it)
	{
		for (auto it2 = int16map.begin(); it2 != int16map.end(); ++it2)
			testOperandsMultiplication(it, it2);
	}
	for (auto it = int16map.begin(); it != int16map.end(); ++it)
	{
		for (auto it2 = int32map.begin(); it2 != int32map.end(); ++it2)
			testOperandsMultiplication(it, it2);
	}
	for (auto it = int16map.begin(); it != int16map.end(); ++it)
	{
		for (auto it2 = floatmap.begin(); it2 != floatmap.end(); ++it2)
			testOperandsMultiplication(it, it2);
	}
	for (auto it = int16map.begin(); it != int16map.end(); ++it)
	{
		for (auto it2 = doublemap.begin(); it2 != doublemap.end(); ++it2)
			testOperandsMultiplication(it, it2);
	}
}

TEST_F(OperandsFixture2, MultiplicationInt32)
{
	for (auto it = int32map.begin(); it != int32map.end(); ++it)
	{
		for (auto it2 = int32map.begin(); it2 != int32map.end(); ++it2)
			testOperandsMultiplication(it, it2);
	}
	for (auto it = int32map.begin(); it != int32map.end(); ++it)
	{
		for (auto it2 = floatmap.begin(); it2 != floatmap.end(); ++it2)
			testOperandsMultiplication(it, it2);
	}
	for (auto it = int32map.begin(); it != int32map.end(); ++it)
	{
		for (auto it2 = doublemap.begin(); it2 != doublemap.end(); ++it2)
			testOperandsMultiplication(it, it2);
	}
}

TEST_F(OperandsFixture2, MultiplicationFloat)
{
	for (auto it = floatmap.begin(); it != floatmap.end(); ++it)
	{
		for (auto it2 = floatmap.begin(); it2 != floatmap.end(); ++it2)
			testOperandsMultiplication(it, it2);
	}
	for (auto it = floatmap.begin(); it != floatmap.end(); ++it)
	{
		for (auto it2 = doublemap.begin(); it2 != doublemap.end(); ++it2)
			testOperandsMultiplication(it, it2);
	}
}

TEST_F(OperandsFixture2, MultiplicationDouble)
{
	for (auto it = doublemap.begin(); it != doublemap.end(); ++it)
	{
		for (auto it2 = doublemap.begin(); it2 != doublemap.end(); ++it2)
			testOperandsMultiplication(it, it2);
	}
}

//Division tests
TEST_F(OperandsFixture2, DivisionInt8)
{
	for (auto it = int8map.begin(); it != int8map.end(); ++it)
	{
		for (auto it2 = int8map.begin(); it2 != int8map.end(); ++it2)
			testOperandsDivision(it, it2);
	}
	for (auto it = int8map.begin(); it != int8map.end(); ++it)
	{
		for (auto it2 = int16map.begin(); it2 != int16map.end(); ++it2)
			testOperandsDivision(it, it2);
	}
	for (auto it = int8map.begin(); it != int8map.end(); ++it)
	{
		for (auto it2 = int32map.begin(); it2 != int32map.end(); ++it2)
			testOperandsDivision(it, it2);
	}
	for (auto it = int8map.begin(); it != int8map.end(); ++it)
	{
		for (auto it2 = floatmap.begin(); it2 != floatmap.end(); ++it2)
			testOperandsDivision(it, it2);
	}
	for (auto it = int8map.begin(); it != int8map.end(); ++it)
	{
		for (auto it2 = doublemap.begin(); it2 != doublemap.end(); ++it2)
			testOperandsDivision(it, it2);
	}
}

TEST_F(OperandsFixture2, DivisionInt16)
{
	for (auto it = int16map.begin(); it != int16map.end(); ++it)
	{
		for (auto it2 = int16map.begin(); it2 != int16map.end(); ++it2)
			testOperandsDivision(it, it2);
	}
	for (auto it = int16map.begin(); it != int16map.end(); ++it)
	{
		for (auto it2 = int32map.begin(); it2 != int32map.end(); ++it2)
			testOperandsDivision(it, it2);
	}
	for (auto it = int16map.begin(); it != int16map.end(); ++it)
	{
		for (auto it2 = floatmap.begin(); it2 != floatmap.end(); ++it2)
			testOperandsDivision(it, it2);
	}
	for (auto it = int16map.begin(); it != int16map.end(); ++it)
	{
		for (auto it2 = doublemap.begin(); it2 != doublemap.end(); ++it2)
			testOperandsDivision(it, it2);
	}
}

TEST_F(OperandsFixture2, DivisionInt32)
{
	for (auto it = int32map.begin(); it != int32map.end(); ++it)
	{
		for (auto it2 = int32map.begin(); it2 != int32map.end(); ++it2)
			testOperandsDivision(it, it2);
	}
	for (auto it = int32map.begin(); it != int32map.end(); ++it)
	{
		for (auto it2 = floatmap.begin(); it2 != floatmap.end(); ++it2)
			testOperandsDivision(it, it2);
	}
	for (auto it = int32map.begin(); it != int32map.end(); ++it)
	{
		for (auto it2 = doublemap.begin(); it2 != doublemap.end(); ++it2)
			testOperandsDivision(it, it2);
	}
}

TEST_F(OperandsFixture2, DivisionFloat)
{
	for (auto it = floatmap.begin(); it != floatmap.end(); ++it)
	{
		for (auto it2 = floatmap.begin(); it2 != floatmap.end(); ++it2)
			testOperandsDivision(it, it2);
	}
	for (auto it = floatmap.begin(); it != floatmap.end(); ++it)
	{
		for (auto it2 = doublemap.begin(); it2 != doublemap.end(); ++it2)
			testOperandsDivision(it, it2);
	}
}

TEST_F(OperandsFixture2, DivisionDouble)
{
	for (auto it = doublemap.begin(); it != doublemap.end(); ++it)
	{
		for (auto it2 = doublemap.begin(); it2 != doublemap.end(); ++it2)
			testOperandsMultiplication(it, it2);
	}
}

//Modulo tests
TEST_F(OperandsFixture2, ModuloInt8)
{
	for (auto it = int8map.begin(); it != int8map.end(); ++it)
	{
		for (auto it2 = int8map.begin(); it2 != int8map.end(); ++it2)
			testOperandsModulo(it, it2);
	}
	for (auto it = int8map.begin(); it != int8map.end(); ++it)
	{
		for (auto it2 = int16map.begin(); it2 != int16map.end(); ++it2)
			testOperandsModulo(it, it2);
	}
	for (auto it = int8map.begin(); it != int8map.end(); ++it)
	{
		for (auto it2 = int32map.begin(); it2 != int32map.end(); ++it2)
			testOperandsModulo(it, it2);
	}
	for (auto it = int8map.begin(); it != int8map.end(); ++it)
	{
		for (auto it2 = floatmap.begin(); it2 != floatmap.end(); ++it2)
			testOperandsModulo(it, it2);
	}
	for (auto it = int8map.begin(); it != int8map.end(); ++it)
	{
		for (auto it2 = doublemap.begin(); it2 != doublemap.end(); ++it2)
			testOperandsModulo(it, it2);
	}
}

TEST_F(OperandsFixture2, ModuloInt16)
{
	for (auto it = int16map.begin(); it != int16map.end(); ++it)
	{
		for (auto it2 = int16map.begin(); it2 != int16map.end(); ++it2)
			testOperandsModulo(it, it2);
	}
	for (auto it = int16map.begin(); it != int16map.end(); ++it)
	{
		for (auto it2 = int32map.begin(); it2 != int32map.end(); ++it2)
			testOperandsModulo(it, it2);
	}
	for (auto it = int16map.begin(); it != int16map.end(); ++it)
	{
		for (auto it2 = floatmap.begin(); it2 != floatmap.end(); ++it2)
			testOperandsModulo(it, it2);
	}
	for (auto it = int16map.begin(); it != int16map.end(); ++it)
	{
		for (auto it2 = doublemap.begin(); it2 != doublemap.end(); ++it2)
			testOperandsModulo(it, it2);
	}
}

TEST_F(OperandsFixture2, ModuloInt32)
{
	for (auto it = int32map.begin(); it != int32map.end(); ++it)
	{
		for (auto it2 = int32map.begin(); it2 != int32map.end(); ++it2)
			testOperandsModulo(it, it2);
	}
	for (auto it = int32map.begin(); it != int32map.end(); ++it)
	{
		for (auto it2 = floatmap.begin(); it2 != floatmap.end(); ++it2)
			testOperandsModulo(it, it2);
	}
	for (auto it = int32map.begin(); it != int32map.end(); ++it)
	{
		for (auto it2 = doublemap.begin(); it2 != doublemap.end(); ++it2)
			testOperandsModulo(it, it2);
	}
}

TEST_F(OperandsFixture2, ModuloFloat)
{
	for (auto it = floatmap.begin(); it != floatmap.end(); ++it)
	{
		for (auto it2 = floatmap.begin(); it2 != floatmap.end(); ++it2)
			testOperandsModulo(it, it2);
	}
	for (auto it = floatmap.begin(); it != floatmap.end(); ++it)
	{
		for (auto it2 = doublemap.begin(); it2 != doublemap.end(); ++it2)
			testOperandsModulo(it, it2);
	}
}

TEST_F(OperandsFixture2, ModuloDouble)
{
	for (auto it = doublemap.begin(); it != doublemap.end(); ++it)
	{
		for (auto it2 = doublemap.begin(); it2 != doublemap.end(); ++it2)
			testOperandsModulo(it, it2);
	}
}
