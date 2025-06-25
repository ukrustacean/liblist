# liblist
A small library containing two kinds of char lists: native and circular.
Written in C++, tested with GTests. (Also my university assignment)

## Building and running

You will need the `make`, `cmake` and C++ compiler toolchain to run this program.
After you have aforementioned utilities up and running, use the following
commands to clone, build and run the program:

```shell
$ git clone https://github.com/ukrustacean/liblist.git
$ cd ./liblist

# To build
$ mkdir build && cd ./build
$ cmake .. && make

# To test
$ make test
```

## Variant

I am 6th in a students list, so my variants are:

> 6 mod 4 = **2**

So, I need to implement two lists:
 - Char list based upon standard implementation
 - Singly-linked circular char list

## Commit with failed tests

Link to [commit](https://github.com/ukrustacean/liblist/commit/76e8bef5914afe30c95b831b953a8550740a5a23).\
Its hash: `76e8bef5914afe30c95b831b953a8550740a5a23`\

## Short summary on using unit tests

I feel like unit tests become mostly irrelevant with
sufficiently strong and powerful type system (like in
Rust or C++). I imagine these tests may become quite
useful whenever working with weak and/or dynamic type
system. But for sufficiently strong type systems the
necessity of writing unit tests means you are underutilizing
it and are not encoding invariants of your code within
the constraints of type system efficiently. 