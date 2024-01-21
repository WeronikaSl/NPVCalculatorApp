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
			std::cout << "BLAD/ERROR - PODAJ NUMER Z ZAKRESU 0.00-1.00/ENTER NUMBER FROM 0.00 TO 1.00: "; //create statement in StatementDisplayer
			std::cin.clear();
			std::cin.ignore(123, '\n'); //todo hardcoded, fix
		}
		if (!(result >= 0 && result <= 1))
		{
			std::cout << "BLAD/ERROR - PODAJ NUMER Z ZAKRESU 0.00-1.00/ENTER NUMBER FROM 0.00 TO 1.00: "; //create statement in StatementDisplayer
			std::cin.clear();
			std::cin.ignore(123, '\n'); //todo hardcoded, fix
		}
	} while (!(result >= 0 && result <= 1));
	return result;
}

YearsOfInvestment UserInteractionHandlerImpl::getYearsOfInvestment() const
{
	YearsOfInvestment result{ 0 };
	statementDisplayer->yearsOfInvestment();
	do
	{
		while (!(std::cin >> result))
		{
			std::cout << "BLAD/ERROR - PODAJ LICZBE WIEKSZA OD 0/ENTER NUMBER GREATER THAN 0: "; //create statement in StatementDisplayer
			std::cin.clear();
			std::cin.ignore(123, '\n'); //todo hardcoded, fix
		}
		if (!(result > 0))
		{
			std::cout << "BLAD/ERROR - PODAJ LICZBE WIEKSZA OD 0/ENTER NUMBER GREATER THAN 0: "; //create statement in StatementDisplayer
			std::cin.clear();
			std::cin.ignore(123, '\n'); //todo hardcoded, fix
		}
	} while (!(result > 0));
	return result;
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
			std::cout << "BLAD/ERROR - PODAJ LICZBE WIEKSZA OD 0/ENTER NUMBER GREATER THAN 0: "; //create statement in StatementDisplayer
			std::cin.clear();
			std::cin.ignore(123, '\n'); //todo hardcoded, fix
		}
		if (!(cashflow > 0))
		{
			std::cout << "BLAD/ERROR - PODAJ LICZBE WIEKSZA OD 0/ENTER NUMBER GREATER THAN 0: "; //create statement in StatementDisplayer
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
			std::cout << "BLAD/ERROR - PODAJ LICZBE CALKOWITA/ENTER A WHOLE NUMBER: "; //create statement in StatementDisplayer
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
	std::cout << "Wybierz jezyk/select language - polski nacisnij 1/for English press 2: ";

	while (!(result == 1 || result == 2))
	{
		while (!(std::cin >> result))
		{
			std::cout << "BLAD/ERROR - PODAJ NUMER 1 LUB 2/ENTER NUMBER 1 OR 2: "; //create statement in StatementDisplayer
			std::cin.clear();
			std::cin.ignore(123, '\n'); //todo hardcoded, fix
		}
		if (!(result == 1 || result == 2))
		{
			std::cout << "BLAD/ERROR - PODAJ NUMER 1 LUB 2/ENTER NUMBER 1 OR 2: ";
			std::cin.clear();
			std::cin.ignore(123, '\n'); //todo hardcoded, fix
		}

	}
	return static_cast<Language>(static_cast<uint16_t>(result));
}
