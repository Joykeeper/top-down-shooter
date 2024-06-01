#pragma once
#include <vector>


template <typename T>
class OldHandler {
    std::vector<T *> items = std::vector<T *>();
public:
    OldHandler(){};

    void add(T *elem) {
        this->items.push_back(elem);
    };

    void addAll(std::vector<T *> toInsert){
        this->items.insert(this->items.end(),
                           toInsert.begin(),
                           toInsert.end());
    };

    void remove(T *elem) {
        std::erase(this->items, elem);
        delete elem;
    };

    std::vector<T *> getItems() const {
        return this->items;
    };
};









