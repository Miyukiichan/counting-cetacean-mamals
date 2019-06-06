#include <stdio.h>

void insert_observers(FILE *);

void print_observers();

void insert_sightings(FILE *);

void print_sightings();

char *calculate_positions(double, double, double, double);

char *stpcpy(char *, const char *); //workaround for building with C11 error