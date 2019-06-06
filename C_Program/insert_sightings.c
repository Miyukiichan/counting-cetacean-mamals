#include "functions.h"
#include "shared.h"
#include <stdlib.h>

/* Function that creates a node in the sightings linked list and assigns the member variables the appropriate values
 * that are passed into the function. It is also ensured that all of the elements of the list are kept track of by
 * reassigning pointers in the right order
 *
 * @param id - id of the observer that sighted the mammal
 * @param mammal_type - d or p (dolphin or porpoise)
 * @param bearing - pointing from an observer to the mammal
 * @param range - between an observer and the mammal
*/
void insert_sightings(FILE *stream) {
    char id[3];
    char mammal_type;
    double bearing;
    double range;
    while (fscanf(stream, "%s %c %lf %lf", id, &mammal_type, &bearing, &range) == 4) {
        /*creation and allocation of a node to be inserted into the linked list*/
        struct sightings *sighting_ptr = (struct sightings *) calloc(1, sizeof(struct sightings));
        stpcpy(sighting_ptr->id, id);
        sighting_ptr->type = mammal_type;
        sighting_ptr->bearing = bearing;
        sighting_ptr->range = range;
        if (sighting_head->next != NULL) { //if the list is not empty
            /*new node points to whatever the head was pointing to (puts it at the start of the list)*/
            sighting_ptr->next = sighting_head->next;
        }
        sighting_head->next = sighting_ptr; //head points to the new node
    }
}
