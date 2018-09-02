#ifndef __DOUBLY_LINKED_LIST_H__
#define __DOUBLY_LINKED_LIST_H__

#include <memory>
#include <optional>

template <typename T>
class DoublyLinkedList {
    private:
        class DoublyLinkedNode {
            public:
                T data() const
                {
                    return m_data;
                }

                const std::optional<DoublyLinkedNode> rest() const
                {
                    if (m_rest) {
                        return *m_rest;
                    } else {
                        return std::nullopt;
                    }
                }

            private:
                friend void DoublyLinkedList::insert(T);
                T m_data;
                std::shared_ptr<DoublyLinkedNode> m_rest;
                std::shared_ptr<DoublyLinkedNode> prev;
        };

        std::shared_ptr<DoublyLinkedNode> m_head;
        int m_size;

    public:

        DoublyLinkedList()
            : m_size(0)
        {
        }

        const std::optional<DoublyLinkedNode> head() const
        {
            if (m_head) {
                return *m_head;
            } else {
                return std::nullopt;
            }
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

            new_head->m_rest = m_head;
            if (m_head) {
                m_head->prev = new_head;
            }

            m_head = new_head;
            new_head->prev = nullptr;
        }

        std::optional<T> search(T search_data)
        {
            std::optional<DoublyLinkedNode> node = head();

            while (node && node->data() != search_data) {
                node = node->rest();
            }

            if (node) {
                return std::optional<T>(node->data());
            } else {
                return std::nullopt;
            }
        }
};

#endif
