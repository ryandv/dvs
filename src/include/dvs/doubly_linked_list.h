#ifndef __DOUBLY_LINKED_LIST_H__
#define __DOUBLY_LINKED_LIST_H__

#include <memory>

template <typename T>
class DoublyLinkedList {
    private:
        class DoublyLinkedNode {
            public:
                T data() const
                {
                    return m_data;
                }
            private:
                friend void DoublyLinkedList::insert(T);
                T m_data;
                std::shared_ptr<DoublyLinkedNode> rest;
                std::shared_ptr<DoublyLinkedNode> prev;
        };

        std::shared_ptr<DoublyLinkedNode> m_head;
        int m_size;

    public:

        DoublyLinkedList()
            : m_size(0)
        {
        }

        const DoublyLinkedNode& head() const
        {
            return *m_head;
        }

        int size() const
        {
            return m_size;
        }

        void insert(T data)
        {
            ++m_size;
            std::shared_ptr<DoublyLinkedNode> new_head(new DoublyLinkedNode());
            new_head->m_data = data;

            new_head->rest = m_head;
            if (m_head) {
                m_head->prev = new_head;
            }

            m_head = new_head;
            new_head->prev = nullptr;
        }
};

#endif
