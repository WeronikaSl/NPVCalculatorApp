#include "StatementDisplayer.hpp"

void StatementDisplayer::selectLanguage()
{
	std::cout << "Wybierz jezyk/select language - polski nacisnij 1/for English press 2: ";
}

void StatementDisplayer::incorrectLanguageChoice()
{
	std::cout << "BLAD/ERROR - PODAJ NUMER 1 LUB 2/ENTER NUMBER 1 OR 2: ";
}
