//
// Created by Kostantin Alaev on 17.11.2020.
//

#ifndef BENCHMARK_C_MYCLASS_H
#define BENCHMARK_C_MYCLASS_H


struct MyClass {
    friend bool operator==(const MyClass &lhs, const MyClass &rhs) {
        return lhs.c == rhs.c;
    }

    int a[100];
    int c = 0;
};

#endif //BENCHMARK_C_MYCLASS_H
