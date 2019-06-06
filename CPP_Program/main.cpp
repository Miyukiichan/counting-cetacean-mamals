/*
 * Main file for running the generic processes of the program and where the
 * main function is
 *
 * @author Sam Matthews - sam82
 */

#include <iostream>
#include <fstream>
#include "Location.h"
#include "Mammal.h"

using namespace std;

/*
 * Function for setting up and calling the read_data function in order to read
 * the mammal data from a file.
 * 
 * @return Returns a list of mammals that have been read in from a file
 */
vector<Mammal> read_file() {
    char file_name[30];
    vector<Mammal> mammals;
    cout << "Enter the name of the file containing the locations of the mammals:" << endl;
    cin >> file_name;
    std::ifstream stream;
    stream.open(file_name, ios::in);
    if (stream.is_open()) {
        while (stream.good()) {
            Mammal mammal(1, 1, "D"); //constructing effectively a blank mammal
            mammal.read_data(&stream); //giving a mammal its proper attributes
            mammals.push_back(mammal);
        }
        mammals.pop_back(); //TEMPORARY FIX FOR DUPLICATION OF FINAL MAMMAL
        stream.close();
    }
    return mammals;
}

/*
 * Function for iterating through a list of pods and returning an improved list
 * after calling check_pods.
 *
 * @param pods - a list of pods that will be iterated through and checked
 * @return Returns a list of pods that has been checked for duplication
 */
vector<vector<Mammal> > check(vector<vector<Mammal> > pods) {
    for (unsigned int i = 0; i < pods.size(); i++) {
        for (unsigned int j = 0; j < pods[i].size(); j++) {
            pods = pods[i][j].check_pods(pods);
        }
    }
    return pods;
}

/*
 * This function is purely for aesthetic purposes. It changes the grammar of
 * certain sentences based on how many pods there are and then prints out that
 * sentence. It also prints out all of the recorded pods.
 */
void print_pods(vector<vector<Mammal> > pods, const std::string &type) {
    string linking_verb;
    string podPlural;
    if (pods.size() == 1) { //AKA if amount of pods is non-plural
        linking_verb = " is ";
        podPlural = " pod ";
    } else { //if amount of pods is plural
        linking_verb = " are ";
        podPlural = " pods ";
    }
    cout << "\nThere" << linking_verb << pods.size() << podPlural << "of " << type << endl;
    for (unsigned int i = 0; i < pods.size(); i++) {
        string mamPlural;
        if (pods[i].size() == 1) {
            if (type == "dolphins") {
                mamPlural = "dolphin";
            }
            else {
                mamPlural = "porpoise";
            }
        }
        else {
            mamPlural = type;
        }
        cout << "Pod " << i + 1 << " contains " << pods[i].size() << " " << mamPlural << " located at:" << endl;
        for (const auto &j : pods[i]) {
            cout << j << endl;
        }
        cout << "\n";
    }
}

int main() {
    cout.precision(9);
    std::vector<Mammal> mammals, real_mammals;
    std::vector<vector<Mammal> > dolphin_pods, porpoise_pods;
    mammals = read_file(); //generating a list of mammals from the C output file
    if (!mammals.empty()) {

        /*Finding average locations*/
        for (unsigned int i = 0; i < mammals.size(); i++) {
            real_mammals.push_back(mammals[i].find_average(mammals));
        }

        /*Checking true average locations*/
        for (unsigned int i = 0; i < real_mammals.size(); i++) {
            real_mammals = real_mammals[i].check_mammals(real_mammals);
        };

        /*Locating pods*/
        for (unsigned int i = 0; i < real_mammals.size(); i++) {
            vector<Mammal> pod = real_mammals[i].find_pod(real_mammals);
            if (real_mammals[i].get_type() == "D") {
                dolphin_pods.push_back(pod);
            } else {
                porpoise_pods.push_back(pod);
            }
        }

        /*Checking pods for duplication*/
        dolphin_pods = check(dolphin_pods);
        porpoise_pods = check(porpoise_pods);

        /*Printing pods*/
        print_pods(dolphin_pods, "dolphins");
        print_pods(porpoise_pods, "porpoises");
        cout << "The total amount of pods is " << dolphin_pods.size() + porpoise_pods.size() << endl;
    } else {
        cout << "Unable to open file" << endl;
    }
    return 0;
}
