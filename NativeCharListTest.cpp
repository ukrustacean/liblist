#include <gtest/gtest.h>
#include "NativeCharList.h"  // Replace with actual path

TEST(NativeCharListTest, ConstructorWithInitializerList) {
    std::vector x {'a', 'b', 'c'};
    NativeCharList list(x.begin(), x.end());
    EXPECT_EQ(list.Length(), 3);
    EXPECT_EQ(list.Get(0), 'a');
    EXPECT_EQ(list.Get(1), 'b');
    EXPECT_EQ(list.Get(2), 'c');
}

TEST(NativeCharListTest, ConstructorWithIterators) {
    std::vector<char> vec = {'x', 'y', 'z'};
    NativeCharList list(vec.begin(), vec.end());
    EXPECT_EQ(list.Length(), 3);
    EXPECT_EQ(list.Get(2), 'z');
}

TEST(NativeCharListTest, AppendIncreasesLengthAndAddsElement) {
    NativeCharList list({'a'});
    list.Append('b');
    EXPECT_EQ(list.Length(), 2);
    EXPECT_EQ(list.Get(1), 'b');
}

TEST(NativeCharListTest, InsertElementAtIndex) {
    NativeCharList list({'a', 'c'});
    list.Insert('b', 1);
    EXPECT_EQ(list.Get(1), 'b');
    EXPECT_EQ(list.Length(), 3);
}

TEST(NativeCharListTest, RemoveReturnsAndRemovesElementAtIndex) {
    std::vector x {'a', 'b', 'c'};
    NativeCharList list(x.begin(), x.end());
    char removed = list.Remove(1);
    EXPECT_EQ(removed, 'y');
    EXPECT_EQ(list.Length(), 2);
    EXPECT_EQ(list.Get(1), 'z');
}

TEST(NativeCharListTest, RemoveAllRemovesAllOccurrences) {
    std::vector x {'a', 'b', 'a', 'c', 'a'};
    NativeCharList list(x.begin(), x.end());
    list.RemoveAll('a');
    EXPECT_EQ(list.Length(), 2);
    EXPECT_EQ(list.Get(0), 'b');
    EXPECT_EQ(list.Get(1), 'c');
}

TEST(NativeCharListTest, CloneCreatesIdenticalCopy) {
    std::vector x {'a', 'b', 'c'};
    NativeCharList original(x.begin(), x.end());
    NativeCharList copy = original.Clone();
    EXPECT_EQ(copy.Length(), 3);
    EXPECT_EQ(copy.Get(1), 'b');
}

TEST(NativeCharListTest, ReverseReversesTheList) {
    std::vector x {'1', '2', '3'};
    NativeCharList list(x.begin(), x.end());
    list.Reverse();
    EXPECT_EQ(list.Get(0), '3');
    EXPECT_EQ(list.Get(1), '2');
    EXPECT_EQ(list.Get(2), '1');
}

TEST(NativeCharListTest, FindFirstReturnsCorrectIndex) {
    std::vector x {'a', 'b', 'c', 'b'};
    NativeCharList list(x.begin(), x.end());
    EXPECT_EQ(list.FindFirst('b'), 1);
    EXPECT_EQ(list.FindFirst('z'), -1);
}

TEST(NativeCharListTest, FindLastReturnsCorrectIndex) {
    std::vector x {'a', 'b', 'c', 'b'};
    NativeCharList list(x.begin(), x.end());
    EXPECT_EQ(list.FindLast('b'), 3);
    EXPECT_EQ(list.FindLast('z'), -1);
}

TEST(NativeCharListTest, ClearRemovesAllElements) {
    std::vector x {'x', 'y', 'z'};
    NativeCharList list(x.begin(), x.end());
    list.Clear();
    EXPECT_EQ(list.Length(), 0);
}

TEST(NativeCharListTest, ExtendAppendsAnotherList) {
    NativeCharList list1({'a', 'b'});
    NativeCharList list2({'c', 'd'});
    list1.Extend(list2);
    EXPECT_EQ(list1.Length(), 4);
    EXPECT_EQ(list1.Get(2), 'c');
    EXPECT_EQ(list1.Get(3), 'd');
}
