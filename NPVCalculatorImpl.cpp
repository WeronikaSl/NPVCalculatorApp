#include "NPVCalculatorImpl.hpp"
#include <cmath>

NPVCalculatorImpl::NPVCalculatorImpl(DiscountRate discountRate, YearsOfInvestment yearsOfInvestment, CashFlows cashFlows)
	: discountRate(discountRate), yearsOfInvestment(yearsOfInvestment), cashFlows(cashFlows)
{}

double NPVCalculatorImpl::countNPV()
{
	uint16_t yearOfInvestment{ 0 };
	double npv{ 0.0 };
	for (int64_t cashflow : cashFlows)
	{
		npv += (cashflow / std::pow((1 + discountRate), yearOfInvestment)); //NPV formula
		yearOfInvestment++;
	}
	return npv;
}