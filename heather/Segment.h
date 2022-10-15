#ifndef UNTITLED1_SEGMENT_H
#define UNTITLED1_SEGMENT_H

#include <string>
#include <vector>

using namespace std;

class Segment {

    int from, to;

    Segment(int _from, int _to);


    static void addDuplicates(vector<Segment> *duplicates, int start, int end);

public:

    int getFrom() const;

    void compare(const Segment &segment, vector<Segment> *duplicates) const;

    ~Segment();

    Segment(const string &_from, const string &_to);

    void print() const;

    bool equal(const Segment &segment) const;

    int getTo() const;
};


#endif
