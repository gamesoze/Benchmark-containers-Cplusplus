//
// Created by Kostantin Alaev on 17.11.2020.
//

#include <vector>
#include "MyClass.h"

#ifndef BENCHMARK_C_BEN_VECTOR_H
#define BENCHMARK_C_BEN_VECTOR_H


using test_cont = std::vector<int>;

// ##################################
//  Push back
// ##################################

template<typename T>
const std::vector<T> &vector_push_back(int64_t count) {
    std::vector<T> vec;
    T obj;

    for (int i = 0; i < count; ++i) {
        vec.push_back(obj);
    }

    return vec;
}

template<typename T>
const std::vector<T> &vector_push_back_reserve(int64_t count) {
    std::vector<T> vec;
    vec.reserve(count);
    T obj;

    for (int i = 0; i < count; ++i) {
        vec.push_back(obj);
    }

    return vec;
}

// ##################################
//  Push front
// ##################################

template<typename T>
const std::vector<T> &vector_push_front(int64_t count) {
    std::vector<T> vec;
    T obj;

    for (int i = 0; i < count; ++i) {
        vec.insert(vec.begin(), obj);
    }

    return vec;
}

template<typename T>
const std::vector<T> &vector_push_front_reserve(int64_t count) {
    std::vector<T> vec;
    vec.reserve(count);
    T obj;

    for (int i = 0; i < count; ++i) {
        vec.insert(vec.begin(), obj);
    }

    return vec;
}

// ##################################
//  Random access
// ##################################

template<typename T>
const std::vector<T> &vector_random_access(int64_t count) {
    T obj;
    std::vector<T> vec(count, obj);

    for (int i = 0; i < count; ++i) {
        vec[i];
    }

    return vec;
}

// ##################################
//  find
// ##################################

const std::vector<int> &vector_find_int(int64_t count) {
    std::vector<int> vec(count, 0);

    vec[count - 1] = 1;

    auto it = std::find(vec.begin(), vec.end(), 1);

    return vec;
}

const std::vector<MyClass> &vector_find_myType(int64_t count) {
    MyClass obj;
    std::vector<MyClass> vec(count, obj);

    vec[count - 1].c = 1;
    obj.c = 1;

    auto it = std::find(vec.begin(), vec.end(), obj);

    return vec;
}


#endif //BENCHMARK_C_BEN_VECTOR_H