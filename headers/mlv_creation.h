/**
 * @file mlv_creation.h
  * @author mathevon/palisse
 * @brief mode creation mlv
 * @version 0.1
 * @date 2023-05-21
 */
#ifndef __MLV_CREATION_H__
#define __MLV_CREATION_H__

#include "tad_tableau_points.h"
#include "tad_arbre_kd.h"
#include "mlv_interface.h"
#include "MLV/MLV_all.h"

/**
 * @brief Creation d'un point
 * 
 * @return point* 
 */
point * mlv_creer_point();

/**
 * @brief Ajouter des points au tableau
 * 
 * @param tableau 
 * @param a 
 */
void mlv_ajouter_point(tab_points tableau, arbre_kd * a);

/**
 * @brief Selection d'un point
 * 
 * @param tableau 
 * @return int 
 */
int selection_point(tab_points tableau);

/**
 * @brief Supprimer les points selectionnés
 * 
 * @param tableau 
 */
void mlv_supprimer_point(tab_points tableau);

#endif
