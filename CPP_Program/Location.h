/*
 * Created by Neal  Snooke on 24/10/2017.
 */

#ifndef CODE_LOCATION_H
#define CODE_LOCATION_H

#define EARTH_RADIUS 3440.07
//#define DEBUG
#include <iostream> //This line was not previously provided
/*
 * class to represent a location
 */
class Location {

private:
    double lat;
    double lng;

public:
    /**
     * @param lat
     * @param lng
     */
    Location(double lat, double lng);

    /**
     * change the coordinates of this location
     * @param lat
     * @param lng
     */
    void setLocation(double lat, double lng);

    /**
     * @return latitude of this location
     */
    double getLatitude() { return lat; }

    /**
     * @return longitude of this location
     */
    double getLongitude() { return lng; }

    /**
     * calculate the great circle distance between this location and another
     * The code is based on the calculation as described on the web page
     * http://en.wikipedia.org/wiki/Great-circle_distance
     *
     * @return distance
     */
    double distance(Location);

    /**
     * stream insertion operator overload to allow formatted stream output
     * @return the stream
     */
    friend std::basic_ostream<char>& operator<<(
            std::basic_ostream<char>&, const Location&);
};

#endif //CODE_LOCATION_H
