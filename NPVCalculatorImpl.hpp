#pragma once
#include "NPVCalculator.hpp"
#include "Types.hpp"

class NPVCalculatorImpl
{
private:
	DiscountRate discountRate{ 0.0f }; //stopa dyskontowa
	YearsOfInvestment yearsOfInvestment{ 0 }; //is it needed? 
	CashFlows cashFlows{};
public:
	NPVCalculatorImpl(DiscountRate, YearsOfInvestment, CashFlows);
	NPVCalculatorImpl() = default;
	double countNPV();

};