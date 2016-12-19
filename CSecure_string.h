#pragma once
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string>

using namespace std;

class CSecure {
protected:
	string mPassword;

public:
	CSecure();
	string codare(string);
};