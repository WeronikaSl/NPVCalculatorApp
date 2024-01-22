#include "StatementDisplayerFactoryImpl.hpp"
#include <exception>

std::shared_ptr<StatementDisplayer> StatementDisplayerFactoryImpl::getStatementDisplayer(Language language)
{
	std::shared_ptr<StatementDisplayer> result{ nullptr };
	switch (language)
	{
	case Language::POLISH:
		result = std::make_shared<PolishStatementDisplayerImpl>();
		break;
	case Language::ENGLISH:
		result = std::make_shared<EnglishStatementDisplayerImpl>();
		break;
	default: 
		throw std::invalid_argument(StatementDisplayer::incorrectLanguageException()); //will probably never happen but just in case to prevent returning a nullptr and undefined behaviour
		break;
	}
	return result;
}
