#include "queue.cpp"

int main() {
    Queue<int> queue = Queue<int>(10);

    bool isLoop = true;
    while (isLoop) {
        std::cout << "Data structure - Queue(ADT)" << std::endl;
        std::cout << "(1). Enqueue" << std::endl;
        std::cout << "(2). Dequeue" << std::endl;
        std::cout << "(3). Front data in queue" << std::endl;
        std::cout << "(4). Check queue is empty" << std::endl;
        std::cout << " - Input" << std::endl;

        int index;
        std::cin >> index;

        switch (index) {
            case 1:
                int data;
                std::cout << " - Input" << std::endl;
                std::cin >> data;
                queue.Enqueue(data);
                break;
            case 2:
                queue.Dequeue();
                break;
            case 3:
                std::cout << " - Output" << std::endl;
                std::cout << queue.Front() << std::endl;
                break;
            case 4:
                std::cout << " - Output" << std::endl;
                std::cout << (queue.IsEmpty() ? "True" : "False") << std::endl;
                break;
            default:
                isLoop = false;
                break;
        }

        std::cout << std::endl;
    }
}