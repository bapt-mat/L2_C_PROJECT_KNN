#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void ecriture(FILE * fichier, int n, int d, int c){
    int i, j, classe;
    float dim[n][d];

    for (i=0; i<n; i++){

        for (j=0; j<d; j++){
            dim[i][j] = ((float)rand()/(float)(RAND_MAX/2.0))-1.0;
        }
    }

    fprintf(fichier, "%d %d %d\n", n, d, c);
    for (i=0; i<n; i++){
        classe = rand()%(c)+1;
        fprintf(fichier, "%d ",classe);
        for (j=0; j<d; j++){
            fprintf(fichier, "%f ", dim[i][j]);
        }
        fprintf(fichier, "\n");
    }
}

int main(int argc, char *argv[]){
    srand(time(NULL));
    char chemin_fichier[100];
    FILE * fichier = NULL;

    if (argc < 5){
        printf("Usage : <generation_fichier> <nom_fichier> <nb points> <nb dimensions> <nb classes> \n");
        exit(EXIT_FAILURE);
    }

    sprintf(chemin_fichier, "./%s",argv[1]);
    fichier = fopen(chemin_fichier, "w");
    if (fichier == NULL){
        printf("Impossible d'ouvrir le fichier %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    
    ecriture(fichier, atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));

    fclose(fichier);

    exit(EXIT_SUCCESS);
}
