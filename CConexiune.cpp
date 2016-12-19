#include"CConexiune.h"

CConexiune::CConexiune() {
	
	CWebsite aux_mWebsite;
	CProtocol aux_Protocol;

	mWebsite = aux_mWebsite;
	mProtocol = aux_Protocol;
	mStatus = "";
}
CConexiune::CConexiune(CProtocol protocol, CWebsite website, CClient client) {
	
	CClient aux_Client(client);
	CWebsite aux_mWebsite(website);

	mWebsite = aux_mWebsite;
	mClient = aux_Client;


	if (protocol.get_name() == "HTTP")
	{
		CProtocol_type_HTTP aux_HTTP(protocol);
			mProtocol = aux_HTTP;
	}
	else if (protocol.get_name() == "HTTPS" )
	{
		CProtocol_type_HTTPS aux_HTTPS(protocol);
		mProtocol = aux_HTTPS;
	}
	mStatus = "inactiva";

}

CConexiune::CConexiune(CConexiune &conexiune) {

	CWebsite auxiliar_website(conexiune.get_website());
	mWebsite = auxiliar_website;
		
	CClient aux_client(conexiune.get_client());
	mClient = aux_client;


	if (conexiune.get_protocol().get_name() == "HTTP")
	{
		CProtocol_type_HTTP aux_HTTP(conexiune.get_protocol());
		mProtocol = aux_HTTP;
	}
	else if (conexiune.get_protocol().get_name() == "HTTPS" )
	{
		CProtocol_type_HTTPS aux_HTTPS(conexiune.get_protocol());
		mProtocol = aux_HTTPS;
	}
	mStatus = "inactiva";

}

CConexiune CConexiune::operator=(CConexiune &conexiune) {
	CWebsite auxiliar_website(conexiune.get_website());
	mWebsite = auxiliar_website;

	CClient aux_client(conexiune.get_client());
	mClient = aux_client;


	if (conexiune.get_protocol().get_name() == "HTTP")
	{
		CProtocol_type_HTTP aux_HTTP(conexiune.get_protocol());
		mProtocol = aux_HTTP;
	}
	else if (conexiune.get_protocol().get_name() == "HTTPS" )
	{
		CProtocol_type_HTTPS aux_HTTPS(conexiune.get_protocol());
		mProtocol = aux_HTTPS;
	}
	mStatus = "inactiva";
	return *this;
}

CProtocol CConexiune::get_protocol() {
	return mProtocol;
}
CWebsite CConexiune::get_website() {
	return mWebsite;
}
CClient	CConexiune::get_client() {
	return mClient;
}

string CConexiune::get_status() {
	return mStatus;
}

void CConexiune::set_protocol(CProtocol protocol) {
	mProtocol = protocol;
}

void CConexiune::set_website(CWebsite website) {
	mWebsite = website;
}

void CConexiune::set_client(CClient client) {
	mClient = client;
}

void CConexiune::set_status(string status) {
	mStatus = status;
}

void CConexiune::Init() {
	if (mProtocol.get_name() == "HTTPS") {
		if (mClient.get_Password() == mWebsite.get_password())
			mStatus = "activa";
		else mStatus = "inactiva";
	}
	else mStatus = "activa";
}

void CConexiune::Destroy() {

}