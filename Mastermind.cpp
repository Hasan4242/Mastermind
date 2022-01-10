/*
Erstellt von
Hasan Baran 
Timon Meyer 
Patrick Frerk 
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>                                  
#include <ctime>
#include "mastermind.hpp"                 
#include <string>

Begin::Begin() {
	spiel_nachricht();
	srand(time(NULL));
}

Pieces::Pieces() {
	setBuchstabe();
}

Abfrage::Abfrage() {
	string erste, zweite, dritte;
	Pieces piece_eins, piece_zwei, piece_drei;
	benutzer_input(erste, zweite, dritte, piece_eins, piece_zwei, piece_drei);
}


void Pieces::setBuchstabe() {
	int wert;								
	wert = rand() % 3;	
										
	switch (wert) {						
	case 0:					
		string_buchstabe = "A";
		break;
	case 1:
		string_buchstabe = "B";
		break;
	case 2:
		string_buchstabe = "C";
		break;

	}
}

void Pieces::setBuchstabe(buchstaben given_buchstabe) {
	int wert;
	wert = given_buchstabe;
	switch (wert) {
	case 0:
		string_buchstabe = "A";
		break;
	case 1:
		string_buchstabe = "B";
		break;
	case 2:
		string_buchstabe = "C";
		break;
	}
}

void Pieces::getBuchstabe() {
	cout << string_buchstabe << " ";
}

char Pieces::getBuchstabeletter(Pieces piece) {
	return(piece.string_buchstabe[0]);
}

void Begin::spiel_nachricht() {

	int wahl = 0;

	cout << "Willkommen in MASTERMIND!\n ";

	while (wahl != 3) {
		cout << "\nWaehle 1 fuer ANLEITUNG des Spiels.\nWaehle 2 fuer Spiel INFO.\nWaehle 3 fuers Spielbegin. \n";
		cin >> wahl;
		cout << "\n";

		switch (wahl) {
		case 1:
			zeige_anleitung();
			break;
		case 2:
			zeige_info();
		case 3:
			break; //Weiter mit Spiel
		default:
			cout << "\nSie haben keine gueltige Auswahl getroffen. Bitte verwenden Sie ausschliesslich eine Zahl zwischen 1-3 und versuchen Sie es erneut.";

		}
	}
}

void Begin::zeige_anleitung() {
	cout << "Das Ziel dieses Spiels ist es, den 3-Buchstaben-Code des Computers herauszufinden. \nWaehlen Sie zunaechst 3 Buchstaben aus:"
		"\n\tA\n\tB\n\tC\nAls Naechstes, verwenden Sie die Hinweise, um Ihre naechste Vermutung zu bestimmen:\n\tX bedeutet richtige Buchstabe und richtiger Ort."
		"\n\tO bedeutet richtige Buchstabe, aber falscher Ort.";
	cout << "\nBeispiel:\n\tCode:\t\t B\tA\tC\n\tEingabe:\t B\tC\tA\n\tErgebnis: \tXOO\n";
}

void Begin::zeige_info() {
	cout << "--Softwaretechnik Praktikum--\nMastermind 2.0 in C++\n\nHasan Baran 5084173\nTimon Meyer 5159794\nPatrick Frerk 5106938 \n";
}

bool play_again() {
	char eingabe;
	bool ergebnis = 1;
	bool gueltig = 0;

	do {
		cout << "\nMoechten Sie noch einmal spielen? (j - ja, n - nein) eingeben: ";
		cin >> eingabe;
		if (eingabe == 'J' || eingabe == 'j' || eingabe == 'N' || eingabe == 'n' || eingabe == 'ja' || eingabe == 'Ja' || eingabe == 'si' || eingabe == 'nein') {

			if (eingabe == 'J' || eingabe == 'j' || eingabe == 'ja' || eingabe == 'Ja' || eingabe == 'si') {
				ergebnis = 0;
				gueltig = 1;
			}
			 if (eingabe == 'N' || eingabe == 'n' || eingabe == 'nein') {
				ergebnis = 1;
				return 0;
			}
		}
		else {
			cout << "\nSie haben keine gueltige Auswahl getroffen. Bitte versuchen Sie es erneut.";
			gueltig = 0;
		}
	} while (!gueltig);
	return(!ergebnis);
}

void Abfrage::benutzer_input(string erste, string zweite, string dritte, Pieces& erstep, Pieces& zweitep, Pieces& drittep) {
	int zaehler = 0;
	

	while (zaehler < 3) {
		int schwarz = 0;
		int weiss = 0;

		cout << "\nBitte geben Sie drei durch ein Leerzeichen getrennte Buchstaben ein: ";
		cin >> erste >> zweite >> dritte;

		//Erster String
		if (erste[0] == erstep.getBuchstabeletter(erstep)) {
			schwarz++;
			zaehler++;
		}
		else if (erste[0] == zweitep.getBuchstabeletter(zweitep) || erste[0] == drittep.getBuchstabeletter(drittep)) {
			weiss++;
		}
		//Zweiter String
		if (zweite[0] == zweitep.getBuchstabeletter(zweitep)) {
			schwarz++;
			zaehler++;
		}
		else if (zweite[0] == erstep.getBuchstabeletter(erstep) || zweite[0] == drittep.getBuchstabeletter(drittep)) {
			weiss++;
		}
		//Dritter String
		if (dritte[0] == drittep.getBuchstabeletter(drittep)) {
			schwarz++;
			zaehler++;
		}
		else if (dritte[0] == erstep.getBuchstabeletter(erstep) || dritte[0] == zweitep.getBuchstabeletter(zweitep)) {
			weiss++;
		}

		if (zaehler < 3) {
			zaehler = 0;
		}
		// Ausgabe Bedingungen
		if (schwarz>0)
			cout << "Richtige Stelle: " << schwarz << "\n";
		if(weiss>0)
			cout << "Falscher Ort: " << weiss << "\n";
		if (schwarz == 0 && weiss == 0)
			cout << "---";
		if (schwarz == 3)
			cout << "\nXXX";
		if (schwarz == 2)
			cout << "\nXX";
		if (schwarz == 1)
			cout << "\nX";
		if (weiss == 3)
			cout << "\nOOO";
		if (weiss == 2)
			cout << "OO";
		if (weiss == 1)
			cout << "O";
		if (schwarz == 2 && weiss == 0)
			cout << "-";
		if (schwarz == 1 && weiss == 0)
			cout << "--";
	}
	if (zaehler >= 3) {
		cout << " ...\n\nHerzliche Glueckwuensche! Du hast den Code geknackt !!";
	}
}




