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

    unit.print_line_block("Set size of hash table");
    unit.print_input_block();

    int size;
    cin >> size;

    HashTable hash_table = HashTable(size);
    Node* value = nullptr;

    unit.print();

    bool isLoop = true;
    while (isLoop == true)
    {
        unit.print_command_block();

        int index;
        cin >> index;

        switch (index)
        {
            case 1:
            {
                unit.print_input_block();

                int key;
                string value;
                cin >> key >> value;
                
                hash_table.insert(Node(key, value));

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

                value = hash_table.search(key);
                string output = (value != nullptr ? value->value : "NONE");

                unit.print_output_block();

                cout << output << endl;

                break;
            }
            case 4:
            {
                vector<string> lines = hash_table.display();
                for (int i = 0; i < (int)lines.size(); i++)
                {
                    unit.print_output_block();

                    cout << lines[i] << endl;
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

    return 0;
}