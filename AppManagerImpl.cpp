#include "AppManagerImpl.hpp"
#include <iostream>


void AppManagerImpl::useNPVCalculator()
{
	statementDisplayer = StatementDisplayerFactoryImpl::getStatementDisplayer(userInteractionHandler.getLanguage()); //create enum class for this
	userInteractionHandler.setStatementDisplayer(statementDisplayer);
	npvCalculator.setStatementDisplayer(statementDisplayer);
	npvCalculator.setDiscountRate(userInteractionHandler.getDiscountRate());
	npvCalculator.setYearsOfInvestment(userInteractionHandler.getYearsOfInvestment());
	npvCalculator.setCashFlows(userInteractionHandler.getCashFlows(npvCalculator.getYearsOfInvestment()));
	npvCalculator.isInvestmentProfitable();
}
