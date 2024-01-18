#pragma once
#include <iostream>

class StatementDisplayer
{
public: 
	virtual ~StatementDisplayer() = default;
	virtual void discountRate() const = 0;
	virtual void yearsOfInvestment() const = 0;
	virtual void investedAmountOfMoney() const = 0;
	virtual void allCashFlows() const = 0;
	virtual void singleCashFlow(uint16_t) const = 0;
};