/**
 * @file mlv_kppv.c
 * @author mathevon/palisse
 * @brief Fonctions mlv mode tableau kppv
 * @version 0.1
 * @date 2023-05-21
 */
#include "../headers/mlv_kppv.h"

/**
 * @brief Reinitialisation de l'affichage
 * 
 * @param tableau tableau des points
 * @param tab_kppv tableau des kppv
 * @param p 
 */
void mlv_maj_affichage(tab_points tableau, tab_points tab_kppv, point p){
    mlv_affichage_menu(3);
    mlv_dessin_point(p);
    mlv_affichage_points(tableau);
    mlv_affichage_points_kppv(tab_kppv, MLV_COLOR_YELLOW);
    MLV_draw_filled_rectangle(900, 95, 300, 30, MLV_COLOR_ANTIQUE_WHITE); 
    MLV_draw_text(910, 95, "*Selection*", MLV_COLOR_BLACK);
}

/**
 * @brief Selection du point 
 * 
 * @param tableau 
 * @return int 
 */
int selection_point_kppv(tab_points tableau){
    int x,y;
    float coor_x, coor_y;
    int i;
    MLV_wait_mouse(&x, &y);
    if ((x>35 && x<865) && (y>35 && y<865)){
        for (i=0; i<tableau->taille; i++){
            coor_x = (tableau->tab[i].x+1)*400+50;
            coor_y = (-tableau->tab[i].y+1)*400+50;
            if ((x>=coor_x && x<=coor_x+15) && (y>=coor_y-7.5 && y<=coor_y+7.5)){
                mlv_dessin_point(tableau->tab[i]);
                MLV_actualise_window();
                return i;
            }
        }
    }

    return -1;
}

/**
 * @brief Mise en évidence du point selectionné
 * 
 * @param p point selectionné
 */
void mlv_dessin_point(point p){

    float coor_x, coor_y;
    coor_x = (p.x+1)*400+50;
    coor_y = (-p.y+1)*400+50;
    if (p.classe %2 == 0){
        MLV_draw_line(coor_x, coor_y-0.5, coor_x+15, coor_y-0.5, MLV_COLOR_WHITE);
        MLV_draw_line(coor_x+7.5, coor_y-7.5, coor_x+7.5, coor_y+7.5, MLV_COLOR_WHITE);

        MLV_draw_line(coor_x, coor_y, coor_x+15, coor_y, MLV_COLOR_WHITE);
        MLV_draw_line(coor_x+7, coor_y-7.5, coor_x+7, coor_y+7.5, MLV_COLOR_WHITE);

        MLV_draw_line(coor_x, coor_y+0.5, coor_x+15, coor_y+0.5, MLV_COLOR_WHITE);
        MLV_draw_line(coor_x+8, coor_y-7.5, coor_x+8, coor_y+7.5, MLV_COLOR_WHITE);

    }
    else {
                
        MLV_draw_line(coor_x, coor_y-0.5, coor_x+15, coor_y-0.5, MLV_COLOR_WHITE);
        MLV_draw_line(coor_x, coor_y, coor_x+15, coor_y, MLV_COLOR_WHITE);
        MLV_draw_line(coor_x, coor_y+0.5, coor_x+15, coor_y+0.5, MLV_COLOR_WHITE);
        
    }

}

/**
 * @brief Dessin du voisinage du point
 * 
 * @param tab_kppv 
 * @param p 
 */
void mlv_dessin_voisinage(tab_points tab_kppv, point p){
    float max = distance_euclidienne(tab_kppv->tab[tab_kppv->taille-1], p);
    MLV_draw_circle((p.x+1)*400+50+7.5, (-p.y+1)*400+50, max*400, MLV_COLOR_YELLOW1);
    MLV_actualise_window();
}

/**
 * @brief Affichage de la classe du point calculé en fct des classe de ses kppv
 * 
 * @param tab_kppv tableau des kppv
 * @param p point selectionné
 */
void mlv_classe_kppv(tab_points tab_kppv, point p){
    int classe = classe_kppv(tab_kppv);
    int rouge=50, vert=100, bleu=150;
    float coor_x, coor_y;

    coor_x = ((p.x+1)*400)+50;
    coor_y = ((-p.y+1)*400)+50;

    MLV_draw_filled_circle(coor_x+7.5, coor_y, 8, MLV_rgba(rouge * classe, vert * classe, bleu * classe, 255));

    MLV_actualise_window();
}

/**
 * @brief Fonction general mode kppv tableau
 * 
 * @param tableau 
 */
void mlv_kppv(tab_points tableau){
    int x, y, quitter=0, i=-1;
    char * texte;
    int nb_kppv;
    tab_points tab_kppv = creer_tableau_points(0);
    point p;

    MLV_draw_filled_rectangle(900, 95, 300, 30, MLV_COLOR_ANTIQUE_WHITE); 
    MLV_draw_text(910, 95, "*Selection*", MLV_COLOR_BLACK);
    MLV_actualise_window();

    MLV_wait_input_box(700, 450, 300,100 , MLV_COLOR_WHITE, MLV_COLOR_ANTIQUE_WHITE, MLV_COLOR_BLACK, "Valeur de K : ", &texte);
    nb_kppv = atoi(texte);

    do {

        i = selection_point_kppv(tableau);
        p=tableau->tab[i];
        tri_points_distance(tableau, p);

        if (i != -1){
            kppv(tableau, tab_kppv, p, nb_kppv);
            mlv_affichage_points_kppv(tab_kppv, MLV_COLOR_YELLOW);

        }

    }while (i == -1);

    do{

        MLV_wait_mouse(&x, &y);

        if ((x>1350 && x<1550) && (y>110 && y<160)){
            quitter=1;
        }

        if ((x>480 && x<780) && (y>5 && y<35)){
            MLV_wait_input_box(700, 450, 300,100 , MLV_COLOR_WHITE, MLV_COLOR_ANTIQUE_WHITE, MLV_COLOR_BLACK, "Valeur de K : ", &texte);
            nb_kppv = atoi(texte);
            kppv(tableau, tab_kppv, p, nb_kppv);
            mlv_maj_affichage(tableau, tab_kppv, p);
        }

        if ((x>1150 && x<1525) && (y>350 && y<380)){ /*dessin du voisinage*/
            mlv_maj_affichage(tableau, tab_kppv, p);
            mlv_dessin_voisinage(tab_kppv, p);
        }

        if ((x>1150 && x<1525) && (y>400 && y<430)){ /*affichage couleur classe pts kppv*/
            mlv_affichage_points(tab_kppv);
            MLV_actualise_window();
        }

        if ((x>1150 && x<1525) && (y>450 && y<480)){ /*prise de décision*/
            mlv_classe_kppv(tab_kppv, p);
            MLV_actualise_window();
        }

        if ((x>1150 && x<1525) && (y>500 && y<530)){ /*effacer l'affichage*/
            mlv_maj_affichage(tableau, tab_kppv, p);
            MLV_actualise_window();
        }


    }while(quitter == 0);
    ajouter_point(tableau, p);
    liberation_tableau_points(tab_kppv);
    
}

/**
 * @brief Création d'un nouveau point pour le mode kppv tableau
 * 
 * @param tableau 
 * @return point* 
 */
point * mlv_creer_point_kppv(tab_points tableau){
    int x,y;
    float coor_x, coor_y;
    int classe, nb_kppv;
    char * texte;
    tab_points tab_kppv = creer_tableau_points(0);
    point * p = malloc(sizeof(point));


    if (p == NULL){
        fprintf(stderr, "Erreur d'allocation mémoire mlv_creation.c/mlv_creer_point");
        free(p);
        exit(EXIT_FAILURE);
    }

    MLV_wait_input_box(700, 450, 200,100 , MLV_COLOR_WHITE, MLV_COLOR_ANTIQUE_WHITE, MLV_COLOR_BLACK, "Valeur de K : ", &texte);
    nb_kppv = atoi(texte);

    MLV_wait_mouse(&x, &y);

    if ((x>35 && x<865) && (y>35 && y<865)){
        coor_x = (((float)x-50)/400)-1;
        coor_y = (((float)y-50)/400)-1;

        p->x = coor_x;
        p->y = -coor_y;

        tri_points_distance(tableau, *p);
        kppv(tableau, tab_kppv, *p, nb_kppv);
        classe = classe_kppv(tab_kppv);
        p->classe = classe;
        free(texte);
        return p;

    }
    else {
        free(texte);
        free(p);
        return NULL;
    }
}

/**
 * @brief Ajout d'un point dans le tableau et dans l'arbre kd et calcul de la classe en fct des kppv
 * 
 * @param tableau 
 * @param a 
 */
void mlv_ajouter_point_kppv(tab_points tableau, arbre_kd * a){
    point * p ;
    MLV_draw_filled_rectangle(880, 760,350,50, MLV_COLOR_ANTIQUE_WHITE);
    MLV_draw_text(890, 770, "Click hors zone -> quit", MLV_COLOR_BLACK);
    MLV_actualise_window();

    p = mlv_creer_point_kppv(tableau);

    if (p == NULL){
        mlv_message("Fin du mode ajout");
    }
    else {
        ajouter_point(tableau, *p);
	    *a=inserer(*a, p);
        mlv_affichage_points(tableau);
        free(p);
    }


}
