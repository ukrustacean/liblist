#include "NativeCharList.h"

auto NativeCharList::Length() const -> size_t {
    return size();
}

auto NativeCharList::Append(char element) -> void {
    push_back(element);
}

auto NativeCharList::Insert(char element, size_t index) -> void {
    insert(begin() + index, element);
}

auto NativeCharList::Remove(size_t index) -> char {
    const auto c = at(index);
    erase(begin() + index);
    return c;
}

auto NativeCharList::RemoveAll(char element) -> void {
    erase(std::remove(begin(), end(), element), end());
}

auto NativeCharList::Get(size_t index) const -> char {
    return at(index);
}

auto NativeCharList::Clone() -> NativeCharList {
    NativeCharList l{begin(), end()};
    return l;
}

auto NativeCharList::Reverse() -> void {
    std::reverse(begin(), end());
}

auto NativeCharList::FindFirst(char element) -> int {
    const auto it = std::find(begin(), end(), element);
    return it == end() ? -1 : static_cast<int>(it - begin());
}

auto NativeCharList::FindLast(char element) -> int {
    const auto it = std::find(rbegin(), rend(), element);
    return it == rend() ? -1 : static_cast<int>(it - rbegin());
}

auto NativeCharList::Clear() -> void {
    erase(begin(), end());
}

auto NativeCharList::Extend(NativeCharList elements) -> void {
    insert(end(), elements.begin(), elements.end());
}