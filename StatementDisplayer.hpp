#pragma once
#include <iostream>

class StatementDisplayer
{
public: 
	virtual ~StatementDisplayer() = default;
	static void selectLanguage();
	static void incorrectLanguageChoice();
	static std::string incorrectLanguageException();
	virtual void discountRate() const = 0;
	virtual void yearsOfInvestment() const = 0;
	virtual void investedAmountOfMoney() const = 0;
	virtual void allCashFlows() const = 0;
	virtual void singleCashFlow(uint16_t) const = 0;
	virtual void compareNPVAndInitialCost(double, int64_t) const = 0;
	virtual void isProfitable() const = 0;
	virtual void isNotProfitable() const = 0;
	virtual void incorrectDiscountRateInput() const = 0;
	virtual void enterIntGreaterThanZero() const = 0;
	virtual void enterWholeNumber() const = 0;
};