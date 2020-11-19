//
// Created by Kostantin Alaev on 19.11.2020.
//

#ifndef BENCHMARK_C_SET_H
#define BENCHMARK_C_SET_H

#include <set>
#include "MyClass.h"
#include <typeinfo>


template<typename T> std::multiset<T> multisetT;

template<typename T>
const std::multiset<T> &multiset_insert(int64_t count) {
    multisetT<T>.clear();
    T obj;

    for (int i = 0; i < count; ++i) {
        multisetT<T>.insert(obj);
    }

    return multisetT<T>;
}

std::multiset<int> multisetI;

const std::multiset<int> &multiset_insert_int(int64_t count) {
    multisetI.clear();
    for (int i = 0; i < count; ++i) {
        multisetI.insert(i);
    }

    return multisetI;
}

void multiset_insert_int(benchmark::State &state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(
                multiset_insert_int(state.range_x())
        );
    }
}

void multiset_insert_myType(benchmark::State &state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(
                multiset_insert<MyClass>(state.range_x())
        );
    }
}

BENCHMARK(multiset_insert_int)->Arg(100);
BENCHMARK(multiset_insert_int)->Arg(10000);
BENCHMARK(multiset_insert_int)->Arg(1000000);

BENCHMARK(multiset_insert_myType)->Arg(100);
BENCHMARK(multiset_insert_myType)->Arg(10000);
BENCHMARK(multiset_insert_myType)->Arg(1000000);

// ##################################
//  Random access
// ##################################

template<typename T>
const std::multiset<T> &multiset_random_access(const std::multiset<T> &multisetInput) {
    for (auto it : multisetInput) { ;
    }

    return multisetInput;
}

static void multiset_random_access_int(benchmark::State &state) {
    for (auto _ : state) {
        state.PauseTiming();
        auto multisetInput = multiset_insert_int(state.range_x());
        state.ResumeTiming();

        benchmark::DoNotOptimize(
                multiset_random_access<int>(multisetInput)
        );
    }
}

static void multiset_random_access_myType(benchmark::State &state) {
    for (auto _ : state) {
        state.PauseTiming();
        auto multisetInput = multiset_insert<MyClass>(state.range_x());
        state.ResumeTiming();

        benchmark::DoNotOptimize(
                multiset_random_access<MyClass>(multisetInput)
        );
    }
}

BENCHMARK(multiset_random_access_int)->Arg(100);
BENCHMARK(multiset_random_access_int)->Arg(10000);
BENCHMARK(multiset_random_access_int)->Arg(1000000);

BENCHMARK(multiset_random_access_myType)->Arg(100);
BENCHMARK(multiset_random_access_myType)->Arg(10000);
BENCHMARK(multiset_random_access_myType)->Arg(1000000);

// ##################################
//  find
// ##################################

template<typename T>
const std::multiset<T> &multiset_find(const std::multiset<T> &multisetInput) {
    T obj;
    auto it = multisetInput.find(obj);

    return multisetInput;
}

static void multiset_find_int(benchmark::State &state) {
    for (auto _ : state) {
        state.PauseTiming();
        auto multisetInput = multiset_insert_int(state.range_x());
        state.ResumeTiming();

        benchmark::DoNotOptimize(
                multiset_find<int>(multisetInput)
        );
    }
}

static void multiset_find_myType(benchmark::State &state) {
    for (auto _ : state) {
        state.PauseTiming();
        auto multisetInput = multiset_insert<MyClass>(state.range_x());
        state.ResumeTiming();

        benchmark::DoNotOptimize(
                multiset_find<MyClass>(multisetInput)
        );
    }
}

BENCHMARK(multiset_find_int)->Arg(100);
BENCHMARK(multiset_find_int)->Arg(10000);
BENCHMARK(multiset_find_int)->Arg(1000000);

BENCHMARK(multiset_find_myType)->Arg(100);
BENCHMARK(multiset_find_myType)->Arg(10000);
BENCHMARK(multiset_find_myType)->Arg(1000000);

#endif //BENCHMARK_C_SET_H
