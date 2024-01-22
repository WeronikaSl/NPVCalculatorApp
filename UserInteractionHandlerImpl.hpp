#pragma once
#include "UserInteractionHandler.hpp"
#include "ErrorHandlerImpl.hpp"
#include "Types.hpp"
#include "PolishStatementDisplayerImpl.hpp"
#include "EnglishStatementDisplayerImpl.hpp"
#include <memory>

class UserInteractionHandlerImpl : public UserInteractionHandler
{
private:
	ErrorHandlerImpl errorHandler;
	std::shared_ptr<StatementDisplayer> statementDisplayer{ nullptr };
public:
	DiscountRate getDiscountRate() const;
	YearsOfInvestment getYearsOfInvestment() const;
	CashFlows getCashFlows(YearsOfInvestment) const;
	void setStatementDisplayer(std::shared_ptr<StatementDisplayer>);
	Language getLanguage() const;
	void discardImput() const;
};