#pragma once
#include "StatementDisplayerFactory.hpp"
#include "EnglishStatementDisplayerImpl.hpp"
#include "PolishStatementDisplayerImpl.hpp"
#include "Types.hpp"

//implemented to hide implementation details from client code - supports O from SOLID

class StatementDisplayerFactoryImpl : public StatementDisplayerFactory 
{
public:
	static std::shared_ptr<StatementDisplayer> getStatementDisplayer(Language); 
};