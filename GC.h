#ifndef GC_H_INCLUDED
#define GC_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct contact{
    char* nom;
    char* prenom;
    char *tel;
    char* email;
    struct contact * suivant;
}Contact;
typedef Contact* Liste;//Declaration d'une liste de contact

void menu();
Contact* creer_contact(char*, char*, char*, char*);
void ajouter_contact(Liste *,char*, char*, char*, char*);
bool rechercher_contact(Liste, char *);
bool save_contact(Liste, char*);
void affichage_fichier(char *filename);


#endif // GC_H_INCLUDED
