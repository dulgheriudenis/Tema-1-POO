#pragma once
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string>
#include"CSecure_string.h"

using namespace std;

class CClient {
protected:
	string mFirst_name;
	string mSecond_name;
	string mPassword;
	CSecure mSecure;
public:
	CClient();
	CClient(string, string,string);
	CClient(CClient &);
	CClient operator=(CClient &);

	string get_Fname();
	void set_F_name(string);
	string get_Sname();
	void set_S_name(string);
	string get_Password();
	void set_password(string);
};