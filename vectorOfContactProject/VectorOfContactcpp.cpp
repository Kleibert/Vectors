#include "Header.h"
//author : Kleibert Souza de Aquino
//submitted to : Houria Houmel
//created date : 15/04/2018
void main() {

	do
	{
		
		choice = Recupererchoix();
		if (choice == 1 && choice != 2 && choice != 3 && choice != 4 && choice != 4 && choice != 5)
		{
			system("cls");
			ajouterUnContact();
		}
		else if (choice == 2)
		{
			system("cls");
			cout<<"\nTous les contacts: \n\n";
			afficherTousLesContact();
		}
		else if (choice == 3)
		{
			system("cls");
			int position,numero;
			cout<<"\n\tEntrer le numero du contact a supprimer contacts: ";
			cin >> numero;
			position = RechercherUnContact(numero);
			supprimerUnContactDuVecteur(position);			
		}
		else if (choice == 4) {
			system("cls");
			do
			{
				choiceRecherche = RecupererChoixDeRecherche();
				if (choiceRecherche == 1 && choiceRecherche != 2)
				{
					int numeroContact;
					int position;

					numeroContact = recupererNumeroContact();
					position = RechercherUnContact(numeroContact);
					if (position>=0)
					{
						afficherUnContact(position);
					}
					else
					{
						cout<<"CONTACT N'INEXIST PAS";						
					}					
				}
				if (choiceRecherche == 2 && choiceRecherche != 1)
				{
					string lastName;
					int position;

					lastName = recupererNomContact();
					position = RechercherUnContact(lastName);					
					afficherUnContact(position);
							
				}

			} while (choiceRecherche <= 2);	
		}
		else if(choice==5)
		{
			system("cls");
			cout<<"\tSorting by CompanyName: \n";
			CompNameComparator nameComparator;
			sort(vectOfContact.begin(), vectOfContact.end(), nameComparator);
			afficherTousLesContact();
		}
		else if (choice == 6) {
			system("exit");
		}
	} while (choice < 6);
	system("pause");
}


