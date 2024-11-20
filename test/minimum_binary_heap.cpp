#include <iostream>

#include "minimum_binary_heap.hpp"
#include "tree\binary_heap\minimum_binary_heap\minimum_binary_heap.cpp"

#include "test\terminal\unit.hpp"

using namespace std;
using namespace test::terminal;

int main()
{
    Unit unit("Data Structure Test - Minimum Binary Heap(ADT)");
    unit.add("insert(data)");
    unit.add("extract()");
    unit.add("top()");

    MinimumBinaryHeap<int> heap = MinimumBinaryHeap<int>();

    unit.print();

    bool isLoop = true;
    while (isLoop)
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

                heap.insert(data);

                break;
            }
            case 2:
            {
                try
                {
                    heap.extract();
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
                    int output = heap.top();

                    unit.print_output_block();

                    cout << output << endl;
                }
                catch (const out_of_range& exception)
                {
                    unit.print_exception_block(exception.what());
                }

                break;
            }
            default:
            {
                isLoop = false;

                break;
            }
        }

        if (isLoop)
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