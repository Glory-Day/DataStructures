#ifndef __ITERATOR_HPP__
#define __ITERATOR_HPP__

template<typename T>
class Iterator
{
private:
    int _size;
    Iterator<T>** _iterator;

protected:
    Iterator(int size) : _size(size), _iterator(new Iterator<T>*[size]) {}

    ~Iterator()
    {
        delete[] _iterator;
    }

    Iterator<T>** get_iterator() { return _iterator; }
    Iterator<T>*  get_iterator(int index) { return _iterator[index]; }
    void          set_iterator(int index, Iterator<T>* iterator) { _iterator[index] = iterator; }
};

#endif