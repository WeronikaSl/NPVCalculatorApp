#pragma once
#include "UserInteractionHandler.hpp"
#include "ErrorHandlerImpl.hpp"
#include "Types.hpp"
#include "PolishStatementDisplayerImpl.hpp"
#include <memory>

class UserInteractionHandlerImpl : public UserInteractionHandler
{
private:
	ErrorHandlerImpl errorHandler;
	std::shared_ptr<StatementDisplayer> statementDisplayer{ nullptr };
public:
	UserInteractionHandlerImpl();
	DiscountRate getDiscountRate() const;
	YearsOfInvestment getYearsOfInvestment() const;
	CashFlows getCashFlows(YearsOfInvestment) const;
};