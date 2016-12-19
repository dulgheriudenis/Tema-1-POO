#include"CFolder.h"

CFolder::CFolder() {
	mPagini = NULL;
	mResurse = NULL;
	mIndex = "";
	mNbr_pagini = 0;
	mNbr_resurse = 0;
}

CFolder CFolder::operator=(CFolder &folder) {
	mNbr_pagini = folder.get_nr_pagini();
	mNbr_resurse = folder.get_nr_resurse();

	mPagini = new CPagina[mNbr_pagini + 1];
	mResurse = new CResursa[mNbr_resurse + 1];

	string *nume_pagini;

	CPagina *auxiliar;
	auxiliar = folder.get_pagini();

	nume_pagini = new string[mNbr_pagini + 1];

	for (int i = 1; i <= mNbr_pagini; i += 1)
		nume_pagini[i] = auxiliar[i].get_nume();

	for (int i = 1; i <= mNbr_pagini; i += 1)
		mPagini[i].adauga(nume_pagini[i]);

	delete[]nume_pagini;

	string *nume_resurse;

	CResursa *temporar;
	temporar = folder.get_resurse();

	nume_resurse = new string[mNbr_resurse + 1];

	for (int i = 1; i <= mNbr_resurse; i += 1)
		nume_resurse[i] = temporar[i].get_nume();

	for (int i = 1; i <= mNbr_resurse; i += 1)
		mResurse[i].adauga(nume_resurse[i]);

	delete[]nume_resurse;

	return *this;

}

CFolder::CFolder(CFolder &folder) {

	mNbr_pagini = folder.get_nr_pagini();
	mNbr_resurse = folder.get_nr_resurse();

	mPagini = new CPagina[mNbr_pagini + 1];
	mResurse = new CResursa[mNbr_resurse + 1];

	string *nume_pagini;

	CPagina *auxiliar;
	auxiliar = folder.get_pagini();

	nume_pagini = new string[mNbr_pagini + 1];

	for (int i = 1; i <= mNbr_pagini; i += 1)
		nume_pagini[i] = auxiliar[i].get_nume();

	for (int i = 1; i <= mNbr_pagini; i += 1)
		mPagini[i].adauga(nume_pagini[i]);

	delete[]nume_pagini;
	nume_pagini = NULL;

	string *nume_resurse;

	CResursa *temporar;
	temporar = folder.get_resurse();

	nume_resurse = new string[mNbr_resurse + 1];

	for (int i = 1; i <= mNbr_resurse; i += 1)
		nume_resurse[i] = temporar[i].get_nume();

	for (int i = 1; i <= mNbr_resurse; i += 1)
		mResurse[i].adauga(nume_resurse[i]);

	delete[]nume_resurse;
	nume_resurse = NULL;
}

void CFolder::initializare_folder(string index_html) {
	
	ifstream index;
	mIndex = index_html;
	index.open(index_html);

	int contor_de_pagini = 0;
	int contor_de_resurse = 0;
	string tip, nume;

	while (!index.eof()) {
		index >> tip >> nume;
		if (tip == "P")
			mNbr_pagini += 1;
		else mNbr_resurse += 1;
	}

		mPagini = new CPagina[mNbr_pagini + 1];
		mResurse = new CResursa[mNbr_resurse + 1];
		index.seekg(0);

		while (!index.eof()) {
			index >> tip >> nume;
			if (tip == "P") {
				contor_de_pagini += 1;
				mPagini[contor_de_pagini].adauga(nume);
			}
			else {
				contor_de_resurse += 1;
				mResurse[contor_de_resurse].adauga(nume);
			}
		}
}

void CFolder::adaugare_fisier_in_folder(string tip, string nume) {
	
	if (tip == "P") {
		mNbr_pagini += 1;
		string *backup;
		backup = new string[mNbr_pagini + 1];

		for (int i = 1; i <= mNbr_pagini - 1; i += 1)
			backup[i] = mPagini[i].get_nume();

		delete[]mPagini;
		mPagini = new CPagina[mNbr_pagini + 1];

		for (int i = 1; i < mNbr_pagini ; i += 1)
			mPagini[i].adauga(backup[i]);
		mPagini[mNbr_pagini].adauga(nume);
	}
	else {
		mNbr_resurse += 1;
		string *backup;
		backup = new string[mNbr_resurse];

		for (int i = 1; i <= mNbr_resurse - 1; i += 1)
			backup[i] = mResurse[i].get_nume();

		delete[]mResurse;
		mResurse = new CResursa[mNbr_resurse + 1];

		for (int i = 1; i < mNbr_resurse - 1; i += 1)
			mResurse[i].adauga(backup[i]);

		mResurse[mNbr_resurse].adauga(nume);
	}
	reimprospatare();
}

void CFolder::reimprospatare() {
	ofstream index;
	index.open(mIndex);
	for (int i = 1; i <= mNbr_pagini; i += 1)
		index << mPagini[i].get_tip() << " " << mPagini[i].get_nume() << endl;
	index.close();
	
	index.open(mIndex, ios::app);
	for (int i = 1; i <= mNbr_resurse - 1; i += 1)
		index << mResurse[i].get_tip() << " " << mResurse[i].get_nume() << endl;
	index << mResurse[mNbr_resurse].get_tip() << " " << mResurse[mNbr_resurse].get_nume();
}

void CFolder::listare() {
	for (int i = 1; i <= mNbr_pagini; i += 1)
		cout << mPagini[i].get_tip() << " " << mPagini[i].get_nume() << endl;
	for (int i = 1; i <= mNbr_resurse; i += 1)
		cout << mResurse[i].get_tip() << " " << mResurse[i].get_nume() << endl;
}

CPagina *CFolder::get_pagini() {
	return this->mPagini;
}
int CFolder::get_nr_pagini() {
	return this->mNbr_pagini;
}
CResursa *CFolder::get_resurse() {
	return this->mResurse;
}
int	CFolder::get_nr_resurse() {
	return this->mNbr_resurse;
}

string CFolder::get_index() {
	return this->mIndex;
}