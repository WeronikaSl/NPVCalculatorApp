#include "NPVCalculatorImpl.hpp"
#include <cmath>
#include <iostream>

NPVCalculatorImpl::NPVCalculatorImpl(DiscountRate discountRate, YearsOfInvestment yearsOfInvestment, CashFlows cashFlows)
	: discountRate(discountRate), yearsOfInvestment(yearsOfInvestment), cashFlows(cashFlows)
{}

double NPVCalculatorImpl::countNPV()
{
	uint16_t yearOfInvestment{ 0 };
	double result{ 0.0 };
	for (int64_t cashflow : cashFlows)
	{
		result += (cashflow / std::pow((1 + discountRate), yearOfInvestment)); //NPV formula
		yearOfInvestment++;
	}
	return result;
}

void NPVCalculatorImpl::setDiscountRate(DiscountRate newDiscountRate)
{
	discountRate = newDiscountRate;
}

void NPVCalculatorImpl::setYearsOfInvestment(YearsOfInvestment newYearsOfInvestment)
{
	yearsOfInvestment = newYearsOfInvestment;
}

void NPVCalculatorImpl::setCashFlows(CashFlows newCashFlows)
{
	cashFlows = newCashFlows;
}

YearsOfInvestment NPVCalculatorImpl::getYearsOfInvestment() const
{
	return yearsOfInvestment;
}

void NPVCalculatorImpl::isInvestmentProfitable()
{
	double npv{ countNPV() };
	int64_t initialCost{ (cashFlows[0] * (-1)) };
	std::cout 
		<< "NPV: " << npv << std::endl //data is stored internally in binary format so it's not possible to accurately represent decimal digits - hence lack of precision
		<< "Koszt poczatkowy: " << initialCost << std::endl; //to get positive value
	if (npv > initialCost)
	{
		std::cout << "Inwestycja jest oplacalna" << std::endl;
	}
	else
	{
		std::cout << "Inwestycja nie jest oplacalna" << std::endl;
	}
}
