#include <iostream>
#include <string>

#include "binary_search_tree.hpp"
#include "tree\binary_search_tree.cpp"

#include "test\terminal\unit.hpp"

using namespace std;
using namespace test::terminal;

int main()
{
    Unit unit("Data Structure Test - Binary Search Tree(ADT)");
    unit.add("insert(data)");
    unit.add("remove(data)");
    unit.add("search(data)");
    unit.add("traversal()");
    unit.add("display()");

    BinarySearchTree<int> tree = BinarySearchTree<int>();

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
                try
                {
                    unit.print_input_block();

                    int data;
                    cin >> data;

                    tree.insert(data);
                }
                catch (const invalid_argument& exception)
                {
                    unit.print_exception_block(exception.what());
                }

                break;
            }
            case 2:
            {
                try
                {
                    unit.print_input_block();

                    int data;
                    cin >> data;

                    tree.remove(data);
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

                    int data;
                    cin >> data;

                    string output = (tree.search(data) ? "TRUE" : "FALSE");

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
                vector<string> output = tree.traversal();

                unit.print_output_line();

                unit.print_line("Preorder", Foreground::Default, Background::Default, Style::Bold);
                cout << endl;

                cout << output[0] << endl;

                cout << endl;

                unit.print_line("Inorder", Foreground::Default, Background::Default, Style::Bold);
                cout << endl;

                cout << output[1] << endl;

                cout << endl;

                unit.print_line("Post-order", Foreground::Default, Background::Default, Style::Bold);
                cout << endl;

                cout << output[2] << endl;

                cout << endl;

                break;
            }
            case 5:
            {
                unit.print_output_line();

                vector<string> output = tree.display();
                for (int i = 0; i < (int)output.size(); i++)
                {
                    cout << output[i] << endl;
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