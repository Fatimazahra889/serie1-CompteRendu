#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Fonction ex�cut�e par le thread 
void *print_message(void *arg) {
	char *msg = (char *) arg; // Conversion de l'argument vers un pointeur de caract�re
	printf("%s\n", msg);
	return NULL;
}

int main(int argc, char *argv[]) {
	pthread_t t; // Variable pour stocker l'identifiant du thread
	char *msg = "hi there!"; // Message � imprimer 
	
	// Cr�ation du thread secondaire
	if (pthread_create(&t, NULL, print_message, msg) != 0) {
		perror("thread creation error");
		return EXIT_FAILURE;
	}
	
	// Attente de la fin d'ex�cution du thread secondaire
	if(pthread_join(t, NULL) !=0){
        perror("Error");
        EXIT_FAILURE;
    }
	return EXIT_SUCCESS;
}
