/**
 * @file kppv.c
 * @author mathevon/palisse
 * @brief Kppv mode tableau
 * @version 0.1
 * @date 2023-05-21
 * 
 */
#include "../headers/kppv.h"

/**
 * @brief Calcul de la distance euclidienne entre deux points
 * @param p1
 * @param p2
 * @return
*/
float distance_euclidienne(point p1, point p2){
    return sqrt(powf(p1.x - p2.x, 2) + powf(p1.y - p2.y, 2));
}

/**
 * @brief Tri a bulle du tableau
 * @param t tableau de points
 * @param p point selectionné
 */
void tri_points_distance (tab_points t, point p){
    int i,j;
    double time_spent = 0.0;
    clock_t begin, end;
    begin=clock();

    for (i=0; i <t->taille-1; i++){
        for (j=i+1; j<t->taille; j++){
            if (distance_euclidienne(t->tab[i], p) > distance_euclidienne(t->tab[j], p)){
                point tmp = t->tab[i];
                t->tab[i] = t->tab[j];
                t->tab[j] = tmp;
            }
        }
    }

    end=clock();
    time_spent+=(double)(end-begin) / CLOCKS_PER_SEC;
    printf("%f\n", time_spent);
    
    for (i=0; i < t->taille; i++){
        if (t->tab[i].x == p.x && t->tab[i].y == p.y){
            supprimer_point(t, i);
        }
    }
} 


/**
 * @brief Tri fusion du tableau fonction 1
 * 
 * @param t tableau de points
 * @param p point selectionné
 */
void tri_points_distance_fusion(tab_points t, point p) {
    int i;
    double time_spent = 0.0;
    clock_t begin, end;
    begin = clock();
    tri_fusion(t, p, 0, t->taille - 1);
    end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f\n", time_spent);
    for (i = 0; i < t->taille; i++) {
        if (t->tab[i].x == p.x && t->tab[i].y == p.y) {
            supprimer_point(t, i);
        }
    }
}

/**
 * @brief Tri fusion du tableau fonction 2
 * 
 * @param t tableau de points
 * @param p point selectionné
 * @param debut 
 * @param fin 
 */
void tri_fusion(tab_points t, point p, int debut, int fin) {
    if (debut < fin) {
        int milieu = (debut + fin) / 2;
        tri_fusion(t, p, debut, milieu);
        tri_fusion(t, p, milieu + 1, fin);
        fusionner(t, p, debut, milieu, fin);
    }
}

/**
 * @brief Tri fusion du tableau fonction 3
 * 
 * @param t tableau de points
 * @param p point selectionné
 * @param debut 
 * @param milieu 
 * @param fin 
 */
void fusionner(tab_points t, point p, int debut, int milieu, int fin) {
    int n1 = milieu - debut + 1;
    int n2 = fin - milieu;
    int i,j, k;
    point* gauche = (point*) malloc(n1 * sizeof(point));
    point* droite = (point*) malloc(n2 * sizeof(point));

    for (i = 0; i < n1; i++) {
        gauche[i] = t->tab[debut + i];
    }
    for (j = 0; j < n2; j++) {
        droite[j] = t->tab[milieu + 1 + j];
    }

    i = 0, j = 0, k = debut;
    while (i < n1 && j < n2) {
        if (distance_euclidienne(gauche[i], p) <= distance_euclidienne(droite[j], p)) {
            t->tab[k] = gauche[i];
            i++;
        } else {
            t->tab[k] = droite[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        t->tab[k] = gauche[i];
        i++;
        k++;
    }

    while (j < n2) {
        t->tab[k] = droite[j];
        j++;
        k++;
    }

    free(gauche);
    free(droite);
}


/**
 * @brief kppv
 * 
 * @param tableau tableau de points
 * @param tab_kppv tableau des kppv
 * @param p point selectionné
 * @param nb_kppv nb max de kppv
 */
void kppv(tab_points tableau, tab_points tab_kppv, point p, int nb_kppv){
    int i;
    nettoyer_tableau_points(tab_kppv);

    for (i=0; i<nb_kppv; i++){
        if (tableau->tab[i].x != p.x || tableau->tab[i].y != p.y){
            tab_kppv = ajouter_point(tab_kppv, tableau->tab[i]);
        }
    }
    
} 

/**
 * @brief Calcul de la classe du point
 * 
 * @param tab_kppv tableau des kppv
 * @return int 
 */
int classe_kppv(tab_points tab_kppv){
    int i, j, classe, nb_classe, nb_max = 0;
    int * tab_classe = malloc(sizeof(int) * tab_kppv->taille);

    if (tab_classe == NULL){
        printf("Malloc error kppv.c/classe_kppv\n");
        exit(1);
    }

    for (i=0; i<tab_kppv->taille; i++){
        tab_classe[i] = 0;
    }

    for (i=0; i<tab_kppv->taille; i++){
        classe = tab_kppv->tab[i].classe;
        nb_classe = 0;
        for (j=0; j<tab_kppv->taille; j++){
            if (tab_kppv->tab[j].classe == classe){
                nb_classe++;
            }
        }
        if (nb_classe > nb_max){
            nb_max = nb_classe;
            tab_classe[0] = classe;
        }
        else if (nb_classe == nb_max){
            tab_classe[i] = classe;
        }
    }
    classe = tab_classe[0];
    free(tab_classe);
    return classe;
}
