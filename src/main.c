/**
 * @file main.c
 * @author mathevon/palisse
 * @brief Fonctions principales
 * @version 0.1
 * @date 2023-05-21
 */
#include "../headers/all.h"

/**
 * @brief Affichage du menu mode creation
 * 
 * @param tableau 
 * @param arbre 
 * @return int 
 */
int mlv_mode_creation(tab_points tableau, arbre_kd * arbre){
    int code = 0;
    int x,y;
    do{
        
        mlv_affichage_menu(2);
        mlv_affichage_points(tableau);
        MLV_wait_mouse(&x, &y);

        if ((x>1350 && x<1550) && (y>50 && y<100)){ /*exit*/
            code = 1;
        }
        if ((x>35 && x<435) && (y>5 && y<35)){ /*changer mode*/
            code = 3;
        }
        if ((x>1350 && x<1550) && (y>110 && y<160)){ /*reinitialiser*/
            mlv_reinitialiser(tableau);
            mlv_nb_classes(tableau);
            *arbre=orchestre_suppression(tableau, *arbre);
        }
        if ((x>1240 && x<1590) && (y>760 && y<810)){ /*chargement fichier*/
            mlv_chargement_fichier(tableau);
        }
        if ((x>1240 && x<1590) && (y>820 && y<870)){ /*sauvegarde fichier*/
            mlv_sauvegarde_fichier(tableau);
        }
        if ((x>1240 && x<1590) && (y>700 && y<750)){ /*generation fichier*/
            mlv_generation_fichier(tableau, arbre);
        }
        if ((x>880 && x<1230) && (y>760 && y<810)){ /*ajout point*/
	        mlv_ajouter_point(tableau, arbre);
        }
        if ((x>880 && x<1230) && (y>820 && y<870)){ /*suppression points*/
            mlv_supprimer_point(tableau);
            *arbre=orchestre_suppression(tableau, *arbre);
        }

    }while(code == 0);

    return code;

}

/**
 * @brief Affichage du menu mode kppv tableau
 * 
 * @param tableau 
 * @param a 
 * @return int 
 */
int mlv_mode_kppv(tab_points tableau, arbre_kd * a){
    int code = 0;
    int x,y;
    
    do{
        mlv_affichage_menu(3);
        mlv_affichage_points(tableau);
        MLV_wait_mouse(&x, &y);


        if ((x>1350 && x<1550) && (y>50 && y<100)){ /*exit*/
            code = 1;
        }
        if ((x>35 && x<435) && (y>5 && y<35)){ /*changer mode*/
            code = 2;
        }
        if ((x>900 && x<1200) && (y>95 && y<125)){ /*lancer kppv*/
            mlv_kppv(tableau);
        }
        if ((x>880 && x<1230) && (y>760 && y<810)){ /*ajout point et calcul de la classe en fct des kppv*/
	        mlv_ajouter_point_kppv(tableau, a);
        }
        if ((x>1150 && x<1525) && (y>610 && y<640)){ /*mode arbre_kd*/
            code = 4;
        }


    }while(code == 0);

    return code;
}

/**
 * @brief Affichage du menu mode kppv arbre
 * 
 * @param arbre 
 * @param tableau 
 * @return int 
 */
int mlv_mode_kppv_arbre(arbre_kd * arbre, tab_points tableau){
    int code = 0;
    int x,y;
    
    do{
        mlv_affichage_menu(4);
        mlv_affichage_points_arbre_kd(*arbre,0);
        MLV_actualise_window();
        MLV_wait_mouse(&x, &y);


        if ((x>1350 && x<1550) && (y>50 && y<100)){ /*exit*/
            code = 1;
        }
        if ((x>35 && x<435) && (y>5 && y<35)){ /*changer mode*/
            code = 2;
        }
        if ((x>900 && x<1200) && (y>95 && y<125)){ /*lancer kppv*/
            mlv_kppv_arbre_kd(*arbre);
        }
        if ((x>880 && x<1280) && (y>760 && y<810)){ /*ajout point et calcul de la classe en fct des kppv*/
	        mlv_ajouter_point_kppv(tableau, arbre);
        }
        if ((x>1150 && x<1525) && (y>610 && y<640)){ /*mode arbre_kd*/
            code = 3;
        }


    }while(code == 0);

    return code;
}


/**
 * @brief Main
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char *argv[]){
    int code = 2;
    tab_points tableau = creer_tableau_points(0); 
    arbre_kd arbre = creer_arbre_kd_vide();
    char * chemin_fichier;
    int nb_kppv;
    point p;

    srand(time(NULL));
    p = gen_point_aleatoire(0, -1, 1, -1, 1);

    if (argc < 2){
        printf("Usage : %s <MLV_yes_no> <chemin_fichier (opt.)> <nb_kppv (opt.)> <mode (tab/tab_fusion/arbre) (opt.)>\n", argv[0]);
    }

    if (strcmp(argv[1], "yes") == 0){
        MLV_create_window_with_default_font("KPPV", "KPPV", 1600, 890, "font/OpenSans-Semibold.ttf", 20); 
        
        if (argv[2] != NULL){
            chemin_fichier = argv[2];
            chargement_fichier(tableau, chemin_fichier);
            chargement_fichier_arbre_kd(&arbre, chemin_fichier);
        }
        else {
            chargement_fichier(tableau, "donnees/lunes.txt");
            chargement_fichier_arbre_kd(&arbre, "donnees/lunes.txt");
        }
        
        
        do{

            if (code == 2){
                code = mlv_mode_creation(tableau, &arbre);
            }
            if (code == 3){
	            code = mlv_mode_kppv(tableau, &arbre);
            }
            if (code == 4){
	            code = mlv_mode_kppv_arbre(&arbre, tableau);
            }

        }while(code != 1);  

        MLV_free_window();
    }

    else{
        chemin_fichier = argv[2];
        nb_kppv = atoi(argv[3]);

        if (strcmp(argv[4], "tab") == 0){
            chargement_fichier(tableau, chemin_fichier);
            tri_points_distance(tableau, p);
        }
        else{
	  if (strcmp(argv[4], "tab_fusion") == 0){
	    chargement_fichier(tableau, chemin_fichier);
            tri_points_distance_fusion(tableau, p);
	  }
	  else{
            chargement_fichier_arbre_kd(&arbre, chemin_fichier);
            rechercher(&arbre, p, nb_kppv);
	  }
        }
    }

    
    liberation_tableau_points(tableau); 
    free(arbre);
    
    exit(EXIT_SUCCESS);
}
    

