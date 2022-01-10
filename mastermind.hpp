/*
Erstellt von 
Hasan Baran 
Timon Meyer 
Patrick Frerk 
*/

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

#ifndef MASTERMIND_HEADER_HPP
#define MASTERMIND_HEADER_HPP

enum buchstaben { A, B, C };

class Pieces {
public:
	Pieces();
	void getBuchstabe();
	void setBuchstabe();
	void setBuchstabe(buchstaben given_buchstabe);
	char getBuchstabeletter(Pieces piece);
private:
	string string_buchstabe;
};

class Begin {
public:
	Begin();
	void spiel_nachricht();
	void zeige_anleitung();
	void zeige_info();
};

class Abfrage {
public:
	Abfrage();
	string erste, zweite, dritte;
	void benutzer_input(string erste, string zweite, string dritte, Pieces& erstep, Pieces& zweitep, Pieces& drittep);
};

bool play_again();

#endif 
