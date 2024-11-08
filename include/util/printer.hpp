#ifndef __PRINTER_HPP__
#define __PRINTER_HPP__

#include <iostream>
#include <cctype>
#include <string>
#include <vector>

#include "colorizer.hpp"

using namespace colorize;

class Printer {
private:
    std::string _subject;
    std::vector<std::string> _orders;

public:
    Printer(const std::string subject) : _subject(subject) { }

    void append(const std::string& order);

    void print_subject();
    void print_order();
    void print_input();
    void print_output();
    void print_sucess();
    void print_exception(const std::string& message);
    void print_finish();
};

inline void Printer::append(const std::string& order) {
    _orders.push_back(order);
}

inline void Printer::print_subject() {
    std::cout << std::endl;
    std::cout << set_color(Foreground::Green, Background::Default, Style::Bold) << _subject << COLOR_RESET;
    std::cout << std::endl;

    for (int i = 0; i < (int)_orders.size(); i++) {
        std::cout << "(" << i + 1 << ") " << _orders[i] << std::endl;
    }

    std::cout << std::endl;
}

inline void Printer::print_order() {
    std::cout << set_color(Foreground::Yellow) << "[ORDER ] " << COLOR_RESET;
}

inline void Printer::print_input() {
    std::cout << set_color(Foreground::Yellow) << "[INPUT ] " << COLOR_RESET;
}

inline void Printer::print_output() {
    std::cout << set_color(Foreground::Yellow) << "[OUTPUT] " << COLOR_RESET;
}

inline void Printer::print_sucess() {
    std::cout << set_color(Foreground::Green) << "[OK    ]" << COLOR_RESET << std::endl;
}

inline void Printer::print_exception(const std::string& message) {
    std::cout << set_color(Foreground::Red) << "[ERROR ] " << message << COLOR_RESET << std::endl;
}

inline void Printer::print_finish() {
    std::cout << set_color(Foreground::Red) << "[FINISH] " << COLOR_RESET << std::endl;
    std::cout << std::endl;
}

#endif