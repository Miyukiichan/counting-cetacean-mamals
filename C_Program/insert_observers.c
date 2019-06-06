#include "functions.h"
#include <stdlib.h>
#include "shared.h"

/* Function that creates a node in the observers linked list and assigns the member variables the appropriate values
 * that are passed into the function. It is also ensured that all of the elements of the list are kept track of by
 * reassigning pointers in the right order
 *
 * @param id
 * @param latitude
 * @param longitude
 */
void insert_observers(FILE *stream) {
    char id[3];
    double latitude;
    double longitude;
    while (fscanf(stream, "%s %lf %lf", id, &latitude, &longitude) == 3) {
        /*creation and allocation of a node to be inserted into the linked list*/
        struct observers *observer_ptr = (struct observers *) calloc(1, sizeof(struct observers));
        stpcpy(observer_ptr->id, id);
        observer_ptr->latitude = latitude;
        observer_ptr->longitude = longitude;
        if (observer_head->next != NULL) { //if the list is not empty
            /*new node points to whatever the head was pointing to (puts it at the start of the list)*/
            observer_ptr->next = observer_head->next;
        }
        observer_head->next = observer_ptr; //head points to the new node
    }
}

