#pragma once
#include "NPVCalculator.hpp"
#include "Types.hpp"

class NPVCalculatorImpl
{
private:
	DiscountRate discountRate{ 0.0f };
	YearsOfInvestment yearsOfInvestment{ 0 };
	CashFlows cashFlows{};
public:
	NPVCalculatorImpl(DiscountRate, YearsOfInvestment, CashFlows);
	NPVCalculatorImpl() = default;
	double countNPV();
	void setDiscountRate(DiscountRate);
	void setYearsOfInvestment(YearsOfInvestment);
	void setCashFlows(CashFlows);
	YearsOfInvestment getYearsOfInvestment() const;
	void isInvestmentProfitable();
};