/*
 * fichier : main.cpp
 * auteur.e : Marie-Flavie Auclair-Fortier
 * date : 01/08/2019
 * modifié par : Marie-Flavie Auclair-Fortier - octobre 2019
 * modifié par : Marie-Flavie Auclair-Fortier - mars 2020
 */

 // bibliothèques personnelles
#include "batailleNavale.h" // bibliothèque contenant le code du jeu

// bibliothèques du système
#include <iostream> // Pour l'affichage et les lectures

using namespace std;

int main()
{
    Grille grilleBateaux;

    // 1. Initialiser la grille des bateaux
    initialiserGrille(grilleBateaux);

    // 2. Placer les bateaux sur la grille
    placerBateaux(grilleBateaux);

    // Afficher la grille pour fin de tests
    afficherGrille(grilleBateaux);

    // 3. Jouer au jeu
    jouer(grilleBateaux);

    std::cout << " Partie terminée" << std::endl;

    return 0;
}