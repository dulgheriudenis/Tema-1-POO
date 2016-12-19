#include"CPagina.h"

CPagina::CPagina() {
	mTip = 'P';
	mName = " ";
}

CPagina::CPagina(string nume) {
	mTip = 'P';
	mName = nume;
}

CPagina::CPagina(CPagina &pagina) {
	mTip = pagina.get_tip();
	mName = pagina.get_nume();
}

void CPagina::adauga(string nume) {
	mName = nume;
}

string CPagina::get_nume() {
	return this->mName;
}
string CPagina::get_tip() {
	return this->mTip;
}