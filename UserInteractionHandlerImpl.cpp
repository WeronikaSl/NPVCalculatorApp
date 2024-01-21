#include "UserInteractionHandlerImpl.hpp"
#include <iostream>


DiscountRate UserInteractionHandlerImpl::getDiscountRate() const
{
	DiscountRate result{ 0.00 };
	statementDisplayer->discountRate();
	do
	{
		while (!(std::cin >> result))
		{
			statementDisplayer->incorrectDiscountRateInput();
			std::cin.clear();
			std::cin.ignore(123, '\n'); //todo hardcoded, fix
		}
		if (!(result >= 0 && result <= 1))
		{
			statementDisplayer->incorrectDiscountRateInput();
			std::cin.clear();
			std::cin.ignore(123, '\n'); //todo hardcoded, fix
		}
	} while (!(result >= 0 && result <= 1));
	return result;
}

YearsOfInvestment UserInteractionHandlerImpl::getYearsOfInvestment() const
{
	double result{ 0 }; //when its an int console treats 2.2 as correct imput, which shoule be an error
	statementDisplayer->yearsOfInvestment();
	do
	{
		while (!(std::cin >> result))
		{
			statementDisplayer->enterIntGreaterThanZero();
			std::cin.clear();
			std::cin.ignore(123, '\n'); //todo hardcoded, fix
		}
		if (!(result > 0))
		{
			statementDisplayer->enterIntGreaterThanZero();
			std::cin.clear();
			std::cin.ignore(123, '\n'); //todo hardcoded, fix
		}
	} while (!(result > 0));
	return static_cast<YearsOfInvestment>(result);
}

CashFlows UserInteractionHandlerImpl::getCashFlows(YearsOfInvestment yearsOfInvestment) const
{
	CashFlows result{};
	int64_t cashflow{ 0 };

	statementDisplayer->investedAmountOfMoney();

	do
	{
		while (!(std::cin >> cashflow))
		{
			statementDisplayer->enterIntGreaterThanZero();
			std::cin.clear();
			std::cin.ignore(123, '\n'); //todo hardcoded, fix
		}
		if (!(cashflow > 0))
		{
			statementDisplayer->enterIntGreaterThanZero();
			std::cin.clear();
			std::cin.ignore(123, '\n'); //todo hardcoded, fix
		}
	} while (!(cashflow > 0));

	result.push_back(cashflow * (-1)); //to get negative number for NPV formula

	std::cin.clear();
	std::cin.ignore(123, '\n'); //todo hardcoded, fix

	statementDisplayer->allCashFlows();
	for (uint16_t i{ 1 }; i <= yearsOfInvestment; i++)
	{
		statementDisplayer->singleCashFlow(i);
		while (!(std::cin >> cashflow))
		{
			statementDisplayer->enterWholeNumber();
			std::cin.clear();
			std::cin.ignore(123, '\n'); //todo hardcoded, fix
		}
		result.push_back(cashflow);
	}
	return result;
}

void UserInteractionHandlerImpl::setStatementDisplayer(std::shared_ptr<StatementDisplayer> newStatementDisplayer) //todo shouldnt this be passed-by-reference?
{
	statementDisplayer = newStatementDisplayer;
}

Language UserInteractionHandlerImpl::getLanguage() const
{
	double result{ 0 }; //when  its an int console treats 2.2 as correct imput, which shoule be an error
	StatementDisplayer::selectLanguage(); //static because here we dont have an object yet

	while (!(result == 1 || result == 2))
	{
		while (!(std::cin >> result))
		{
			StatementDisplayer::incorrectLanguageChoice();
			std::cin.clear();
			std::cin.ignore(123, '\n'); //todo hardcoded, fix
		}
		if (!(result == 1 || result == 2))
		{
			StatementDisplayer::incorrectLanguageChoice();
			std::cin.clear();
			std::cin.ignore(123, '\n'); //todo hardcoded, fix
		}

	}
	return static_cast<Language>(static_cast<uint16_t>(result));
}
