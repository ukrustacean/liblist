#include <gtest/gtest.h>
#include "CircularCharList.h"

TEST(CircularCharListTest, DefaultConstructorCreatesEmptyList) {
    CircularCharList list;
    EXPECT_EQ(list.Length(), 0);
}

TEST(CircularCharListTest, ConstructorWithCharCreatesSingleElementList) {
    CircularCharList list('x');
    EXPECT_EQ(list.Length(), 1);
    EXPECT_EQ(list.Get(0), 'x');
}

TEST(CircularCharListTest, AppendAddsElements) {
    CircularCharList list('a');
    list.Append('b');
    list.Append('c');
    EXPECT_EQ(list.Length(), 3);
    EXPECT_EQ(list.Get(0), 'a');
    EXPECT_EQ(list.Get(1), 'b');
    EXPECT_EQ(list.Get(2), 'c');
}

TEST(CircularCharListTest, InsertInsertsAtCorrectPosition) {
    CircularCharList list;
    list.Append('a');
    list.Append('c');
    list.Insert('b', 1);
    EXPECT_EQ(list.Get(1), 'b');
    EXPECT_EQ(list.Length(), 3);
}

TEST(CircularCharListTest, RemoveRemovesCorrectElementAndReturnsIt) {
    CircularCharList list;
    list.Append('x');
    list.Append('y');
    list.Append('z');
    char removed = list.Remove(1);
    EXPECT_EQ(removed, 'y');
    EXPECT_EQ(list.Length(), 2);
    EXPECT_EQ(list.Get(1), 'z');
}

TEST(CircularCharListTest, RemoveAllRemovesAllOccurrences) {
    CircularCharList list;
    list.Append('a');
    list.Append('b');
    list.Append('a');
    list.Append('c');
    list.Append('a');
    list.RemoveAll('a');
    EXPECT_EQ(list.Length(), 2);
    EXPECT_EQ(list.Get(0), 'b');
    EXPECT_EQ(list.Get(1), 'c');
}

TEST(CircularCharListTest, CloneCreatesExactCopy) {
    CircularCharList list;
    list.Append('a');
    list.Append('b');
    CircularCharList copy = list.Clone();
    EXPECT_EQ(copy.Length(), 2);
    EXPECT_EQ(copy.Get(0), 'a');
    EXPECT_EQ(copy.Get(1), 'b');
}

TEST(CircularCharListTest, ReverseReversesList) {
    CircularCharList list;
    list.Append('1');
    list.Append('2');
    list.Append('3');
    list.Reverse();
    EXPECT_EQ(list.Get(0), '3');
    EXPECT_EQ(list.Get(1), '2');
    EXPECT_EQ(list.Get(2), '1');
}

TEST(CircularCharListTest, FindFirstReturnsCorrectIndex) {
    CircularCharList list;
    list.Append('x');
    list.Append('y');
    list.Append('x');
    EXPECT_EQ(list.FindFirst('x'), 0);
    EXPECT_EQ(list.FindFirst('y'), 1);
    EXPECT_EQ(list.FindFirst('z'), -1);
}

TEST(CircularCharListTest, FindLastReturnsCorrectIndex) {
    CircularCharList list;
    list.Append('a');
    list.Append('b');
    list.Append('a');
    list.Append('c');
    EXPECT_EQ(list.FindLast('a'), 2);
    EXPECT_EQ(list.FindLast('b'), 1);
    EXPECT_EQ(list.FindLast('z'), -1);
}

TEST(CircularCharListTest, ClearRemovesAllElements) {
    CircularCharList list;
    list.Append('a');
    list.Append('b');
    list.Clear();
    EXPECT_EQ(list.Length(), 0);
}