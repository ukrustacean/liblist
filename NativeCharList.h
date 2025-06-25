#ifndef NATIVECHARLIST_H
#define NATIVECHARLIST_H

#include <vector>
#include <initializer_list>

class NativeCharList : public std::vector<char> {
public:
    NativeCharList(std::initializer_list<char> initializer): std::vector<char>(initializer) {}
    template<class Start, class End>
    NativeCharList(Start start, End end): std::vector<char>(start, end) {}

    auto Length() const -> size_t;
    auto Append(char element) -> void;
    auto Insert(char element, size_t index) -> void;
    auto Remove(size_t index) -> char;
    auto RemoveAll(char element) -> void;
    auto Get(size_t index) const -> char;
    auto Clone() -> NativeCharList;
    auto Reverse() -> void;
    auto FindFirst(char element) -> int;
    auto FindLast(char element) -> int;
    auto Clear() -> void;
    auto Extend(NativeCharList elements) -> void;
};

#endif //NATIVECHARLIST_H