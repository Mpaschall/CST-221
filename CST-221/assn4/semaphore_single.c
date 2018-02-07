/*Mathew Paschall
This program creates a binary semaphores that allows only one thread to access a resource at a time. It does this by decrementing the semaphore with sem_wait. Once the thread has completed its function, it increments the semaphore using sem_post. This allows other threads to access the resource. Once all threads have finished, the semaphore is destroyed.
*/

//Include libraries
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

//create global mutex
sem_t semaphore;

//initialize function before main method
void *fxn (void *vari);

//main method
int main(int argc, char *argv[]){

//define variables
	pthread_t thread1, thread2, thread3;
	
	sem_init(&semaphore, 0, 1);	
	
	char *msg1 = "First Thread";
	char *msg2 = "Second Thread";
	char *msg3 = "Third Thread";

//create threads and run myfunc
	pthread_create(&thread1, NULL, fxn, (void *) msg1);
	pthread_create(&thread2, NULL, fxn, (void *) msg2);
	pthread_create(&thread3, NULL, fxn, (void *) msg3);

//join threads back into main function
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);

//Destroys mutex after the threads have finished
	sem_destroy(&semaphore);	
	
	printf("all threads finished\n");

	return 0;
}

//function that threads perform
void *fxn (void *vari){
	char *msg;
	msg = (char *) vari;

//lock mutex if not already taken
	sem_wait(&semaphore);
//increments i and prints the name of the thread and value of i	
	for(int i=0; i < 10; i++){
	printf("%s accessing resources\n", msg);
	sleep(1);
	}
printf("%s all done\n", msg);
//unlock mutex after critical section
//allows other thread to access resource by sleeping for 1 second
sem_post(&semaphore);	

return NULL;
}
	
