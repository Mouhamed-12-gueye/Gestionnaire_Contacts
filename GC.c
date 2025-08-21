#include "GC.h"

void menu(){
    printf("I============= Menu =============I\n");
    printf("\t1- Ajouter un contact\n");
    printf("\t2- Rechercher un contact\n");
    printf("\t3- Afficher tous les contacts\n");
    printf("\t4- Sauvegarder et quitter\n");
}

Contact* creer_contact(char* nom, char* prenom, char* tel , char* email) {
    Contact *C = malloc(sizeof(Contact));
    if (!C) {
        printf("ERREUR d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    C->nom = strdup(nom);
    C->prenom = strdup(prenom);
    C->tel = strdup(tel);
    C->email = strdup(email);
    C->suivant = NULL;
    return C;
}


void ajouter_contact(Liste *L, char* nom, char* prenom, char* tel , char* email) {
    Contact *maillon = creer_contact(nom, prenom, tel, email);

    if (*L == NULL) {
        // Si la liste est vide, le nouveau contact devient le premier
        *L = maillon;
    } else {
        // Sinon, on parcourt jusqu'au dernier
        Contact *courant = *L;
        while (courant->suivant != NULL) {
            courant = courant->suivant;
        }
        courant->suivant = maillon;
    }
}


bool rechercher_contact(Liste L, char *tel) {
    Contact *courant = L;
    while (courant != NULL) {
        if (strcmp(courant->tel, tel) == 0)
            return true;
        courant = courant->suivant;
    }
    return false;
}


void affichage_fichier(char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("Impossible d'ouvrir le fichier %s ❌\n", filename);
        return;
    }

    char ligne[200];
    printf("\n=== Contenu du fichier %s ===\n", filename);
    while (fgets(ligne, sizeof(ligne), f) != NULL) {
        printf("%s", ligne);
    }
    fclose(f);
}

bool save_contact(Liste L, char* filename) {
    FILE *f = fopen(filename, "a");
    if (!f) return false;
    Contact *courant = L;
    while (courant != NULL) {
        fprintf(f, "%s | %s | %s | %s |\n",
                courant->nom, courant->prenom, courant->tel, courant->email);
        courant = courant->suivant;
    }
    fclose(f);
    return true;
}

