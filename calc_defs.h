#ifndef CALC_DEFS_H
#define CALC_DEFS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#define MAX_BUF_SIZE 100
#define MAX_SIZE 10
#define CALCULATOR 1
#define MATH_GENERATOR 2
#define MATH_GENERATOR_TOURNAMENT 3
#define EPSILON 1e-9

double calc (char *a_str, char *operat, char *b_str);
double getnumber(char *num);
void add_hisory(char *expression, char ***history, int *history_count);
char *make_str(char *a, char *operation, char *b, double result);
void display_history(char **history, int history_count);
int check_answer(double result, double answer);
void double_to_point_char(double a, char *buffer, size_t size);

#endif