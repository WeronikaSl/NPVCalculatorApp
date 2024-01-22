#pragma once
#include "Types.hpp"

class UserInteractionHandler
{
public:
	virtual ~UserInteractionHandler() = default;
	virtual DiscountRate getDiscountRate() const = 0;
	virtual YearsOfInvestment getYearsOfInvestment() const = 0;
	virtual CashFlows getCashFlows(YearsOfInvestment) const = 0;
	virtual Language getLanguage() const = 0;
};