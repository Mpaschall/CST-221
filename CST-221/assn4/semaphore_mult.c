/*Mathew Paschall
This code creates a semaphore which allows two threads to access the resource at a time. This is initialized in the sem_init(sem_t *sem, pshare, value) call, where value is the number of threads allowed to access the resource. It does this by decrementing the semaphore when calling sem_wait. Once a thread has completed its function, it will allow other threads to access the resource with sem_post. This increments the semaphore. The semaphore is destroyed once all threads are finished.
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
	
	sem_init(&semaphore, 0, 2);	
	
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
	
