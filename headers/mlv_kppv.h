/**
 * @file mlv_kppv.h
 * @author mathevon/palisse
 * @brief Fonctions mlv mode tableau kppv
 * @version 0.1
 * @date 2023-05-21
 */
#ifndef __MLV_KPPV_H__
#define __MLV_KPPV_H__

#include "tad_tableau_points.h"
#include "tad_arbre_kd.h"
#include "kppv.h"
#include "mlv_interface.h"
#include "MLV/MLV_all.h"

/**
 * @brief Mise à jour de l'affichage
 * 
 * @param tableau 
 * @param tab_kppv 
 * @param p 
 */
void mlv_maj_affichage(tab_points tableau, tab_points tab_kppv, point p);

/**
 * @brief Selection d'un point
 * 
 * @param tableau 
 * @return int 
 */
int selection_point_kppv(tab_points tableau);

/**
 * @brief Mise en évidence du point sélectionné
 * 
 * @param p 
 */
void mlv_dessin_point(point p);

/**
 * @brief Fonction général mode kppv tableau
 * 
 * @param tableau 
 */
void mlv_kppv(tab_points tableau);

/**
 * @brief Création d'un point
 * 
 * @param tableau 
 * @return point* 
 */
point * mlv_creer_point_kppv(tab_points tableau);

/**
 * @brief Ajout d'un point au tableau et a l'arbre et calcul de ses kppv et de sa classe
 * 
 * @param tableau 
 * @param a 
 */
void mlv_ajouter_point_kppv(tab_points tableau, arbre_kd * a);



#endif
