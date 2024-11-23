#include <iostream>
#include <string>
#include <vector>

#include "doubly_linked_list.hpp"
#include "linked_list\doubly_linked_list.cpp"

#include "test\terminal\unit.hpp"

using namespace std;
using namespace test::terminal;

int main()
{
    Unit unit("Data Structure Test - Doubly Linked List(ADT)");
    unit.add("push(data)");
    unit.add("pop()");
    unit.add("insert(index, data)");
    unit.add("remove(index)");
    unit.add("search(data)");
    unit.add("size()");
    unit.add("empty()");
    unit.add("clear()");
    unit.add("display()");

    DoublyLinkedList<int> linked_list = DoublyLinkedList<int>();

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

                linked_list.push(data);

                break;
            }
            case 2:
            {
                try
                {
                    linked_list.pop();
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
                    unit.print_input_block();

                    int index, data;
                    cin >> index >> data;

                    linked_list.insert(index, data);
                }
                catch (const out_of_range& exception)
                {
                    unit.print_exception_block(exception.what());
                }

                break;
            }
            case 4:
            {
                try
                {
                    unit.print_input_block();

                    int index;
                    cin >> index;

                    linked_list.remove(index);
                }
                catch (const out_of_range& exception)
                {
                    unit.print_exception_block(exception.what());
                }

                break;
            }
            case 5:
            {
                try
                {
                    unit.print_input_block();

                    int index;
                    cin >> index;

                    int output = linked_list.search(index);

                    unit.print_output_block();

                    cout << output << endl;
                }
                catch (const out_of_range& exception)
                {
                    unit.print_exception_block(exception.what());
                }

                break;
            }
            case 6:
            {
                int output = linked_list.size();
                
                unit.print_output_block();

                cout << output << endl;

                break;
            }
            case 7:
            {
                string output = (linked_list.empty() ? "TRUE" : "FALSE");
                
                unit.print_output_block();

                cout << output << endl;

                break;
            }
            case 8:
            {
                linked_list.clear();

                break;
            }
            case 9:
            {
                vector<string> output = linked_list.display();

                unit.print_output_line();

                unit.print_line("FORWARD", Foreground::Default, Background::Default, Style::Bold);
                cout << endl;

                cout << output[0] << endl;

                cout << endl;

                unit.print_line("REVERSE", Foreground::Default, Background::Default, Style::Bold);
                cout << endl;

                cout << output[1] << endl;

                cout << endl;

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