/**
 * @file tad_arbre_kd.c
 * @author mathevon/palisse
 * @brief TAD arbre kd
 * @version 0.1
 * @date 2023-05-21
 */
#include "../headers/tad_arbre_kd.h"

/**
 * @brief Vérifie si un arbre est vide
 * 
 * @param a 
 * @return int 
 */
int est_vide_arbre_kd(arbre_kd * a) {
    if (a == NULL) {
        return 1;
    }
    return 0;
}

/**
 * @brief Créer un arbre kd vide
 * 
 * @return arbre_kd 
 */
arbre_kd creer_arbre_kd_vide(){
    return NULL;
}

/**
 * @brief Affiche l'arbre kd dans le terminal
 * 
 * @param a 
 */
void afficher_arbre_kd(arbre_kd a) {
    if (a == NULL) {
        return;
    }
    printf("%f, %f", a->p.x, a->p.y);
    if (a->gauche != NULL || a->droite != NULL) {
        printf(" -> ");
        if (a->gauche != NULL) {
            printf("%f, %f |", a->gauche->p.x, a->gauche->p.y);
        } else {
            printf("NULL");
        }
        if (a->droite != NULL) {
            printf(" | %f, %f", a->droite->p.x, a->droite->p.y);
        } else {
            printf("NULL");
        }
        printf("\n");
        afficher_arbre_kd(a->gauche);
        afficher_arbre_kd(a->droite);
    } else {
        printf("\n");
    }
}

/**
 * @brief Créer une zone pour un point
 * 
 * @param x_max 
 * @param x_min 
 * @param y_max 
 * @param y_min 
 * @return zone 
 */
zone creer_zone(float x_max, float x_min, float y_max, float y_min){
    zone z;
    z.x_max = x_max;
    z.x_min = x_min;
    z.y_max = y_max;
    z.y_min = y_min;
    return z;
}

/**
 * @brief Insertion d'un point dans l'arbre kd
 * 
 * @param a 
 * @param p point a insérer dans l'arbre
 * @param z 
 */
void inserer_aux(arbre_kd a, point * p, zone z){
    if (a->prof % 2 == 0) {
        if (p->x < a->p.x) {
            if (a->gauche == NULL) {
                a->gauche = (arbre_kd)malloc(sizeof(noeud));
                a->gauche->p = *p;
		a->gauche->prof = a->prof+1;
                a->gauche->gauche = NULL;
                a->gauche->droite = NULL;
                a->gauche->zone_noeud = creer_zone(a->p.x, z.x_min, z.y_max, z.y_min);

            } else {
                inserer_aux(a->gauche, p, a->gauche->zone_noeud);
            }
        } else {
            if (a->droite == NULL) {
                a->droite = (arbre_kd)malloc(sizeof(noeud));
                a->droite->p = *p;
		a->droite->prof = a->prof+1;
                a->droite->gauche = NULL;
                a->droite->droite = NULL;
                a->droite->zone_noeud = creer_zone(z.x_max, a->p.x, z.y_max, z.y_min);

            } else {
                inserer_aux(a->droite, p, a->droite->zone_noeud);
            }
        }
    } else if (p->y < a->p.y) {
        
            if (a->gauche == NULL) {
                a->gauche = (arbre_kd)malloc(sizeof(noeud));
                a->gauche->p = *p;
		a->gauche->prof = a->prof+1;
                a->gauche->gauche = NULL;
                a->gauche->droite = NULL;
                a->gauche->zone_noeud = creer_zone(z.x_max, z.x_min, a->p.y, z.y_min);

            } else {
	      inserer_aux(a->gauche, p, a->gauche->zone_noeud);
            }
      } else {
          if (a->droite == NULL) {
                a->droite = (arbre_kd)malloc(sizeof(noeud));
                a->droite->p = *p;
		a->droite->prof = a->prof+1;
                a->droite->gauche = NULL;
                a->droite->droite = NULL;
                a->droite->zone_noeud = creer_zone(z.x_max, z.x_min, z.y_max, a->p.y);

            } else {
                inserer_aux(a->droite, p, a->droite->zone_noeud);
            }
        }
    }

/**
 * @brief Insertion d'un point dans l'arbre kd
 * 
 * @param a 
 * @param p point a inserer dans l'arbre
 * @return arbre_kd 
 */
arbre_kd inserer(arbre_kd a, point *p) {
    if (a == NULL) {
        a = (arbre_kd)malloc(sizeof(noeud));
	a->prof=0;
        a->p = *p;
        a->gauche = NULL;
        a->droite = NULL;
        a->zone_noeud = creer_zone(1, -1, 1, -1);

    } else {
        inserer_aux(a, p, a->zone_noeud);
    }
    return a;
}


/**
 * @brief Vérifie si un arbre est une feuille
 * 
 * @param a 
 * @return int 
 */
int est_feuille (arbre_kd a){
  if(a->gauche == NULL && a->droite == NULL)
    return 1;
  return 0;
}

/**
 * @brief Supprime une feuille
 * 
 * @param a 
 * @return arbre_kd 
 */
arbre_kd supprimer_feuille (arbre_kd a){
  free(a);
  a=NULL;
  return a;
}

/**
 * @brief Vide un arbre kd
 * 
 * @param a 
 * @return arbre_kd 
 */
arbre_kd vider_arbre (arbre_kd a){
  if( est_feuille(a) ){
    return supprimer_feuille(a);
  }
  else {
    if(a->gauche!=NULL){
      a->gauche=vider_arbre(a->gauche);
    }
    if(a->droite!=NULL){
      a->droite=vider_arbre(a->droite);
    }
  }

    return supprimer_feuille(a);
}

/**
 * @brief Met a jour l'arbre kd pour qu'il corresponde au tableau actuel
 * 
 * @param tableau 
 * @param a 
 * @return arbre_kd 
 */
arbre_kd orchestre_suppression (tab_points tableau, arbre_kd a){
    int i;
    a=vider_arbre(a);
    for (i=0;i<tableau->taille;i++){
        a = inserer(a, &tableau->tab[i]);
    }
    return a;
}

/**
 * @brief Charge un fichier de points dans un arbre kd
 * 
 * @param a 
 * @param nom_fichier nom du fichier a charger dans l'arbre
 * @return int 
 */
int chargement_fichier_arbre_kd(arbre_kd * a, char * nom_fichier){
    point p;
    int taille;
    int dim;
    int classe;
    FILE * f = fopen(nom_fichier, "r");

    if (f == NULL){
        printf("Erreur lors de l'ouverture du fichier (tad_arbre_kd.c/chargement_fichier_arbre_kd)\n");
        return 0;
    }

    if (fscanf(f, "%d %d %d", &taille, &dim, &classe)!=3){
        printf("Erreur lors de la lecture du fichier (tad_arbre_kd.c/chargement_fichier_arbre_kd)\n");
        return 0;
    }

    while (fscanf(f, "%d %f %f", &p.classe, &p.x, &p.y)!=EOF){
        *a = inserer(*a, &p);
    }
    fclose(f);
    return 1;
}

/**
 * @brief Verifie si un point est dans une zone
 * 
 * @param p point a verifier
 * @param z_tmp 
 * @return int 
 */
int est_dans_zone(point p, zone z_tmp){
    if (p.x >= z_tmp.x_min && p.x <= z_tmp.x_max && p.y >= z_tmp.y_min && p.y <= z_tmp.y_max){
        return 1;
    }
    return 0;
}

/**
 * @brief Met a jour la liste acutel des kppv
 * 
 * @param p le point a ajouter/verifier
 * @param liste liste contenant les kppv actuels
 * @param nb_kppv le nombre kppv max
 * @param taille_liste la taille actuelle de la liste
 * @return point* 
 */
point * maj_liste(point * p, point * liste, int nb_kppv, int * taille_liste){
    float d1, d2, d_max=0;
    int i, i_max=0;
    point p_kppv = liste[0];

    if (*taille_liste <= nb_kppv && liste[0].x != p->x && liste[0].y != p->y){
        if (liste == NULL){
            printf("Erreur lors de l'allocation memoire (tad_arbre_kd.c/maj_liste)\n");
            return NULL;
        }
        liste[*taille_liste] = *p;
        (*taille_liste)++;
        return liste;
    }

    d1 = distance_euclidienne(p_kppv, *p);
    
    /*recherche distance max de la liste*/
    for (i=1; i<*taille_liste; i++){
        d2 = distance_euclidienne(p_kppv, liste[i]);
        if (d2 > d_max){
            d_max = d2;
            i_max = i;
        }
    }

    if (d1 < d_max && liste[0].x != p->x && liste[0].y != p->y){
        liste[i_max] = *p;
    }

    return liste;
}

/**
 * @brief Distance max entre un point et le point le plus éloigné de la liste
 * 
 * @param p point recherché
 * @param liste liste des points kppv actuels
 * @param taille_liste taille de la liste
 * @return float 
 */
float d_max_liste(point p, point * liste, int taille_liste){
    float d_max = distance_euclidienne(p, liste[1]);
    float d_tmp;
    int i;

    for (i=1; i<taille_liste; i++){
        d_tmp = distance_euclidienne(p, liste[i]);
        if (d_tmp > d_max){
            d_max = d_tmp;
        }
    }
    return d_max;
}


/**
 * @brief Trouve le point le plus proche de p et appartenant a la zone z_tmp
 * 
 * @param p 
 * @param z_tmp 
 * @return point 
 */
point point_proche_dans_zone(point * p, zone z_tmp){
    point * res;
    res = (point*)malloc(sizeof(point));
    if (res == NULL){
        printf("Erreur lors de l'allocation memoire (tad_arbre_kd.c/point_proche_dans_zone)\n");
        exit(1);
    }
    /*8 cas autour du point p*/
    if (p->x < z_tmp.x_min && p->y < z_tmp.y_min){
        res->x = z_tmp.x_min;
        res->y = z_tmp.y_min;
    } else if (p->x < z_tmp.x_min && p->y > z_tmp.y_max){
        res->x = z_tmp.x_min;
        res->y = z_tmp.y_max;
    } else if (p->x > z_tmp.x_max && p->y < z_tmp.y_min){
        res->x = z_tmp.x_max;
        res->y = z_tmp.y_min;
    } else if (p->x > z_tmp.x_max && p->y > z_tmp.y_max){
        res->x = z_tmp.x_max;
        res->y = z_tmp.y_max;
    } else if (p->x < z_tmp.x_min){
        res->x = z_tmp.x_min;
        res->y = p->y;
    } else if (p->x > z_tmp.x_max){
        res->x = z_tmp.x_max;
        res->y = p->y;
    } else if (p->y < z_tmp.y_min){
        res->x = p->x;
        res->y = z_tmp.y_min;
    } else if (p->y > z_tmp.y_max){
        res->x = p->x;
        res->y = z_tmp.y_max;
    } else {
        res->x = p->x;
        res->y = p->y;
    }
    
    return *res;
}

/**
 * @brief Recherche des kppv dans l'arbre kd
 * 
 * @param a 
 * @param p 
 * @param nb_kppv nombre max de kppv
 * @return point* 
 */
point* rechercher(arbre_kd * a, point p, int nb_kppv) {
    point* liste_kppv = (point*)malloc((nb_kppv+1) * sizeof(point));
    int * taille_liste = (int*)malloc((nb_kppv+1) * sizeof(int));
    double time_spent = 0.0;
    clock_t begin, end;
    *taille_liste = 1;
    if (liste_kppv == NULL) {
        printf("Erreur lors de l'allocation memoire (recherche_kppv)\n");
        return NULL;
    }
    liste_kppv[0] = p;
    begin = clock();
    recherche_rec(a, p, nb_kppv, &liste_kppv, taille_liste);
    end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f\n", time_spent);

    return liste_kppv;
}

/**
 * @brief Recherche des kppv dans l'arbre kd fonction recursive
 * 
 * @param a 
 * @param p 
 * @param nb_kppv nb max de kppv
 * @param liste_kppv liste actuel des kppv
 * @param taille_liste taille actuel de la liste
 */
void recherche_rec(arbre_kd * a, point p, int nb_kppv, point** liste_kppv, int * taille_liste) {
    float d_max, d_tmp, d_proche_droite, d_proche_gauche;
    zone z_tmp, z_proche_droite, z_proche_gauche;
    point p_tmp, p_proche_droite, p_proche_gauche;

    
    if (*a == NULL) {
        return;
    }

    *liste_kppv = maj_liste(&((*a)->p), *liste_kppv, nb_kppv, taille_liste);

    if ((*a)->gauche == NULL && (*a)->droite == NULL) {
        return;
    }
    
    if ((*a)->gauche != NULL && est_dans_zone(p, (*a)->gauche->zone_noeud)) {
        recherche_rec(&((*a)->gauche), p, nb_kppv, liste_kppv, taille_liste);
        if ((*a)->droite != NULL){
            z_proche_droite = (*a)->droite->zone_noeud;
            p_proche_droite = point_proche_dans_zone(&p, z_proche_droite);
            d_proche_droite = distance_euclidienne(p, p_proche_droite);

            d_max = d_max_liste(p, *liste_kppv, *taille_liste);

            if (d_proche_droite < d_max){
                recherche_rec(&((*a)->droite), p, nb_kppv, liste_kppv, taille_liste);
            }
        }
        else{
            return;
        }
    }
    
    else if ((*a)->droite != NULL && est_dans_zone(p, (*a)->droite->zone_noeud)) {
        recherche_rec(&((*a)->droite), p, nb_kppv, liste_kppv, taille_liste);
        if ((*a)->gauche != NULL){
            z_proche_gauche = (*a)->gauche->zone_noeud;
            p_proche_gauche = point_proche_dans_zone(&p, z_proche_gauche);
            d_proche_gauche = distance_euclidienne(p, p_proche_gauche);

            d_max = d_max_liste(p, *liste_kppv, *taille_liste);

            if (d_proche_gauche < d_max){
                recherche_rec(&((*a)->gauche), p, nb_kppv, liste_kppv, taille_liste);
            }
        }
        else{
            return;
        }               
    }

    else if ((*a)->droite != NULL && (*a)->gauche != NULL && !est_dans_zone(p, (*a)->droite->zone_noeud) && !est_dans_zone(p, (*a)->gauche->zone_noeud)) {
        z_proche_droite = (*a)->droite->zone_noeud;
        p_proche_droite = point_proche_dans_zone(&p, z_proche_droite);
        d_proche_droite = distance_euclidienne(p, p_proche_droite);

        z_proche_gauche = (*a)->gauche->zone_noeud;
        p_proche_gauche = point_proche_dans_zone(&p, z_proche_gauche);
        d_proche_gauche = distance_euclidienne(p, p_proche_gauche);

        d_max = d_max_liste(p, *liste_kppv, *taille_liste);

        if (d_proche_droite < d_max && d_proche_gauche < d_max){
            recherche_rec(&((*a)->droite), p, nb_kppv, liste_kppv, taille_liste);
            recherche_rec(&((*a)->gauche), p, nb_kppv, liste_kppv, taille_liste);
        }
        else if (d_proche_droite < d_max){
            recherche_rec(&((*a)->droite), p, nb_kppv, liste_kppv, taille_liste);
        }
        else if (d_proche_gauche < d_max){
            recherche_rec(&((*a)->gauche), p, nb_kppv, liste_kppv, taille_liste);
        }
    }

    else if ((*a)->droite != NULL){
        z_tmp = (*a)->droite->zone_noeud;
        p_tmp = point_proche_dans_zone(&p, z_tmp);
        d_max = d_max_liste(p, *liste_kppv, *taille_liste);
        d_tmp = distance_euclidienne(p, p_tmp);
        if (d_tmp < d_max) {
            recherche_rec(&((*a)->droite), p, nb_kppv, liste_kppv, taille_liste);
        }
    }
    
    else if ((*a)->gauche != NULL){
        z_tmp = (*a)->gauche->zone_noeud;
        p_tmp = point_proche_dans_zone(&p, z_tmp);
        d_max = d_max_liste(p, *liste_kppv, *taille_liste);
        d_tmp = distance_euclidienne(p, p_tmp);
        if (d_tmp < d_max) {
            recherche_rec(&((*a)->gauche), p, nb_kppv, liste_kppv, taille_liste);
        }
    }

}



/**
 * @brief Calcul de la classe en fonction des kppv
 * 
 * @param liste liste des kppv
 * @param nb_kppv nb max de kppv
 * @return int 
 */
int classe_kppv_arbre(point *liste, int nb_kppv){
    int i, j, classe, nb_classe, nb_max = 0;
    int * tab_classe = malloc(sizeof(int) * nb_kppv);

    if (tab_classe == NULL){
        printf("Malloc error kppv.c/classe_kppv\n");
        exit(1);
    }

    for (i=0; i<nb_kppv; i++){
        tab_classe[i] = 0;
    }

    for (i=0; i<nb_kppv; i++){
        classe = liste[i].classe;
        nb_classe = 0;
        for (j=0; j<nb_kppv; j++){
            if (liste[j].classe == classe){
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
