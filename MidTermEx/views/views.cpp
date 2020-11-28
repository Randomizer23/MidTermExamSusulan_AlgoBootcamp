#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../models/models.h"
#include "../controllers/controllers.h"

int main() {
    int p, c, date, year, ctr = 0;
    char name[255], month[255];

    scanf("%d %d", &p, &c);
    for(int i = 0; i < p; i++) {
        scanf("%d %s %d - %[^\n]", &date, month, &year, name);
        getchar();
        addPatients((char*)name, (char*)month, date, year);
    }

    int a = c - p;
    if(p >= c) {
        for(int i = 0; i < c; i++) {
            removePatients();
        }
    } else {
        for(int i = 0; i < p; i++) {
            removePatients();
        }
    }
    if(a >= 0) {
        printf("All Patients get the cure, %d cure left\n", a);
    } else {
        printf("Need %d more cure\n", a*(-1));
        printPatients();
    }

    return 0;
}