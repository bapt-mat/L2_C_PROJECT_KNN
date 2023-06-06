/**
 * @file tad_arbre_kd.h
 * @author mathevon/palisse
 * @brief TAD arbre kd
 * @version 0.1
 * @date 2023-05-21
 */
#ifndef __TAD_ARBRE_KD_H__
#define __TAD_ARBRE_KD_H__

#include "tad_tableau_points.h"
#include "kppv.h"
#include <time.h>

/**
 * @brief Structure d'une zone d'un point
 * 
 */
typedef struct zone{
    float x_max;
    float x_min;
    float y_max;
    float y_min;
}zone;

/**
 * @brief Structure d'un noeud de l'arbre
 * 
 */
typedef struct noeud {
  point p;
  int prof;
  zone zone_noeud;
  struct noeud * gauche;
  struct noeud * droite;
}noeud;

/**
 * @brief Type arbre_kd
 * 
 */
typedef noeud * arbre_kd;

/**
 * @brief Test si un arbre est vide
 * 
 * @param a 
 * @return int 
 */
int est_vide_arbre_kd(arbre_kd * a);

/**
 * @brief Création d'un arbre vide
 * 
 * @return arbre_kd 
 */
arbre_kd creer_arbre_kd_vide();

/**
 * @brief Affichage de l'arbre
 * 
 * @param a 
 */
void afficher_arbre_kd(arbre_kd a);

/**
 * @brief Création d'une zone
 * 
 * @param x_max 
 * @param x_min 
 * @param y_max 
 * @param y_min 
 * @return zone 
 */
zone creer_zone(float x_max, float x_min, float y_max, float y_min);

/**
 * @brief Insertion d'un point dans l'arbre
 * 
 * @param a 
 * @param p 
 * @param z 
 */
void inserer_aux(arbre_kd a, point * p, zone z);

/**
 * @brief Insertion d'un point dans l'arbre
 * 
 * @param a 
 * @param p 
 * @return arbre_kd 
 */
arbre_kd inserer(arbre_kd a, point * p);

/**
 * @brief Teste si un arbre est une feuille
 * 
 * @param a 
 * @return int 
 */
int est_feuille (arbre_kd a);

/**
 * @brief Recherche parent d'un point
 * 
 * @param p 
 * @param a 
 * @return arbre_kd 
 */
arbre_kd rechercher_parent (point p, arbre_kd a);

/**
 * @brief Supprime une feuille
 * 
 * @param a 
 * @return arbre_kd 
 */
arbre_kd supprimer_feuille (arbre_kd a);

/**
 * @brief Vide l'arbre kd
 * 
 * @param a 
 * @return arbre_kd 
 */
arbre_kd vider_arbre(arbre_kd a);

/**
 * @brief Met a jour l'arbre kd pour correspondre au tableau
 * 
 * @param tableau 
 * @param a 
 * @return arbre_kd 
 */
arbre_kd orchestre_suppression (tab_points tableau, arbre_kd a);

/**
 * @brief Chargement d'un fichier de points dans un arbre kd
 * 
 * @param a 
 * @param nom_fichier 
 * @return int 
 */
int chargement_fichier_arbre_kd(arbre_kd * a, char * nom_fichier);

/**
 * @brief Test si un point est dans une zone
 * 
 * @param p 
 * @param z_tmp 
 * @return int 
 */
int est_dans_zone(point p, zone z_tmp);

/**
 * @brief Met a jour la liste des kppv actuel avec le nouveau point
 * 
 * @param p_tmp 
 * @param liste 
 * @param nb_kppv 
 * @param taille_liste 
 * @return point* 
 */
point * maj_liste(point * p_tmp, point * liste, int nb_kppv, int * taille_liste);

/**
 * @brief Distance max entre le point et la liste des kppv
 * 
 * @param p 
 * @param liste 
 * @param taille_liste 
 * @return float 
 */
float d_max_liste(point p, point * liste, int taille_liste);

/**
 * @brief Recherche le point potentiel le plus proche dans la zone 
 * 
 * @param p 
 * @param z_tmp 
 * @return point 
 */
point point_proche_dans_zone(point * p, zone z_tmp);

/**
 * @brief Recherche des kppv
 * 
 * @param a 
 * @param p 
 * @param k 
 * @param liste_kppv 
 * @param taille_liste 
 */
void recherche_rec(arbre_kd * a, point p, int k, point** liste_kppv, int * taille_liste);

/**
 * @brief Recherche des kppv
 * 
 * @param a 
 * @param p 
 * @param nb_kppv 
 * @return point* 
 */
point * rechercher(arbre_kd * a, point p, int nb_kppv);

/**
 * @brief Calcul de la classe du point en fonction des la classe de ses kppv
 * 
 * @param liste 
 * @param nb_kppv 
 * @return int 
 */
int classe_kppv_arbre(point *liste, int nb_kppv);
#endif


