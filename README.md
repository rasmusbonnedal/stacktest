# Stacktest
A couple of C macros to measure stack usage on Linux

## Usage
1. Include `stacktest.h` and `stacktest.c` in your build
2. Put the macro STACK_START on the first line in main() and in any thread functions (like those called by `pthread_create`)
3. Put the macro STACK_USAGE first in a function where you want to measure current stack usage.
4. Current stack usage can now be seen in the variable `stack_usage` and max stack size in `max_stack_size`

## Example
1. `main.c` contains an example of measuring stack usage in a recursive function which has a 512kB array as a local variable, both from main thread and from a pthread thread.
2. Build with `make`
3. Run with `./stacktest`
4. Output: 
```
Max stack size: 8388608
In foo(0), stack usage: 524355 (6%)
In foo(1), stack usage: 1048707 (12%)
In foo(2), stack usage: 1573059 (18%)
In foo(3), stack usage: 2097411 (25%)
In foo(4), stack usage: 2621763 (31%)
In foo(5), stack usage: 3146115 (37%)
In foo(6), stack usage: 3670467 (43%)
In foo(7), stack usage: 4194819 (50%)
In foo(8), stack usage: 4719171 (56%)
In foo(9), stack usage: 5243523 (62%)
In foo(10), stack usage: 5767875 (68%)
In foo(0), stack usage: 524340 (6%)
In foo(1), stack usage: 1048692 (12%)
In foo(2), stack usage: 1573044 (18%)
In foo(3), stack usage: 2097396 (25%)
In foo(4), stack usage: 2621748 (31%)
In foo(5), stack usage: 3146100 (37%)
In foo(6), stack usage: 3670452 (43%)
In foo(7), stack usage: 4194804 (50%)
In foo(8), stack usage: 4719156 (56%)
In foo(9), stack usage: 5243508 (62%)
In foo(10), stack usage: 5767860 (68%)
```

## License
MIT (https://opensource.org/license/mit)
