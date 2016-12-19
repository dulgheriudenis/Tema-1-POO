#include"CWebsite.h"

CWebsite::CWebsite() {
	mWeb_name = "";
	mPassword = "";
}

CWebsite::CWebsite(string nume, string cale) {
	mWeb_name = nume;
	mPath = cale;

}

CWebsite::CWebsite(CWebsite &website){
	mWeb_name = website.get_web_name();

	CFolder f(website.get_folder());
	mFolder = f;

	mPassword = website.get_password();
	mPath = website.get_path();
}

CWebsite CWebsite::operator=(CWebsite &website) {
	mWeb_name = website.get_web_name();

	CFolder f(website.get_folder());
	mFolder = f;

	mPassword = website.get_password();
	mPath = website.get_path();

	return *this;
}

void CWebsite::set_name(string nume) {
	this->mWeb_name = nume;
}

string CWebsite::get_web_name() {
	return this->mWeb_name;
}

string CWebsite::get_password() {
	return this->mPassword;
}

string CWebsite::get_path() {
	return this->mPath;
}

void CWebsite::set_cale(string cale) {
	this->mPath = cale;
}

void CWebsite::load() {
	mFolder.initializare_folder(mPath);
	mFolder.reimprospatare();
}

void CWebsite::list() {
	mFolder.listare();
}

void CWebsite::add(string tip, string nume) {
	mFolder.adaugare_fisier_in_folder(tip, nume);		
}

void CWebsite::set_password(string parola) {
	mPassword = mSecure.codare(parola);
}

CFolder CWebsite::get_folder() { 
	return this->mFolder;
}