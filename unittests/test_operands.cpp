/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_operands.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <aminadzh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 16:55:00 by aminadzh          #+#    #+#             */
/*   Updated: 2019/04/20 16:55:00 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdio>
#include <stdint.h>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../src/OperandFactory.h"
#include "../src/OperandSizeException.h"

class OperandsFixture : public ::testing::Test {
public:
	OperandsFixture() :
	int8map{
			{FACTORY->createOperand(Int8, "42"), 42},
			{FACTORY->createOperand(Int8, "-25"), -25},
			{FACTORY->createOperand(Int8, std::to_string(INT8_MIN)), INT8_MIN},
			{FACTORY->createOperand(Int8, std::to_string(INT8_MAX)), INT8_MAX}
	},
	int16map{
			{FACTORY->createOperand(Int16, "4200"), 4200},
			{FACTORY->createOperand(Int16, "-2500"), -2500},
			{FACTORY->createOperand(Int16, std::to_string(INT16_MIN)), INT16_MIN},
			{FACTORY->createOperand(Int16, std::to_string(INT16_MAX)), INT16_MAX}
	},
	int32map{
			{FACTORY->createOperand(Int32, "42000"), 42000},
			{FACTORY->createOperand(Int32, "-25000"), -25000},
			{FACTORY->createOperand(Int32, std::to_string(INT32_MIN)), INT32_MIN},
			{FACTORY->createOperand(Int32, std::to_string(INT32_MAX)), INT32_MAX},
	},
	floatmap{
			{FACTORY->createOperand(Float, "42.42"), 42.42f},
			{FACTORY->createOperand(Float, "-25.42"), -25.42f}
	},
	doublemap{
			{FACTORY->createOperand(Double, "42.42"), 42.42},
			{FACTORY->createOperand(Double, "-25.42"), -25.42}
	}
	{
	}
	virtual ~OperandsFixture() {}

protected:
	virtual void SetUp() {

	}

	std::map<const IOperand*, int8_t> int8map;
	std::map<const IOperand*, int16_t> int16map;
	std::map<const IOperand*, int32_t> int32map;
	std::map<const IOperand*, float> floatmap;
	std::map<const IOperand*, double> doublemap;
};

template <class T, class D>
void testOperandsAddition(T op1, D op2) {
	try {
		auto result = *op1->first + *op2->first;
		if (result->getType() == Int8) {
			int64_t expected = op1->second + op2->second;
			ASSERT_STREQ(result->toString().data(), std::to_string(expected).data());
		}
		else if (result->getType() == Int16) {
			int16_t expected = op1->second + op2->second;
			ASSERT_STREQ(result->toString().data(), std::to_string(expected).data());
		}
		else if (result->getType() == Int32) {
			int32_t expected = op1->second + op2->second;
			ASSERT_STREQ(result->toString().data(), std::to_string(expected).data());
		}
//		else if (result->getType() == Float) {
//			std::ostringstream strs;
//			strs << op1->second + op2->second;
//			ASSERT_STREQ(result->toString().data(), strs.str().data());
//		}
//		else if (result->getType() == Double) {
//			std::ostringstream strs;
//			strs << op1->second + op2->second;
//			ASSERT_STREQ(result->toString().data(), strs.str().data());
//		}
	}
	catch (OperandSizeException& e)
	{
		ASSERT_THROW(auto result = *op1->first + *op2->first;, OperandSizeException);
	}
}

template <class T, class D>
void testOperandsSubtraction(T op1, D op2)
{
	try {
		auto result = *op1->first - *op2->first;
		if (result->getType() == Int8) {
			int64_t expected = op1->second - op2->second;
			ASSERT_STREQ(result->toString().data(), std::to_string(expected).data());
		}
		else if (result->getType() == Int16) {
			int16_t expected = op1->second - op2->second;
			ASSERT_STREQ(result->toString().data(), std::to_string(expected).data());
		}
		else if (result->getType() == Int32) {
			int32_t expected = op1->second - op2->second;
			ASSERT_STREQ(result->toString().data(), std::to_string(expected).data());
		}
//		else if (result->getType() == Float) {
//			std::cout << "+++++++++\n" << "op1: " << (int)op1->second << "\nop2: " << op2->second << std::endl;
////			std::stringstream strs;
////			strs << op1->second - op2->second;
////			ASSERT_STREQ(result->toString().data(), strs.str().data());
//			ASSERT_NEAR(std::stof(result->toString()), op1->second - op2->second, 0.1);
//		}
//		else if (result->getType() == Double) {
//			std::cout << "+++++++++\n" << "op1: " << (int)op1->second << "\nop2: " << op2->second << std::endl;
////			std::stringstream strs;
////			strs << op1->second - op2->second;
////			ASSERT_STREQ(result->toString().data(), strs.str().data());
//			ASSERT_NEAR(std::stof(result->toString()), op1->second - op2->second, 0.1);
//		}
	}
	catch (OperandSizeException& e)
	{
		ASSERT_THROW(auto result = *op1->first - *op2->first;, OperandSizeException);
	}
}

TEST_F(OperandsFixture, AddInt8Int8)
{
	for (auto it = int8map.begin(); it != int8map.end(); ++it)
	{
		for (auto it2 = int8map.begin(); it2 != int8map.end(); ++it2)
			testOperandsAddition(it, it2);
	}
}

TEST_F(OperandsFixture, AddInt8Int16)
{
	for (auto it = int8map.begin(); it != int8map.end(); ++it)
	{
		for (auto it2 = int16map.begin(); it2 != int16map.end(); ++it2)
		{
			testOperandsAddition(it, it2);
			testOperandsSubtraction(it, it2);
		}
	}
}

TEST_F(OperandsFixture, AddInt8Int32)
{
	for (auto it = int8map.begin(); it != int8map.end(); ++it)
	{
		for (auto it2 = int32map.begin(); it2 != int32map.end(); ++it2)
		{
			testOperandsAddition(it, it2);
			testOperandsSubtraction(it, it2);
		}
	}
}

TEST_F(OperandsFixture, AddInt8Float)
{
	for (auto it = int8map.begin(); it != int8map.end(); ++it)
	{
		for (auto it2 = floatmap.begin(); it2 != floatmap.end(); ++it2)
		{
			testOperandsAddition(it, it2);
			testOperandsSubtraction(it, it2);
		}
	}
}

TEST_F(OperandsFixture, AddInt8Double)
{
	for (auto it = int8map.begin(); it != int8map.end(); ++it)
	{
		for (auto it2 = doublemap.begin(); it2 != doublemap.end(); ++it2)
		{
			testOperandsAddition(it, it2);
			testOperandsSubtraction(it, it2);
		}
	}
}

TEST_F(OperandsFixture, AddInt16Int16)
{
	for (auto it = int16map.begin(); it != int16map.end(); ++it)
	{
		for (auto it2 = it; it2 != int16map.end(); ++it2)
		{
			testOperandsAddition(it, it2);
			testOperandsSubtraction(it, it2);
		}
	}
}

TEST_F(OperandsFixture, AddInt16Int32)
{
	for (auto it = int16map.begin(); it != int16map.end(); ++it)
	{
		for (auto it2 = int32map.begin(); it2 != int32map.end(); ++it2)
		{
			testOperandsAddition(it, it2);
			testOperandsSubtraction(it, it2);
		}
	}
}

TEST_F(OperandsFixture, AddInt16Float)
{
	for (auto it = int16map.begin(); it != int16map.end(); ++it)
	{
		for (auto it2 = floatmap.begin(); it2 != floatmap.end(); ++it2)
		{
			testOperandsAddition(it, it2);
			testOperandsSubtraction(it, it2);
		}
	}
}

TEST_F(OperandsFixture, AddInt16Double)
{
	for (auto it = int16map.begin(); it != int16map.end(); ++it)
	{
		for (auto it2 = doublemap.begin(); it2 != doublemap.end(); ++it2)
		{
			testOperandsAddition(it, it2);
			testOperandsSubtraction(it, it2);
		}
	}
}

TEST_F(OperandsFixture, AddInt32Int32)
{
	for (auto it = int32map.begin(); it != int32map.end(); ++it)
	{
		for (auto it2 = it; it2 != int32map.end(); ++it2)
		{
			testOperandsAddition(it, it2);
			testOperandsSubtraction(it, it2);
		}
	}
}

TEST_F(OperandsFixture, AddInt32Float)
{
	for (auto it = int32map.begin(); it != int32map.end(); ++it)
	{
		for (auto it2 = floatmap.begin(); it2 != floatmap.end(); ++it2)
		{
			testOperandsAddition(it, it2);
			testOperandsSubtraction(it, it2);
		}
	}
}

TEST_F(OperandsFixture, AddInt32Double)
{
	for (auto it = int32map.begin(); it != int32map.end(); ++it)
	{
		for (auto it2 = doublemap.begin(); it2 != doublemap.end(); ++it2)
		{
			testOperandsAddition(it, it2);
			testOperandsSubtraction(it, it2);
		}
	}
}

TEST_F(OperandsFixture, AddFloatFloat)
{
	for (auto it = floatmap.begin(); it != floatmap.end(); ++it)
	{
		for (auto it2 = it; it2 != floatmap.end(); ++it2)
		{
			testOperandsAddition(it, it2);
			testOperandsSubtraction(it, it2);
		}
	}
}

TEST_F(OperandsFixture, AddFloatDouble)
{
	for (auto it = floatmap.begin(); it != floatmap.end(); ++it)
	{
		for (auto it2 = doublemap.begin(); it2 != doublemap.end(); ++it2)
		{
			testOperandsAddition(it, it2);
			testOperandsSubtraction(it, it2);
		}
	}
}

TEST_F(OperandsFixture, AddDoubleDouble)
{
	for (auto it = doublemap.begin(); it != doublemap.end(); ++it)
	{
		for (auto it2 = doublemap.begin(); it2 != doublemap.end(); ++it2)
		{
			testOperandsAddition(it, it2);
			testOperandsSubtraction(it, it2);
		}
	}
}