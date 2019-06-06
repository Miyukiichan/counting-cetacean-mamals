#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "shared.h"

struct observers *observer_head; //head of the observers linked list, declared in shared.h
struct sightings *sighting_head; //head of the sightings linked list, declared in shared.h

int main() {
    /*Declaration of variable*/
    observer_head = (struct observers *) calloc(1, sizeof(struct observers));
    sighting_head = (struct sightings *) calloc(1, sizeof(struct sightings));
    char file_name[30]; //contains the name of the file to be read
    FILE *stream;
    char time_temp[18]; //contains the time read from the observer file
    struct observers observer; //temporary struct used for looping
    struct sightings sighting; //temporary struct used for looping

    /*Reading observer data*/
    printf("\nEnter the name of a file containing observer information to be read:\n");
    scanf("%s", file_name);
    stream = fopen(file_name, "r");
    fgets(time_temp, 20, stream); //gets the date and time
    insert_observers(stream); //gets the observer data from each line until EOF
    print_observers(); //prints all of the observer data from the linked list after it is stored
    fclose(stream);

    /*Reading sightings data*/
    printf("\nEnter the name of a file containing sightings information to be read:\n");
    scanf("%s", file_name);
    stream = fopen(file_name, "r");
    insert_sightings(stream); //gets the sighting data from each line until EOF
    print_sightings(); //prints all of the observer data from the linked list after it is stored
    fclose(stream);

    /*Outputting the data to a file*/
    printf("\nEnter the name of a file where the sighting locations will be stored:\n");
    scanf("%s", file_name);
    stream = fopen(file_name, "w");
    observer = *observer_head; //resetting the current node to the start of the list
    while (observer.next != NULL) {
        sighting = *sighting_head;
        while (sighting.next != NULL) {
            if (strcmp(observer.next->id, sighting.next->id) == 0) { //matching the mammal with the observer that sighted it
                /*calculating the position of the mammal according to its observer(s)*/
                char *location = calculate_positions(observer.next->latitude, observer.next->longitude,
                                                     sighting.next->bearing, sighting.next->range);
                if (location != NULL) {
                    printf("%c %s\n", sighting.next->type, location);
                    fprintf(stream, "%c %s\n", sighting.next->type, location);
                }
            }
            sighting = *sighting.next;
        }
        observer = *observer.next;
    }
    fclose(stream);
    return 0;
}
