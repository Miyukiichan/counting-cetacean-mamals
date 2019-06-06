#include "functions.h"
#include <stdlib.h>
#include <math.h>
#define M_PI 3.14159265358979323846 //fixes c11 build error

/* Function for returning the location of a mammal relative to the observer who spotted the mammal based on the bearing and  range given by the observer
 * 
 * @param latitude - the latitude of the observer
 * @param longitude - the longitude of the observer
 * @param bearing - the bearing of the mammal given by the observer
 * @param range - the range of the mammal given by the observer
 * @return location or NULL - the location of a mammal within the sea area, returns NULL if the mammal is outside the sea area
 */

char * calculate_positions(double latitude, double longitude, double bearing, double range) {
  double BGR = bearing * M_PI / 180.0; //calculates the bearing in radians
  double OLATR = latitude * M_PI / 180.0; // calculates the latitude of the observer in radians
  double CMLAT = latitude + (range * cos(BGR)) / 60.0; //calculates the latitude of the mammal
  double CMLONG = longitude + (range * sin(BGR) / cos(OLATR)) / 60.0; //calculates the longitude of the mammal
  if (CMLAT >= 52.00 && CMLAT <= 52.833 && CMLONG <= -4.00 && CMLONG >= -5.500) { //check if the mammal is within our sea area
    char * location = malloc(19 * sizeof(char));
    sprintf(location, "%lf %lf", CMLAT, CMLONG); //converting the locations to a char * in order to be returned as one location variable
    return location;
  }
  return NULL; //if the mammal is outside the sea area the function returns null as we are not interested in that mammal
}
