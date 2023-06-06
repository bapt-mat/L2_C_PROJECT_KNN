/**
 * @file mlv_interface.h
  * @author mathevon/palisse
 * @brief gestion de l'interface mlv
 * @version 0.1
 * @date 2023-05-21
 */
#ifndef __AFFICHAGE_H__
#define __AFFICHAGE_H__

#include "tad_tableau_points.h"
#include "MLV/MLV_all.h"
#define BLEU MLV_COLOR_ROYAL_BLUE
#define ROUGE MLV_COLOR_RED

/**
 * @brief Affichage général de la fenêtre
 * 
 * @param mode 
 */
void mlv_affichage_menu(int mode);

/**
 * @brief Affichage des points du tableau
 * 
 * @param tableau 
 */
void mlv_affichage_points(tab_points tableau);

/**
 * @brief Affichage des points du tableau kppv (Couleur différénte)
 * 
 * @param tableau 
 * @param couleur 
 */
void mlv_affichage_points_kppv(tab_points tableau, MLV_Color couleur);

/**
 * @brief Reinitalisation du tableau
 * 
 * @param tableau 
 */
void mlv_reinitialiser(tab_points tableau);

/**
 * @brief Creation d'un nouveau tableau vide avec nb_classes
 * 
 * @param tableau 
 */
void mlv_nb_classes(tab_points tableau);

/**
 * @brief Affichage d'un message d'erreur
 * 
 * @param s 
 */
void mlv_message(char * s);



#endif