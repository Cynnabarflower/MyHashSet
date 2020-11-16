//
// Created by Dmitry on 16.11.2020.
//

#ifndef UNTITLED56_RESTAURANT_H
#define UNTITLED56_RESTAURANT_H


#include <string>

class Restaurant {
public:
    Restaurant(std::string name);

    const std::string &getName() const;
    void setName(const std::string &name);
    int hash() const;
    std::string toString();
    bool operator==(const Restaurant &other) {
        return getName() == other.getName();
    }

private:
    std::string name;
};



#endif //UNTITLED56_RESTAURANT_H
