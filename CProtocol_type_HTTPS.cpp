#include"CProtocol_type_HTTPS.h"

CProtocol_type_HTTPS::CProtocol_type_HTTPS() {
	mProtocol_name = "";
}

CProtocol_type_HTTPS::CProtocol_type_HTTPS(string nume) {
	mProtocol_name = nume;
}

CProtocol_type_HTTPS::CProtocol_type_HTTPS(CProtocol &protocol) {
	mProtocol_name = protocol.get_name();
}
