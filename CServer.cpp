#include"CServer.h"

CServer::CServer() {
	mWebsite = NULL;
	mConnection = NULL;
	mNbr_of_websites = 0;
	mNbr_of_connections = 0;
	mNbr_max_of_connection = 10;
}

void CServer::create_connection(string protocol,string website,CClient client) {
	CProtocol protocol_auxiliar(protocol);

	CWebsite website_auxiliar;
	website_auxiliar = cauta(website);
	if (website_auxiliar.get_web_name() != "")
	{		
		if (numbers_of_active_connections_till_now() < mNbr_max_of_connection)
		{
			CConexiune conexiune_auiliara(protocol_auxiliar, website_auxiliar, client);

			mNbr_of_connections += 1;
			if (mNbr_of_connections == 1)
			{
				mConnection = new CConexiune[2];
				mConnection[1] = conexiune_auiliara;
			}
			else {
				CClient *aux_Client; aux_Client = new CClient[mNbr_of_connections + 1];
				CWebsite *aux_Website; aux_Website = new CWebsite[mNbr_of_connections + 1];
				CProtocol *aux_Protocol; aux_Protocol = new CProtocol[mNbr_of_connections + 1];
				string *aux_status; aux_status = new string[mNbr_of_connections + 1];

				for (int i = 1; i <= mNbr_of_connections - 1; i += 1)
				{
					aux_Client[i] = mConnection[i].get_client();
					aux_Protocol[i] = mConnection[i].get_protocol();
					aux_Website[i] = mConnection[i].get_website();
					aux_status[i] = mConnection[i].get_status();
				}

				delete[]mConnection;

				mConnection = new CConexiune[mNbr_of_connections + 1];

				for (int i = 1; i <= mNbr_of_connections - 1; i += 1)
				{
					mConnection[i].set_status(aux_status[i]);
					mConnection[i].set_website(aux_Website[i]);
					mConnection[i].set_client(aux_Client[i]);
					mConnection[i].set_protocol(aux_Protocol[i]);
				}
				mConnection[mNbr_of_connections].set_status(conexiune_auiliara.get_status());
				mConnection[mNbr_of_connections].set_website(conexiune_auiliara.get_website());
				mConnection[mNbr_of_connections].set_client(conexiune_auiliara.get_client());
				mConnection[mNbr_of_connections].set_protocol(conexiune_auiliara.get_protocol());

				delete[]aux_Client;
				delete[]aux_Website;
				delete[]aux_Protocol;
				delete[]aux_status;
			}
			cout << "Conexiunea dintre website-ul : \"" << mConnection[mNbr_of_connections].get_website().get_web_name() << "\" si clientul " << mConnection[mNbr_of_connections].get_client().get_Fname() << " " << mConnection[mNbr_of_connections].get_client().get_Sname() << " este : " << mConnection[mNbr_of_connections].get_status() << endl;
		}	
		else cout << "S-a atins deja numarul maxim de conexiuni active si eroare se introduce in jurnal.";

	}

	else cout << "Nu acest website nu este in baza de date si eroarea se introduce in jurnal.";
	
}

CWebsite CServer::cauta(string nume) {
	for (int i = 1; i <= mNbr_of_websites; i += 1)
		if (mWebsite[i].get_web_name() == nume)
			return mWebsite[i];
	CWebsite retur;
	return retur;
}

int CServer::cauta_pozitie(string nume) {
	for (int i = 1; i <= mNbr_of_websites; i += 1)
		if (mWebsite[i].get_web_name() == nume)
			return i;
	return 0;
}

int CServer::numbers_of_active_connections_till_now() {
	
	int numbers_of_active_connections = 0;
	if (mNbr_of_connections > 1)
	{
		for (int i = 1; i <= mNbr_of_connections; i += 1)
		{
			if (mConnection[i].get_status() == "activat")
				numbers_of_active_connections += 1;
		}
	}

	return numbers_of_active_connections;
}

void CServer::add_website(string nume,string cale,string parola) {
	
	mNbr_of_websites += 1;
	if (mNbr_of_websites == 1)
	{
		CWebsite aux(nume, cale);
		aux.load();
		mWebsite = new CWebsite[2];
		mWebsite[1] = aux;
	}
	else {
			string *nume_auxiliar; nume_auxiliar = new string[mNbr_of_websites + 1];
			string *parola_auxiliara; parola_auxiliara = new string[mNbr_of_websites + 1];
			string *cale_auxiliara; cale_auxiliara = new string[mNbr_of_websites + 1];
		
					for (int i = 1; i <= mNbr_of_websites - 1; i += 1)
				{
					nume_auxiliar[i] = mWebsite[i].get_web_name();
					parola_auxiliara[i] = mWebsite[i].get_password();
					cale_auxiliara[i] = mWebsite[i].get_path();
				}
				
				delete[]mWebsite;

				mWebsite = new CWebsite[mNbr_of_websites + 1];

				for (int i = 1; i <= mNbr_of_websites - 1; i += 1)
				{
					mWebsite[i].set_name(nume_auxiliar[i]);
					mWebsite[i].set_password(parola_auxiliara[i]);
					mWebsite[i].set_cale(cale_auxiliara[i]);
				}
				mWebsite[mNbr_of_websites].set_name(nume);
				mWebsite[mNbr_of_websites].set_password(parola);
				mWebsite[mNbr_of_websites].set_cale(cale);

				delete[]parola_auxiliara;
				delete[]nume_auxiliar;
				delete[]cale_auxiliara;
	}
	
}

void CServer::delete_website(string nume) {
	int x = 0;
	if (cauta(nume).get_web_name() != "") {
		if (mNbr_of_websites == 1)
			delete[]mWebsite;
		else {


			for (int i = 1; i <= mNbr_of_websites; i++)
			{
				if (mWebsite[i].get_web_name() == nume)
					x = i;
			}
			
			string *nume_auxiliar; nume_auxiliar = new string[mNbr_of_websites + 1];
			string *parola_auxiliara; parola_auxiliara = new string[mNbr_of_websites + 1];
			string *cale_auxiliara; cale_auxiliara = new string[mNbr_of_websites + 1];

			for (int i = 1; i < x ; i += 1)
			{
				nume_auxiliar[i] = mWebsite[i].get_web_name();
				parola_auxiliara[i] = mWebsite[i].get_password();
				cale_auxiliara[i] = mWebsite[i].get_path();
			}
			
			for (int i = x + 1; i <= mNbr_of_websites ; i += 1)
			{
				nume_auxiliar[i - 1] = mWebsite[i].get_web_name();
				parola_auxiliara[i - 1] = mWebsite[i].get_password();
				cale_auxiliara[i - 1] = mWebsite[i].get_path();
			}

			delete[]mWebsite;

			mWebsite = new CWebsite[mNbr_of_websites];

			for (int i = 1; i <= mNbr_of_websites - 1; i += 1)
			{
				mWebsite[i].set_name(nume_auxiliar[i]);
				mWebsite[i].set_password(parola_auxiliara[i]);
				mWebsite[i].set_cale(cale_auxiliara[i]);
			}

		}

		for (int i = 1; i <= mNbr_of_websites -1; i += 1)
		{
			cout << mWebsite[i].get_web_name() << endl;
		}
		mNbr_of_websites -= 1;
	}
	else cout << "Adauga in jurnalul de erori";
}



void CServer::request() {

}

void CServer::download() {

}

void CServer::print_stats() {

}

CWebsite *CServer::get_web() {
	return mWebsite;
}

CConexiune *CServer::get_conex() {
	return mConnection;
}
