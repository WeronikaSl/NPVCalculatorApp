#include "NPVCalculatorImpl.hpp"
#include <cmath>

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
