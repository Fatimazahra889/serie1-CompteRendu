#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Fonction exécutée par le thread 
void *print_message(void *arg) {
	char *msg = (char *) arg; // Conversion de l'argument vers un pointeur de caractère
	printf("%s\n", msg);
	return NULL;
}

int main(int argc, char *argv[]) {
	pthread_t t; // Variable pour stocker l'identifiant du thread
	char *msg = "hi there!"; // Message à imprimer 
	
	// Création du thread secondaire
	if (pthread_create(&t, NULL, print_message, msg) != 0) {
		perror("thread creation error");
		return EXIT_FAILURE;
	}
	
	// Attente de la fin d'exécution du thread secondaire
	if(pthread_join(t, NULL) !=0){
        perror("Error");
        EXIT_FAILURE;
    }
	return EXIT_SUCCESS;
}
