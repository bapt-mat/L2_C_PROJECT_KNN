/**
 * @file mlv_arbre_kd.h
 * @author mathevon/palisse
 * @brief fonctions mlv pour le mode arbre kd
 * @version 0.1
 * @date 2023-05-21
 */
#ifndef __MLV_ARBRE_KD_H__
#define __MLV_ARBRE_KD_H__

#include "tad_arbre_kd.h"
#include "MLV/MLV_all.h"
#include "mlv_kppv.h"

/**
 * @brief Reinitialisation de l'affichage
 * 
 * @param a 
 * @param liste 
 * @param p 
 * @param nb_kppv 
 */
void mlv_maj_affichage_arbre_kd(arbre_kd a, point * liste, point p, int nb_kppv);

/**
 * @brief Affichage graphique de l'arbre kd
 * 
 * @param a 
 * @param x 
 * @param y 
 * @param distance_euclidienne 
 */
void afficher_arbre_graphique(arbre_kd a, int x, int y, int distance_euclidienne);

/**
 * @brief Affichage des points de l'arbre kd
 * 
 * @param arbre 
 * @param prof 
 */
void mlv_affichage_points_arbre_kd(arbre_kd arbre, int prof);

/**
 * @brief Affichage des zones de l'arbre kd fonction recursive
 * 
 * @param arbre 
 * @param animation 
 */
void mlv_dessin_zone_rec(arbre_kd arbre, int animation);

/**
 * @brief Affichage des zones de l'arbre kd
 * 
 * @param z 
 * @param animation 
 */
void mlv_dessin_zone(zone z, int animation);

/**
 * @brief Dessin du voisinage du point
 * 
 * @param p 
 * @param liste 
 * @param taille_liste 
 */
void mlv_dessin_voisinage_arbre(point p, point * liste, int taille_liste);

/**
 * @brief Affichage de la classe du point calculé en fct des classe de ses kppv
 * 
 * @param liste 
 * @param p 
 * @param nb_kppv 
 */
void mlv_classe_kppv_arbre(point * liste, point p, int nb_kppv);

/**
 * @brief Affichage des points de la liste
 * 
 * @param liste 
 * @param nb_kppv 
 * @param couleur 
 */
void mlv_affichage_points_kppv_liste(point * liste, int nb_kppv, MLV_Color couleur);

/**
 * @brief Selection du point
 * 
 * @param a 
 * @return point 
 */
point selection_point_kppv_arbre_kd(arbre_kd a);

/**
 * @brief Affichage du menu mode kppv arbre kd
 * 
 * @param a 
 */
void mlv_kppv_arbre_kd(arbre_kd a);


#endif
