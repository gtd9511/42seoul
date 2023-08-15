#pragma once
# ifndef EASY_FIND_HPP
# define EASY_FIND_HPP
#include <iostream>
#include <vector>
#include <list>
#include <deque>

template <typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::runtime_error("Value not found in the container");
    }
    return it;
}

#endif 