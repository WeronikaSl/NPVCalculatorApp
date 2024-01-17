#include "AppManagerImpl.hpp"
#include <iostream>

void AppManagerImpl::useNPVCalculator()
{
	npvCalculator.setDiscountRate(userInteractionHandler.getDiscountRate());
	npvCalculator.setYearsOfInvestment(userInteractionHandler.getYearsOfInvestment());
	npvCalculator.setCashFlows(userInteractionHandler.getCashFlows(npvCalculator.getYearsOfInvestment()));
	npvCalculator.isInvestmentProfitable();
}
