#pragma once
#include"CProtocol.h"

class CProtocol_type_HTTPS : public CProtocol {
public:
	CProtocol_type_HTTPS();
	CProtocol_type_HTTPS(string);
	CProtocol_type_HTTPS(CProtocol &);
};