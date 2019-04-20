/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_int8.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <aminadzh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 17:37:00 by aminadzh          #+#    #+#             */
/*   Updated: 2019/04/14 17:37:00 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdio>
#include <stdint.h>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../src/OperandFactory.h"

class Int8Fixture : public ::testing::Test {
public:
	virtual ~Int8Fixture() {}

protected:
	virtual void SetUp() {
		m_pos = std::to_string(42);
		m_neg = std::to_string(-25);
		m_min = std::to_string(INT8_MIN);
		m_max = std::to_string(INT8_MAX);
		m_underflow = std::to_string(INT8_MIN - 1);
		m_overflow = std::to_string(INT8_MAX + 1);
	}
	std::string m_pos;
	std::string m_neg;
	std::string m_min;
	std::string m_max;
	std::string m_underflow;
	std::string m_overflow;

};

TEST_F(Int8Fixture, Type)
{
	auto op1 = FACTORY.createOperand(Int8, m_pos);
	ASSERT_EQ(op1->getType(), Int8);
	auto op2 = FACTORY.createOperand(Int8, m_neg);
	ASSERT_EQ(op2->getType(), Int8);
	auto op3 = FACTORY.createOperand(Int8, m_min);
	ASSERT_EQ(op3->getType(), Int8);
	auto op4 = FACTORY.createOperand(Int8, m_max);
	ASSERT_EQ(op4->getType(), Int8);
	auto op5 = FACTORY.createOperand(Int8, m_underflow);
	ASSERT_EQ(op5->getType(), Int8);
	auto op6 = FACTORY.createOperand(Int8, m_overflow);
	ASSERT_EQ(op6->getType(), Int8);
}

TEST_F(Int8Fixture, Precision)
{
	auto op1 = FACTORY.createOperand(Int8, m_pos);
	ASSERT_EQ(op1->getPrecision(), 0);
	auto op2 = FACTORY.createOperand(Int8, m_neg);
	ASSERT_EQ(op2->getPrecision(), 0);
	auto op3 = FACTORY.createOperand(Int8, m_min);
	ASSERT_EQ(op3->getPrecision(), 0);
	auto op4 = FACTORY.createOperand(Int8, m_max);
	ASSERT_EQ(op4->getPrecision(), 0);
	auto op5 = FACTORY.createOperand(Int8, m_underflow);
	ASSERT_EQ(op5->getPrecision(), 0);
	auto op6 = FACTORY.createOperand(Int8, m_overflow);
	ASSERT_EQ(op6->getPrecision(), 0);
}

TEST_F(Int8Fixture, ToString)
{
	auto op1 = FACTORY.createOperand(Int8, m_pos);
	ASSERT_STREQ(m_pos.c_str(), op1->toString().c_str());
	auto op2 = FACTORY.createOperand(Int8, m_neg);
	ASSERT_STREQ(m_neg.c_str(), op2->toString().c_str());
	auto op3 = FACTORY.createOperand(Int8, m_min);
	ASSERT_STREQ(m_min.c_str(), op3->toString().c_str());
	auto op4 = FACTORY.createOperand(Int8, m_max);
	ASSERT_STREQ(m_max.c_str(), op4->toString().c_str());
	auto op5 = FACTORY.createOperand(Int8, m_underflow);
	int8_t exp = std::stoi(m_underflow);
	ASSERT_STREQ(std::to_string(exp).data(), op5->toString().c_str());
	auto op6 = FACTORY.createOperand(Int8, m_overflow);
	exp = std::stoi(m_overflow);
	ASSERT_STREQ(std::to_string(exp).data(), op6->toString().c_str());
}
