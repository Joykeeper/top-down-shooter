#pragma once
#include <vector>
#include <memory>
#include <iostream>


template <typename T>
class Handler {
    std::vector<std::unique_ptr<T>> items = std::vector<std::unique_ptr<T>>();
public:
    Handler(){};

    void add(std::unique_ptr<T> elem) {
        items.push_back(std::move(elem));
    }

    void addAll(std::vector<std::unique_ptr<T>> toInsert){
        items.insert(items.end(),
                     std::make_move_iterator(toInsert.begin()),
                     std::make_move_iterator(toInsert.end()));
    };

    void remove(T *elem) {
        auto it = std::find_if(items.begin(), items.end(),
                               [elem](const std::unique_ptr<T>& ptr) {
                                   return ptr.get() == elem;
                               });
        if (it != items.end()) {
            items.erase(it);
        }
    };

    void clear(){
        items.clear();
    }

    std::vector<std::unique_ptr<T>>& getItems() {
        return this->items;
    };
};









