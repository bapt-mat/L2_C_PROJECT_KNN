/**
 * @file mlv_interface.c
  * @author mathevon/palisse
 * @brief gestion de l'interface mlv
 * @version 0.1
 * @date 2023-05-21
 */
#include "../headers/mlv_interface.h"


/**
 * @brief Affichage général de la fenêtre
 * 
 * @param mode 
 */
void mlv_affichage_menu(int mode){
    MLV_clear_window(MLV_COLOR_BLACK);

    MLV_draw_rectangle(45,40,825,825, MLV_COLOR_WHITE); /*On considère que la zone de dessin des points est entre x : 50+800 y : 150+800*/
    /*Mais on agrandit les lignes du carrés pour que les points n'apparaissent pas sur les lignes de ce dernier*/
    
    /*on trace une ligne au milieu de la zone pour faire joli*/
    MLV_draw_line(45, 452, 868, 452, MLV_COLOR_WHITE);
    MLV_draw_text(875,435, "1", MLV_COLOR_WHITE);
    MLV_draw_text(20, 435, "-1", MLV_COLOR_WHITE);
    MLV_draw_line(457, 40, 457, 863, MLV_COLOR_WHITE);
    MLV_draw_text(452, 10, "1", MLV_COLOR_WHITE);
    MLV_draw_text(448, 865, "-1", MLV_COLOR_WHITE);


    MLV_draw_filled_rectangle(1350,50,200,50, MLV_COLOR_ANTIQUE_WHITE); /*quitter*/
    MLV_draw_text(1360, 60, "Quitter", MLV_COLOR_BLACK);

    MLV_draw_filled_rectangle(35, 5, 400, 30, MLV_COLOR_ANTIQUE_WHITE); /*creation - KPPV*/
    MLV_draw_filled_rectangle(1240, 760, 350, 50, MLV_COLOR_ANTIQUE_WHITE); /*chargement_donnees*/
    MLV_draw_filled_rectangle(1240,820,350,50, MLV_COLOR_ANTIQUE_WHITE); /*sauvegarde_donnees*/
    MLV_draw_filled_rectangle(1240, 700, 350, 50, MLV_COLOR_ANTIQUE_WHITE); /*creation fichier aleatoire*/
    MLV_draw_filled_rectangle(880, 760,350,50, MLV_COLOR_ANTIQUE_WHITE); /*Ajouter des points*/
    MLV_draw_filled_rectangle(880, 820,350,50, MLV_COLOR_ANTIQUE_WHITE); /*Supprimer des points*/
    MLV_draw_filled_rectangle(880, 700, 350, 50, MLV_COLOR_ANTIQUE_WHITE); /*effacer dernier point*/


    if (mode == 2){
        MLV_draw_text(45, 5, "Mode création -> click pour changer", MLV_COLOR_BLACK);
        MLV_draw_text(1250, 770, "Charger des données (fichier)", MLV_COLOR_BLACK);
        MLV_draw_text(1250, 830, "Sauvegarder les données", MLV_COLOR_BLACK);
        MLV_draw_text(1250, 710, "Créer un fichier aléatoire", MLV_COLOR_BLACK);
        MLV_draw_text(890, 770, "Ajouter des point", MLV_COLOR_BLACK);
        MLV_draw_text(890, 830, "Supprimer des points", MLV_COLOR_BLACK);
        MLV_draw_text(890, 710, "Effacer dernier point", MLV_COLOR_GREY);
        MLV_draw_filled_rectangle(1350,110,200,50, MLV_COLOR_ANTIQUE_WHITE); /*reinitialiser*/
        MLV_draw_text(1360, 120, "Réinitialiser", MLV_COLOR_BLACK);
    }
    else if (mode == 3){
        MLV_draw_text(800, 5, "MODE TABLEAU", MLV_COLOR_ANTIQUE_WHITE);
        MLV_draw_text(45, 5, "Mode KPPV -> click pour changer", MLV_COLOR_BLACK);
        MLV_draw_text(1250, 770, "Charger des données (fichier)", MLV_COLOR_GREY);
        MLV_draw_text(1250, 830, "Sauvegarder les données", MLV_COLOR_GREY);
        MLV_draw_text(1250, 710, "Créer un fichier aléatoire", MLV_COLOR_GREY);
        MLV_draw_text(890, 770, "Ajouter un point (calcul auto kppv)", MLV_COLOR_BLACK);
        MLV_draw_text(890, 830, "Supprimer des points", MLV_COLOR_GREY);
        MLV_draw_filled_rectangle(480, 5, 300, 30, MLV_COLOR_ANTIQUE_WHITE); /*Valeur de K*/
        MLV_draw_text(490, 5, "Changer la valeur de K", MLV_COLOR_BLACK);
        MLV_draw_filled_rectangle(1100, 300, 450, 250, MLV_COLOR_ANTIQUE_WHITE); /*Options d'affichage*/
        MLV_draw_text(1110, 310, "Options d'affichage", MLV_COLOR_BLACK);
        MLV_draw_filled_rectangle(1150, 350, 375, 30, MLV_COLOR_BLACK); /*dessin du voisinage*/ 
        MLV_draw_text(1160, 350, "Dessin du voisinage", MLV_COLOR_ANTIQUE_WHITE);
        MLV_draw_filled_rectangle(1150, 400, 375, 30, MLV_COLOR_BLACK); /*couleur en fct de la classe*/
        MLV_draw_text(1160, 400, "Couleur selon la classe", MLV_COLOR_ANTIQUE_WHITE);
        MLV_draw_filled_rectangle(1150, 450, 375, 30, MLV_COLOR_BLACK); /*prise de décision*/
        MLV_draw_text(1160, 450, "Prise de décision", MLV_COLOR_ANTIQUE_WHITE);
        MLV_draw_filled_rectangle(1150, 500, 375, 30, MLV_COLOR_BLACK); /*effacer l'affichage*/
        MLV_draw_text(1160, 500, "Effacer l'affichage", MLV_COLOR_ANTIQUE_WHITE);
        MLV_draw_filled_rectangle(1100, 600, 450, 50, MLV_COLOR_ANTIQUE_WHITE); /*mode arbre kd*/
        MLV_draw_filled_rectangle(1150, 610, 375, 30, MLV_COLOR_BLACK); /*mode arbre kd*/
        MLV_draw_text(1160, 610, "Passer en mode arbre KD", MLV_COLOR_ANTIQUE_WHITE);
        MLV_draw_filled_rectangle(900, 95, 300, 30, MLV_COLOR_ANTIQUE_WHITE); /*Selection d'un point*/
        MLV_draw_text(910, 95, "Selectionner un point", MLV_COLOR_BLACK);
        MLV_draw_text(890, 710, "Effacer dernier point", MLV_COLOR_GREY);
        MLV_draw_filled_rectangle(1350,110,200,50, MLV_COLOR_ANTIQUE_WHITE); /*annuler_point*/
        MLV_draw_text(1360, 120, "Annulation", MLV_COLOR_BLACK);
    }
    else {
        MLV_draw_text(800, 5, "MODE ARBRE KD", MLV_COLOR_ANTIQUE_WHITE);
        MLV_draw_text(45, 5, "Mode KPPV -> click pour changer", MLV_COLOR_BLACK);
        MLV_draw_text(1250, 770, "Charger des données (fichier)", MLV_COLOR_GREY);
        MLV_draw_text(1250, 830, "Sauvegarder les données", MLV_COLOR_GREY);
        MLV_draw_text(1250, 710, "Créer un fichier aléatoire", MLV_COLOR_GREY);
        MLV_draw_text(890, 770, "Ajouter un point (calcul auto kppv)", MLV_COLOR_BLACK);
        MLV_draw_text(890, 830, "Supprimer des points", MLV_COLOR_GREY);
        MLV_draw_filled_rectangle(480, 5, 300, 30, MLV_COLOR_ANTIQUE_WHITE); /*Valeur de K*/
        MLV_draw_text(490, 5, "Changer la valeur de K", MLV_COLOR_BLACK);
        MLV_draw_filled_rectangle(1100, 200, 450, 350, MLV_COLOR_ANTIQUE_WHITE); /*Options d'affichage*/
        MLV_draw_text(1110, 210, "Options d'affichage", MLV_COLOR_BLACK);
        MLV_draw_filled_rectangle(1150, 250, 375, 30, MLV_COLOR_BLACK); /*affichage de l'arbre*/
        MLV_draw_text(1160, 250, "Affichage de l'arbre (petit seulement)", MLV_COLOR_ANTIQUE_WHITE);
        MLV_draw_filled_rectangle(1150, 300, 185, 30, MLV_COLOR_BLACK); /*affichage des zones*/
        MLV_draw_text(1160, 300, "Aff. zones (anim.)", MLV_COLOR_ANTIQUE_WHITE);
        MLV_draw_filled_rectangle(1340, 300, 185, 30, MLV_COLOR_BLACK); /*zones sans animation*/
        MLV_draw_text(1350, 300, "Sans animation", MLV_COLOR_ANTIQUE_WHITE);
        MLV_draw_filled_rectangle(1150, 350, 375, 30, MLV_COLOR_BLACK); /*dessin du voisinage*/ 
        MLV_draw_text(1160, 350, "Dessin du voisinage", MLV_COLOR_ANTIQUE_WHITE);
        MLV_draw_filled_rectangle(1150, 400, 375, 30, MLV_COLOR_BLACK); /*couleur en fct de la classe*/
        MLV_draw_text(1160, 400, "Couleur selon la classe", MLV_COLOR_ANTIQUE_WHITE);
        MLV_draw_filled_rectangle(1150, 450, 375, 30, MLV_COLOR_BLACK); /*prise de décision*/
        MLV_draw_text(1160, 450, "Prise de décision", MLV_COLOR_ANTIQUE_WHITE);
        MLV_draw_filled_rectangle(1150, 500, 375, 30, MLV_COLOR_BLACK); /*effacer l'affichage*/
        MLV_draw_text(1160, 500, "Effacer l'affichage", MLV_COLOR_ANTIQUE_WHITE);
        MLV_draw_filled_rectangle(1100, 600, 450, 50, MLV_COLOR_ANTIQUE_WHITE); /*mode arbre kd*/
        MLV_draw_filled_rectangle(1150, 610, 375, 30, MLV_COLOR_BLACK); /*mode arbre kd*/
        MLV_draw_text(1160, 610, "Passer en mode tableau", MLV_COLOR_ANTIQUE_WHITE);
        MLV_draw_filled_rectangle(900, 95, 300, 30, MLV_COLOR_ANTIQUE_WHITE); /*Selection d'un point*/
        MLV_draw_text(910, 95, "Selectionner un point", MLV_COLOR_BLACK);
        MLV_draw_text(890, 710, "Effacer dernier point", MLV_COLOR_GREY);
        MLV_draw_filled_rectangle(1350,110,200,50, MLV_COLOR_ANTIQUE_WHITE); /*annuler_point*/
        MLV_draw_text(1360, 120, "Annulation", MLV_COLOR_BLACK);
    }

    MLV_actualise_window();
}

/**
 * @brief Affichage des points du tableau
 * 
 * @param tableau 
 */
void mlv_affichage_points(tab_points tableau){
    int i;
    int rouge=50, vert=100, bleu=150;
    float coor_x, coor_y;
    if (tableau == NULL || tableau->taille == 0){
        return;
    }

    for (i = 0; i<tableau->taille; i++){
      coor_x = ((tableau->tab[i].x+1)*400)+50;
        coor_y = ((-tableau->tab[i].y+1)*400)+50;
        if (tableau->tab[i].classe % 2 != 0){
            MLV_draw_line(coor_x, coor_y, coor_x+15, coor_y, MLV_rgba(rouge * tableau->tab[i].classe, vert * tableau->tab[i].classe, bleu * tableau->tab[i].classe, 255));
        }
        else {  
            MLV_draw_line(coor_x, coor_y, coor_x+15, coor_y, MLV_rgba(rouge * tableau->tab[i].classe, vert * tableau->tab[i].classe, bleu * tableau->tab[i].classe, 255));
            MLV_draw_line(coor_x+7.5, coor_y-7.5, coor_x+7.5, coor_y+7.5, MLV_rgba(rouge * tableau->tab[i].classe, vert * tableau->tab[i].classe, bleu * tableau->tab[i].classe, 255));
        }
    }

    MLV_actualise_window();
}

/**
 * @brief Affichage des points du tableau kppv (couleur différente)
 * 
 * @param tableau 
 * @param couleur 
 */
void mlv_affichage_points_kppv(tab_points tableau, MLV_Color couleur){
    int i;
    float coor_x, coor_y;
    if (tableau == NULL || tableau->taille == 0){
        return;
    }

    for (i=0; i<tableau->taille; i++){
        coor_x = ((tableau->tab[i].x+1)*400)+50;
        coor_y = ((-tableau->tab[i].y+1)*400)+50;
        if (tableau->tab[i].classe %2 == 0){
            MLV_draw_line(coor_x, coor_y, coor_x+15, coor_y, couleur);
            MLV_draw_line(coor_x+7.5, coor_y-7.5, coor_x+7.5, coor_y+7.5, couleur);
        }
        else {
            MLV_draw_line(coor_x, coor_y, coor_x+15, coor_y, couleur);
        }
    }
    MLV_actualise_window();
}

/**
 * @brief Reinitialisation de la fenêtre
 * 
 * @param tableau 
 */
void mlv_reinitialiser(tab_points tableau){
    nettoyer_tableau_points(tableau);
    mlv_affichage_menu(2);
}

/**
 * @brief Creation d'un nouveau tableau vide de nb_classes
 * 
 * @param tableau 
 */
void mlv_nb_classes(tab_points tableau){
    char * texte;
    int classe;
    MLV_wait_input_box(700, 450, 400,100 , MLV_COLOR_WHITE, MLV_COLOR_ANTIQUE_WHITE, MLV_COLOR_BLACK, "Nombres de classes : ", &texte);
    classe = atoi(texte);
    tableau->nb_classes = classe;
}

/**
 * @brief Affichage d'un message d'erreur
 * 
 * @param s message a afficher
 */
void mlv_message(char * s){
    MLV_draw_filled_rectangle(700, 450, 400, 100, ROUGE);
    MLV_draw_text(750, 480, s, MLV_COLOR_WHITE);
    MLV_actualise_window();
    MLV_wait_seconds(1);
    MLV_actualise_window();
}
