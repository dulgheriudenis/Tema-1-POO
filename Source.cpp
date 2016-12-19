#include"CServer.h"

void main(){

	CClient client("Dulgheriu", "Denis","Denis");
	CClient client2("Chirila", "Stefan","Stefan");
	CClient client3("Nascu", "Marius","Marius");

	CServer s;
	s.add_website("www.mta.ro", "C:\\Users\\Denis\\Documents\\Visual Studio 2015\\Projects\\POO - Tema 1\\POO - Tema 1\\Web1\\index.txt", "Denis");
	s.create_connection("HTTP", "www.mta.ro", client);
	s.add_website("www.protv.ro", "C:\\Users\\Denis\\Documents\\Visual Studio 2015\\Projects\\POO - Tema 1\\POO - Tema 1\\Web1\\index2.txt", "Stefan");
	s.create_connection("HTTPS", "www.protv.ro", client2);
	s.add_website("www.youtube.ro", "C:\\Users\\Denis\\Documents\\Visual Studio 2015\\Projects\\POO - Tema 1\\POO - Tema 1\\Web1\\index3.txt", "Marius");
	s.create_connection("HTTPS", "www.youtube.ro", client3);

	
	cout<< s.get_conex()[1].get_client().get_Password()<< endl;
	cout << s.get_conex()[2].get_client().get_Password() << endl;
	cout << s.get_conex()[3].get_client().get_Password() << endl;
	
	s.get_conex()[1].Init();
	s.get_conex()[2].Init();
	s.get_conex()[3].Init();

	cout << endl;

	cout << "Conexiunea dintre website-ul : \"" << s.get_conex()[1].get_website().get_web_name() << "\" si clientul " << s.get_conex()[1].get_client().get_Fname() << " " << s.get_conex()[1].get_client().get_Sname() << " este : " << s.get_conex()[1].get_status() << endl;
	cout << "Conexiunea dintre website-ul : \"" << s.get_conex()[2].get_website().get_web_name() << "\" si clientul " << s.get_conex()[2].get_client().get_Fname() << " " << s.get_conex()[2].get_client().get_Sname() << " este : " << s.get_conex()[2].get_status() << endl;
	cout << "Conexiunea dintre website-ul : \"" << s.get_conex()[3].get_website().get_web_name() << "\" si clientul " << s.get_conex()[3].get_client().get_Fname() << " " << s.get_conex()[3].get_client().get_Sname() << " este : " << s.get_conex()[3].get_status() << endl;

}