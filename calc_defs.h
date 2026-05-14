#ifndef CALC_DEFS_H
#define CALC_DEFS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 100
#define MAX_SIZE 10

int calc (int a, char *operat, int b);
int getnumber(char *num);
void add_hisory(char *expression, char ***history, int *history_count);
char *make_str(char *a, char *operation, char *b, int result);
void display_history(char **history, int history_count);

#endif