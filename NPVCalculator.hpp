#pragma once

class NPVCalculator
{
public:
	virtual ~NPVCalculator() {}
	virtual double countNPV() = 0;
	virtual void isInvestmentProfitable() = 0;
};