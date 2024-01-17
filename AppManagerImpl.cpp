#include "AppManagerImpl.hpp"
#include <iostream>

void AppManagerImpl::useNPVCalculator()
{
	npvCalculator.setDiscountRate(userInteractionHandler.getDiscountRate());
	npvCalculator.setYearsOfInvestment(userInteractionHandler.getYearsOfInvestment());
	npvCalculator.setCashFlows(userInteractionHandler.getCashFlows(npvCalculator.getYearsOfInvestment()));
	std::cout << "NPV: " << npvCalculator.countNPV() << std::endl; //data is stored internally in binary format so it's not possible to accurately represent decimal digits - hence lack of precision
}
