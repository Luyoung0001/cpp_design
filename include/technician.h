#ifndef TECHNICIAN_H_
#define TECHNICIAN_H_
#include "infomation.h"
#include "employee.h"

class Technician : public Employee {
    int hour;          // 工作时长
    double hourlyRate; // 时薪
  public:
    Technician(int h = 0, double r = 0) : Employee(), hour(h), hourlyRate(r) {}
    // 复制构造
    Technician(const Technician &tech)
        : Employee(tech), hour(tech.hour), hourlyRate(tech.hourlyRate) {}
    // 移动构造
    Technician(Technician &&tech) noexcept
        : Employee(std::move(tech)), hour(tech.hour),
          hourlyRate(tech.hourlyRate) {
        tech.hour = 0;
        tech.hourlyRate = 0;
    }
    // 复制赋值
    Technician &operator=(const Technician &tech) {
        if (this != &tech) {
            Employee::operator=(tech);
            hour = tech.hour;
            hourlyRate = tech.hourlyRate;
        }
        return *this;
    }
    // 移动赋值
    Technician &operator=(Technician &&tech) noexcept {
        if (this != &tech) {
            Employee::operator=(std::move(tech));
            hour = tech.hour;
            hourlyRate = tech.hourlyRate;

            tech.hour = 0;
            tech.hourlyRate = 0;
        }
        return *this;
    }
    // 完美转发
    Technician(Employee &&emP, int h = 0, double hourlyR = 0)
        : Employee(std::forward<Employee>(emP)), hour(h), hourlyRate(hourlyR) {}

    void setHour(int h) { hour = h; }
    int getHour() { return hour; }
    void setHourlyRate(double H) { hourlyRate = H; }
    double getHourlyRate() { return hourlyRate; }

    // override
    void writeFile() override {}
    void pay() override { money = hour * hourlyRate; }
    void showType() const override {
        std::cout << "技术类员工";
        ;
    }
    void showInfo() const override {
        showType();
        Employee::showInfo();
    }
    ~Technician() {}
};
#endif