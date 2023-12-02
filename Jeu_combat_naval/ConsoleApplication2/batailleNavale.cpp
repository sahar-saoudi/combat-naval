
#include "batailleNavale.h"
#include "bnRandom.h"

#include <cassert>  // Pour les assertions

using namespace std;

// constantes
const char TERMINER{ 'q' };          // Caract�re entr� pour terminer la partie

const int NB_BATEAUX{ 5 };           // Nombre de bateaux
const int TAILLE_TORPILLEUR{ 2 };    // Taille du torpilleur
const int TAILLE_C_TORPILLEUR{ 3 };  // Taille du contre-torpilleur
const int TAILLE_SOUS_MARIN{ 3 };    // Taille du sous-marin
const int TAILLE_CROISEUR{ 4 };      // Taille du croiseur
const int TAILLE_PORTE_AVION{ 5 };   // Taille du porte-avion
const int TAILLES_BATEAUX[]{ TAILLE_TORPILLEUR, TAILLE_C_TORPILLEUR, TAILLE_SOUS_MARIN, TAILLE_CROISEUR, TAILLE_PORTE_AVION };

// �num�ration
enum class Orientation { HORIZONTAL, VERTICAL }; // orientation d'un bateau

// type synonyme
using EtatBateaux = bool[NB_BATEAUX];   // tableau d'indicateurs de l'�tat coul� ou non des bateaux

// description : Ce module valide la position du bateau en prenant compte de l�orientation d�sir�e pour ce bateau.
// param[E] : Position, Position � valider
// param[E] : Entier, Taille du bateau � placer
// param[E] : Orientation, Orientation du bateau � placer
// param[E] : Grille, Position des bateaux
// retour : Bool�en, True si la position est valide
// pre : inconnu si la position du bateau est valide ou pas
// post : la position du bateau est soit valide, soit pas valide

bool validerPositionBateau(Position p_bateau, int taille, Orientation o_bateau, Grille g_bateau) {

    if (o_bateau == Orientation::HORIZONTAL) {
        if (p_bateau.m_colonne + taille - 1 > NB_COLS)
        {
            return false;
        }
        for (int a = 0; a < taille; a++) {

            if (g_bateau[p_bateau.m_ligne][p_bateau.m_colonne + a] != (char)ContenuCase::EAU) {

                return false;
            }
        }
    }
    else {

        if (p_bateau.m_ligne + taille - 1 > NB_LIGS)
        {
            return false;
        }
        for (int b = 0; b < taille; b++) {

            if (g_bateau[p_bateau.m_ligne + b][p_bateau.m_colonne] != (char)ContenuCase::EAU) {

                return false;
            }
        }
    }

    return true;
}


// description : Ce module permet de placer les bateaux sur la grille d'une facon al�atoire
// param[ES] :Grille, Position des bateaux
// pre : bateaux non plac�s sur la grille
// post : bateaux plac�s et verifi�s sur la grille

void placerBateaux(Grille& es_grille) {

    Position p_bateau;

    Orientation o_bateau;

    int c = 0;


    for (int taille : TAILLES_BATEAUX) {

        bool a = false;

        while (a == false)
        {

            p_bateau.m_colonne = genererValeur(0, NB_COLS);

            p_bateau.m_ligne = genererValeur(0, NB_LIGS);


            if (genererValeur(0, 1) == 1) {
                o_bateau = Orientation::VERTICAL;
            }
            else {
                o_bateau = Orientation::HORIZONTAL;
            }

            a = validerPositionBateau(p_bateau, taille, o_bateau, es_grille);
        }

        for (int b = 0; b < taille; b++) {


            if (o_bateau == Orientation::HORIZONTAL) {

                es_grille[p_bateau.m_ligne][p_bateau.m_colonne + b] = (char)c;
            }
            else {

                es_grille[p_bateau.m_ligne + b][p_bateau.m_colonne] = (char)c;
            }
        }
        c++;
    }




    return;

}

// description : Ce module r�alise les tours du jeu et initialise et affiche la grille de tirs
// param[E] :Grille, grille des bateaux
// pre : grille de tirs non initialis�e et non afiich�e, les tours de jeu n'ont pas encore commenc�
// post : grille de tirs initialis� et afiich�e, les tours de jeu ont pas commenc�

void jouer(const Grille& e_grilleBateaux)//travail
{
    EtatBateaux etat = { false,false,false,false,false };
    bool a;
    Grille tir;

    bool jouerUnTour(const Grille&, Grille&, EtatBateaux&);

    initialiserGrille(tir);

    do {
        afficherGrille(tir);
        a = jouerUnTour(e_grilleBateaux, tir, etat);

    } while (a);

    return;
}

// description : Ce Module contient toute la logique d�un tour du jeu.
// param[E] : Caract�re, colonne du tir
// param[E] : Entier, ligne du tir
// param[E] : Grille, position des bateaux
// param[ES] : Grille, position des tirs
// param[ES] : EtatBateaux, Etat des Bateaux ( coul�s ou pas )
// retour : Bool�en, False si le jeu termine, True sinon
// retour : Chaine de caract�res, Message � En dehors de la grille! �
// retour : Chaine de caract�res, Message � quitter �
// retour : Chaine de caract�res, Grille des tirs
// pre : le tour du jeu non jou�
// post : le tour du jeu jou�

bool jouerUnTour(const Grille& e_grilleBateaux, Grille& es_grilleTirs, EtatBateaux& es_etatBateau)
{
    bool tirer(const Grille&, Position, Grille&, EtatBateaux&); // retourne true si la partie est gagn�e avec ce tour

    char cColonne;
    int nLigne;

    // 3.1 Lire la colonne du tir
    cout << "Colonne (en majuscules) et ligne du tir ('" << TERMINER << "' pour quitter) : ";
    cin >> cColonne;

    // 3.2 V�rifier si TERMINER
    if (cColonne == TERMINER || cin.fail())
    {
        // 3.1.2.1 Afficher un message et quitter le jeu
        cout << "quitter" << endl;
        return false;
    }

    cColonne = toupper(cColonne) - 'A';

    // 3.3 Lire la ligne du tir
    cin >> nLigne;
    nLigne -= 1;
    cout << endl;

    // 3.4 Valider que la position est bien dans la grille (module ValiderEntrees)
    if (validerPosition({ cColonne, nLigne }))
    {

        // 3.4.1 V�rifier le r�sultat du tir (module Tir)
        if (tirer(e_grilleBateaux, { cColonne, nLigne }, es_grilleTirs, es_etatBateau))
        {
            afficherGrille(es_grilleTirs); // optionnel
            // 3.4.1.1 Si le tir est celui qui fait gagner la partie, sortir du jeu
            return false;
        }

    }

    // 3.5 Sinon, afficher un message
    else cout << "En dehors de la grille!" << endl;

    return true;
};

// description : ce module v�rifie si un tir touche, coule ou termine la partieet puis, il affiche les messages appropri�s a chaque situation
// param[E] : Grille, Position des bateaux
// param[E] : Position, Position du tir
// param[ES] : Grille, Position des tirs
// param[ES] : EtatBateaux, �tat des bateaux
// retour : Bool�en, True si tous les bateaux sont coul�s ( la partie est gagn�e ), False sinon
// retour : chaine de caract�res, Grille des tirs
// retour : chaine de caract�res, Message � Touche! �
// retour : chaine de caract�res, Message � Coule! �
// retour : chaine de caract�res, Message � A l�eau!! �
// retour : chaine de caract�res, Message � VICTOIRE... BRAVO! �
// retour : chaine de caract�res, Message � Vous avez deja tire la! �
// pre : l'effet d'un tir est inconnu
// post : l'effet d'un tir est connu

bool tirer(const Grille& e_grilleBateaux, Position e_pos, Grille& es_grilleTir, EtatBateaux& es_etatBateau)
{

    assert(e_pos.m_ligne < NB_LIGS);
    assert(e_pos.m_ligne >= 0);
    assert(e_pos.m_colonne < NB_COLS);
    assert(e_pos.m_colonne >= 0);

    bool validerCoule(const Grille&, Position, const Grille&);
    bool validerFinPartie(const EtatBateaux&);

    // 1 Si on a d�j� tir� sur la position
    if (es_grilleTir[e_pos.m_ligne][e_pos.m_colonne] != (char)ContenuCase::EAU)
    {
        // 1.1 Afficher un message indiquant qu'on a d�j� tir� sur cette position
        cout << "Vous avez deja tire la!" << endl;
        return false;
    }

    // 1 Si le tir n'est pas sur une position d�j� tir�e
    // 1.1 Si on a touch� un bateau
    if (e_grilleBateaux[e_pos.m_ligne][e_pos.m_colonne] != (char)ContenuCase::EAU)
    {
        // 1.1.1 Afficher le message "Touche!"
        cout << "Touche!" << endl;

        // 1.1.2 Indiquer sur la carte de tir qu'on a touch� un bateau
        es_grilleTir[e_pos.m_ligne][e_pos.m_colonne] = (char)ContenuCase::TOUCHE;

        // 1.1.3 V�rifier que le bateau touch� a �t� coul� (module validerCoule)
        if (validerCoule(e_grilleBateaux, e_pos, es_grilleTir))
        {
            // 1.1.3.1 Afficher le message "Coule!"
            cout << "Coule!" << endl;
            es_etatBateau[e_grilleBateaux[e_pos.m_ligne][e_pos.m_colonne]] = true;

            // 1.1.3.2 Si on a coul� tous les bateaux (module validerFinPartie)
            if (validerFinPartie(es_etatBateau)) {

                // 1.1.3.2.1 Afficher le message de victoire
                cout << "VICTOIRE... BRAVO!" << endl;

                // 1.1.3.2.2 C'est la fin de la partie, retourne vrai
                return true;
            }
        }
    }

    // 1.2 Sinon on a manqu� le tir
    else
    {
        // 1.2.1 Afficher le message "A l'eau!"
        cout << "A l'eau!" << endl;
        // 1.2.2 Indiquer sur la carte qu'on a tir� sur cette position
        es_grilleTir[e_pos.m_ligne][e_pos.m_colonne] = (char)ContenuCase::MANQUE;
    }

    // 3 Ce n'est pas la fin de la partie, retourne faux
    return false;
}

// description : Ce module v�rifie si une partie est finie selon l'�tat des bateaux
// param[ES] : EtatBateaux, �tat des bateaux
// retour : Bool�en, True si tous les bateaux sont coul�s ( la partie est gagn�e ), False sinon
// pre : fin de partie non valid�a
// post : fin de partie valid�e

bool validerFinPartie(const EtatBateaux& es_etatBateau)
{

    // 1 Pour tous les bateaux

    /*
    int numbers[] = { 1, 2, 3, 4, 5 };
    for (int& n : numbers) {
        n *= 2;
    }
     */


     //    for (int i=0; i<NB_BATEAUX; i++) {
    for (bool etat : es_etatBateau) {

        // 1.1 La partie n'est pas termin�e si un bateau n'est pas coul�
//        if (!io_etatBateau[i])
        if (!etat)
            return false;
    }

    // 2 Tous les bateaux sont coul�s, retourne vrai
    return true;
}

// description : Ce module v�rifie si le bateau � la position donn�e est coul�
// param[E] : Grille, position des bateaux
// param[E] : Position, Position du tir � valider
// param[E] : Grille, Position des tirs
// retour : Bool�en, True si le bateau � la position demand�e est coul�, False sinon
// pre : �tat de bateau inconnue ( coul� ou pas )
// post : �tat de bateau connue 

bool validerCoule(const Grille& e_grilleBateaux, Position e_pos, const Grille& e_grilleTirs)
{

    assert(e_pos.m_ligne < NB_LIGS);
    assert(e_pos.m_ligne >= 0);
    assert(e_pos.m_colonne < NB_COLS);
    assert(e_pos.m_colonne >= 0);

    Orientation determinerOrientation(const Grille&, int, Position);
    bool validerCouleH(const Grille&, int, Position, const Grille&);
    bool validerCouleV(const Grille&, int, Position, const Grille&);

    // 1 R�cup�rer le num�ro du bateau courant
    int nBateau{ e_grilleBateaux[e_pos.m_ligne][e_pos.m_colonne] };

    // 2 D�terminer si le bateau est positionn� horizontalement ou verticalement
    Orientation bOrientation{ determinerOrientation(e_grilleBateaux, nBateau, e_pos) };

    // 3 V�rifier si toutes les cases du bateau sont touch�es
    // 3.1 Si le bateau est horizontal
    if (bOrientation == Orientation::HORIZONTAL) {
        return validerCouleH(e_grilleBateaux, nBateau, e_pos, e_grilleTirs);
    }

    // 3.2  Sinon, le bateau est vertical
    return validerCouleV(e_grilleBateaux, nBateau, e_pos, e_grilleTirs);
}

// description : ce module Valide qu�un bateau horizontal � la position du tir courant est coul�
// param[E] : Grille, position des bateaux
// param[E] : Position, Position du tir
// param[E] : Grille, Position des tirs
// param[E] : Entier, Num�ro du bateau
// retour : Bool�en, True si le bateau horizontal est coul�, False sinon
// pre : �tat de bateau horizontal inconnue ( coul� ou pas )
// post : �tat de bateau horizontal connue

bool validerCouleH(const Grille& e_grilleBateaux, int e_noBateau, Position e_pos, const Grille& e_grilleTirs)
{

    assert(e_pos.m_ligne < NB_LIGS);
    assert(e_pos.m_ligne >= 0);
    assert(e_pos.m_colonne < NB_COLS);
    assert(e_pos.m_colonne >= 0);
    assert(e_noBateau >= 0);
    assert(e_noBateau < 5);

    int nTaille{ TAILLES_BATEAUX[e_noBateau] };
    int ncol{ e_pos.m_colonne };

    // 3.1 Trouver la colonne de d�part du bateau
    // 3.1.1 Revenir vers la gauche jusqu�� ce que ce ne soit plus le num�ro du bateau
    do {
        ncol--;
    } while (e_grilleBateaux[e_pos.m_ligne][ncol] == e_noBateau);
    ncol++;

    assert(ncol >= 0);

    // 3.2.1 Pour toute la taille du bateau
    for (int i = 0; i < nTaille; i++, ncol++) {
        // 3.2.1.1 Le bateau n'est pas coul� si la case n'est pas touch�
        if (e_grilleTirs[e_pos.m_ligne][ncol] != (char)ContenuCase::TOUCHE)
            return false;
    }

    return true;
};

// description : ce module Valide qu�un bateau vertical � la position du tir courant est coul�
// param[E] : Grille, grille des bateaux
// param[E] : Position, Position du tir
// param[E] : Grille, Position des tirs
// param[E] : Entier, Num�ro du bateau
// retour : Bool�en, True si le bateau vertical est coul�, False sinon
// pre : �tat de bateau vertical inconnue ( coul� ou pas )
// post : �tat de bateau vertical connue

bool validerCouleV(const Grille& e_grilleBateaux, int e_noBateau, Position e_pos, const Grille& e_grilleTirs)
{
    assert(e_pos.m_ligne < NB_LIGS);
    assert(e_pos.m_ligne >= 0);
    assert(e_pos.m_colonne < NB_COLS);
    assert(e_pos.m_colonne >= 0);
    assert(e_noBateau >= 0);
    assert(e_noBateau < 5);

    int nlig{ e_pos.m_ligne };
    int nTaille{ TAILLES_BATEAUX[e_noBateau] };

    // Revenir vers le haut jusqu�� ce que ce ne soit plus le num�ro du bateau
    while (e_grilleBateaux[nlig][e_pos.m_colonne] == e_noBateau)
        nlig--;
    nlig++;

    assert(nlig >= 0);

    // 4.2 V�rifier si toutes les cases du bateau sont touch�es
    // 4.2.1 Pour toute la taille du bateau
    for (int i = 0; i < nTaille; i++, nlig++)
    {
        // 4.2.1.1 Le bateau n'est pas coul� si la case n'est pas touch�e
        if (e_grilleTirs[nlig][e_pos.m_colonne] != (char)ContenuCase::TOUCHE)
            return false;
    }

    return true;
}

// description : Ce module permet de d�terminer l�orientation d�un bateau situ� � une position donn�e
// param[E] : Grille, grille des bateaux
// param[E] : Position, Position du bateau
// param[E] : Entier, Num�ro du bateau
// retour : Orientation, l�orientation du bateau
// pre : orientation du bateau inconnue
// post : orientation du bateau connue

Orientation determinerOrientation(const Grille& e_grilleBateaux, int e_noBateau, Position e_pos)
{
    assert(e_pos.m_ligne < NB_LIGS);
    assert(e_pos.m_ligne >= 0);
    assert(e_pos.m_colonne < NB_COLS);
    assert(e_pos.m_colonne >= 0);
    assert(e_noBateau >= 0);
    assert(e_noBateau <= 5);

    const char PREMIERE_COLONNE = 0;
    const char DERNIERE_COLONNE = NB_COLS - 1;

    // 2.1 Si la colonne est la premi�re
    if (e_pos.m_colonne == PREMIERE_COLONNE)
    {
        // 2.1.1 Le bateau est horizontal si la colonne 2 a le m�me num�ro de bateau
        if (e_grilleBateaux[e_pos.m_ligne][2] == e_noBateau)
            return Orientation::HORIZONTAL;
    }
    // 2.2 Si la colonne est la derni�re
    else if (e_pos.m_colonne == DERNIERE_COLONNE)
    {
        // 2.2.1 Le bateau est horizontal si l'avant-derni�re colonne a le m�me num�ro de bateau
        if (e_grilleBateaux[e_pos.m_ligne][NB_COLS - 2] == e_noBateau)
            return Orientation::HORIZONTAL;
    }
    // 2.3 Sinon, si la colonne pr�c�dente le bateau est horizontal
    else if ((e_grilleBateaux[e_pos.m_ligne][e_pos.m_colonne - 1] == e_noBateau))
        return Orientation::HORIZONTAL;

    // ou suivante a le m�me num�ro de bateau
    else if ((e_grilleBateaux[e_pos.m_ligne][e_pos.m_colonne + 1] == e_noBateau))
        return Orientation::HORIZONTAL;

    // 2.4 Sinon, le bateau est vertical
    return Orientation::VERTICAL;

};