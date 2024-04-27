#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_TASKS 3 // Definir le nombre de taches



typedef struct {
    int id;
    int period;  // in seconds
} PeriodicTask; // Renommage de la structure pour plus de clart�


void *taskFunction(void *arg) {
    PeriodicTask *task = (PeriodicTask *)arg;//Le pointeur arg est converti en un pointeur PeriodicTask* pour acc�der aux membres de la structure (id et periode)

    while (1) {
        sleep(task->period);// The thread pauses execution implementing the task's execution interval
        printf("Task %d executed.\n", task->id);//prints a message indicating the task's ID and execution
    }

    return NULL;
}

int main() {
    int TASK_PERIODS[]={1, 2, 3};// Tableau des p�riodes d'ex�cution des t�ches (en secondes)
    pthread_t threads[NUM_TASKS];// Tableau pour stocker les identifiants des threads
    PeriodicTask tasks[NUM_TASKS]; // Tableau de structures de donn�es des t�ches
    int i;

    // Cr�ation des t�ches et des threads
    for (i = 0; i < NUM_TASKS; ++i) {
        tasks[i].id = i + 1;
        tasks[i].period = TASK_PERIODS[i];
        pthread_create(&threads[i], NULL, taskFunction, (void *)&tasks[i]);
    }

    // Attente de 10 secondes pour laisser les t�ches s'ex�cuter
    sleep(10);
    
    // Arr�t et attente de la fin des threads
    for (i = 0; i < NUM_TASKS; ++i) {
        pthread_cancel(threads[i]);
        pthread_join(threads[i], NULL);
    }
    return 0;
}
