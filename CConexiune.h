#pragma once
#include"CClient.h"
#include"CWebsite.h"
#include"CProtocol_type_HTTP.h"
#include"CProtocol_type_HTTPS.h"


class CConexiune {
protected:
	CClient mClient;
	CWebsite mWebsite;
	CProtocol mProtocol;
	string mStatus;
public:
	CConexiune();
	CConexiune(CProtocol, CWebsite, CClient);
	CConexiune(CConexiune &);
	CConexiune operator=(CConexiune &);

	CProtocol get_protocol();
	void set_protocol(CProtocol);
	CWebsite get_website();
	void set_website(CWebsite);
	CClient get_client();
	void set_client(CClient);
	string get_status();
	void set_status(string);

	void Init();
	void Destroy();
};