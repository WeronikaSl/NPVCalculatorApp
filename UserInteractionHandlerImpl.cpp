#include "UserInteractionHandlerImpl.hpp"
#include <iostream>

void UserInteractionHandlerImpl::discardImput() const
{
	std::cin.clear();
	constexpr int64_t amountOfCharsToSkip{ std::numeric_limits<std::streamsize>::max() };
	constexpr uint8_t newLine{ '\n' };
	std::cin.ignore(amountOfCharsToSkip, newLine);
}

DiscountRate UserInteractionHandlerImpl::getDiscountRate() const
{
	DiscountRate result{ 0.00 };
	statementDisplayer->discountRate();
	do
	{
		while (!(std::cin >> result))
		{
			statementDisplayer->incorrectDiscountRateInput();
			discardImput();
		}
		if (!(result >= 0 && result <= 1))
		{
			statementDisplayer->incorrectDiscountRateInput();
			discardImput();
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
			discardImput();
		}
		if (!(result > 0))
		{
			statementDisplayer->enterIntGreaterThanZero();
			discardImput();
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
			discardImput();
		}
		if (!(cashflow > 0))
		{
			statementDisplayer->enterIntGreaterThanZero();
			discardImput();
		}
	} while (!(cashflow > 0));

	result.push_back(cashflow * (-1)); //to get negative number for NPV formula

	discardImput();

	statementDisplayer->allCashFlows();
	for (uint16_t i{ 1 }; i <= yearsOfInvestment; i++)
	{
		statementDisplayer->singleCashFlow(i);
		while (!(std::cin >> cashflow))
		{
			statementDisplayer->enterWholeNumber();
			discardImput();
		}
		result.push_back(cashflow);
	}
	return result;
}

void UserInteractionHandlerImpl::setStatementDisplayer(std::shared_ptr<StatementDisplayer> newStatementDisplayer)
{
	statementDisplayer = newStatementDisplayer;
}

Language UserInteractionHandlerImpl::getLanguage() const
{
	double result{ 0 }; //when  its an int console treats 2.2 as correct imput, which shoule be an error
	StatementDisplayer::selectLanguage(); //static because here we dont have an object yet
	do
	{
		while (!(std::cin >> result))
		{
			StatementDisplayer::incorrectLanguageChoice();
			discardImput();
		}
		if (!(result == 1 || result == 2))
		{
			StatementDisplayer::incorrectLanguageChoice();
			discardImput();
		}
	} while (!(result == 1 || result == 2));
	return static_cast<Language>(static_cast<uint16_t>(result));
}

