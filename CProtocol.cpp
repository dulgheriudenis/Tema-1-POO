#include"CProtocol.h"

CProtocol::CProtocol() {
	mProtocol_name = "";
}

CProtocol::CProtocol(string nume) {
	mProtocol_name = nume;
}

string CProtocol::get_name() {
	return this->mProtocol_name;
}
