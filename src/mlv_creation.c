/**
 * @file mlv_creation.c
  * @author mathevon/palisse
 * @brief mode creation mlv
 * @version 0.1
 * @date 2023-05-21
 */
#include "../headers/mlv_creation.h"

/**
 * @brief Creation d'un point
 * 
 * @param classe classe du nouveau point
 * @return point* 
 */
point * mlv_creer_point(int classe){
    int x,y;
    float coor_x, coor_y;
    point * p = malloc(sizeof(point));

    if (p == NULL){
        fprintf(stderr, "Erreur d'allocation mémoire mlv_creation.c/mlv_creer_point");
        free(p);
        exit(EXIT_FAILURE);
    }

    MLV_wait_mouse(&x, &y);

    if ((x>35 && x<865) && (y>35 && y<865)){
        coor_x = (((float)x-50)/400)-1;
        coor_y = (((float)y-50)/400)-1;

        p->x = coor_x;
        p->y = -coor_y;
        p->classe = classe;
        return p;

    }
    if ((x>880 && x<1280) && (y>700 && y<750)){
        p->x = 2; 
        p->y = 2;
        return p;
    }
    else {
        return NULL;
    }
}


/**
 * @brief Ajouter des points au tableau
 * 
 * @param tableau 
 * @param a 
 */
void mlv_ajouter_point(tab_points tableau, arbre_kd * a){
    point * p ;
    int classe;
    char * texte;
    MLV_draw_filled_rectangle(890, 760,300,50, MLV_COLOR_ANTIQUE_WHITE);
    MLV_draw_text(885, 770, "Click hors zone -> quit", MLV_COLOR_BLACK);
    MLV_draw_filled_rectangle(890, 700, 300, 50, MLV_COLOR_ANTIQUE_WHITE); /*effacer dernier point*/
    MLV_draw_text(890, 710, "Effacer dernier point", MLV_COLOR_BLACK);
    MLV_actualise_window();

    MLV_wait_input_box(700, 450, 300,100 , MLV_COLOR_WHITE, MLV_COLOR_ANTIQUE_WHITE, MLV_COLOR_BLACK, "Classe du point : ", &texte);
    classe = atoi(texte);

    while (classe > tableau->nb_classes){
        mlv_message("La classe doit être < nb_classes");
        MLV_wait_input_box(700, 450, 300,100 , MLV_COLOR_WHITE, MLV_COLOR_ANTIQUE_WHITE, MLV_COLOR_BLACK, "Classe du point : ", &texte);
        classe = atoi(texte);
    }
    free(texte);

    do{

        p = mlv_creer_point(classe);
        if (p == NULL){
            mlv_message("Fin du mode ajout");
        }
        
        else{
            if (p->x == 2 && p->y == 2){
                supprimer_point(tableau, tableau->taille-1);
                mlv_affichage_menu(2);
                MLV_draw_filled_rectangle(890, 760,350,50, MLV_COLOR_ANTIQUE_WHITE);
                MLV_draw_text(885, 770, "click hors zone -> quit", MLV_COLOR_BLACK);
                MLV_draw_filled_rectangle(890, 700, 350, 50, MLV_COLOR_ANTIQUE_WHITE); 
                MLV_draw_text(910, 710, "Effacer dernier point", MLV_COLOR_BLACK);
                mlv_affichage_points(tableau);
                free(p);
            }
            else {
                ajouter_point(tableau, *p);
		*a=inserer(*a, p);
                mlv_affichage_points(tableau);
                free(p);
            }
        }

    }while(p!=NULL);

}

/**
 * @brief Selection d'un point
 * 
 * @param tableau 
 * @return int 
 */
int selection_point(tab_points tableau){
    int x,y;
    int i;
    MLV_wait_mouse(&x, &y);
    if ((x>35 && x<865) && (y>35 && y<865)){
        for (i=0; i<tableau->taille; i++){
            if ((x>=(tableau->tab[i].x+1)*400+50) && (x<=(tableau->tab[i].x+1)*400+50+15) && (y>=(-tableau->tab[i].y+1)*400+50-7.5) && (y<=(-tableau->tab[i].y+1)*400+50+7.5)){
                MLV_draw_rectangle((tableau->tab[i].x+1)*400+50, (-tableau->tab[i].y+1)*400+50-7.5, 16, 16, MLV_COLOR_RED);
                return i;
            }
        }
    }

    return -1;
}

/**
 * @brief Suppression des points selectionnés
 * 
 * @param tableau 
 */
void mlv_supprimer_point(tab_points tableau){
  int i;
    int quit = 0;
    MLV_draw_filled_rectangle(880, 760,350,50, MLV_COLOR_ANTIQUE_WHITE);
    MLV_draw_text(885, 770, "Click hors zone -> quit", MLV_COLOR_BLACK);
    MLV_actualise_window();
    do{

        i = selection_point(tableau);
        if (i == -1){
            mlv_message("Suppression des points");
            quit = 1;
        }
        else {
	  if (i!=-1 && i!=-2){ 
	      supprimer_point(tableau, i);

	      mlv_affichage_points(tableau);
            }
        }

    }while(quit != 1);
}









