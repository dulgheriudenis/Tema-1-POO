#include"CResursa.h"

CResursa::CResursa() {
	mTip = 'R';
	mName = "";
}

CResursa::CResursa(string nume) {
	mTip = 'R';
	mName = nume;
}

CResursa::CResursa(CResursa &resursa) {
	mTip = resursa.get_tip();
	mName = resursa.get_nume();
}

void CResursa::adauga(string nume) {
	mName = nume;
}

string CResursa::get_nume() {
	return this->mName;
}

string CResursa::get_tip() {
	return this->mTip;
}