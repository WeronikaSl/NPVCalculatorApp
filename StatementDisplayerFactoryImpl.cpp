#include "StatementDisplayerFactoryImpl.hpp"

std::shared_ptr<StatementDisplayer> StatementDisplayerFactoryImpl::getStatementDisplayer(Language language) //pick a better name for this variable
{
	std::shared_ptr<StatementDisplayer> result{ nullptr };
	if (language == Language::POLISH)
	{
		result = std::make_shared<PolishStatementDisplayerImpl>();
	}
	else if (language == Language::ENGLISH)
	{
		result = std::make_shared<EnglishStatementDisplayerImpl>();

	}
	return result; //make sure you dont return nullptr!!!
}
