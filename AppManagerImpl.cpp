#include "AppManagerImpl.hpp"
#include <iostream>

AppManagerImpl AppManagerImpl::instance;

AppManagerImpl& AppManagerImpl::getInstance()
{
	return instance;
}

void AppManagerImpl::useNPVCalculator()
{
	try
	{
		statementDisplayer = StatementDisplayerFactoryImpl::getStatementDisplayer(userInteractionHandler.getLanguage());
	}
	catch (const std::exception& error)
	{
		std::cout << error.what() << std::endl;
		statementDisplayer = std::make_shared<EnglishStatementDisplayerImpl>(); //should never happen but in worst case scenario eng will be choosen and program will not crush
	}
	userInteractionHandler.setStatementDisplayer(statementDisplayer);
	npvCalculator.setStatementDisplayer(statementDisplayer);
	npvCalculator.setDiscountRate(userInteractionHandler.getDiscountRate());
	npvCalculator.setYearsOfInvestment(userInteractionHandler.getYearsOfInvestment());
	npvCalculator.setCashFlows(userInteractionHandler.getCashFlows(npvCalculator.getYearsOfInvestment()));
	npvCalculator.isInvestmentProfitable();
}
