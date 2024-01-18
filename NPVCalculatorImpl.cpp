#include "NPVCalculatorImpl.hpp"
#include <cmath>
#include <iostream>

NPVCalculatorImpl::NPVCalculatorImpl(DiscountRate discountRate, YearsOfInvestment yearsOfInvestment, CashFlows cashFlows)
	: discountRate(discountRate), yearsOfInvestment(yearsOfInvestment), cashFlows(cashFlows)
{}

NPVCalculatorImpl::NPVCalculatorImpl()
{
	statementDisplayer = std::make_shared<EnglishStatementDisplayerImpl>();
}

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
	double npv{ countNPV() }; //data is stored internally in binary format so it's not possible to accurately represent decimal digits - hence lack of precision
	int64_t initialCost{ (cashFlows[0] * (-1)) }; //to get positive value
	statementDisplayer->compareNPVAndInitialCost(npv, initialCost);
	if (npv > initialCost)
	{
		statementDisplayer->isProfitable();
	}
	else
	{
		statementDisplayer->isNotProfitable();
	}
}
