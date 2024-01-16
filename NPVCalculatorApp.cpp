// NPVCalculatorApp.cpp : Defines the entry point for the application.
//

#include "NPVCalculatorApp.hpp"


int main()
{
	CashFlows cashFlows{ -40000, 20000, 25000,17000,15000,16000 };
	DiscountRate discountRate{ 0.08 };
	YearsOfInvestment yearsOfInvestments{ 5 };
	NPVCalculatorImpl nvpCalc{ discountRate, yearsOfInvestments, cashFlows };
	std::cout << nvpCalc.countNPV() << std::endl; //data is stored internally in binary format so it's not possible to accurately represent decimal digits - hence lack of precision

}
