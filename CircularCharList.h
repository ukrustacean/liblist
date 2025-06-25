//
// Created by ivand on 6/18/25.
//

#ifndef CIRCULARCHARLIST_H
#define CIRCULARCHARLIST_H

#include <cstddef>

class CircularCharList {
    struct Node {
        char value;
        Node *next;
    } *head = nullptr;

    auto Last() const -> Node* ;

    template<class F>
    auto ForEach(F func) const -> void {
        if (head == nullptr) return;

        auto it = head;
        do {
            func(it);
            it = it->next;
        } while (it != head);
    }

public:
    CircularCharList(char c);
    CircularCharList() = default;
    auto Length() const -> size_t ;
    auto Append(char element) -> void ;
    auto Insert(char element, size_t index) -> void ;
    auto Remove(size_t index) -> char ;
    auto RemoveAll(char element) -> void ;
    auto Get(size_t index) const -> char ;
    auto Clone() -> CircularCharList ;
    auto Reverse() -> void ;
    auto FindFirst(char element) -> int ;
    auto FindLast(char element) -> int ;
    auto Clear() -> void ;
    auto Extend(CircularCharList elements) -> void ;
    ~CircularCharList();
};

#endif //CIRCULARCHARLIST_H
