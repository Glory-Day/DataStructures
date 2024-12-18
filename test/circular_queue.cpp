#include <iostream>
#include <string>

#include "circular_queue.hpp"
#include "queue\circular_queue.cpp"

#include "test\terminal\unit.hpp"

using namespace std;
using namespace test::terminal;

int main()
{
    Unit unit("Data Structure Test - Circular Queue(ADT)");
    unit.add("enqueue(data)");
    unit.add("dequeue()");
    unit.add("front()");
    unit.add("empty()");

    CircularQueue<int> queue = CircularQueue<int>();

    unit.print();

    bool is_loop = true;
    while (is_loop)
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
                
                queue.enqueue(data);
                
                break;
            }
            case 2:
            {
                try
                {
                    queue.dequeue();
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
                    int output = queue.front();

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
                string output = (queue.empty() ? "TRUE" : "FALSE");
                
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
}