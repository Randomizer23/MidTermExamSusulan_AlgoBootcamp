#ifndef CONTROLLERS
#define CONTROLLERS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../models/models.h"

int convertMonth(char *month) { //apparantly gabisa switch case (idk why)
    if (strcmp(month, "january") == 0) {
        return 1;
    } else if (strcmp(month, "february") == 0) {
        return 2;
    } else if (strcmp(month, "march") == 0) {
        return 3;
    } else if (strcmp(month, "april") == 0) {
        return 4;
    } else if (strcmp(month, "may") == 0) {
        return 5;
    } else if (strcmp(month, "june") == 0) {
        return 6;
    } else if (strcmp(month, "july") == 0) {
        return 7;
    } else if (strcmp(month, "august") == 0) {
        return 8;
    } else if (strcmp(month, "september") == 0) {
        return 9;
    } else if (strcmp(month, "october") == 0) {
        return 10;
    } else if (strcmp(month, "november") == 0) {
        return 11;
    } else if (strcmp(month, "december") == 0) {
        return 12;
    }
} //haven't managed to use this smh

Patient *newPatient(char *name, char *month, int date, int year) {
    Patient *newPatient = (Patient *)malloc(sizeof(Patient));
    strcpy(newPatient->name, name);
    strcpy(newPatient->month, month);
    newPatient->date = date;
    newPatient->year = year;

    return newPatient;
}

void addPatients(char *name, char *month, int date, int year) {
    Patient *patient = newPatient((char*)name, (char*)month, date, year);
    if(!head) {
      head = tail = patient;
    } else if(year < head->year) {
      patient->next = head;
      head->prev = patient;
      head = patient; 
    } else if(year > tail->year) {
      patient->prev = tail;
      tail->next = patient;
      tail = patient; 
    } else { 
      Patient *curr = head;
      while(curr && curr->next->year < patient->year) {
        curr = curr->next;
      }
      curr->next->prev = patient; 
      patient->next = curr->next; 
      curr->next = patient; 
      patient->prev = curr; 
    }
}

void removePatients() {
   if (!head) {
        return;
    } else if(head == tail) {
        head = tail = NULL;
        free(head);
    } else {
        Patient *temp = head->next;
        head->next = temp->prev = NULL;
        free(head);
        head = temp;
    }
}

void printPatients() {
    Patient *curr = head;
    if(!curr) {
      return;
    } else {
      while(curr) {
        printf("%d %s %d - %s\n", curr->date, curr->month, curr->year, curr->name);
        curr = curr->next;
      }
    }
}

#endif