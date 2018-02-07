/*Mathew Paschall
This program will create a mutex, which is a monitor that will allow only a single thread to access resources at a time. Once the function has run, it will release the resources to the next thread. After all threads have run, the mutex will be destroyed.
*/
//Include libraries
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

//create global mutex
pthread_mutex_t lock;

//function that threads perform
void *fxn (void *vari){
	char *msg;
	msg = (char *) vari;

//lock mutex if not already taken
	if(pthread_mutex_lock(&lock) == 0){
//increments i and prints the name of the thread and value of i	
		for(int i=0; i < 10; i++){
		printf("%s = accessing resources\n", msg);
		sleep(1);
		}
	//unlock mutex after critical section
	//allows other thread to access resource by sleeping for 1 second
	pthread_mutex_unlock(&lock);
	}

	return NULL;
}

//main method
int main(int argc, char *argv[]){

//define variables
	pthread_t thread1, thread2, thread3;
	
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
	pthread_mutex_destroy(&lock);	
	
	printf("Finished\n");

	return 0;
}
	
