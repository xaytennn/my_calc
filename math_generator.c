#include "calc_defs.h"
#include <time.h>

#define RAND_BORDER 100
#define OPERATION_COUNT 4

int main(){
    srand(time(NULL));
    char *operations[] = {"+", "-", "/", "*"};
    double a = (double)rand() / RAND_MAX * RAND_BORDER + 1;
    double b = (double)rand() / RAND_MAX * RAND_BORDER + 1;
    char *operation = operations[rand() % OPERATION_COUNT];
    double answer = 0, result = 0;
    char a_str[20], b_str[20];

    printf("%.4g %s %.4g\n", a, operation, b);
    printf("Input your answer: \n");
    scanf("%lg", &answer);

    double_to_point_char(a, a_str, sizeof(a_str));
    double_to_point_char(b, b_str, sizeof(b_str));

    result = calc(a_str, operation, b_str);
    int true = check_answer(result, answer);
    
    if(true == 1){
        printf("Good job! Your are right!\n");
    }
    else{
        printf("Sadge. Wrong answer\n");
        printf("You should aswer: %.4g\n", result);
    }

    exit(EXIT_SUCCESS);
}