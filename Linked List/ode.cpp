namespace SinglyLinkedList {
    template<typename T>
    class Node {
    private:
        T _data;     // Data of node
        Node *_next; // Next linked node pointer

    public:
        /**
         * Default node constructor
         */
        Node() : _data{0}, _next{nullptr} {}

        /**
         * Node constructor to initialize node's fields
         * @param data : Data in node
         * @param next : Next linked node pointer
         */
        explicit Node(T data, Node *next) : _data{data}, _next{next} {}

        T getData();
        Node* getNext();
        void setNext(Node*);
    };

    template <typename T>
    T Node<T>::getData() {
        return _data;
    }

    template <typename T>
    Node<T>* Node<T>::getNext() {
        return _next;
    }

    template <typename T>
    void Node<T>::setNext(Node<T>* next) {
        _next = next;
    }
}

namespace DoublyLinkedList {
    template<typename T>
    class Node {
    private:
        T _data;        // Data of node
        Node* _next;    // Next linked node pointer
        Node* _preview; // Preview linked node pointer

    public:
        /**
         * Default node constructor
         */
        Node() : _data{0}, _next{nullptr}, _preview{nullptr} {}

        /**
         * Node constructor to initialize node's fields
         * @param data : Data in node
         * @param next : Next linked node pointer
         */
        explicit Node(T data, Node* next, Node* preview) : _data{data}, _next{next}, _preview{preview} {}

        T getData();
        Node* getNext();
        Node* getPreview();
        void setNext(Node*);
        void setPreview(Node*);
    };

    template <typename T>
    T Node<T>::getData() {
        return _data;
    }

    template <typename T>
    Node<T>* Node<T>::getNext() {
        return _next;
    }

    template <typename T>
    Node<T>* Node<T>::getPreview() {
        return _preview;
    }

    template <typename T>
    void Node<T>::setNext(Node<T>* next) {
        _next = next;
    }

    template <typename T>
    void Node<T>::setPreview(Node<T>* preview) {
        _preview = preview;
    }
}