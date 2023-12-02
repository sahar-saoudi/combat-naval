
// fichier : bnRandom.h
// auteur : Vincent Ducharme
// modifi� par : Marie-Flavie Auclair-Fortier - 15 octobre
// modifi� par : Marie-Flavie Auclair-Fortier - 16 mars
// r�sum� : Ce fichier contient une fonction de g�n�ration de valeur al�atoire


#ifndef BNRANDOM_H
#define BNRANDOM_H

// description : g�n�re une valeur al�atoire enti�re entre deux bornes
// param[E] : entier, valeur minimale que peut prendre la valeur
// param[E] : entier, valeur max que peut prendre la valeur
// sorties : aucune
// retour : entier, valeur al�atoire produite
// pre : min < max
// post : le retour est entre min et max

int genererValeur(int min, int max);

#endif // BNRANDOM_H
