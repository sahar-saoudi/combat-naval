
// fichier : bnRandom.h
// auteur : Vincent Ducharme
// modifié par : Marie-Flavie Auclair-Fortier - 15 octobre
// modifié par : Marie-Flavie Auclair-Fortier - 16 mars
// résumé : Ce fichier contient une fonction de génération de valeur aléatoire


#ifndef BNRANDOM_H
#define BNRANDOM_H

// description : génère une valeur aléatoire entière entre deux bornes
// param[E] : entier, valeur minimale que peut prendre la valeur
// param[E] : entier, valeur max que peut prendre la valeur
// sorties : aucune
// retour : entier, valeur aléatoire produite
// pre : min < max
// post : le retour est entre min et max

int genererValeur(int min, int max);

#endif // BNRANDOM_H
