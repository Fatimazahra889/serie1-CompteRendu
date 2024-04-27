#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Fonction à exécuter par le thread 1
void *thread_func1(void *arg) {
	printf("Thread 1: Bonjour !\n");
	return NULL;
}

// Fonction à exécuter par le thread 2
void *thread_func2(void *arg) {
	printf("Thread 2: Salut !\n");
	return NULL;
}

int main(int argc, char *argv[]) {
	pthread_t t1;
	pthread_t t2;
	pthread_create(&t1, NULL, thread_func1, NULL);
	pthread_join(t1, NULL);
	pthread_create(&t2, NULL, thread_func2, NULL);
	pthread_join(t2, NULL);
	return EXIT_SUCCESS;
}
