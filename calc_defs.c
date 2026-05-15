#include "calc_defs.h"

double calc (char *a_str, char *operat, char *b_str){
    double a = getnumber(a_str);
    double b = getnumber(b_str);
    if(strcmp("+", operat) == 0) return a + b;
    if(strcmp("-", operat) == 0) return a - b;
    if(strcmp("*", operat) == 0) return a * b;
    if(strcmp("/", operat) == 0 || strcmp(":", operat) == 0) return a / b;
    if(strcmp("%", operat) == 0) return fmod(a, b);
    if(strcmp("pow", operat) == 0 || strcmp("^", operat) == 0) return pow(a, b);
    else printf("Wrong operation %s. Try again\n", operat);
    return NAN;
}

double getnumber(char *num){
    return atof(num);
}

void add_hisory(char *expression, char ***history, int *history_count){
    *history = realloc(*history, (*history_count + 1) * sizeof(char*));
    if (*history == NULL) {
        printf("realloc error");
        exit(EXIT_FAILURE);
    }
    (*history)[*history_count] = expression;
    (*history_count)++;
}

char *make_str(char *a, char *operation, char *b, double result){
    int need_byte = snprintf(NULL, 0, "%s %s %s = %.10g", a, operation, b, result);
    char *expression = malloc(need_byte + 1);
    if (expression == NULL) {
        printf("malloc error");
        exit(EXIT_FAILURE);
    }
    snprintf(expression, need_byte + 1, "%s %s %s = %.10g\n", a, operation, b, result);
    return expression;
}

void display_history(char **history, int history_count){
    printf("\n_________________\nHistory\n");
    for(int i = 0; i < history_count; i++){
        printf("%s\n", history[i]);
    }
    printf("_________________\nend history\n\n");
}

int check_answer(double result, double answer){
    return fabs(result - answer) < EPSILON;
}

void double_to_point_char(double a, char *buffer, size_t size){
    snprintf(buffer, size, "%.4g", a);
}