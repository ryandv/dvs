#ifndef __DOUBLY_LINKED_LIST_H__
#define __DOUBLY_LINKED_LIST_H__

template <typename T>
class DoublyLinkedList {
    public:

    DoublyLinkedList()
        : m_size(0)
    {
    }

    int size()
    {
        return m_size;
    }

    private:

    int m_size;
};

#endif
