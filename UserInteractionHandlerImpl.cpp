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
	std::cout << "Podaj ilosc zainwestowanych pieniedzy(wyrazone w liczbie calkowitej, dodatniej): ";
	std::cin >> cashflow;
	result.push_back(cashflow * (-1)); //to get negative number for NPV formula

	std::cout << "Podaj cash flows z poszczegolnych lat (wyrazone w liczbach calkowitych, dodatnich lub ujemnych): " << std::endl;
	for (uint16_t i{ 1 }; i <= yearsOfInvestment; i++)
	{
		std::cout << "Podaj cash flow w roku " << i << ": ";
		std::cin >> cashflow;
		result.push_back(cashflow);
	}
	return result;
}
