#pragma once
#include"CFisier.h"

class CResursa : public CFisier {
public:
	CResursa();
	CResursa(string);
	CResursa(CResursa &);
	void adauga(string);
	string get_nume();
	string get_tip();
};