//
// Created by Dmitry on 16.11.2020.
//

#include "HSet.h"

bool HSet::put(Restaurant value) {
    int hash = value.hash();
    int pos = getPosition(hash, capacity);
    for (auto a : (*(this->table))[pos])
        if (a.key == hash && a.value == value) {
            return false;
        }
    (*table)[pos].push_back(Entry(hash, value));
    m_size++;
    if (m_size == threshold) {
        resize(capacity * 2);
    }
    return true;
}

int HSet::getPosition(int hash, int  size) const {
    return (size - 1) & hash;
}

int HSet::size() const {
    return m_size;
}

bool HSet::contains(Restaurant restaurant) const {
    int hash = restaurant.hash();
    int pos = getPosition(hash, capacity);
    for (auto a : (*this->table)[pos])
        if (a.key == hash && a.value == restaurant)
            return true;
    return false;
}

HSet::HSet(int capacity) : capacity(capacity) {
    threshold = (int)(capacity * loadFactor);
}

bool HSet::remove(Restaurant restaurant) {
    if (contains(restaurant)) {
        int hash = restaurant.hash();
        int pos = getPosition(hash, size());
        for (auto a = (*this->table)[pos].begin(); a != (*this->table)[pos].end(); a++)
            if (a->key == hash && a->value == restaurant) {
                (*this->table)[pos].erase(a);
                m_size--;
                return true;
            }
    }
    return false;
}

void HSet::clear() {
    delete table;
    table = new std::vector<std::vector<Entry>>(capacity);
    m_size = 0;
}

void HSet::resize(int newCapacity)
{
    if (this->capacity == MAXIMUM_CAPACITY)
    {
        threshold = 999999999;
        return;
    }

    auto tempTable = new std::vector<std::vector<Entry>>(newCapacity);
    transfer(tempTable, newCapacity);
    delete table;
    table = tempTable;
    threshold = (int)(newCapacity * loadFactor);
    capacity = newCapacity;
}


void HSet::transfer(std::vector<std::vector<Entry>> *tempTable, int newCapacity) {
    for (auto a : *table)
        for (auto e : a)
            (*tempTable)[getPosition(e.key, newCapacity)].push_back(e);
}

bool HSet::operator==(HSet &other) const {
    if (size() != other.size())
        return false;
    for (auto a : *table)
        for (auto e : a)
            if (!other.contains(e.value))
                return false;

}

std::string HSet::toString() const {
    std::string s = "";
    bool first = true;
    for (auto a : *table)
        for (auto e : a) {
            if (!first)
                s += ", ";
            first = false;
            s += e.value.toString();
        }
    return s;
}




HSet::Entry::Entry(int key, const Restaurant &value) : key(key), value(value) {}
