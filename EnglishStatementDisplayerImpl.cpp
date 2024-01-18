#include "EnglishStatementDisplayerImpl.hpp"

void EnglishStatementDisplayerImpl::discountRate() const
{
	std::cout << "Enter the discount rate (a number between 0.00 and 1, e.g. 0.15 means 15%): ";
}

void EnglishStatementDisplayerImpl::yearsOfInvestment() const
{
	std::cout << "Enter the number of years for which the investment is planned (without taking into account year 0, when the money was invested): ";
}

void EnglishStatementDisplayerImpl::investedAmountOfMoney() const
{
	std::cout << "Enter the invested amount of money (as a positive integer): ";
}

void EnglishStatementDisplayerImpl::allCashFlows() const
{
	std::cout << "Enter cash flows per year (as whole numbers, positive or negative): " << std::endl;
}

void EnglishStatementDisplayerImpl::singleCashFlow(uint16_t year) const
{
	std::cout << "Enter the cash flow for the year " << year << ": ";
}

void EnglishStatementDisplayerImpl::compareNPVAndInitialCost(double npv, int64_t initialCost) const
{
	std::cout << "NPV: " << npv << std::endl << "Initial cost: " << initialCost << std::endl;
}

void EnglishStatementDisplayerImpl::isProfitable() const
{
	std::cout << "The investment is profitable" << std::endl;
}

void EnglishStatementDisplayerImpl::isNotProfitable() const
{
	std::cout << "The investment is not profitable" << std::endl;
}

