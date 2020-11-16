//
// Created by Dmitry on 16.11.2020.
//

#ifndef UNTITLED56_HSET_H
#define UNTITLED56_HSET_H


#include <vector>
#include "Restaurant.h"

class HSet {
public:
    bool put(Restaurant value);
    bool contains(Restaurant restaurant) const;
    static const int MAXIMUM_CAPACITY = 100;
    bool operator==(HSet &other) const;
    explicit HSet(int capacity);
    bool remove(Restaurant restaurant);
    void clear();
    std::string toString() const;
    int size() const;

private:
    class Entry {
    public:
        Entry(int key, const Restaurant &value);

        int key;
        Restaurant value;
    };

    std::vector<std::vector<Entry>> *table = new std::vector<std::vector<Entry>>(capacity);
    double loadFactor = 0.75;
    int m_size = 0;
    int capacity = 4;
    int threshold = (int)(capacity * loadFactor);

    int getPosition(int hash, int size) const;

    void resize(int newCapacity);

    void transfer(std::vector<std::vector<Entry>> *tempTable, int newCapacity);
};


#endif //UNTITLED56_HSET_H
