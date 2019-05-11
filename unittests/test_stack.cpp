/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <aminadzh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 16:50:00 by aminadzh          #+#    #+#             */
/*   Updated: 2019/05/11 16:50:00 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdio>
#include <stdint.h>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../src/OperandStack.h"
#include "../src/StackException.h"
#include "../src/OperandFactory.h"

class StackFixture : public ::testing::Test
{
public:
	StackFixture()
	{}
	virtual ~StackFixture() {}
protected:
	virtual void SetUp() {}
	OperandStack stack;
};

TEST_F(StackFixture, stack_empty)
{
	ASSERT_THROW(stack.dump(), StackException);
	try {
		stack.dump();
	}
	catch (StackException& e)
	{
		ASSERT_STREQ(e.getInfo(), "Dump on empty stack");
	}
	ASSERT_THROW(stack.pop(), StackException);
	try {
		stack.pop();
	}
	catch (StackException& e)
	{
		ASSERT_STREQ(e.getInfo(), "Pop on empty stack");
	}

}

TEST_F(StackFixture, dump)
{
	stack.push(FACTORY.createOperand(Int8, "8"));
	stack.push(FACTORY.createOperand(Int16, "16"));
	stack.push(FACTORY.createOperand(Int32, "32"));
	stack.push(FACTORY.createOperand(Float, "-2.42"));
	stack.push(FACTORY.createOperand(Double, "32.042"));
	stack.dump();
	stack.pop();
	stack.dump();
	stack.compare(FACTORY.createOperand(Float, "-2.42"));
	ASSERT_THROW(stack.compare(FACTORY.createOperand(Int8, "12")), StackException);
	try {
		stack.compare(FACTORY.createOperand(Int8, "12"));
	}
	catch (StackException& e)
	{
		ASSERT_STREQ(e.getInfo(), "Assertion of -2.42 of type Float with 12 of type Int8");
	}

}
