#pragma once
#include "StatementDisplayerFactory.hpp"
#include "EnglishStatementDisplayerImpl.hpp"
#include "PolishStatementDisplayerImpl.hpp"

class StatementDisplayerFactoryImpl : public StatementDisplayerFactory
{
public:
	static std::shared_ptr<StatementDisplayer> getStatementDisplayer(uint16_t);
};