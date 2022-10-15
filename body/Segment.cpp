#include <iostream>
#include "../heather/Segment.h"

Segment::Segment(const string &_from, const string &_to) {
    from = stoi(_from);
    to = stoi(_to);
}

Segment::Segment(int _from, int _to) : from(_from), to(_to) {}

/*
void Segment::compare(Segment segment, Segment* duplicates, int duplicatesSize) {

    if (segment.getFrom() >= from && segment.getFrom() <= to){
        getDuplicates(duplicates, duplicatesSize, segment.getFrom(), to);
    } else if (segment.getTo() >= from  && segment.getTo() <= to){
        getDuplicates(duplicates, duplicatesSize, from, segment.getTo());
    } else if (segment.getFrom() >= from && segment.getTo() <= to){
        getDuplicates(duplicates, duplicatesSize,  segment.getFrom(), segment.getTo());
    } else if (segment.getFrom() <= from && segment.getTo() >= to) {
        getDuplicates(duplicates, duplicatesSize, from, to);
    }
}
*/

int Segment::getFrom() const {
    return from;
}

int Segment::getTo() const {
    return to;
}

/*
void Segment::getDuplicates(Segment *duplicates, int duplicatesSize, int start, int end) {
    duplicates[duplicatesSize] = *new Segment(start, end);
    duplicatesSize++;
}
*/

void Segment::addDuplicates(vector<Segment> *duplicates, int start, int end) {
    duplicates->emplace_back(Segment(start, end));

}

void Segment::compare(const Segment &segment, vector<Segment> *duplicates) const {

    if (segment.getFrom() >= from && segment.getTo() <= to) {
        addDuplicates(duplicates, segment.getFrom(), segment.getTo());
    } else if (segment.getFrom() <= from && segment.getTo() >= to) {
        addDuplicates(duplicates, from, to);
    } else if (segment.getFrom() >= from && segment.getFrom() <= to) {
        addDuplicates(duplicates, segment.getFrom(), to);
    } else if (segment.getTo() >= from && segment.getTo() <= to) {
        addDuplicates(duplicates, from, segment.getTo());
    }
}


bool Segment::redundantFinder(const Segment &segment) {

    if (segment.getFrom() >= from && segment.getTo() <= to) {
        return true;
    } else if (segment.getFrom() <= from && segment.getTo() >= to) {
        from = segment.getFrom();
        to = segment.getTo();
        return true;
    } else if (segment.getFrom() >= from && segment.getFrom() <= to) {
        to = segment.getTo();
        return true;
    } else if (segment.getTo() >= from && segment.getTo() <= to) {
        from = segment.getFrom();
        return true;
    }
    return false;
}


bool Segment::equal(const Segment &segment) const {
    if (segment.getFrom() == from && segment.getTo() == to)
        return true;
    return false;
}

void Segment::print() const {
    std::cout << "from: " << from << " to: " << to << "\n";
}

/*
bool Segment::compare(Segment segment) {
    if (segment.getFrom() >= from && segment.getFrom() <= to){
        getDuplicates(duplicates, duplicatesSize, segment.getFrom(), to);
    } else if (segment.getTo() >= from  && segment.getTo() <= to){
        getDuplicates(duplicates, duplicatesSize, from, segment.getTo());
    } else if (segment.getFrom() >= from && segment.getTo() <= to){
        getDuplicates(duplicates, duplicatesSize,  segment.getFrom(), segment.getTo());
    } else if (segment.getFrom() <= from && segment.getTo() >= to) {
        getDuplicates(duplicates, duplicatesSize, from, to);
    }
}*/

Segment::~Segment() = default;


