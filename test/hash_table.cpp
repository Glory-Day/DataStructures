#include <iostream>
#include <string>
#include <vector>

#include "hash_table.hpp"
#include "hash_table\hash_table.cpp"

#include "test\terminal\unit.hpp"

using namespace std;
using namespace test::terminal;

int main()
{
    Unit unit("Data Structure Test - Hash Table(ADT)");
    unit.add("Insert(key, value)");
    unit.add("Remove()");
    unit.add("Search(value)");
    unit.add("Display()");

    unit.print();

    unit.print_line("Set Size Of Hash Table : ", Foreground::Yellow, Background::Default, Style::Bold);
    
    int size;
    cin >> size;

    cout << endl;

    HashTable<string> hash_table = HashTable<string>(size);

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

                int key;
                string value;
                cin >> key >> value;
                
                hash_table.insert(Node<string>(key, value));

                break;
            }
            case 2:
            {
                try
                {
                    unit.print_input_block();

                    int key;
                    cin >> key;

                    hash_table.remove(key);
                }
                catch (const std::exception& exception)
                {
                    unit.print_exception_block(exception.what());
                }

                break;
            }
            case 3:
            {
                unit.print_input_block();

                int key;
                cin >> key;

                Node<string>* node = hash_table.search(key);
                string output = (node != nullptr ? node->get_value() : "NONE");

                unit.print_output_block();

                cout << output << endl;

                break;
            }
            case 4:
            {
                unit.print_output_line();

                vector<string> lines = hash_table.display();
                for (int i = 0; i < (int)lines.size(); i++)
                {
                    cout << lines[i] << endl;
                }

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

    return 0;
}