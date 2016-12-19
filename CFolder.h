#pragma once
#include"CPagina.h"
#include"CResursa.h"
#include<fstream>

class CFolder {
public:	
	CPagina *mPagini;
	int mNbr_pagini;

	CResursa *mResurse;
	int mNbr_resurse;

	string mIndex;

public:
	CFolder();
	CFolder(CFolder &);
	CFolder operator=(CFolder &);
	void initializare_folder(string);
	void adaugare_fisier_in_folder(string, string);
	void reimprospatare();
	void listare();

	string get_index();
	CPagina *get_pagini();
	int get_nr_pagini();
	CResursa *get_resurse();
	int get_nr_resurse();
};