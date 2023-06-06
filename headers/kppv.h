/**
 * @file kppv.h
 * @author mathevon/palisse
 * @brief Kppv mode tableau
 * @version 0.1
 */
#ifndef __KPPV_H__
#define __KPPV_H__

#include "tad_tableau_points.h"
#include <math.h>
#include <time.h>

/**
 * @brief Calcul de la distance euclidienne entre deux points
 * 
 * @param p1 
 * @param p2 
 * @return float 
 */
float distance_euclidienne(point p1, point p2);
/**
 * @brief Tri a bulle du tableau
 * 
 * @param t 
 * @param p 
 */
void tri_points_distance (tab_points t, point p);
/**
 * @brief Calcul des kppv
 * 
 * @param tableau 
 * @param tab_kppv 
 * @param p 
 * @param nb_kppv 
 */
void kppv(tab_points tableau, tab_points tab_kppv, point p, int nb_kppv);
/**
 * @brief Calcul de la classe du point
 * 
 * @param tab_kppv 
 * @return int 
 */
int classe_kppv(tab_points tab_kppv);
/**
 * @brief Tri fusion du tableau fonction 1
 * 
 * @param t 
 * @param p 
 */
void tri_points_distance_fusion(tab_points t, point p);
/**
 * @brief Tri fusion du tableau fonction 2
 * 
 * @param t 
 * @param p 
 * @param debut 
 * @param fin 
 */
void tri_fusion(tab_points t, point p, int debut, int fin);
/**
 * @brief Tri fusion du tableau fonction 3
 * 
 * @param t 
 * @param p 
 * @param debut 
 * @param milieu 
 * @param fin 
 */
void fusionner(tab_points t, point p, int debut, int milieu, int fin);

#endif
