j

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <omp.h>
#include <iostream>
#define NUMOFTHREADS    4
#define TOTAL 200000

/* Prototypes */
void *printPrimeThreadCalculation(void *threadid);
void primeCheckerThread(int numOfThreads);

pthread_mutex_t contad;
pthread_mutex_t cuent;

int contador = 0;
int cuenta = 1;

int main() {

    /* Thread Prime Checker */
    primeCheckerThread(NUMOFTHREADS);
    /* Exits the threads */
    pthread_exit(NULL);
    return 0;
}

void *printPrimeThreadCalculation(void *threadid) {
    long tid = (long) threadid;
    int cuentapriv;
    pthread_mutex_lock(&cuent);
    cuentapriv = cuenta;
    cuenta++;
    pthread_mutex_unlock(&cuent);
    int isPrime, i;

    while (contador < TOTAL) {
        /* Assume isPrime is true */
        isPrime = 1;

        for (i = 2; i < cuentapriv && isPrime; i++) {
            if (cuentapriv % i == 0) {
                isPrime = 0;
            }
        }
        if (isPrime == 1) {
            std::cout<<cuentapriv<<std::endl;
            pthread_mutex_lock(&contad);
            contador++;
            pthread_mutex_unlock(&contad);
        }
        pthread_mutex_lock(&cuent);
        cuentapriv = cuenta;
        cuenta++;
        pthread_mutex_unlock(&cuent);
    }
    return NULL;
}

void primeCheckerThread(int numOfThreads) {
    double t1,t0;
    /* Create threads */
    pthread_t threads[numOfThreads];
    int rc;
    long t;
    t0 = omp_get_wtime();
    for (t = 0; t < numOfThreads; t++) {
        /* Creates threads */
        rc = pthread_create(&threads[t], NULL, printPrimeThreadCalculation, (void *)t);
        if (rc) {
            // printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }  pthread_join(threads[t],NULL);
    }
    t1 = omp_get_wtime();
    t1 = t1 - t0;
    std::cout<<"Tiempo de ejecución: "<<t1<<std::endl;
}

