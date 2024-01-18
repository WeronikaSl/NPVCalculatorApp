#pragma once
#include "AppManager.hpp"
#include "NPVCalculatorImpl.hpp"
#include "UserInteractionHandlerImpl.hpp"
#include "PolishStatementDisplayerImpl.hpp"
#include "EnglishStatementDisplayerImpl.hpp"
#include "StatementDisplayerFactoryImpl.hpp"
#include <memory>

class AppManagerImpl : public AppManager
{
private:
	AppManagerImpl() = default;
	static AppManagerImpl instance;
	AppManagerImpl(const AppManagerImpl&) = delete;
	NPVCalculatorImpl npvCalculator;
	UserInteractionHandlerImpl userInteractionHandler;
	std::shared_ptr<StatementDisplayer> statementDisplayer{ nullptr };

public:
	static AppManagerImpl& getInstance();
	void useNPVCalculator();
};