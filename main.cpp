#include <iostream>
#include <cstdlib>
#include <ctime>

bool playAgain = false;

void Jeu() {
	//Initialisation des variables
	srand((int)time(0));
	bool playing = false;
	int allumettes;
	int choixAllumettesJoueur;
	bool tourJoueur = false;
	bool bonNombreAllumettes = true;

	std::cout << "Bienvenue au jeu des allumettes! Le but du jeu est simple, ne pas prendre la derniere allumette.\nVoulez-vous jouer?(y/n) ";
	char answer;
	std::cin >> answer;
	if (answer == 'y') {
		std::cout << "Combien voulez-vous d'allumettes dans la partie?\n";
		std::cin >> allumettes;
		if(allumettes <= 0){
			std::cout << "Vous ne pouvez pas avoir un nombre negatif ou nul d'allumettes!\n";
			bonNombreAllumettes = false;
		}
		if(bonNombreAllumettes){
			int tourDebut = rand() % 2 + 1;
			if (tourDebut == 1) {
				std::cout << "Vous commencez!\n";
				tourJoueur = true;
				playing = true;
			} else if (tourDebut == 2) {
				tourJoueur = false;
				std::cout << "L'ordinateur commence!\n";
				playing = true;
			}
			while (playing && allumettes > 0) {
				if (tourJoueur == true) {
					std::cout << "Prenez 1, 2 ou 3 allumettes.\n";
					std::cin >> choixAllumettesJoueur;
					switch (choixAllumettesJoueur)
					{
					case 1:
						allumettes -= choixAllumettesJoueur;
						break;
					case 2:
						allumettes -= choixAllumettesJoueur;
						break;
					case 3:
						allumettes -= choixAllumettesJoueur;
						break;
					default:
						std::cout << "Vous ne pouvez pas enlever autant d'allumettes!\n";
						continue;
					}
					std::cout << "\nIl reste " << allumettes << " allumettes!\n";
					tourJoueur = false;
				} else if (tourJoueur == false) {
					int choixAllumettesOrdinateur = rand() % 3 + 1;
					std::cout << "L'ordinateur prend " << choixAllumettesOrdinateur << " allumettes.\n";
					allumettes -= choixAllumettesOrdinateur;
					std::cout << "\nIl reste " << allumettes << " allumettes!\n";
					std::cout << "A votre tour!\n";
					tourJoueur = true;
				};
				if (allumettes <= 0 && tourJoueur) {
					std::cout << "Vous gagnez!\n";
					playing = false;
					playAgain = true;
				} else if (allumettes <= 0 && !tourJoueur) {
					std::cout << "Vous avez perdu!\n";
					playing = false;
					playAgain = true;
				}
		}
		
		}
	} else if (answer == 'n') {
		std::cout << "Au revoir!";
	}
}
int main() {
	Jeu();
	while (playAgain == true) {
		std::cout << "Voulez-vous rejouer?(y/n)\n";
		char answer;
		std::cin >> answer;
		if (answer == 'y') {
			playAgain = false;
			Jeu();
		} else if (answer == 'n') {
			std::cout << "Au revoir!";
			break;
		}
	}
	return 0;
}