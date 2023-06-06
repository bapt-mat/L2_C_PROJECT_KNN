/**
 * @file mlv_arbre_kd.c
* @author mathevon/palisse
 * @brief fonctions mlv pour le mode arbre kd
 * @version 0.1
 * @date 2023-05-21
 */
#include "../headers/mlv_arbre_kd.h"

/**
 * @brief Reinitialisation de l'affichage
 * 
 * @param a 
 * @param liste liste des kppv
 * @param p point selectionné
 * @param nb_kppv nombre max de kppv
 */
void mlv_maj_affichage_arbre_kd(arbre_kd a, point * liste, point p, int nb_kppv){
    mlv_affichage_menu(4);
    mlv_dessin_point(p);
    mlv_affichage_points_arbre_kd(a, 0);
    mlv_affichage_points_kppv_liste(liste, nb_kppv, MLV_COLOR_RED);
    MLV_draw_filled_rectangle(900, 95, 300, 30, MLV_COLOR_ANTIQUE_WHITE); 
    MLV_draw_text(910, 95, "*Selection*", MLV_COLOR_BLACK);
}

/**
 * @brief Affichage de l'arbre (petit arbre seulement)
 * 
 * @param a 
 * @param x 
 * @param y 
 * @param distance_euclidienne 
 */
void afficher_arbre_graphique(arbre_kd a, int x, int y, int distance_euclidienne) {
    
    int x_gauche = x - distance_euclidienne;
    int x_droit = x + distance_euclidienne;
    int x_fils_gauche, y_fils_gauche, x_fils_droit, y_fils_droit;
    int y_fils = y + 100;
    int distance_fils = distance_euclidienne/2;
    char s[20];

    if (a == NULL) {
        return;
    }


    snprintf(s, 20, "%.4f | %.4f", a->p.x, a->p.y);

    MLV_draw_text(x-60, y-8, s, MLV_COLOR_WHITE, MLV_TEXT_CENTER);

    MLV_draw_rectangle(x-70, y-15, 170, 40, MLV_COLOR_WHITE);


    if (a->gauche != NULL) {
        x_fils_gauche = x_gauche - distance_fils;
        y_fils_gauche = y_fils;
        MLV_draw_line(x, y + 25, x_fils_gauche, y_fils_gauche - 25, MLV_COLOR_WHITE);
        afficher_arbre_graphique(a->gauche, x_fils_gauche, y_fils_gauche, distance_fils);
    }

    if (a->droite != NULL) {
        x_fils_droit = x_droit + distance_fils;
        y_fils_droit = y_fils;
        MLV_draw_line(x, y + 25, x_fils_droit, y_fils_droit - 25, MLV_COLOR_WHITE);
        afficher_arbre_graphique(a->droite, x_fils_droit, y_fils_droit, distance_fils);
    }

    MLV_actualise_window();
}

/**
 * @brief Affichage des points de l'arbre
 * 
 * @param arbre 
 * @param prof profondeur de l'arbre
 */
void mlv_affichage_points_arbre_kd(arbre_kd arbre, int prof){
    int rouge=50, vert=100, bleu=150;
    float coor_x, coor_y;
    if (arbre == NULL){
        return;
    }
    
    coor_x = ((arbre->p.x+1)*400)+50;
    coor_y = ((-arbre->p.y+1)*400)+50;

    if (arbre->p.classe % 2 != 0){
        MLV_draw_line(coor_x, coor_y, coor_x+15, coor_y, MLV_rgba(rouge * arbre->p.classe, vert * arbre->p.classe, bleu * arbre->p.classe, 255));
    }
    else {  
        MLV_draw_line(coor_x, coor_y, coor_x+15, coor_y, MLV_rgba(rouge * arbre->p.classe, vert * arbre->p.classe, bleu * arbre->p.classe, 255));
        MLV_draw_line(coor_x+7.5, coor_y-7.5, coor_x+7.5, coor_y+7.5, MLV_rgba(rouge * arbre->p.classe, vert * arbre->p.classe, bleu * arbre->p.classe, 255));
    }

    if (arbre->gauche != NULL){
        mlv_affichage_points_arbre_kd(arbre->gauche, prof+1);
    }
    if (arbre->droite != NULL){
        mlv_affichage_points_arbre_kd(arbre->droite, prof+1);
    }

}

/**
 * @brief Dessin des zones des points de l'arbre fonction recursive
 * 
 * @param arbre 
 * @param animation booleen pour dessiner avec animation ou non
 */
void mlv_dessin_zone_rec(arbre_kd arbre, int animation){

    if (arbre == NULL){
        return;
    }

    mlv_dessin_zone(arbre->zone_noeud, animation);

    mlv_dessin_zone_rec(arbre->gauche, animation);
    mlv_dessin_zone_rec(arbre->droite, animation);
}

/**
 * @brief Dessin des zones des points de l'arbre
 * 
 * @param z 
 * @param animation booleen pour dessiner avec animation ou non
 */
void mlv_dessin_zone(zone z, int animation){
    int i;
    float x_min, x_max, y_min, y_max;
    x_min = ((z.x_min+1)*400)+50;
    x_max = ((z.x_max+1)*400)+50;
    y_min = ((-z.y_min+1)*400)+50;
    y_max = ((-z.y_max+1)*400)+50;

    for (i=x_min; i<x_max; i+=15){
        MLV_draw_line(i, y_min, i+5, y_min, MLV_COLOR_WHITE);
        MLV_draw_line(i, y_max, i+5, y_max, MLV_COLOR_WHITE); 
        if (animation == 1){
            MLV_actualise_window();
            MLV_wait_milliseconds(1);
        }
    }
    
    for (i=y_max; i<y_min; i+=15){
        MLV_draw_line(x_min, i, x_min, i+5, MLV_COLOR_WHITE);
        MLV_draw_line(x_max, i, x_max, i+5, MLV_COLOR_WHITE);
        if (animation == 1){
            MLV_actualise_window();
            MLV_wait_milliseconds(1);
        }
    }

}

/**
 * @brief Dessin du voisinage du point
 * 
 * @param p point selectionné
 * @param liste liste des kppv
 * @param taille_liste taille de la liste
 */
void mlv_dessin_voisinage_arbre(point p, point * liste, int taille_liste){
    float max = d_max_liste(p, liste, taille_liste);
    MLV_draw_circle((p.x+1)*400+50+7.5, (-p.y+1)*400+50, max*400, MLV_COLOR_RED);
    MLV_actualise_window();
}

/**
 * @brief Affichage de la classe du point calculé en fct des classe de ses kppv
 * 
 * @param liste liste des kppv du point
 * @param p point selectionné
 * @param nb_kppv nb max de kppv
 */
void mlv_classe_kppv_arbre(point * liste, point p, int nb_kppv){
    int classe = classe_kppv_arbre(liste, nb_kppv);
    int rouge=50, vert=100, bleu=150;
    float coor_x, coor_y;

    coor_x = ((p.x+1)*400)+50;
    coor_y = ((-p.y+1)*400)+50;

    MLV_draw_filled_circle(coor_x+7.5, coor_y, 8, MLV_rgba(rouge * classe, vert * classe, bleu * classe, 255));

    MLV_actualise_window();
}

/**
 * @brief Affichage des points de la liste 
 * 
 * @param liste liste des kppvs
 * @param nb_kppv nb max de kppv
 * @param couleur 
 */
void mlv_affichage_points_kppv_liste(point * liste, int nb_kppv, MLV_Color couleur){
    int i;
    float coor_x, coor_y;
    for (i=1; i<=nb_kppv; i++){
        coor_x = ((liste[i].x+1)*400)+50;
        coor_y = ((-liste[i].y+1)*400)+50;

        if (liste[i].classe % 2 != 0){
            MLV_draw_line(coor_x, coor_y, coor_x+15, coor_y, couleur);
        }
        else {  
            MLV_draw_line(coor_x, coor_y, coor_x+15, coor_y, couleur);
            MLV_draw_line(coor_x+7.5, coor_y-7.5, coor_x+7.5, coor_y+7.5, couleur);
        }
    }
    MLV_actualise_window();
}

/**
 * @brief Selection du point pour le kppv
 * 
 * @param a 
 * @return point 
 */
point selection_point_kppv_arbre_kd(arbre_kd a){
    int x, y;
    float coor_x, coor_y;
    arbre_kd courant = a;
    point p;
    p.x = -2;
    p.y = -2;
    MLV_wait_mouse(&x, &y);
    if ((x>35 && x<865) && (y>35 && y<865)){

        while (courant != NULL){

            coor_x = ((courant->p.x+1)*400)+50;
            coor_y = ((-courant->p.y+1)*400)+50;

            if ((x>=coor_x && x<=coor_x+15) && (y>=coor_y-7.5 && y<=coor_y+7.5)){
                p = courant->p;
                mlv_dessin_point(p);
                MLV_actualise_window();
                return p;
            }
            if (courant->prof % 2 == 0){
                if (x < coor_x){
                    courant = courant->gauche;
                }
                else {
                    courant = courant->droite;
                }
            }
            else {
                if (coor_y < y){
                    courant = courant->gauche;
                }
                else {
                    courant = courant->droite;
                }
            }
        }
    }
    return p;
}

/**
 * @brief Affichage du menu mode kppv arbre
 * 
 * @param a 
 */
void mlv_kppv_arbre_kd(arbre_kd a){
    int x, y, quitter=0;
    char * texte;
    int nb_kppv, i;
    point * liste = NULL;
    point p;
    p.x = -2;
    p.y = -2;

    MLV_draw_filled_rectangle(900, 95, 300, 30, MLV_COLOR_ANTIQUE_WHITE); 
    MLV_draw_text(910, 95, "*Selection*", MLV_COLOR_BLACK);
    MLV_actualise_window();

    MLV_wait_input_box(700, 450, 300,100 , MLV_COLOR_WHITE, MLV_COLOR_ANTIQUE_WHITE, MLV_COLOR_BLACK, "Valeur de K : ", &texte);
    nb_kppv = atoi(texte);

    do {
        p=selection_point_kppv_arbre_kd(a);

        if (p.x != -2 && p.y != -2){
            liste = rechercher(&a, p, nb_kppv);

            if (liste != NULL){
                mlv_affichage_points_kppv_liste(liste, nb_kppv, MLV_COLOR_RED);
            }
        }
        
    }while (p.x == -2 && p.y == -2);

    do{

        MLV_wait_mouse(&x, &y);

        if ((x>1350 && x<1550) && (y>110 && y<160)){
            quitter=1;
        }

        if ((x>480 && x<780) && (y>5 && y<35)){
            MLV_wait_input_box(700, 450, 300,100 , MLV_COLOR_WHITE, MLV_COLOR_ANTIQUE_WHITE, MLV_COLOR_BLACK, "Valeur de K : ", &texte);
            nb_kppv = atoi(texte);
            liste = rechercher(&a, p, nb_kppv);
            if (liste != NULL){
                mlv_maj_affichage_arbre_kd(a, liste, p, nb_kppv);
                mlv_affichage_points_kppv_liste(liste, nb_kppv, MLV_COLOR_RED);
            }
        }

        if ((x>1150 && x<1525) && (y>250 && y<280)){ 
            MLV_draw_filled_rectangle(0, 0, 1800, 1000, MLV_COLOR_BLACK);
            MLV_draw_text(10, 10, "Affichage de l'arbre pendant 5 secondes", MLV_COLOR_ANTIQUE_WHITE);
            afficher_arbre_graphique(a, 900, 50, 200);

            for (i=5; i>=0; i--){
                MLV_draw_text(20, 50, "%d", MLV_COLOR_ANTIQUE_WHITE, i);
                MLV_actualise_window();
                MLV_wait_seconds(1);
                MLV_draw_filled_rectangle(15, 45, 30, 30, MLV_COLOR_BLACK);
            }
            mlv_maj_affichage_arbre_kd(a, liste, p, nb_kppv);
        }

        if ((x>1150 && x<1335) && (y>300 && y<330)){ 
            mlv_dessin_zone_rec(a, 1);
        }

        if ((x>1340 && x<1525) && (y>300 && y<330)){ 
            mlv_dessin_zone_rec(a, 0);
            MLV_actualise_window();
        }

        if ((x>1150 && x<1525) && (y>350 && y<380)){ 
            mlv_maj_affichage_arbre_kd(a, liste, p, nb_kppv);
            mlv_dessin_voisinage_arbre(p, liste, nb_kppv);
        }

        if ((x>1150 && x<1525) && (y>400 && y<430)){ 
            mlv_affichage_points_arbre_kd(a,0);
            MLV_actualise_window();
        }
    
        if ((x>1150 && x<1525) && (y>450 && y<480)){ 
            mlv_classe_kppv_arbre(liste, p, nb_kppv);
            MLV_actualise_window();
        }
   
        if ((x>1150 && x<1525) && (y>500 && y<530)){ 
            mlv_maj_affichage_arbre_kd(a, liste, p, nb_kppv);
            MLV_actualise_window();
        } 


    }while(quitter == 0);
}
