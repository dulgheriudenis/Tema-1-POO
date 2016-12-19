#pragma once
#include"CFisier.h"

class CPagina : public CFisier {
public:
	CPagina();
	CPagina(string);
	CPagina(CPagina &);
	void adauga(string);
	string get_nume();
	string get_tip();
};