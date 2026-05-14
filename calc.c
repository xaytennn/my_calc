#include "calc_defs.h"

int main(int argc, char **argv){
    int result, history_count = 0;
    char *expression = NULL;
    char **history = NULL;
    char input[MAX_BUF_SIZE];
    printf("Input task. Calculator can do +, -, /, *, %%. Example: a + b\n");
    
    if(argc == 4){
        result = calc(getnumber(argv[1]), argv[2], getnumber(argv[3]));
        printf("%d\n", result);
    }

    if(argc == 1){
        char a[MAX_SIZE], b[MAX_SIZE], operation[MAX_SIZE];
        while(1){
            display_history(history, history_count);
            printf("Input next task or ""exit"" \n");
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = 0;

            if(strcmp(input, "exit") == 0) 
                break;
            
            sscanf(input, "%s %s %s", a, operation, b);
            result = calc(getnumber(a), operation, getnumber(b));
            
            expression = make_str(a, operation, b, result);
            add_hisory(expression, &history, &history_count);
            printf("Result: %s \n", expression);
        }
    }

    for (int i = 0; i < history_count; i++) {
        free(history[i]);
    }
    free(history);

    exit(EXIT_SUCCESS);
}