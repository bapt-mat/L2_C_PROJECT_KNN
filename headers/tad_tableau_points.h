/**
 * @file tad_tableau_points.h
 * @author mathevon/palisse
 * @brief TAD tableau de points
 * @version 0.1
 * @date 2023-05-21
 */
#ifndef __CHARGEMENT_H__
#define __CHARGEMENT_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * @brief Structure d'un point
 * 
 */
typedef struct{
  int classe;
    float x;
    float y;
} point;

/**
 * @brief Structure d'un tableau de points
 * 
 */
typedef struct struct_tab_points{
    point * tab;
    int taille;
    int nb_classes;
}struct_tab_points;

/**
 * @brief Type tab_points
 * 
 */
typedef struct_tab_points * tab_points;

/**
 * @brief Allocation de la mémoire nécessaire pour un tab_points d'une taille_max
 * 
 * @param taille_max 
 * @return tab_points 
 */
tab_points creer_tableau_points(int taille_max);

/**
 * @brief Ajout d'un point dans le tableau
 * 
 * @param tableau 
 * @param p 
 * @return tab_points 
 */
tab_points ajouter_point(tab_points tableau, point p);

/**
 * @brief Suppression d'un point dans le tableau
 * 
 * @param tableau 
 * @param position 
 * @return tab_points 
 */
tab_points supprimer_point(tab_points tableau, int position);

/**
 * @brief Réallocation de la mémoire pour un tableau de points
 * 
 * @param tableau 
 * @param taille 
 * @return tab_points 
 */
tab_points realloc_tab(tab_points tableau, int taille);

/**
 * @brief Nettoyage du tableau
 * 
 * @param tableau 
 */
void nettoyer_tableau_points(tab_points tableau);

/**
 * @brief Affichage du tableau
 * 
 * @param tableau 
 */
void afficher_tableau_points(tab_points tableau);

/**
 * @brief Test si un point est présent dans le tableau
 * 
 * @param tableau 
 * @param p 
 * @return int 
 */
int est_present_tab_points(tab_points tableau, point p);

/**
 * @brief Chargement d'un fichier dans un tableau de points
 * 
 * @param tableau 
 * @param nom_fichier 
 * @return int 
 */
int chargement_fichier(tab_points tableau, char * nom_fichier);

/**
 * @brief Sauvegarde d'un tableau de points dans un fichier
 * 
 * @param tableau 
 * @param nom_fichier 
 * @return int 
 */
int sauvegarde_fichier(tab_points tableau, char * nom_fichier);

/**
 * @brief Génération d'un point aléatoire
 * 
 * @param classe 
 * @param x_min 
 * @param x_max 
 * @param y_min 
 * @param y_max 
 * @return point 
 */
point gen_point_aleatoire(int classe, int x_min, int x_max, int y_min, int y_max);

/**
 * @brief Libere la mémoire allouée pour un tableau de points
 * 
 * @param tableau 
 */
void liberation_tableau_points(tab_points tableau);


#endif





