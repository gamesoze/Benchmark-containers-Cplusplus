//
// Created by Kostantin Alaev on 17.11.2020.
//

#include <deque>
#include "MyClass.h"

#ifndef BENCHMARK_C_BEN_VECTOR_H
#define BENCHMARK_C_BEN_VECTOR_H

// ##################################
//  Push back
// ##################################

template<typename T>
const std::deque<T> &deque_push_back(int64_t count) {
    std::deque<T> deque;
    T obj;

    for (int i = 0; i < count; ++i) {
        deque.push_back(obj);
    }

    return deque;
}

// ##################################
//  Push front
// ##################################

template<typename T>
const std::deque<T> &deque_push_front(int64_t count) {
    std::deque<T> deque;
    T obj;

    for (int i = 0; i < count; ++i) {
        deque.insert(deque.begin(), obj);
    }

    return deque;
}

// ##################################
//  Random access
// ##################################

template<typename T>
const std::deque<T> &deque_random_access(int64_t count) {
    T obj;
    std::deque<T> deque(count, obj);

    for (int i = 0; i < count; ++i) {
        deque[i];
    }

    return deque;
}

// ##################################
//  find
// ##################################

const std::deque<int> &deque_find_int(int64_t count) {
    std::deque<int> deque(count, 0);

    auto it = std::find(deque.begin(), deque.end(), 1);

    return deque;
}

const std::deque<MyClass> &deque_find_myType(int64_t count) {
    MyClass obj;
    std::deque<MyClass> deque(count, obj);

    auto it = std::find(deque.begin(), deque.end(), obj);

    return deque;
}

void deque_push_back_int(benchmark::State &state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(
                deque_push_back<int>(state.range_x())
        );
    }
}


BENCHMARK(deque_push_back_int)->Arg(100);
BENCHMARK(deque_push_back_int)->Arg(10000);
BENCHMARK(deque_push_back_int)->Arg(1000000);

// ##################################
//  Push front int
// ##################################

void deque_push_front_int(benchmark::State &state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(
                deque_push_front<int>(state.range_x())
        );
    }
}


BENCHMARK(deque_push_front_int)->Arg(100);
BENCHMARK(deque_push_front_int)->Arg(10000);


// ##################################
//  Push back myType
// ##################################

void deque_push_back_myType(benchmark::State &state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(
                deque_push_back<MyClass>(state.range_x())
        );
    }
}

BENCHMARK(deque_push_back_myType)->Arg(100);
BENCHMARK(deque_push_back_myType)->Arg(10000);

// ##################################
//  Push front myType
// ##################################

void deque_push_front_myType(benchmark::State &state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(
                deque_push_front<MyClass>(state.range_x())
        );
    }
}

BENCHMARK(deque_push_front_myType)->Arg(100);
BENCHMARK(deque_push_front_myType)->Arg(10000);

// ##################################
//  Random access
// ##################################

void deque_random_access_int(benchmark::State &state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(
                deque_random_access<int>(state.range_x())
        );
    }
}

void deque_random_access_myType(benchmark::State &state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(
                deque_random_access<MyClass>(state.range_x())
        );
    }
}

BENCHMARK(deque_random_access_int)->Arg(100);
BENCHMARK(deque_random_access_int)->Arg(10000);
BENCHMARK(deque_random_access_int)->Arg(1000000);

BENCHMARK(deque_random_access_myType)->Arg(100);
BENCHMARK(deque_random_access_myType)->Arg(10000);
BENCHMARK(deque_random_access_myType)->Arg(1000000);

// ##################################
// find
// ##################################

void deque_find_int_test(benchmark::State &state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(
                deque_find_int(state.range_x())
        );
    }
}

void deque_find_myType_test(benchmark::State &state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(
                deque_find_myType(state.range_x())
        );
    }
}

BENCHMARK(deque_find_int_test)->Arg(100);
BENCHMARK(deque_find_int_test)->Arg(10000);
BENCHMARK(deque_find_int_test)->Arg(1000000);

BENCHMARK(deque_find_myType_test)->Arg(100);
BENCHMARK(deque_find_myType_test)->Arg(10000);
BENCHMARK(deque_find_myType_test)->Arg(1000000);

#endif //BENCHMARK_C_BEN_VECTOR_H