#ifndef CALC_DEFS_H
#define CALC_DEFS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BUF_SIZE 100
#define MAX_SIZE 10

double calc (char *a_str, char *operat, char *b_str);
double getnumber(char *num);
void add_hisory(char *expression, char ***history, int *history_count);
char *make_str(char *a, char *operation, char *b, double result);
void display_history(char **history, int history_count);

#endif