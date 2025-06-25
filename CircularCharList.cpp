#include "CircularCharList.h"

auto CircularCharList::Last() const -> Node * {
    if (!head) return nullptr;
    Node* current = head;
    while (current->next != head)
        current = current->next;
    return current;
}

CircularCharList::CircularCharList(char c): head(new Node{c, nullptr}) {
    head->next = head;
}

auto CircularCharList::Length() const -> size_t {
    size_t count = 0;
    ForEach([&](Node*) { ++count; });
    return count;
}

auto CircularCharList::Append(char element) -> void {
    Node* newNode = new Node{element, head};
    if (!head) {
        head = newNode;
        head->next = head;
    } else {
        Node* last = Last();
        last->next = newNode;
    }
}

auto CircularCharList::Insert(char element, size_t index) -> void {
    if (!head || index == 0) {
        Node* newNode = new Node{element, head ? head : nullptr};
        if (!head) {
            newNode->next = newNode;
            head = newNode;
        } else {
            Node* last = Last();
            last->next = newNode;
            head = newNode;
        }
        return;
    }

    Node* current = head;
    for (size_t i = 0; i < index - 1 && current->next != head; ++i)
        current = current->next;

    Node* newNode = new Node{element, current->next};
    current->next = newNode;
}

auto CircularCharList::Remove(size_t index) -> char {
    if (!head) throw std::out_of_range("Empty list");

    if (index == 0) {
        char val = head->value;
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* last = Last();
            Node* toDelete = head;
            head = head->next;
            last->next = head;
            delete toDelete;
        }
        return val;
    }

    Node* prev = head;
    for (size_t i = 0; i < index - 1 && prev->next != head; ++i)
        prev = prev->next;

    Node* toDelete = prev->next;
    if (toDelete == head) throw std::out_of_range("Index out of bounds");
    char val = toDelete->value;
    prev->next = toDelete->next;
    delete toDelete;
    return val;
}

auto CircularCharList::RemoveAll(char element) -> void {
    if (!head) return;

    while (head && head->value == element)
        Remove(0);

    if (!head) return;

    Node* prev = head;
    Node* current = head->next;

    while (current != head) {
        if (current->value == element) {
            prev->next = current->next;
            delete current;
            current = prev->next;
        } else {
            prev = current;
            current = current->next;
        }
    }
}

auto CircularCharList::Get(size_t index) const -> char {
    if (!head) throw std::out_of_range("Empty list");
    Node* current = head;
    for (size_t i = 0; i < index; ++i) {
        current = current->next;
        if (current == head) throw std::out_of_range("Index out of bounds");
    }
    return current->value;
}

auto CircularCharList::Clone() -> CircularCharList {
    CircularCharList copy;
    ForEach([&](Node* n) { copy.Append(n->value); });
    return copy;
}

auto CircularCharList::Reverse() -> void {
    if (!head || head->next == head) return;

    Node* prev = head;
    Node* current = head->next;
    Node* next;

    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != head);

    head->next = prev;
    head = prev;
}

auto CircularCharList::FindFirst(char element) -> int {
    int index = 0;
    Node* current = head;
    if (!head) return -1;
    do {
        if (current->value == element) return index;
        current = current->next;
        ++index;
    } while (current != head);
    return -1;
}

auto CircularCharList::FindLast(char element) -> int {
    int index = 0, found = -1;
    Node* current = head;
    if (!head) return -1;
    do {
        if (current->value == element) found = index;
        current = current->next;
        ++index;
    } while (current != head);
    return found;
}

auto CircularCharList::Clear() -> void {
    if (!head) return;

    Node* current = head->next;
    while (current != head) {
        Node* tmp = current;
        current = current->next;
        delete tmp;
    }
    delete head;
    head = nullptr;
}

auto CircularCharList::Extend(CircularCharList elements) -> void {
    elements.ForEach([&](Node* n) { Append(n->value); });
}

CircularCharList::~CircularCharList() {
    Clear();
}
