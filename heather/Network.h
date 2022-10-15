#ifndef UNTITLED1_NETWORK_H
#define UNTITLED1_NETWORK_H

#include <vector>
#include "Street.h"
#include <string>

class Network {

    vector<Street> streets;

    static void parityCheck(const string &scheme, const string &from, const string &to, Street *street);

public:
    Network();

    void addnewSegment(const string &name, const string &type,
                       const string &schemeLeft, const string &fromLeft, const string &toLeft,
                       const string &schemeRight, const string &fromRight, const string &toRight);

    void getDuplicates();

    void printDuplicates();

    void sortDuplicates();

    void sortAdresses();

    void sortStreets();

    static bool compareStreets(Street s1, Street s2);

    void readFile();

    void writeFile();

    void removeQuotationMarks();
};


#endif
