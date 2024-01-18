#pragma once
#include "NPVCalculator.hpp"
#include "Types.hpp"
#include "PolishStatementDisplayerImpl.hpp"
#include "EnglishStatementDisplayerImpl.hpp"
#include <memory>

class NPVCalculatorImpl
{
private:
	DiscountRate discountRate{ 0.0f };
	YearsOfInvestment yearsOfInvestment{ 0 };
	CashFlows cashFlows{};
	std::shared_ptr<StatementDisplayer> statementDisplayer{ nullptr };
public:
	NPVCalculatorImpl(DiscountRate, YearsOfInvestment, CashFlows);
	NPVCalculatorImpl();
	double countNPV();
	void setDiscountRate(DiscountRate);
	void setYearsOfInvestment(YearsOfInvestment);
	void setCashFlows(CashFlows);
	YearsOfInvestment getYearsOfInvestment() const;
	void isInvestmentProfitable();
};