#include"CClient.h"

CClient::CClient() {
	mFirst_name = " ";
	mSecond_name = " ";
	mPassword = " ";
}
CClient::CClient(string nume, string prenume,string parola) {
	mFirst_name = nume;
	mSecond_name = prenume;
	set_password(parola);
}
CClient::CClient(CClient &client) {
	mFirst_name = client.get_Fname();
	mSecond_name = client.get_Sname();
	mPassword = client.get_Password();
}

CClient CClient::operator=(CClient &client) {
	mFirst_name = client.get_Fname();
	mSecond_name = client.get_Sname();
	mPassword = client.get_Password();

	return *this;
}

string CClient::get_Fname() {
	return this->mFirst_name;
}

string CClient::get_Sname() {
	return this->mSecond_name;
}

string CClient::get_Password() {
	return this->mPassword;
}

void CClient::set_password(string parola) {
	mPassword = mSecure.codare(parola);
}

void CClient::set_F_name(string nume) {
	mFirst_name = nume;
}

void CClient::set_S_name(string nume) {
	mFirst_name = nume;
}