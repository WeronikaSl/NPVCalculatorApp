#include "AppManagerImpl.hpp"
#include <iostream>

AppManagerImpl AppManagerImpl::instance;

AppManagerImpl& AppManagerImpl::getInstance()
{
	return instance;
}

void AppManagerImpl::useNPVCalculator()
{
	statementDisplayer = StatementDisplayerFactoryImpl::getStatementDisplayer(userInteractionHandler.getLanguage());
	userInteractionHandler.setStatementDisplayer(statementDisplayer);
	npvCalculator.setStatementDisplayer(statementDisplayer);
	npvCalculator.setDiscountRate(userInteractionHandler.getDiscountRate());
	npvCalculator.setYearsOfInvestment(userInteractionHandler.getYearsOfInvestment());
	npvCalculator.setCashFlows(userInteractionHandler.getCashFlows(npvCalculator.getYearsOfInvestment()));
	npvCalculator.isInvestmentProfitable();
}
