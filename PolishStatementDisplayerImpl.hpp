#pragma once
#include "PolishStatementDisplayer.hpp"

class PolishStatementDisplayerImpl : public PolishStatementDisplayer
{
public:
	void discountRate() const;
	void yearsOfInvestment() const;
	void investedAmountOfMoney() const;
	void allCashFlows() const;
	void singleCashFlow(uint16_t) const;
};