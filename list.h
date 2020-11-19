//
// Created by Kostantin Alaev on 17.11.2020.
//

#include <list>
#include "MyClass.h"

#ifndef BENCHMARK_C_BEN_VECTOR_H
#define BENCHMARK_C_BEN_VECTOR_H


using test_cont = std::list<int>;

// ##################################
//  Push back
// ##################################

template<typename T>
const std::list<T> &list_push_back(int64_t count) {
    std::list<T> list;
    T obj;

    for (int i = 0; i < count; ++i) {
        list.push_back(obj);
    }

    return list;
}

// ##################################
//  Push front
// ##################################

template<typename T>
const std::list<T> &list_push_front(int64_t count) {
    std::list<T> list;
    T obj;

    for (int i = 0; i < count; ++i) {
        list.insert(list.begin(), obj);
    }

    return list;
}

// ##################################
//  Random access
// ##################################

template<typename T>
const std::list<T> &list_random_access(int64_t count) {
    T obj;
    std::list<T> list(count, obj);

    for (auto it : list) {
        it;
    }

    return list;
}

// ##################################
//  find
// ##################################

const std::list<int> &list_find_int(int64_t count) {
    std::list<int> list(count, 0);

    std::list<int>::iterator it_end = list.end();
    *(--it_end) = 1;

    auto it = std::find(list.begin(), list.end(), 1);

    return list;
}

const std::list<MyClass> &list_find_myType(int64_t count) {
    MyClass obj;
    std::list<MyClass> list(count, obj);

    std::list<MyClass>::iterator it_end = list.end();
    (--it_end)->c = 1;
    obj.c = 1;

    auto it = std::find(list.begin(), list.end(), obj);

    return list;
}

void list_push_back_int(benchmark::State &state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(
                list_push_back<int>(state.range_x())
        );
    }
}


BENCHMARK(list_push_back_int)->Arg(100);
BENCHMARK(list_push_back_int)->Arg(10000);
BENCHMARK(list_push_back_int)->Arg(1000000);

// ##################################
//  Push front int
// ##################################

void list_push_front_int(benchmark::State &state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(
                list_push_front<int>(state.range_x())
        );
    }
}


BENCHMARK(list_push_front_int)->Arg(100);
BENCHMARK(list_push_front_int)->Arg(10000);


// ##################################
//  Push back myType
// ##################################

void list_push_back_myType(benchmark::State &state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(
                list_push_back<MyClass>(state.range_x())
        );
    }
}

BENCHMARK(list_push_back_myType)->Arg(100);
BENCHMARK(list_push_back_myType)->Arg(10000);

// ##################################
//  Push front myType
// ##################################

void list_push_front_myType(benchmark::State &state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(
                list_push_front<MyClass>(state.range_x())
        );
    }
}

BENCHMARK(list_push_front_myType)->Arg(100);
BENCHMARK(list_push_front_myType)->Arg(10000);

// ##################################
//  Random access
// ##################################

void list_random_access_int(benchmark::State &state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(
                list_random_access<int>(state.range_x())
        );
    }
}

void list_random_access_myType(benchmark::State &state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(
                list_random_access<MyClass>(state.range_x())
        );
    }
}

BENCHMARK(list_random_access_int)->Arg(100);
BENCHMARK(list_random_access_int)->Arg(10000);
BENCHMARK(list_random_access_int)->Arg(1000000);

BENCHMARK(list_random_access_myType)->Arg(100);
BENCHMARK(list_random_access_myType)->Arg(10000);
BENCHMARK(list_random_access_myType)->Arg(1000000);

// ##################################
// find
// ##################################

void list_find_int_test(benchmark::State &state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(
                list_find_int(state.range_x())
        );
    }
}

void list_find_myType_test(benchmark::State &state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(
                list_find_myType(state.range_x())
        );
    }
}

BENCHMARK(list_find_int_test)->Arg(100);
BENCHMARK(list_find_int_test)->Arg(10000);
BENCHMARK(list_find_int_test)->Arg(1000000);

BENCHMARK(list_find_myType_test)->Arg(100);
BENCHMARK(list_find_myType_test)->Arg(10000);
BENCHMARK(list_find_myType_test)->Arg(1000000);


#endif //BENCHMARK_C_BEN_VECTOR_H