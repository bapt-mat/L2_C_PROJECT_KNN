/**
 * @file mlv_chargement.h
 * @author mathevon/palisse
 * @brief fonctions de chargement/sauvegarde de fichiers
 * @version 0.1
 * @date 2023-05-21
 */
#ifndef __MLV_CHARGEMENT_H__
#define __MLV_CHARGEMENT_H__

#include "tad_tableau_points.h"
#include "mlv_interface.h"
#include "MLV/MLV_all.h"
#include <unistd.h>
#include <sys/wait.h>
#include "tad_arbre_kd.h"

/**
 * @brief Permet de charger un fichier de points dans un tableau
 * 
 * @param tableau 
 */
void mlv_chargement_fichier(tab_points tableau);

/**
 * @brief Permet de sauvegarder un tableau de points dans un fichier
 * 
 * @param tableau 
 */
void mlv_sauvegarde_fichier(tab_points tableau);

/**
 * @brief Permet de générer un fichier de points aléatoires
 * 
 * @param tableau 
 * @param arbre 
 */
void mlv_generation_fichier(tab_points tableau, arbre_kd * arbre);

#endif