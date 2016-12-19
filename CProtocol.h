#pragma once
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string>

using namespace std;

class CProtocol {
protected:
	string mProtocol_name;
public:
	CProtocol();
	CProtocol(string);
	string get_name();
};