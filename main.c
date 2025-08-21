#include "GC.h"

int main(){

    Liste L = NULL;
    int choice;
    char nom[50], prenom[50], tel[50], email[50];
     menu();
    do {
        printf("Veuillez donner votre choix ou 0 pour quitter:  ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n=== AJOUT D'UN CONTACT ===\n");
                printf("Nom : ");
                scanf("%s", nom);
                printf("Prenom : ");
                scanf("%s", prenom);
                printf("Telephone : ");
                scanf("%s", tel);
                printf("Email : ");
                scanf("%s", email);

                ajouter_contact(&L, nom, prenom, tel, email);
                printf("Contact ajoute avec succes \n\n");
                break;

            case 2:
                printf("\n=== RECHERCHE ===\n");
                printf("Entrez un numero de telephone : ");
                scanf("%s", tel);
                if (rechercher_contact(L, tel)) {
                    printf("Contact trouve\n");
                } else {
                    printf("Aucun contact trouve \n");
                }
                break;

            case 3:
                printf("\n=== LISTE DES CONTACTS ===\n");
                affichage_fichier("contacts.txt");
                break;

            case 4:
                if (save_contact(L, "contacts.txt")) {
                    printf("Contacts sauvegardés avec succes\n");
                } else {
                    printf("Erreur lors de la sauvegarde ❌\n");
                }
                break;

            default:
                if (choice != 0) {
                    printf("Choix invalide \n");
                }
            }
    } while (choice != 0);

    return 0;
}
