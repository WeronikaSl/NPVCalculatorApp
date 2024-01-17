#include "UserInteractionHandlerImpl.hpp"
#include <iostream>

DiscountRate UserInteractionHandlerImpl::getDiscountRate() const
{
	DiscountRate result{ 0.00 };
	std::cout << "Podaj stope dyskontowa (liczba z przedzialu 0.00 - 1, np 0.15 oznacza 15%): ";
	std::cin >> result;
	return result;
}

YearsOfInvestment UserInteractionHandlerImpl::getYearsOfInvestment() const
{
	YearsOfInvestment result{ 0 };
	std::cout << "Podaj ilosc lat, na ktore przewidziana jest inwestycja (bez uwzglednienia roku 0, gdy pieniadze zainwestowano): ";
	std::cin >> result;
	return result;
}

CashFlows UserInteractionHandlerImpl::getCashFlows(YearsOfInvestment yearsOfInvestment) const
{
	CashFlows result{};
	int64_t cashflow{ 0 };
	std::cout << "Podaj cash flows z poszczegolnych lat (zaczynajac od roku 0, gdy pieniadze zainwestowano): ";
	for (uint16_t i{ 0 }; i <= yearsOfInvestment; i++)
	{
		std::cout << "Podaj cash flow w roku " << i << ": ";
		std::cin >> cashflow;
		result.push_back(cashflow);
	}
	return result;
}
