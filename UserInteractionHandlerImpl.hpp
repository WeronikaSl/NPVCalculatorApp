#pragma once
#include "UserInteractionHandler.hpp"
#include "ErrorHandlerImpl.hpp"
#include "Types.hpp"

class UserInteractionHandlerImpl : public UserInteractionHandler
{
private:
	ErrorHandlerImpl errorHandler;
public:
	DiscountRate getDiscountRate() const;
	YearsOfInvestment getYearsOfInvestment() const;
	CashFlows getCashFlows(YearsOfInvestment) const;
};