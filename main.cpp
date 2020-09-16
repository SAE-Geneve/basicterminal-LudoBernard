#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

bool playAgain = false;

bool Jeu() {
	//Initialisation des variables
	bool trouvé = false;
	srand((int)time(0));
	int chiffre = ((rand() % 100) + 1);
	int tentatives = 0;

	//On continue à jouer tant que le chiffre n'est pas trouvé
	while (trouvé == false) {
		std::cout << "Devinez le chiffre entre 1 et 100!\n";
		int essai = 0;
		std::string temp;
		std::getline(std::cin, temp);
		essai = std::atol(temp.c_str());
		if (essai > chiffre) {
			std::cout << "Trop grand!\n";
			tentatives += 1;
		}
		else if (essai < chiffre) {
			std::cout << "Trop petit!\n";
			tentatives += 1;
		}
		else if (essai == chiffre) {
			tentatives += 1;
			std::cout << "Bravo vous gagnez avec " << tentatives << " tentatives!\n";
			trouvé = true;
			playAgain = true;
		}
	}
	return true;
}

int main() {
	Jeu();
	while (playAgain == true) {
		std::cout << "Voulez-vous rejouer?(y/n)\n";
		char answer = 'a';
		std::cin >> answer;
		if (answer == 'y') {
			playAgain = false;
			Jeu();
		}
		else if (answer == 'n') {
			std::cout << "Au revoir!";
			break;
		}
	}
}