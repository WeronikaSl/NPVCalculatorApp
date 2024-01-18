#include "AppManagerImpl.hpp"
#include <iostream>


void AppManagerImpl::useNPVCalculator()
{
	uint16_t userInput{ 0 }; //todo put it in UserInteractionHandler
	std::cout << "Wybierz jezyk/select language - polski nacisnij 1/for English press 2: ";
	std::cin >> userInput;
	if (userInput == 1) //todo create Factory Method
	{
		statementDisplayer = std::make_shared<PolishStatementDisplayerImpl>();
	}
	else if (userInput == 2)
	{
		statementDisplayer = std::make_shared<EnglishStatementDisplayerImpl>();

	}
	userInteractionHandler.setStatementDisplayer(statementDisplayer);
	npvCalculator.setStatementDisplayer(statementDisplayer);
	npvCalculator.setDiscountRate(userInteractionHandler.getDiscountRate());
	npvCalculator.setYearsOfInvestment(userInteractionHandler.getYearsOfInvestment());
	npvCalculator.setCashFlows(userInteractionHandler.getCashFlows(npvCalculator.getYearsOfInvestment()));
	npvCalculator.isInvestmentProfitable();
}
