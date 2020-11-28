#ifndef MODELS
#define MODELS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Patient {
    char name[255];
    char month[25];
    int conMonth;
    int date;
    int year;
    Patient *prev, *next;
} *head, *tail;

#endif