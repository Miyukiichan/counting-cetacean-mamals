/*
 * Implementation of Mammal class
 *
 * @author Sam Matthews - sam82
 */

#include <iostream>
#include "Mammal.h"

using namespace std;

/*
 * Mammal constructor is essentially the location constructor with the inclusion of mammal type
 *
 * @param lat - The latitude of the mammal
 * @param lon - The longitude of the mammal
 * @param ty - The type of mammal
 */
Mammal::Mammal(double lat, double lon, std::string ty) : Location(lat, lon) {
    type = ty;
}

/*
 * Searches through a given list of mammals an keeps track of potential similarities. The average value is then calculated and returned
 *
 * @param mammals - vector of mammals to search through
 * @return Mammal - returns a mammal with the average latitude and longitude of the similar mammals
 */
Mammal Mammal::find_average(vector<Mammal> mammals) {
    std::vector<Mammal> similar;
    for (unsigned int i = 0; i <= mammals.size(); i++) {
        if (this->distance(mammals[i]) <= 0.02 && this->type == mammals[i].get_type()) {
            similar.push_back(mammals[i]); //keeps track of similar mammals of the same type
        }
    }
    if (similar.size() >
        1) { //similar will always have at least one as the function also compares an object with itself in the list
        double trueLat = 0;
        double trueLong = 0;
        for (auto &i : similar) {
            trueLat += i.getLatitude();
            trueLong += i.getLongitude();
        }
        trueLat /= similar.size();
        trueLong /= similar.size();
        Mammal mammal(trueLat, trueLong, this->type);
        return mammal;
    }
    return *this;
}


/*
 * Checks for duplicated mammals as a result of finding the averages. This is due to A=b being the same as B=A.
 *
 * @param mammals - vector of mammals to be checked
 * @return vector<Mammal> - an improved list of mammals
 */
vector<Mammal> Mammal::check_mammals(vector<Mammal> mammals) {
    bool seen = false; //used to ensure that one duplication is returned
    vector<Mammal> improved_mammals;
    for (const auto &mammal : mammals) {
        if (this->equals(mammal)) {
            if (!seen) {
                improved_mammals.push_back(mammal);
                seen = true;
            }
        } else {
            improved_mammals.push_back(mammal);
        }
    }
    return improved_mammals;
}

/*
 * Finds a pod for a given mammal based on a list.
 *
 * @param mammals - list of mammals
 * @return vector<Mammals> - The generated pod
 */
std::vector<Mammal> Mammal::find_pod(vector<Mammal> mammals) {
    std::vector<Mammal> pod;
    for (auto &mammal : mammals) {
        if (this->distance(mammal) <= 0.1 && type == mammal.get_type()) { //this includes the original mammal itself (can have a pod of size one)
            pod.push_back(mammal);
        }
    }
    return pod;
}

/*
 * Checks a list of pods for duplication.
 *
 * @param pods - a list of pods
 * @return vector<vector<Mammal> > - an improved list of pods
 */
std::vector<vector<Mammal> > Mammal::check_pods(vector<vector<Mammal> > pods) {
    vector<vector<Mammal> > improved_pods;
    vector<Mammal> correct; //the pod with the most amount of mammals which is added later (accounts for chaining)
    for (auto &pod : pods) {
        bool seen = false; //assumes that a pod has not been seen
        for (unsigned int j = 0; j < pod.size(); j++) {
            if (this->equals(pod[j])) {
                seen = true;
                if (pod.size() > correct.size()) {
                    correct = pod;
                }
            }
        }
        if (!seen) {
            improved_pods.push_back(pod);
        }
    }
    improved_pods.push_back(correct); //adds the correct version of the duplicated pod
    return improved_pods;
}

std::string Mammal::get_type() {
    return this->type;
}

/*
 * Comparision between two mammals
 * 
 * @return bool - true if mammals are the same
 */
bool Mammal::equals(Mammal mammal) {
    return this->getLatitude() == mammal.getLatitude() && this->getLongitude() == mammal.getLongitude() &&
           this->get_type() == mammal.get_type();
}

/*
 * Reads data from a given file stream and sets the mammal attributes accordingly
 *
 * @param *stream - file stream to read from
 */
void Mammal::read_data(std::ifstream *stream) {
    double latitude;
    double longitude;
    *stream >> type;
    *stream >> latitude;
    *stream >> longitude;
    this->setLocation(latitude, longitude);
}
