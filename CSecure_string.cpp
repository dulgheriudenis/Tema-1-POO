#include"CSecure_string.h"

CSecure::CSecure() {
	mPassword = "";
}

string CSecure::codare(string parola) {
	int numar_de_codare;

	for (int i = 0; i < parola.length(); i += 1)
		numar_de_codare = parola[i];

	for (int i = 0; i < parola.length(); i += 1)
		parola[i] = parola[i] + (numar_de_codare - i + 85) - parola[parola.length() - 1];
	return parola;
}