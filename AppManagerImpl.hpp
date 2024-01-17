#pragma once
#include "AppManager.hpp"
#include "NPVCalculatorImpl.hpp"
#include "UserInteractionHandlerImpl.hpp"

class AppManagerImpl : public AppManager
{
private:
	NPVCalculatorImpl npvCalculator;
	UserInteractionHandlerImpl userInteractionHandler;
public:
	void useNPVCalculator();
};