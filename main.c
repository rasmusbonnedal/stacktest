/*
Copyright 2024 Rasmus Bonnedal

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the “Software”), to deal
in the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include <stdio.h>
#include "stacktest.h"

void foo(int recursion) {
    // Put this in the function where you want to measure stack usage
    STACK_USAGE;

    // 512kb array to fill up the stack on recursion
    char dummy[512 * 1024];

    // When STACK_USAGE has been put in a function the variable stack_usage
    // will contain the amount of stack used. Note that STACK_START must have
    // been put in the start of the thread from which this function is called.
    printf("In foo(%d), stack usage: %d (%d%%)\n", recursion, stack_usage, 100 * stack_usage / max_stack_size);
    if (recursion < 10) {
        foo(recursion + 1);
    }
}

void* thread_func(void*) {
    // Put this first line in main() and any thread start functions
    STACK_START;

    foo(0);
}

int main(char argc, char** argv) {
    // Put this first line in main() and any thread start functions
    STACK_START;

    // max_stack_size is initialized to the global stack size set by the system
    printf("Max stack size: %d\n", max_stack_size);
    foo(0);

    // Start a thread which calls foo to check that stack measurement
    // works in threads
    pthread_t thread;
    pthread_create(&thread, NULL, thread_func, NULL);
    pthread_join(thread, NULL);

    return 0;
}
