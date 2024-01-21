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

void PolishStatementDisplayerImpl::compareNPVAndInitialCost(double npv, int64_t initialCost) const
{
	std::cout << "NPV: " << npv << std::endl << "Koszt poczatkowy: " << initialCost << std::endl;
}

void PolishStatementDisplayerImpl::isProfitable() const
{
	std::cout << "Inwestycja jest oplacalna" << std::endl;
}

void PolishStatementDisplayerImpl::isNotProfitable() const
{
	std::cout << "Inwestycja nie jest oplacalna" << std::endl;
}

void PolishStatementDisplayerImpl::incorrectDiscountRateInput() const
{
	std::cout << "BLAD! Podaj liczbe z zakresu 0.00-1.00: ";
}

void PolishStatementDisplayerImpl::enterIntGreaterThanZero() const
{
	std::cout << "BLAD! Podaj liczbe wieksza od 0: ";
}

void PolishStatementDisplayerImpl::enterWholeNumber() const
{
	std::cout << "BLAD! Podaj liczbe calkowita: ";
}
