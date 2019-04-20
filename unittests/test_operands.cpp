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

class OperandsFixture : public ::testing::Test {
public:
	virtual ~OperandsFixture() {}

protected:
	virtual void SetUp() {
		int8map = {
				{std::to_string(42), 42},
				{std::to_string(-25), -25},
				{std::to_string(INT8_MIN), INT8_MIN},
				{std::to_string(INT8_MAX), INT8_MAX},
				{std::to_string(INT8_MIN - 1), INT8_MIN - 1},
				{std::to_string(INT8_MAX + 1), INT8_MIN + 1}
		};
	}

	std::map<std::string, int8_t> int8map;
	std::map<std::string, int16_t> int16map;
	std::map<std::string, int32_t> int32map;
	std::map<std::string, float> floatmap;
	std::map<std::string, double> doublemap;
};

TEST_F(OperandsFixture, AddInt8Int8)
{
	for (auto it = int8map.begin(); it != int8map.end(); ++it)
	{
		for (auto it2 = it; )
		IOperand** const =
	}
	auto op1 = FACTORY.createOperand(int8map.find("42")->second);
	auto res = op1 + op1;
}
