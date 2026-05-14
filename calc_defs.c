#include "calc_defs.h"

int calc (int a, char *operat, int b){
    if(strcmp("+", operat) == 0) return a + b;
    if(strcmp("-", operat) == 0) return a - b;
    if(strcmp("*", operat) == 0) return a * b;
    if(strcmp("/", operat) == 0) return a / b;
    if(strcmp("%", operat) == 0) return a % b;
    return 0;
}

int getnumber(char *num){
    return atoi(num);
}

void add_hisory(char *expression, char ***history, int *history_count){
    *history = realloc(*history, (*history_count + 1) * strlen(expression));
    (*history)[*history_count] = expression;
    (*history_count)++;
}

char *make_str(char *a, char *operation, char *b, int result){
    int need_byte = snprintf(NULL, 0, "%s %s %s = %d", a, operation, b, result);
    char *expression = malloc(need_byte + 1);
    snprintf(expression, need_byte + 1, "%s %s %s = %d\n", a, operation, b, result);
    return expression;
}

void display_history(char **history, int history_count){
    printf("\n_________________\nHistory\n");
    for(int i = 0; i < history_count; i++){
        printf("%s\n", history[i]);
    }
    printf("_________________\nend history\n\n");
}