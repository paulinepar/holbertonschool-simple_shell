#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 *   main - fork & wait example
 *   
 *    Return: Always 0.
 */
int main(void)
{
        int i = 0;
        /**
         * pid_t data type stands for process
         * identification and it is used to represent process ids.
         * Whenever, we want to declare a variable that is going to deal
         * with the process ids we can use pid_t data type.
         * The type of pid_t data is a signed integer type
         * (signed int or we can say int)
         */
        pid_t child_pid;
        pid_t pid;
        int status;
        char *argvec[] = {"ls", "-l", "/tmp", NULL};
        char *argenvp[] = {
                "Home=/root",
                "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin",
                "TZ=America/Los_Angeles",
                "_=/usr/bin/env",
                 NULL
        };
        /**
         * use a while to create the number of children needed
         */while (i < 5)
        {
                child_pid = fork();
                if (child_pid == -1)
                {
                        perror("Error:");
                        return (1);
                }


                /**
                 * on success fork return 0
                 * so in other word we can say if
                 * fork creates a new child
                 * run the commad ls -l /tmp
                 */
                if (child_pid == 0)
                {
                        /**
                         * i used getpid just to print the process id of each process
                         * this is not required in the excercise
                         */
                        pid = getpid();
                        printf("my pid is :%u\n", pid);
                        execve("/bin/ls", argvec, argenvp);
                }
                /**
                 * after the process is called it returns to the parent
                 * so here we want the parent to wait before creating a new chile
                 * for this we use sleep and wait
                 * sleep(n) only tells the terminal to wait n seconds before running the command
                 * wait() tells the parent to wait for the child to be terminated before creating a new child
                 */
                else
                {
                        sleep(3);
                        wait(&status);
                }

                i++;
        }
        return (0);
}
