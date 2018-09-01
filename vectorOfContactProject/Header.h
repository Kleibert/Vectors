#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

//author : Kleibert Souza de Aquino
//submitted to : Houria Houmel
//created date : 15/04/2018

int choice; int choiceRecherche; int choiceSort;
int maxPrincipal;


struct Date
{
	int month;
	int day;
	int year;

};

struct PhoneC
{
	int internCode;
	int countCode;
	int cityCode;
	int cellCode;
};
struct Address
{
	int strNumber;
	string strName;
	string city;
	string province;
	string postalCode;
	string country;


};

struct Contact
{
	int number;
	string frstName; string lastName; string compName; string email;
	
	//default constructor
	Contact() {
		number = 0000;
		frstName = "undefined";
		lastName = "undefined";
		compName = "undefined";
		email = "undefuned";
	}

	//overload constructor
	Contact(int Num, string fn, string ln, string cpName, string e_mail) {
		number = Num;
		frstName = fn;
		lastName = ln;
		compName = cpName;
		email = e_mail;
	}
};

struct CompNameComparator {

	bool operator () (Contact & s1, Contact & s2) {

		return s1.compName < s2.compName;
	}
};

vector<Contact> vectOfContact;




int Recupererchoix() {
	
	int choice;
	cout << "\nDynamic Allocation Memory & Algorithms" << endl;
	cout << "--------------------------------------" << endl << endl;

	cout << "1-Add a contact:" << endl;
	cout << "2-Display all the contacts:" << endl;
	cout << "3-Remove a contact from vector :" << endl;
	cout << "4-Search for a contact by :" << endl;
	cout << "5-Sort the contacts by company name:" << endl;
	cout << "6-Exit application:" << endl << endl;
	cout << "Enter your choice : ";
	cin >> choice;
	return choice;
}
int RecupererChoixDeRecherche() {

	int choice;
	cout << "Search by: "<<endl;
	cout << "\t 1-Contact number :" << endl;
	cout << "\t 2-Company Name :" << endl;
	cout << "\t 3-Back to the main menu :" << endl;
	
	cin >> choice;
	return choice;
}
void ajouterUnContact() {

	Contact unContact;

	cout << "\n\tContact number :";
	cin >> unContact.number;

	cout << "\t Last Name :";
	cin >> unContact.lastName;
	cin.ignore();

	cout << "\t First Name :";
	getline(cin, unContact.frstName);

	cout << "\tCompagnie Name :";
	getline(cin, unContact.compName);

	cout << "\tE-mail:";
	getline(cin, unContact.email);

	

	vectOfContact.push_back(unContact);
	
}
void afficherUnContact(int position) {
	cout << "\n\tContact number :" << vectOfContact.at(position).number;
	cout << "\tLast Name :" << vectOfContact.at(position).lastName;
	cout << "\tFirst Name :" << vectOfContact.at(position).frstName;
	cout << "\tCompany name :" << vectOfContact.at(position).compName << endl ;
	cout << "\tE-mail:" << vectOfContact.at(position).email << endl << endl;
}
void afficherTousLesContact() {
	for (size_t index = 0; index < vectOfContact.size(); index++)
	{
		afficherUnContact(index);
	}
}

int RechercherUnContact(int numeroContact) {
	int position;
	for (size_t index = 0; index < vectOfContact.size(); index++) {
		if (vectOfContact.at(index).number==numeroContact)
		{
			position = index;	
			return position;
		}
	}	
}
int RechercherUnContact(string lastName) {
	int position;
	for (size_t index = 0; index < vectOfContact.size(); index++) {
		if (vectOfContact.at(index).lastName == lastName)
		{
			position = index;
			return position;
		}
	}	
}
int recupererNumeroContact() {
	int position,numero;
	cout<<"\n\t Entrer le numero du contact à rechercher:";
	cin >> numero;
	return numero;
}
string recupererNomContact() {
	int position;
	string nom;
	cout<<"\n\t Entrer le nom du contact à rechercher:";
	cin >> nom;
	return nom;
}
void supprimerUnContactDuVecteur(int position) {
	vectOfContact.erase(vectOfContact.begin() + (position));
}
