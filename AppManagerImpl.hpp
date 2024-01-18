#pragma once
#include "AppManager.hpp"
#include "NPVCalculatorImpl.hpp"
#include "UserInteractionHandlerImpl.hpp"
#include "PolishStatementDisplayerImpl.hpp"
#include "EnglishStatementDisplayerImpl.hpp"
#include <memory>

class AppManagerImpl : public AppManager
{
private:
	NPVCalculatorImpl npvCalculator;
	UserInteractionHandlerImpl userInteractionHandler;
	std::shared_ptr<StatementDisplayer> statementDisplayer{ nullptr };
public:
	void useNPVCalculator();
};