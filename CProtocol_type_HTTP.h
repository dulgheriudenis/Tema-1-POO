#pragma once
#include"CProtocol.h"

class CProtocol_type_HTTP : public CProtocol {
public:
	CProtocol_type_HTTP();
	CProtocol_type_HTTP(string);
	CProtocol_type_HTTP(CProtocol &);
};