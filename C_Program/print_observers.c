#include "functions.h"
#include "shared.h"

/* Function that prints the contents of the observers linked list*/
void print_observers() {
    printf("\nObservers read in:\n");
    struct observers observer = *observer_head; //starting at the beginning of the list
    while (observer.next != NULL) { //when there is another element in the list
        printf("%s %lf %lf\n", observer.next->id, observer.next->latitude, observer.next->longitude);
        observer = *observer.next; //move to the next element
    }
}

