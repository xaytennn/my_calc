#include "calc_defs.h"
#include <sys/types.h>
#include <sys/wait.h>

void fork_mode(char *path, char *name){
    pid_t pid = fork();
    if(pid == 0){
        if(execl(path, name, NULL) == -1){
            perror("execl problem");
            exit(EXIT_FAILURE);
        }
    }
    else{
        int status;
        wait(&status);
        if (WIFEXITED(status)) {
            printf("Fork returned status: %d\n", WEXITSTATUS(status));
        }
    }
}

void print_menu(){
    printf("Select programm mode: \n"
        "1. Calculator\n"
        "2. Math task generator\n"
        "3. Math tournament[WORK IN PROGRESS]");
}

int main(){
    int mode = 0;
    print_menu();
    scanf("%d", &mode);
    switch (mode)
    {
        case CALCULATOR:
            fork_mode("./calc", "my_calc");
            break;
        case MATH_GENERATOR:
            fork_mode("./math_generator", "math_generator");
            break; 
    }
    exit(EXIT_SUCCESS);
}