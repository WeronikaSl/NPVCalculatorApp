#include "StatementDisplayer.hpp"

//those methods have to be updated in case of adding new language

void StatementDisplayer::selectLanguage()
{
	std::cout << "Wybierz jezyk/select language - polski nacisnij 1/for English press 2: ";
}

void StatementDisplayer::incorrectLanguageChoice()
{
	std::cout << "BLAD/ERROR - PODAJ NUMER 1 LUB 2/ENTER NUMBER 1 OR 2: ";
}

std::string StatementDisplayer::incorrectLanguageException()
{
	return "BLAD! PODALES/AS ZLA WARTOSC, PROGRAM WYSWIETLI SIE PO ANGIELSKU/ ERROR! YOUVE ENTERED A WRONG VALUE, PROGRAM WILL BE DISPLAYED IN ENGLISH";
}
