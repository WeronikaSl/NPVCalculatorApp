#include "PolishStatementDisplayerImpl.hpp"
#include <iostream>

void PolishStatementDisplayerImpl::discountRate() const
{
	std::cout << "Podaj stope dyskontowa (liczba z przedzialu 0.00 - 1, np 0.15 oznacza 15%): ";
}

void PolishStatementDisplayerImpl::yearsOfInvestment() const
{
	std::cout << "Podaj ilosc lat, na ktore przewidziana jest inwestycja (bez uwzglednienia roku 0, gdy pieniadze zainwestowano): ";
}

void PolishStatementDisplayerImpl::investedAmountOfMoney() const
{
	std::cout << "Podaj ilosc zainwestowanych pieniedzy(wyrazone w liczbie calkowitej, dodatniej): ";
}

void PolishStatementDisplayerImpl::allCashFlows() const
{
	std::cout << "Podaj cash flows z poszczegolnych lat (wyrazone w liczbach calkowitych, dodatnich lub ujemnych): " << std::endl;
}

void PolishStatementDisplayerImpl::singleCashFlow(uint16_t year) const
{
	std::cout << "Podaj cash flow w roku " << year << ": ";
}