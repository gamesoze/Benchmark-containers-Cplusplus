//
// Created by Kostantin Alaev on 17.11.2020.
//

#include <vector>
#include <iostream>
#include "MyClass.h"

#ifndef BENCHMARK_C_BEN_VECTOR_H
#define BENCHMARK_C_BEN_VECTOR_H

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

    auto it = std::find(vec.begin(), vec.end(), 1);

    return vec;
}

const std::vector<MyClass> &vector_find_myType(int64_t count) {
    MyClass obj;
    std::vector<MyClass> vec(count, obj);

    auto it = std::find(vec.begin(), vec.end(), obj);

    return vec;
}

void vector_push_back_int(benchmark::State &state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(
                vector_push_back<int>(state.range_x())
        );
    }
}

void vector_push_back_reserve_int(benchmark::State &state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(
                vector_push_back_reserve<int>(state.range_x())
        );
    }
}


BENCHMARK(vector_push_back_int)->Arg(100);
BENCHMARK(vector_push_back_int)->Arg(10000);
BENCHMARK(vector_push_back_int)->Arg(1000000);

BENCHMARK(vector_push_back_reserve_int)->Arg(100);
BENCHMARK(vector_push_back_reserve_int)->Arg(10000);
BENCHMARK(vector_push_back_reserve_int)->Arg(1000000);

// ##################################
//  Push front int
// ##################################

void vector_push_front_int(benchmark::State &state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(
                vector_push_front<int>(state.range_x())
        );
    }
}

void vector_push_front_int_reserve(benchmark::State &state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(
                vector_push_front_reserve<int>(state.range_x())
        );
    }
}


BENCHMARK(vector_push_front_int)->Arg(100);
BENCHMARK(vector_push_front_int)->Arg(10000);

BENCHMARK(vector_push_front_int_reserve)->Arg(100);
BENCHMARK(vector_push_front_int_reserve)->Arg(10000);


// ##################################
//  Push back myType
// ##################################

void vector_push_back_myType(benchmark::State &state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(
                vector_push_back<MyClass>(state.range_x())
        );
    }
}

void vector_push_back_myType_reserve(benchmark::State &state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(
                vector_push_back_reserve<MyClass>(state.range_x())
        );
    }
}

BENCHMARK(vector_push_back_myType)->Arg(100);
BENCHMARK(vector_push_back_myType)->Arg(10000);

BENCHMARK(vector_push_back_myType_reserve)->Arg(100);
BENCHMARK(vector_push_back_myType_reserve)->Arg(10000);

// ##################################
//  Push front myType
// ##################################

void vector_push_front_myType(benchmark::State &state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(
                vector_push_front<MyClass>(state.range_x())
        );
    }
}

void vector_push_front_myType_reserve(benchmark::State &state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(
                vector_push_front_reserve<MyClass>(state.range_x())
        );
    }
}

BENCHMARK(vector_push_front_myType)->Arg(100);
BENCHMARK(vector_push_front_myType)->Arg(10000);

BENCHMARK(vector_push_front_myType_reserve)->Arg(100);
BENCHMARK(vector_push_front_myType_reserve)->Arg(10000);


// ##################################
//  Random access
// ##################################

static void vector_random_access_int(benchmark::State &state) {
    for (auto _ : state)
        benchmark::DoNotOptimize(
                vector_random_access<int>(state.range_x())
        );
}

void vector_random_access_myType(benchmark::State &state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(
                vector_random_access<MyClass>(state.range_x())
        );
    }
}

BENCHMARK(vector_random_access_int)->Arg(100);
BENCHMARK(vector_random_access_int)->Arg(10000);
BENCHMARK(vector_random_access_int)->Arg(1000000);

BENCHMARK(vector_random_access_myType)->Arg(100);
BENCHMARK(vector_random_access_myType)->Arg(10000);
BENCHMARK(vector_random_access_myType)->Arg(1000000);

// ##################################
// find
// ##################################

void vector_find_int_test(benchmark::State &state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(
                vector_find_int(state.range_x())
        );
    }
}

void vector_find_myType_test(benchmark::State &state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(
                vector_find_myType(state.range_x())
        );
    }
}

BENCHMARK(vector_find_int_test)->Arg(100);
BENCHMARK(vector_find_int_test)->Arg(10000);
BENCHMARK(vector_find_int_test)->Arg(1000000);

BENCHMARK(vector_find_myType_test)->Arg(100);
BENCHMARK(vector_find_myType_test)->Arg(10000);
BENCHMARK(vector_find_myType_test)->Arg(1000000);

#endif //BENCHMARK_C_BEN_VECTOR_H