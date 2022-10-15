#include "../heather/Network.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <fstream>

string INPUT_FILENAME = "network.csv";
string OUTPUT_FILENAME = "output.txt";


void Network::readFile() {
    vector<string> row;
    std::string line, word;
    fstream file(INPUT_FILENAME, ios::in);
    if (file.is_open()) {

        while (getline(file, line)) {
            row.clear();
            std::stringstream str(line);

            while (getline(str, word, ','))
                row.push_back(word);

            addnewSegment(row[7], row[8], row[9], row[10], row[11], row[12], row[13], row[14]);
        }
    } else
        cout << "Could not open the file\n";

    file.close();
}

void Network::writeFile() {
    std::ofstream file(OUTPUT_FILENAME, ios::out);
    vector<string> row;

    if (file.is_open()) {

        for (Street s: streets) {
            s.writeDuplicateFile(file);
        }

        file.close();
    } else
        cout << "Could not open the file\n";

}

void Network::addnewSegment(const std::string &name,
                            const string &type,
                            const string &schemeLeft, const string &fromLeft, const string &toLeft,
                            const string &schemeRight, const string &fromRight, const string &toRight) {

    if (name == "\"\"" || (schemeLeft == "\"\"" && schemeRight == "\"\""))
        return;

    if (!streets.empty()) {
        for (auto i = streets.rbegin(); i != streets.rend(); ++i) {
            if (name == i->getName() && type == i->getType()) {
                parityCheck(schemeLeft, fromLeft, toLeft, &*i);
                parityCheck(schemeRight, fromRight, toRight, &*i);
                return;
            }
        }
    }

    streets.emplace_back(name, type);
    parityCheck(schemeLeft, fromLeft, toLeft, &streets.back());
    parityCheck(schemeRight, fromRight, toRight, &streets.back());
}


void Network::parityCheck(const std::string &scheme, const string &from, const string &to, Street *street) {

    if (scheme == "\"O\"" || "O") {
        street->addOddAddress(Segment(from, to));
        return;

    } else if (scheme == "\"E\"" || "E") {
        street->addEvenAddress(Segment(from, to));
        return;
    }
}

Network::Network() = default;

void Network::getDuplicates() {

    for (auto &street: streets) {
        street.findEvenDuplicates();
        street.findOddDuplicates();
    }
    //printDuplicates();
}

//print for debug
void Network::printDuplicates() {

    for (Street i: streets) {
        i.printDuplicates();
    }
}

void Network::sortDuplicates() {
    removeQuotationMarks();
    sortAdresses();
    sortStreets();
}

void Network::sortAdresses() {
    for (auto &street: streets) {
        street.sortAdresses();
    }
}

bool Network::compareStreets(Street s1, Street s2) {
    return (s1.getName() < s2.getName());
}

void Network::sortStreets() {
    sort(streets.begin(), streets.end(), compareStreets);
}

void Network::removeQuotationMarks() {
    for (auto &street: streets) {
        street.removeQuatationMarks();
    }
}
