#include <iostream>
#include <string>

#include "stack.hpp"
#include "stack\stack.cpp"

#include "test\terminal\unit.hpp"

using namespace std;
using namespace test::terminal;

int main()
{
    Unit unit("Data Structure Test - Stack(ADT)");
    unit.add("push(data)");
    unit.add("pop()");
    unit.add("top()");
    unit.add("empty()");

    Stack<int> stack = Stack<int>();

    unit.print();

    bool is_loop = true;
    while (is_loop == true)
    {
        unit.print_command_block();

        int command;
        cin >> command;

        switch (command)
        {
            case 1:
            {
                unit.print_input_block();

                int data;
                cin >> data;

                stack.push(data);

                break;
            }
            case 2:
            {
                try
                {
                    stack.pop();
                }
                catch (const out_of_range& exception)
                {
                    unit.print_exception_block(exception.what());
                }

                break;
            }
            case 3:
            {
                try
                {
                    int output = stack.top();

                    unit.print_output_block();

                    cout << output << endl;
                }
                catch (const out_of_range& exception)
                {
                    unit.print_exception_block(exception.what());
                }

                break;
            }
            case 4:
            {
                string output = (stack.empty() ? "TRUE" : "FALSE");

                unit.print_output_block();

                cout << output << endl;

                break;
            }
            default:
            {
                is_loop = false;

                break;
            }
        }

        if (is_loop)
        {
            unit.print_sucess_block();
        }
        else
        {
            unit.print_finish_block();
        }

        cin.clear();
        cin.ignore();
    }

    return 0;
}