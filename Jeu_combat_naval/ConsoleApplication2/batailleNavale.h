//
//  batailleNavale.h
//  D5_BatailleNavale
//
// Modifi� par : Sahar Saoudi - Cristiano Doresca
// date : 13-11-2023
// 
//  Created by Marie-Flavie Auclair-Fortier on 2019-10-11.
//  Copyright � 2019 Marie-Flavie Auclair-Fortier. All rights reserved.
//

#ifndef BATAILLENAVALE_H
#define BATAILLENAVALE_H

// bibliotheques personnelles
#include "gestionGrille.h"

// description : Ce module permet de placer les bateaux sur la grille d'une facon al�atoire
// param[ES] :Grille, Position des bateaux
// pre : bateaux non plac�s sur la grille
// post : bateaux plac�s et verifi�s sur la grille

void placerBateaux(Grille&);

// description : Ce module r�alise les tours du jeu et initialise et affiche la grille de tirs
// param[E] :Grille, grille des bateaux
// pre : grille de tirs non initialis�e et non afiich�e, les tours de jeu n'ont pas encore commenc�
// post : grille de tirs initialis� et afiich�e, les tours de jeu ont pas commenc�

void jouer(const Grille&);

#endif /* BATAILLENAVALE_H */
