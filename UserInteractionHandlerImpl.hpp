#pragma once
#include "UserInteractionHandler.hpp"
#include "Types.hpp"

class UserInteractionHandlerImpl : public UserInteractionHandler
{
public:
	DiscountRate getDiscountRate() const;
	YearsOfInvestment getYearsOfInvestment() const;
	CashFlows getCashFlows(YearsOfInvestment) const;
};