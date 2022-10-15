#ifndef UNTITLED1_STREET_H
#define UNTITLED1_STREET_H

#include <string>
#include "Segment.h"
#include <vector>

class Street {

    std::string name, type;
    vector<Segment> oddAdresses, evenAdresses, oddDuplicates, evenDuplicates;

public:

    void findOddDuplicates();

    void findEvenDuplicates();

    std::string getName();

    std::string getType();

    ~Street();

    void addOddAddress(const Segment &segment);

    void addEvenAddress(const Segment &segment);

    Street(std::string _name, std::string _type);

    void printDuplicates();

    void sortAdresses();

    static void sortAdresses(vector<struct Segment> *vector);

    static bool compareAdresses(const Segment &s1, const Segment &s2);

    static void sortStreets(vector<Segment> *addresses);

    void writeDuplicateFile(std::ofstream &ofstream);

    void removeQuatationMarks();

    static void removeRedundancy(vector<struct Segment> *adresses);
};

#endif
