#include "stack.cpp"

int main() {
    Stack<int> stack = Stack<int>();

    bool isLoop = true;
    while (isLoop) {
        std::cout << "Data structure - Stack(ADT)" << std::endl;
        std::cout << "(1). Push data" << std::endl;
        std::cout << "(2). Pop data" << std::endl;
        std::cout << "(3). Top data in stack" << std::endl;
        std::cout << "(4). Check stack is empty" << std::endl;
        std::cout << " - Input" << std::endl;

        int index;
        std::cin >> index;

        switch (index) {
            case 1:
                std::cout << " - Input" << std::endl;

                int data;
                std::cin >> data;
                stack.Push(data);
                break;
            case 2:
                stack.Pop();
                break;
            case 3:
                std::cout << " - Output" << std::endl;
                std::cout << stack.Top() << std::endl;
                break;
            case 4:
                std::cout << " - Output" << std::endl;
                std::cout << (stack.IsEmpty() ? "True" : "False") << std::endl;
                break;
            default:
                isLoop = false;
                break;
        }

        std::cout << std::endl;
    }
}