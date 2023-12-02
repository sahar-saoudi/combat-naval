//
//  batailleNavale.h
//  D5_BatailleNavale
//
// Modifié par : Sahar Saoudi - Cristiano Doresca
// date : 13-11-2023
// 
//  Created by Marie-Flavie Auclair-Fortier on 2019-10-11.
//  Copyright © 2019 Marie-Flavie Auclair-Fortier. All rights reserved.
//

#ifndef BATAILLENAVALE_H
#define BATAILLENAVALE_H

// bibliotheques personnelles
#include "gestionGrille.h"

// description : Ce module permet de placer les bateaux sur la grille d'une facon aléatoire
// param[ES] :Grille, Position des bateaux
// pre : bateaux non placés sur la grille
// post : bateaux placés et verifiés sur la grille

void placerBateaux(Grille&);

// description : Ce module réalise les tours du jeu et initialise et affiche la grille de tirs
// param[E] :Grille, grille des bateaux
// pre : grille de tirs non initialisée et non afiichée, les tours de jeu n'ont pas encore commencé
// post : grille de tirs initialisé et afiichée, les tours de jeu ont pas commencé

void jouer(const Grille&);

#endif /* BATAILLENAVALE_H */
