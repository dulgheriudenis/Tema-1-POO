#pragma once
#include"CFolder.h"
#include"CSecure_string.h"
#include<fstream>

class CWebsite {
protected:
	string mWeb_name;
	string mPassword;
	string mPath;
	CSecure mSecure;
	CFolder mFolder;
	
public:
	CWebsite();
	CWebsite(string, string);
	CWebsite(CWebsite &);
	CWebsite operator=(CWebsite &);

	string get_web_name();
	void set_name(string);
	string get_password();
	string get_path();
	void set_cale(string);
	CFolder get_folder();
	
	void load();
	void list();
	void set_password(string);
	void add(string, string);
};
