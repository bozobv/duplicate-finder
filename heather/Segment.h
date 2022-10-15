#ifndef UNTITLED1_SEGMENT_H
#define UNTITLED1_SEGMENT_H

#include <string>
#include <vector>

using namespace std;

class Segment {

    int from, to;

    static void addDuplicates(vector<Segment> *duplicates, int start, int end);

public:

    Segment(int _from, int _to);

    int getFrom() const;

    void compare(const Segment &segment, vector<Segment> *duplicates) const;

    ~Segment();

    Segment(const string &_from, const string &_to);

    void print() const;

    bool equal(const Segment &segment) const;

    int getTo() const;

    bool redundantFinder(const Segment &segment);
};


#endif
