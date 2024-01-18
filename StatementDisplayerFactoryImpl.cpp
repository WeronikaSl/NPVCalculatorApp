#include "StatementDisplayerFactoryImpl.hpp"

std::shared_ptr<StatementDisplayer> StatementDisplayerFactoryImpl::getStatementDisplayer(uint16_t language) //pick a better name for this variable
{
	std::shared_ptr<StatementDisplayer> result{ nullptr };
	if (language == 1)
	{
		result = std::make_shared<PolishStatementDisplayerImpl>();
	}
	else if (language == 2)
	{
		result = std::make_shared<EnglishStatementDisplayerImpl>();

	}
	return result; //make sure you dont return nullptr!!!
}
