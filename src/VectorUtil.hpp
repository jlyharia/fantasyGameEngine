//
// Created by Yihung Lee on 5/31/18.
//

#ifndef FANTASY_VECTORUTIL_HPP
#define FANTASY_VECTORUTIL_HPP

#include <vector>
#include <iostream>
#include <glm/vec4.hpp>
#include <glm/vec3.hpp>

template<typename T>
void print(std::vector<T> vec) {
    for (auto i: vec) {
        std::cout << i << " ";
    }
    std::cout << '\n';
}


void print(glm::vec4 vec, size_t st = 4) {
    for (int i = 0; i < st; i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << '\n';
}

void print(glm::vec3 vec) {
    print(glm::vec4(vec, 0), 3);
}

#endif //FANTASY_VECTORUTIL_HPP
