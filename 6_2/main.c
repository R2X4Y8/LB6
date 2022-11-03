#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define SECONDS 4

int main() 
{
    pid_t pid;

    printf("\nForking started\n");
    pid = fork();

    int count = 0;
    time_t currentTime = time(NULL);

    if (pid == 0) 
	{
        while (time(NULL) != (currentTime + SECONDS)) 
            count++;
        printf("Child PID = %d.\nCount = %d\n\n", getpid(), count);
    } 
	else if (pid > 0) 
	{
        while (time(NULL) != (currentTime + SECONDS)) 
            count++;
        printf("Parent PID = %d.\nCount = %d\n\n", getpid(), count);
    } 
	else 
        printf("Error\n");

    return 0;
}
