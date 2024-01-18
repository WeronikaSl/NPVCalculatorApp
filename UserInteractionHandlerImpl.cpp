#include "UserInteractionHandlerImpl.hpp"
#include <iostream>


DiscountRate UserInteractionHandlerImpl::getDiscountRate() const
{
	DiscountRate result{ 0.00 };
	statementDisplayer->discountRate();
	std::cin >> result;
	return result;
}

YearsOfInvestment UserInteractionHandlerImpl::getYearsOfInvestment() const
{
	YearsOfInvestment result{ 0 };
	statementDisplayer->yearsOfInvestment();
	std::cin >> result;
	return result;
}

CashFlows UserInteractionHandlerImpl::getCashFlows(YearsOfInvestment yearsOfInvestment) const
{
	CashFlows result{};
	int64_t cashflow{ 0 };
	statementDisplayer->investedAmountOfMoney();
	std::cin >> cashflow;
	result.push_back(cashflow * (-1)); //to get negative number for NPV formula

	statementDisplayer->allCashFlows();
	for (uint16_t i{ 1 }; i <= yearsOfInvestment; i++)
	{
		statementDisplayer->singleCashFlow(i);
		std::cin >> cashflow;
		result.push_back(cashflow);
	}
	return result;
}

void UserInteractionHandlerImpl::setStatementDisplayer(std::shared_ptr<StatementDisplayer> newStatementDisplayer)
{
	statementDisplayer = newStatementDisplayer;
}
