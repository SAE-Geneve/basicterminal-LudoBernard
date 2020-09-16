#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
	
	//Initialisation des variables
	bool trouvé = false;
	srand((int)time(0));
	int chiffre = ((rand() % 100) + 1);
	int tentatives = 0;

	//On continue à jouer tant que le chiffre n'est pas trouvé
	while (trouvé == false) {
		cout << "Devinez le chiffre entre 1 et 100!\n";
		int essai = 0;
		cin >> essai;
		if(essai > chiffre){
			cout << "Trop grand!\n";
			tentatives += 1;
		} else if(essai < chiffre){
			cout << "Trop petit!\n";
			tentatives += 1;
		} else {
			tentatives += 1;
			cout << "Bravo vous gagnez avec " << tentatives << " tentatives!";
			trouvé = true;
		}
	}
	
}
