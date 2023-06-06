/**
 * @file tad_tableau_points.c
 * @author mathevon/palisse
 * @brief TAD tableau de points
 * @version 0.1
 * @date 2023-05-21
 * 
 */
#include "../headers/tad_tableau_points.h"


/**
 * @brief Allocation de la mémoire nécessaire pour un tab_points d'une taille_max
 * 
 * @param taille_max la taille max du tableau
 * @return tab_points 
 */
tab_points creer_tableau_points(int taille_max){
    tab_points tableau = (tab_points) malloc(sizeof(struct_tab_points));
    if (tableau == NULL){
        printf("Erreur lors de l'allocation (tad_liste_points.c/creer_tableau_points)\n");
        free(tableau);
        return NULL;
    }
    tableau->tab = malloc(taille_max*sizeof(point));
    if (tableau->tab == NULL){
        printf("Erreur lors de l'allocation (tad_liste_points.c/creer_tableau_points)\n");
        free(tableau->tab);
        return NULL;
    }
    tableau->taille = taille_max;
    return tableau;
}

/**
 * @brief Ajout d'un point dans le tableau
 * 
 * @param tableau 
 * @param p 
 * @return tab_points 
 */
tab_points ajouter_point(tab_points tableau, point p){

    if (realloc_tab(tableau, tableau->taille+1) == NULL){
        printf("Erreur lors du realloc (tad_tableau_points.c/ajouter_point)\n");
    }

    tableau->tab[tableau->taille] = p;
    tableau->taille++;

    return tableau;
}

/**
 * @brief Suppression d'un point dans le tableau
 * 
 * @param tableau 
 * @param position pos du point a supprimer
 * @return tab_points 
 */
tab_points supprimer_point(tab_points tableau, int position){
    int i;
    for (i=position; i<tableau->taille-1; i++){
        tableau->tab[i] = tableau->tab[i+1];
    }

    tableau->taille--;
    
    return tableau;
}

/**
 * @brief Réallocation de la mémoire du tableau
 * 
 * @param tableau 
 * @param taille nouvelle taille du tableau
 * @return tab_points 
 */
tab_points realloc_tab(tab_points tableau, int taille){
    tableau->tab = (point *)realloc(tableau->tab, taille*sizeof(point));
    if (tableau->tab == NULL){
        printf("Erreur lors du realloc (tad_tableau_points.c/realloc_tab)\n");
        free(tableau->tab);
        return NULL;
    }
    return tableau;
}

/**
 * @brief Nettoyage du tableau
 * 
 * @param tableau 
 */
void nettoyer_tableau_points(tab_points tableau){
    int i=0;
    while (tableau->taille > 0){
        supprimer_point(tableau, i);
    }
}

/**
 * @brief Affichage du tableau
 * 
 * @param tableau 
 */
void afficher_tableau_points(tab_points tableau){
    int i;
    printf("Nb_points : %d Nb_dim : %d Nb_classes : %d\n", tableau->taille, 2, tableau->nb_classes);
    for (i=0; i<tableau->taille; i++){
        printf("Point %d : classe : %d, x : %f, y : %f\n", i, tableau->tab[i].classe, tableau->tab[i].x, tableau->tab[i].y);
    }
}

/**
 * @brief Vérification de la présence d'un point dans le tableau
 * 
 * @param tableau 
 * @param p point à verifier
 * @return int 
 */
int est_present_tab_points(tab_points tableau, point p){
    int i;
    for (i=0; i<tableau->taille; i++){
        if (tableau->tab[i].x == p.x && tableau->tab[i].y == p.y){
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Chargement d'un fichier de points dans un tableau
 * 
 * @param tableau 
 * @param nom_fichier nom du fichier que l'on veut charger dans le tableau
 * @return int 
 */
int chargement_fichier(tab_points tableau, char * nom_fichier){
    point p;
    int taille;
    int dim;
    int classe;
    FILE * f = fopen(nom_fichier, "r");

    if (f == NULL){
        printf("Erreur lors de l'ouverture du fichier (tad_liste_points.c/chargement_fichier)\n");
        return 0;
    }

    if (fscanf(f, "%d %d %d", &taille, &dim, &classe)!=3){
        printf("Erreur lors de la lecture du fichier (tad_liste_points.c/chargement_fichier)\n");
        return 0;
    }

    while (fscanf(f, "%d %f %f", &p.classe, &p.x, &p.y)!=EOF){
        ajouter_point(tableau, p);
    }
    tableau->nb_classes = classe;
    fclose(f);
    return 1;
}

/**
 * @brief Sauvegarde d'un tableau dans un fichier
 * 
 * @param tableau 
 * @param nom_fichier nom du fichier dans lequel on veut sauvegarder le tableau
 * @return int 
 */
int sauvegarde_fichier(tab_points tableau, char * nom_fichier){
    FILE * f = fopen(nom_fichier, "w");
    int i;

    if (f==NULL){
        printf("Erreur lors de l'ouverture du fichier (tad_liste_points.c/sauvegarde_fichier)\n");
        return 0;
    }

    if (tableau->taille == 0){
        printf("Erreur : tableau vide (tad_liste_points.c/sauvegarde_fichier)\n");
        return 0;
    }

    if (fprintf(f, "%d %d %d\n", tableau->taille, 2, tableau->nb_classes) < 0){
        printf("Erreur lors de l'écriture dans le fichier (tad_liste_points.c/sauvegarde_fichier)\n");
        return 0;
    }

    for (i=0; i<tableau->taille; i++){
        if (fprintf(f, "%d %f %f\n", tableau->tab[i].classe, tableau->tab[i].x, tableau->tab[i].y) < 0){
            printf("Erreur lors de l'écriture dans le fichier (tad_liste_points.c/sauvegarde_fichier)\n");
            return 0;
        }
    }

    fclose(f);
    return 1;
}

/**
 * @brief Génération d'un point aléatoire
 * 
 * @param classe 
 * @param x_min 
 * @param x_max 
 * @param y_min 
 * @param y_max 
 * @return point 
 */
point gen_point_aleatoire(int classe, int x_min, int x_max, int y_min, int y_max){
    point p;
    p.classe = classe;
    p.x = (float)rand()/(float)(RAND_MAX/(x_max-x_min)) + x_min;
    p.y = (float)rand()/(float)(RAND_MAX/(y_max-y_min)) + y_min;
    return p;
}

/**
 * @brief Libération de la mémoire du tableau
 * 
 * @param tableau 
 */
void liberation_tableau_points(tab_points tableau){
    if (tableau != NULL){
        free(tableau->tab);
        tableau->tab=NULL;
        free(tableau);
        tableau=NULL;
    }
}