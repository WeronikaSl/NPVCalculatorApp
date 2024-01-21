#pragma once
#include "EnglishStatementDisplayer.hpp"

class EnglishStatementDisplayerImpl : public EnglishStatementDisplayer
{
public:
	void discountRate() const;
	void yearsOfInvestment() const;
	void investedAmountOfMoney() const;
	void allCashFlows() const;
	void singleCashFlow(uint16_t) const;
	void compareNPVAndInitialCost(double, int64_t) const;
	void isProfitable() const;
	void isNotProfitable() const;
	void incorrectDiscountRateInput() const;
	void enterIntGreaterThanZero() const;
	void enterWholeNumber() const;
};