#pragma once
#include "UserInteractionHandler.hpp"
#include "PolishStatementDisplayerImpl.hpp"
#include "EnglishStatementDisplayerImpl.hpp"
#include <memory>

class UserInteractionHandlerImpl : public UserInteractionHandler
{
private:
	std::shared_ptr<StatementDisplayer> statementDisplayer{ nullptr };
	void discardImput() const;
public:
	DiscountRate getDiscountRate() const;
	YearsOfInvestment getYearsOfInvestment() const;
	CashFlows getCashFlows(YearsOfInvestment) const;
	void setStatementDisplayer(std::shared_ptr<StatementDisplayer>);
	Language getLanguage() const;
};