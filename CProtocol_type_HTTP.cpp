#include"CProtocol_type_HTTP.h"

CProtocol_type_HTTP::CProtocol_type_HTTP() {
	mProtocol_name = "";
}

CProtocol_type_HTTP::CProtocol_type_HTTP(string nume) {
	mProtocol_name = nume;
}

CProtocol_type_HTTP::CProtocol_type_HTTP(CProtocol &protocol) {
	mProtocol_name = protocol.get_name();
}