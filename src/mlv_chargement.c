/**
 * @file mlv_chargement.c
  * @author mathevon/palisse
 * @brief fonctions de chargement/sauvegarde de fichiers
 * @version 0.1
 * @date 2023-05-21
 */
#include "../headers/mlv_chargement.h"

/**
 * @brief Permet de charger un fichier de points dans un tableau 
 * 
 * @param tableau 
 */
void mlv_chargement_fichier(tab_points tableau){
    char * texte;
    nettoyer_tableau_points(tableau);
    MLV_wait_input_box(700, 450, 400,100 , MLV_COLOR_WHITE, MLV_COLOR_ANTIQUE_WHITE, MLV_COLOR_BLACK, "Chemin du fichier : ", &texte);
    
    if (chargement_fichier(tableau, texte)==0){
        mlv_message("Le fichier n'existe pas");
    }

    free(texte);
    mlv_affichage_menu(2);
    mlv_affichage_points(tableau);

}


/**
 * @brief Permet de sauvegarder un tableau de points dans un fichier
 * 
 * @param tableau 
 */
void mlv_sauvegarde_fichier(tab_points tableau){
    char * texte;
    MLV_wait_input_box(700, 450, 400,100 , MLV_COLOR_WHITE, MLV_COLOR_ANTIQUE_WHITE, MLV_COLOR_BLACK, "Chemin du fichier : ", &texte);
    
    if (sauvegarde_fichier(tableau, texte) == 0){
        mlv_message("Liste vide ou problème d'écriture");
    }

    free(texte);
}


/**
 * @brief Permet de générer un fichier de points aléatoires
 * 
 * @param tableau 
 * @param arbre 
 */
void mlv_generation_fichier(tab_points tableau, arbre_kd * arbre){
    char* args[] = {"./donnees/prog_creation/creation", NULL, NULL, "2", NULL, NULL};
    char* nom_fichier;
    /*rajouter des tests*/
    MLV_wait_input_box(700, 450, 400,100 , MLV_COLOR_WHITE, MLV_COLOR_ANTIQUE_WHITE, MLV_COLOR_BLACK, "Nom du fichier : ", &args[1]);
    MLV_wait_input_box(700, 450, 400,100 , MLV_COLOR_WHITE, MLV_COLOR_ANTIQUE_WHITE, MLV_COLOR_BLACK, "Nombre de points : ", &args[2]);
    MLV_wait_input_box(700, 450, 400,100 , MLV_COLOR_WHITE, MLV_COLOR_ANTIQUE_WHITE, MLV_COLOR_BLACK, "Nombre de classes : ", &args[4]);

    if (fork() == 0){
        if (execvp("./donnees/prog_creation/creation", args) == -1) {
            printf("Erreur lors du lancement de la commande.\n");
            exit(EXIT_FAILURE);
        }
    }
    else {
        wait(NULL);
    }
    mlv_reinitialiser(tableau);
    *arbre=orchestre_suppression(tableau, *arbre);
    nom_fichier = malloc(sizeof(char)*(strlen(args[1])+strlen("./donnees/")+1));
    strcpy(nom_fichier, "./donnees/");
    strcat(nom_fichier, args[1]);
    chargement_fichier(tableau ,nom_fichier);
    chargement_fichier_arbre_kd(arbre, nom_fichier);
    mlv_affichage_points(tableau);

}