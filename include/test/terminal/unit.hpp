#ifndef __UNIT_HPP__
#define __UNIT_HPP__

#include <iostream>
#include <cctype>
#include <string>
#include <vector>

#include "colorizer.hpp"

using namespace std;

namespace test::terminal
{
    class Unit
    {
    private:
        string _title;
        vector<string> _commands;

    public:
        Unit(const string title) : _title(title) {}

        void add(const string command);

        void print();
        void print_line_block(const string&);
        void print_command_block();
        void print_input_block();
        void print_output_block();
        void print_sucess_block();
        void print_exception_block(const string&);
        void print_finish_block();
    };

    /**
     * Add the command to the test unit.
     * 
     * @param command: Command for testing.
     */
    inline void Unit::add(const string command)
    {
        _commands.push_back(command);
    }

    /**
     * Print the title and all commands in the test unit.
     */
    inline void Unit::print()
    {
        cout << endl;
        cout << set_color(Foreground::Green, Background::Default, Style::Bold) << _title << COLOR_RESET;
        cout << endl;

        for (int i = 0; i < (int)_commands.size(); i++)
        {
            cout << "(" << i + 1 << ") " << _commands[i] << endl;
        }

        cout << endl;
    }

    inline void Unit::print_line_block(const string& line)
    {
        cout << set_color(Foreground::Yellow) << "[LINE  ] " << COLOR_RESET;
        cout << line << endl; 
    }

    inline void Unit::print_command_block()
    {
        cout << set_color(Foreground::Yellow) << "[CMD   ] " << COLOR_RESET;
    }

    inline void Unit::print_input_block()
    {
        cout << set_color(Foreground::Yellow) << "[INPUT ] " << COLOR_RESET;
    }

    inline void Unit::print_output_block()
    {
        cout << set_color(Foreground::Yellow) << "[OUTPUT] " << COLOR_RESET;
    }

    inline void Unit::print_sucess_block()
    {
        cout << set_color(Foreground::Green) << "[OK    ]" << COLOR_RESET << endl;
    }

    inline void Unit::print_exception_block(const string& message)
    {
        cout << set_color(Foreground::Red) << "[ERROR ] " << message << COLOR_RESET << endl;
    }

    inline void Unit::print_finish_block()
    {
        cout << set_color(Foreground::Red) << "[FINISH] " << COLOR_RESET << endl;
        cout << endl;
    }
}

#endif