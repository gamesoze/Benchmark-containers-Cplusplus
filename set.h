//
// Created by Kostantin Alaev on 19.11.2020.
//

#ifndef BENCHMARK_C_SET_H
#define BENCHMARK_C_SET_H

#include <set>
#include "MyClass.h"
#include <typeinfo>


template<typename T> std::set<T> setT;

template<typename T>
const std::set<T> &set_insert(int64_t count) {
    setT<T>.clear();
    T obj;

    for (int i = 0; i < count; ++i) {
        setT<T>.insert(obj);
    }

    return setT<T>;
}

std::set<int> setI;

const std::set<int> &set_insert_int(int64_t count) {
    setI.clear();
    for (int i = 0; i < count; ++i) {
        setI.insert(i);
    }

    return setI;
}

void set_insert_int(benchmark::State &state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(
                set_insert_int(state.range_x())
        );
    }
}

void set_insert_myType(benchmark::State &state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(
                set_insert<MyClass>(state.range_x())
        );
    }
}

BENCHMARK(set_insert_int)->Arg(100);
BENCHMARK(set_insert_int)->Arg(10000);
BENCHMARK(set_insert_int)->Arg(1000000);

BENCHMARK(set_insert_myType)->Arg(100);
BENCHMARK(set_insert_myType)->Arg(10000);
BENCHMARK(set_insert_myType)->Arg(1000000);

// ##################################
//  Random access
// ##################################

template<typename T>
const std::set<T> &set_random_access(const std::set<T> &setInput) {
    for (auto it : setInput) { ;
    }

    return setInput;
}

static void set_random_access_int(benchmark::State &state) {
    for (auto _ : state) {

        state.PauseTiming();
        const std::set<int> &setInput = set_insert_int(state.range_x());
        state.ResumeTiming();

        benchmark::DoNotOptimize(
                set_random_access<int>(setInput)
        );
    }
}

static void set_random_access_myType(benchmark::State &state) {
    for (auto _ : state) {

        state.PauseTiming();
        const std::set<MyClass> &setInput = set_insert<MyClass>(state.range_x());
        state.ResumeTiming();

        benchmark::DoNotOptimize(
                set_random_access<MyClass>(setInput)
        );
    }
}

BENCHMARK(set_random_access_int)->Arg(100);
BENCHMARK(set_random_access_int)->Arg(10000);
BENCHMARK(set_random_access_int)->Arg(1000000);

BENCHMARK(set_random_access_myType)->Arg(100);
BENCHMARK(set_random_access_myType)->Arg(10000);
BENCHMARK(set_random_access_myType)->Arg(1000000);

// ##################################
//  find
// ##################################

template<typename T>
const std::set<T> &set_find(const std::set<T> &setInput) {
    T obj;
    auto it = setInput.find(obj);

    return setInput;
}

static void set_find_int(benchmark::State &state) {
    for (auto _ : state) {

        state.PauseTiming();
        const std::set<int> &setInput = set_insert_int(state.range_x());
        state.ResumeTiming();

        benchmark::DoNotOptimize(
                set_find<int>(setInput)
        );
    }
}

static void set_find_myType(benchmark::State &state) {
    for (auto _ : state) {

        state.PauseTiming();
        const std::set<MyClass> &setInput = set_insert<MyClass>(state.range_x());
        state.ResumeTiming();

        benchmark::DoNotOptimize(
                set_find<MyClass>(setInput)
        );
    }
}

BENCHMARK(set_find_int)->Arg(100);
BENCHMARK(set_find_int)->Arg(10000);
BENCHMARK(set_find_int)->Arg(1000000);

BENCHMARK(set_find_myType)->Arg(100);
BENCHMARK(set_find_myType)->Arg(10000);
BENCHMARK(set_find_myType)->Arg(1000000);

#endif //BENCHMARK_C_SET_H
