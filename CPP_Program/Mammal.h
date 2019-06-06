/*
 * Class to represent mammals as an extension of locations
 *
 * @author Sam Matthews - sam82
 */

#ifndef MAMMALS
#define MAMMALS

#include <vector>
#include <string>
#include <fstream>
#include "Location.h"

using namespace std;

class Mammal : public Location {

private:
    std::string type; //D or P (Dolphin or Porpoise)

public:

    Mammal(double lat, double lon, std::string ty);

    Mammal find_average(vector<Mammal> mammals);

    vector<Mammal> check_mammals(vector<Mammal> mammals);

    std::vector<Mammal> find_pod(vector<Mammal> mammals);

    std::vector<vector<Mammal> > check_pods(vector<vector<Mammal> > pods);

    std::string get_type();

    bool equals(Mammal mammal);

    void read_data(std::ifstream *stream);
};

#endif
