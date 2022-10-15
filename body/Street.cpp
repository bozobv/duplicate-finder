#include "../heather/Street.h"

#include <utility>
#include <iostream>
#include <algorithm>
#include <fstream>

Street::Street(string _name, string _type) : name(std::move(_name)), type(std::move(_type)) {}

void Street::addOddAddress(const Segment &segment) {
    oddAdresses.emplace_back(segment);
}

void Street::addEvenAddress(const Segment &segment) {
    evenAdresses.emplace_back(segment);
}

void Street::findOddDuplicates() {
    if (oddAdresses.size() > 1) {
        for (int i = 0; i < oddAdresses.size() - 1; i++)
            for (int j = i + 1; j < oddAdresses.size(); j++)
                oddAdresses.at(i).compare(oddAdresses.at(j), &oddDuplicates);
    }
}

void Street::findEvenDuplicates() {
    if (evenAdresses.size() > 1) {
        for (int i = 0; i < evenAdresses.size() - 1; i++)
            for (int j = i + 1; j < evenAdresses.size(); j++)
                evenAdresses.at(i).compare(evenAdresses.at(j), &evenDuplicates);
    }
}

std::string Street::getName() {
    return name;
}

std::string Street::getType() {
    return type;
}

//print for debug
void Street::printDuplicates() {

    if (!oddDuplicates.empty()) {
        std::cout << "-----" << name << "------- \nodd\n";

        for (const Segment &i: oddDuplicates)
            i.print();
    }

    if (!evenDuplicates.empty()) {
        std::cout << " even\n";

        for (const Segment &i: evenDuplicates)
            i.print();
    }
}

bool Street::compareAdresses(const Segment &s1, const Segment &s2) {
    return (s1.getFrom() < s2.getFrom());
}

void Street::sortStreets(vector<Segment> *addresses) {
    sort(addresses->begin(), addresses->end(), compareAdresses);
}

void Street::sortAdresses() {
    sortAdresses(&oddDuplicates);
    sortAdresses(&evenDuplicates);

    removeRedundancy(&oddDuplicates);
    removeRedundancy(&evenDuplicates);

    sortStreets(&oddDuplicates);
    sortStreets(&evenDuplicates);
}

void Street::sortAdresses(vector<struct Segment> *adresses) {
    if (adresses->size() > 1) {
        int i = 0, j;
        bool removed = false;
        while (i < adresses->size() - 1) {
            removed = false;
            j = i + 1;
            while (j < adresses->size()) {
                if (adresses->at(i).equal(adresses->at(j))) {
                    adresses->erase(adresses->begin() + j);
                    removed = true;
                } else
                    j++;
            }
            if (!removed)
                i++;
        }
    }
}

void Street::removeRedundancy(vector<struct Segment> *adresses) {
    if (adresses->size() > 1) {
        int i = 0, j;
        bool removed = false;
        while (i < adresses->size() - 1) {
            removed = false;
            j = i + 1;
            while (j < adresses->size()) {
                if (adresses->at(i).redundantFinder(adresses->at(j))) {
                    adresses->erase(adresses->begin() + j);
                    removed = true;
                } else
                    j++;
            }
            if (!removed)
                i++;
        }
    }
}

void Street::writeDuplicateFile(ofstream &ofstream) {
    if (!evenDuplicates.empty())
        for (const Segment &s: evenDuplicates)
            ofstream << name << ": E " << s.getFrom() << " " << s.getTo() << "\n";

    if (!oddDuplicates.empty())
        for (const Segment &s: oddDuplicates)
            ofstream << name << ": O " << s.getFrom() << " " << s.getTo() << "\n";
}

void Street::removeQuatationMarks() {
    name = name + "" + type;
    name.erase(remove(name.begin(), name.end(), '\"'), name.end());
}

Street::~Street() = default;
