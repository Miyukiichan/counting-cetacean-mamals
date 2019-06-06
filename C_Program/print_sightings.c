#include "functions.h"
#include "shared.h"

/* Function that prints the contents of the sightings linked list*/
void print_sightings() {
    printf("\nSightings read in:\n");
    struct sightings sighting = *sighting_head; //starting at the beginning of the list
    while (sighting.next != NULL) { //when there is another element in the list
        printf("%s %c %lf %lf\n", sighting.next->id, sighting.next->type, sighting.next->bearing, sighting.next->range);
        sighting = *sighting.next; //move to the next element
    }
}

