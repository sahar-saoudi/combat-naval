#include "bnRandom.h"

#include <random>   // Pour les fonctions de nombres aleatoires
#include <chrono>   // Pour les fonctions de temps
#include <cassert>  // Pour les assertions

// description : génère une valeur aléatoire entière entre deux bornes
// param[E] : entier, valeur minimale que peut prendre la valeur
// param[E] : entier, valeur max que peut prendre la valeur
// sorties : aucune
// retour : entier, valeur aléatoire produite
// pre : min < max
// post : le retour est entre min et max

int genererValeur(int e_min, int e_max)
{
    assert(e_min < e_max);

    unsigned int seed{ (unsigned int)std::chrono::system_clock::now().time_since_epoch().count() };
    int retour;

    seed = 1; // à enlever si on veux du vrai aléatoire

    static std::mt19937 s_generateur(seed);
    std::uniform_int_distribution<> distribution(e_min, e_max);

    retour = distribution(s_generateur);

    assert(retour >= e_min);
    assert(retour <= e_max);

    return retour;
}
