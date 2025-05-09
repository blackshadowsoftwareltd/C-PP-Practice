#include <stdio.h>
#include <unistd.h> 
#include <pthread.h> 

typedef struct{
    int a;
    int b;
} thread_args;

void *myThreadFun(void *args)
{
    printf("Printing Thread\n");
    printf("Thread id: %ld\n", (long)pthread_self());
    sleep(5);
    printf("Printing Thread \n");
    if (args != NULL) {
        thread_args *targs = (thread_args *)args;
        int sum = targs->a + targs->b;
        printf("Sum: %d\n", sum);
    }
    return NULL;
}

void *minusThread(void *args)
{
    printf("Printing minusThread Thread\n");
    printf("Thread id: %ld\n", (long)pthread_self());
    sleep(5);
    printf("Printing Thread \n");
    if (args != NULL) {
        thread_args *targs = (thread_args *)args;
        int sub = targs->a - targs->b;
        printf("Sub: %d\n", sub);
    }
    return NULL;
}

int main()
{
    pthread_t thread_id_1;
    pthread_t thread_id_2;
    printf("Thread id 1 : %lu\n", (unsigned long)thread_id_1);
    printf("Thread id 2 : %lu\n", (unsigned long)thread_id_2);
    printf("Enter 2 numbers : ");
    thread_args args; 
    scanf("%d %d", &args.a, &args.b);
    
    printf("Before Thread\n");
    pthread_create(&thread_id_1, NULL, myThreadFun, &args);
    pthread_create(&thread_id_2, NULL, minusThread, &args);

    pthread_join(thread_id_1, NULL);
    pthread_join(thread_id_2, NULL);
    printf("After Thread-common message\n"); 
    return 0; // Returns 0 to indicate successful execution.
}

