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
#include <pthread.h>
#include <sys/resource.h>

extern pthread_key_t stack_start_key;
extern int max_stack_size;

#define STACK_START \
    char stack_start_token; \
    if (max_stack_size == 0) { struct rlimit rlim; getrlimit(RLIMIT_STACK, &rlim); max_stack_size = rlim.rlim_cur; } \
    if (stack_start_key == 0) pthread_key_create(&stack_start_key, NULL); \
    pthread_setspecific(stack_start_key, &stack_start_token)

#define STACK_USAGE \
    int stack_usage = pthread_getspecific(stack_start_key) - (void*)&stack_usage
