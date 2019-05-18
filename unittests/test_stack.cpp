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
#include "../src/OperandSizeException.h"
#include "../src/OperandFactory.h"

class StackFixture : public ::testing::Test
{
public:
	StackFixture()
	{}
	virtual ~StackFixture() {}
protected:
	virtual void SetUp() {}
	void createStack()
	{
		for(size_t i = 0; i < stack.size(); ++i)
			stack.pop();
		stack.push(FACTORY.createOperand(Double, "8.5"));
		stack.push(FACTORY.createOperand(Float, "5.5"));
		stack.push(FACTORY.createOperand(Int32, "5"));
		stack.push(FACTORY.createOperand(Int16, "3"));
		stack.push(FACTORY.createOperand(Int8, "1"));
	}
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
	ASSERT_THROW(stack.compare(FACTORY.createOperand(Int8, "12")), StackException);
	try {
		stack.compare(FACTORY.createOperand(Int8, "12"));
	}
	catch (StackException& e)
	{
		ASSERT_STREQ(e.getInfo(), "Assertion failed");
	}
	stack.push(FACTORY.createOperand(Int8, "1"));
	stack.push(FACTORY.createOperand(Float, "8.5"));
	stack.add();
	stack.compare(FACTORY.createOperand(Float, "9.5"));
}

TEST_F(StackFixture, addition)
{
	createStack();
	stack.add();
	stack.compare(FACTORY.createOperand(Int16, "4"));
	stack.add();
	stack.compare(FACTORY.createOperand(Int32, "9"));
	stack.add();
	stack.compare(FACTORY.createOperand(Float, "14.5"));
	stack.add();
	stack.compare(FACTORY.createOperand(Double, "23"));
	ASSERT_THROW(stack.add(), StackException);
	try {
		stack.add();
	}
	catch (StackException& e)
	{
		ASSERT_STREQ(e.getInfo(), "Stack size is less than 2");
	}
}

TEST_F(StackFixture, subtraction)
{
	createStack();
	stack.sub();
	stack.compare(FACTORY.createOperand(Int16, "2"));
	stack.sub();
	stack.compare(FACTORY.createOperand(Int32, "3"));
	stack.sub();
	stack.compare(FACTORY.createOperand(Float, "2.5"));
	stack.sub();
	stack.compare(FACTORY.createOperand(Double, "6"));
}

TEST_F(StackFixture, multiplication)
{
	createStack();
	stack.mul();
	stack.compare(FACTORY.createOperand(Int16, "3"));
	stack.mul();
	stack.compare(FACTORY.createOperand(Int32, "15"));
	stack.mul();
	stack.compare(FACTORY.createOperand(Float, "82.5"));
	stack.mul();
	stack.compare(FACTORY.createOperand(Double, "701.25"));
}

TEST_F(StackFixture, division)
{
	createStack();
	stack.div();
	stack.compare(FACTORY.createOperand(Int16, "3"));
	stack.div();
	stack.compare(FACTORY.createOperand(Int32, "1"));
	stack.div();
	stack.compare(FACTORY.createOperand(Float, "5.5"));
	stack.div();
	stack.dump();
	stack.compare(FACTORY.createOperand(Double, "1.54545"));
}

TEST_F(StackFixture, modulus)
{
	for(size_t i = 0; i < stack.size(); ++i)
		stack.pop();
	stack.push(FACTORY.createOperand(Float, "5.5"));
	stack.push(FACTORY.createOperand(Int32, "13"));
	stack.push(FACTORY.createOperand(Int16, "8"));
	stack.push(FACTORY.createOperand(Int8, "3"));
	stack.mod();
	stack.compare(FACTORY.createOperand(Int16, "2"));
	stack.mod();
	stack.compare(FACTORY.createOperand(Int32, "1"));
	ASSERT_THROW(stack.mod(), OperandSizeException);
}

TEST_F(StackFixture, print)
{
	createStack();
	stack.push(FACTORY.createOperand(Int8, "77"));
	stack.print();
	stack.pop();
	stack.print();
	stack.pop();
	ASSERT_THROW(stack.print(), StackException);
}
