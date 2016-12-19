#pragma once
#include"CConexiune.h"

class CServer {
protected:
	CWebsite *mWebsite;
	int mNbr_of_websites;

	CConexiune *mConnection;
	int mNbr_of_connections;

	int mNbr_max_of_connection;

public:
	CServer();
	void create_connection(string,string,CClient);
	int numbers_of_active_connections_till_now();
	void add_website(string,string,string);
	void delete_website(string);
	void request();
	void download();
	void print_stats();
	
	CWebsite cauta(string);
	int cauta_pozitie(string);
	CWebsite *get_web();
	CConexiune *get_conex();
};