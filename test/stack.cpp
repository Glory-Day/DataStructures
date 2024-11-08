#include <iostream>

#include "util\printer.hpp"

#include "stack.hpp"
#include "stack\stack.cpp"

using namespace std;

int main() {
    Stack<int> stack = Stack<int>();

    Printer printer("Data Structure Test - Stack(ADT)");
    printer.append("Push Data");
    printer.append("Pop Data");
    printer.append("Top Data in Stack");
    printer.append("Check Stack Is Empty");

    printer.print_subject();

    bool isLoop = true;
    while (isLoop == true) {
        printer.print_order();

        int index;
        cin >> index;

        switch (index) {
            case 1:
                printer.print_input();

                int data;
                cin >> data;
                stack.push(data);

                break;
            case 2:
                try {
                    stack.pop();
                }
                catch (out_of_range& exception) {
                    printer.print_exception(exception.what());
                }

                break;
            case 3:
                try {
                    int data = stack.top();

                    printer.print_output();

                    cout << data << endl;
                }
                catch (out_of_range& exception) {
                    printer.print_exception(exception.what());
                }

                break;
            case 4:
                printer.print_output();

                cout << (stack.empty() ? "TRUE" : "FALSE") << endl;

                break;
            default:
                isLoop = false;

                break;
        }

        if (isLoop) {
            printer.print_sucess();
        }
        else {
            printer.print_finish();
        }
    }
}