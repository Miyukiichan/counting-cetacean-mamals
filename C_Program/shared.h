extern struct observers { //struct to store the data taken from the observers file, stored as elements of a linked list
    char id[3]; //observer's id
    double latitude; //current latitude
    double longitude; //current longitude
    struct observers *next; //pointer to the next structure in the list
} *observer_head;

extern struct sightings { //struct to store data taken from the sightings file, stored as elements of a linked list
    char id[5]; //id of the observer who sighted the mammal
    char type; //d or p (dolphin or porpoise)
    double bearing; //bearing from the observer to the sighted mammal
    double range; //range from the observer to the mammal
    struct sightings *next; //pointer to the next structure in the list
} *sighting_head;


