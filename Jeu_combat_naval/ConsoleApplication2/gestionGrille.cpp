
// bibliotheques personnelles
#include "gestionGrille.h"

// bibliotheques du systeme
#include <iomanip>  // Manipulateurs d'E/S

using namespace std;

// description : Ce module permet d'afficher l’entête d’une grille donnée
// retour : Chaîne de caractères, Entête affichée
// pre : Entête pas affichée
// post : Entête affichée

void afficherEntete()
{

    cout << "    ";

    for (int colonne = 0; colonne < NB_COLS; colonne++) {//Boucle pour afficher les lettres des colonnes

        char a = 'A' + colonne;
        cout << a << " ";
    }

    cout << endl << "----";

    for (int colonne = 0; colonne < NB_COLS; colonne++) { // boucle pour sousligner

        cout << "--";
    }

    cout << endl;

    return;
}

// description : Ce module permet d'affiche l’intérieur d'une grille donnée
// param[E] :Grille, grille a afficher
// retour : Chaîne de caractères, grille affichée
// pre : intérieur d'une grille non affichée
// post : intérieur d'une grille affichée

void afficherGrilleInterieur(const Grille& e_grille) {



    for (int ligne = 0; ligne < NB_LIGS; ligne++)
    {
        int a = ligne + 1;

        if (a == 10) {
            cout << a;
            cout << "| ";
        }
        else {
            cout << a;
            cout << " | ";
        }

        for (int colonne = 0; colonne < NB_COLS; colonne++) {

            if (e_grille[ligne][colonne] == (char)ContenuCase::EAU) {

                cout << " ";
            }

            else if (e_grille[ligne][colonne] == (char)ContenuCase::MANQUE) {

                cout << "O";

            }
            else if (e_grille[ligne][colonne] == (char)ContenuCase::TOUCHE) {

                cout << "*";
            }
            else {

                cout << (int)e_grille[ligne][colonne];
            }

            cout << " ";
        }
        cout << endl;
    }
    return;

}

// description : Ce module permet d'afficher une grille (bateaux ou tirs)
// param[E] :Grille, grille a afficher
// retour : Chaîne de caractères, grille affichée
// pre : grille non affichée
// post : grille affichée

void afficherGrille(const Grille& e_grille)
{
    // fonction bidon : code à remplacer

    afficherEntete();
    afficherGrilleInterieur(e_grille);

    cout << "----";

    for (int colonne = 0; colonne < NB_COLS; colonne++) {

        cout << "--";
    }

    cout << endl;



    return;
}


// description : Initialise une grille
// param[S] : grille
// retour : aucun
// pre : aucun
// post : La grille contient la valeur EAU a chaque case

void initialiserGrille(Grille& s_grille)
{
    // fonction bidon : code à remplacer

    for (int ligne = 0; ligne < NB_LIGS; ligne++) {

        for (int colonne = 0; colonne < NB_COLS; colonne++) {

            s_grille[ligne][colonne] = (char)ContenuCase::EAU;
        }
    }

    return;
}

// description : Valide si l’attaque est faite dans la grille de jeu
// param[E] : Position, Position à valider
// retour : Booléen, False si object est en dehors des lignes ou des colonnes, True sinon
// pre :  Position non validée
// post : Position validée

bool validerPosition(Position e_pos)
{
    // fonction bidon : code à remplacer

    if (e_pos.m_ligne<0 || e_pos.m_ligne> NB_LIGS) {

        return false;
    }
    if (e_pos.m_colonne<0 || e_pos.m_colonne>NB_COLS) {
        return false;
    }

    return true;
}
