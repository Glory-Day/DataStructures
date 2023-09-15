template<typename T>
class Node {
private:
    T _data;     // Data in node
    Node *_next; // Next linked node pointer

public:
    /**
     * `Node` default constructor
     */
    Node() : _data{0}, _next{nullptr} {}

    /**
     * `Node` constructor to initialize fields
     * 
     * @param data : Data in node
     * @param next : Next linked node pointer
     */
    explicit Node(T data, Node *next) : _data{data}, _next{next} {}

    T GetData();
    Node* GetNext();
    void SetNext(Node*);
};

template <typename T>
T Node<T>::GetData() {
    return _data;
}

template <typename T>
Node<T>* Node<T>::GetNext() {
    return _next;
}

template <typename T>
void Node<T>::SetNext(Node<T>* next) {
    _next = next;
}