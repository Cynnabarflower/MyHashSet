//
// Created by Dmitry on 16.11.2020.
//

#include "Restaurant.h"

#include <utility>

const std::string &Restaurant::getName() const {
    return name;
}

void Restaurant::setName(const std::string &name) {
    Restaurant::name = name;
}

int Restaurant::hash() const {
    //todo
//    int hash = 0;
//    for (int i = 0; i < name.length(); i++)
//        hash += name.at(i);
//    return name.length() + name[0];
//для примера, чтобы посмотреть коллизии
return name.length();
}

std::string Restaurant::toString() {
    return getName();
}

Restaurant::Restaurant(std::string name) : name(std::move(name)) {}
