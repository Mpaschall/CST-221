/*Mathew Paschall
This program creates 2 threads that use myfunc to lock and unlock a mutex, which regulates the critical section in the function.
*/

//Include libraries
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

//create global mutex
pthread_mutex_t lock;

//function that threads perform
void *myfunc (void *myvar){
	char *msg;
	msg = (char *) myvar;

//lock mutex if not already locked
	if(pthread_mutex_lock(&lock) == 0){
	printf("%s has lock\n", msg);

//increments i and prints the name of the thread and value of i	
		for(int i=0; i < 10; i++){
		printf("%s = %d\n", msg, i);

//unlock mutex after critical section
//allows other thread to access resource by sleeping for 1 second
		pthread_mutex_unlock(&lock);
		sleep(1);
		}
	
	}

	return NULL;
}

//main method
int main(int argc, char *argv[]){

//define variables
	pthread_t thread1, thread2;
	char *msg1 = "First Thread";
	char *msg2 = "Second Thread";
	int ret1, ret2;

//create threads and run myfunc
	ret1 = pthread_create(&thread1, NULL, myfunc, (void *) msg1);
	ret2 = pthread_create(&thread2, NULL, myfunc, (void *) msg2);

	printf("Main function after pthread_create\n");

//join threads back into main function
	pthread_join(thread1, NULL);
	printf("First thread return = %d\n", ret1);
	pthread_join(thread2, NULL);
	printf("Second thread return = %d\n", ret2);

	return 0;
}
	
