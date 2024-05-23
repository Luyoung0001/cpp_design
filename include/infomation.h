#ifndef INFOMATION_H_
#define INFOMATION_H_
#include <iostream>
class Infomation {
    int age;
    int weight;

  public:
    // 有参、默认构造
    Infomation(int a = 0, int w = 0) : age(a), weight(w) {}
    // 复制构造
    Infomation(const Infomation &info) : age(info.age), weight(info.weight) {}
    // 移动构造
    Infomation(Infomation &&info) noexcept
        : age(info.age), weight(info.weight) {}
    // 复制赋值操作符
    Infomation operator=(const Infomation &info) {
        if (this != &info) {
            age = info.age;
            weight = info.weight;
        }
        return *this;
    }
    // 移动赋值操作符
    Infomation operator=(Infomation &&info) {
        if (this != &info) {
            age = info.age;
            weight = info.weight;
            info.age = 0;
            info.weight = 0;
        }
        return *this;
    }

    void infoSet(int newAge, int newWeight) {
        age = newAge;
        weight = newWeight;
    }
    void printInfo() const {
        std::cout << " age: " << age << ", weight: " << weight << std::endl;
    }
    ~Infomation() {}
};
#endif