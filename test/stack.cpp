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
                stack.Push(data);

                break;
            case 2:
                stack.Pop();

                break;
            case 3:
                printer.print_output();

                cout << stack.Top() << endl;

                break;
            case 4:
                printer.print_output();

                cout << (stack.IsEmpty() ? "TRUE" : "FALSE") << endl;

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