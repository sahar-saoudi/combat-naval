//
//  gestionGrille.h
//  D5_BatailleNavale
//
//  Created by Marie-Flavie Auclair-Fortier on 2019-10-10.
// 
// Modifié par : Sahar Saoudi - Cristiano Doresca
// date : 13-11-2023
// 
//  Copyright © 2019 Marie-Flavie Auclair-Fortier. All rights reserved.
//

#ifndef gestionGrille_h
#define gestionGrille_h

#include <iostream> // Pour l'affichage et les lectures
#include <array>    // Classe de tableaux 1D encapsules
#include <stdio.h>

// Nouveaux types de donnees
struct Position
{
    int m_colonne;
    int m_ligne;
};

// Constantes globales
const int NB_COLS{ 10 };   // Nombre de colonnes dans la grille
const int NB_LIGS{ 10 };     // Nombre de lignes dans la grille

enum class ContenuCase {
    EAU = -2,                     // etiquette pour l'eau
    TOUCHE = 6,                   // Represente une cible touchee
    MANQUE = 7                   // Represente un tir manque
};

// type synonyme représentant une grille 2D 
using Grille = char[NB_COLS][NB_LIGS];

// Declarations des fonctions publiques de la bibliotheque

// description : Ce module permet d'afficher une grille (bateaux ou tirs)
// param[E] :Grille, grille a afficher
// retour : Chaîne de caractères, grille affichée
// pre : grille non affichée
// post : grille affichée

void afficherGrille(const Grille&);

// description : Initialise une grille
// param[S] : grille
// retour : aucun
// pre : aucun
// post : La grille contient la valeur EAU a chaque case

void initialiserGrille(Grille&);

// description : Valide si l’attaque est faite dans la grille de jeu
// param[E] : Position, Position à valider
// retour : Booléen, False si object est en dehors des lignes ou des colonnes, True sinon
// pre :  Position non validée
// post : Position validée

bool validerPosition(Position);


#endif /* gestionGrille_h */

