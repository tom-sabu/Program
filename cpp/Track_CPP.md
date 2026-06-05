# C++ track

30 problems · 6 stages · compile output → `bin/`

---

## Stage 1 · Foundation → `foundation/`

- [x] `hello_world.cpp` — `cout`, variables, basic types
- [x] `calculator.cpp` — two numbers + operator, integer division
- [x] `fizzbuzz.cpp` — 1–100, multiples of 3/5
- [x] `temp_converter.cpp` — °C / °F / K conversion functions
- [x] `guessing_game.cpp` — `rand()` secret number, count guesses

---

## Stage 2 · Arrays & strings → `arrays_strings/`

- [ ] `array_stats.cpp` — min, max, mean, median of N integers
- [ ] `reverse_string.cpp` — manual loop then `std::reverse`
- [ ] `word_frequency.cpp` — word count with `std::map`, sorted by frequency
- [ ] `caesar_cipher.cpp` — encode/decode, upper and lower case
- [ ] `matrix_multiply.cpp` — N×N matrix product

---

## Stage 3 · Pointers & memory → `pointers_memory/`

- [ ] `pointer_walk.cpp` — walk array with pointer, print addresses and values
- [ ] `dynamic_array.cpp` — `new[]` N ints at runtime, double via pointer, `delete[]`
- [ ] `swap_three_ways.cpp` — pass-by-value, pointer, reference
- [ ] `linked_list.cpp` — singly linked list: insert head/tail, delete by value, print
- [ ] `stack_dynamic.cpp` — stack class, dynamic array, double capacity on full

---

## Stage 4 · OOP → `oop/`

- [ ] `shapes.cpp` — `Shape` → `Circle`, `Rectangle`, `Triangle`; `virtual area()`; `vector<Shape*>`
- [ ] `bank_account.cpp` — private balance, `throw` on overdraft, transaction log
- [ ] `copy_move.cpp` — `Buffer` class, rule of five, trace each call
- [ ] `template_stack.cpp` — `Stack<T>` from stage 3, test with `int`, `double`, `string`
- [ ] `observer.cpp` — `EventSource` notifies list of `Listener*`

---

## Stage 5 · STL & modern C++ → `stl_modern/`

- [ ] `word_ladder.cpp` — BFS shortest word-change path, `queue`, `unordered_set`
- [ ] `task_scheduler.cpp` — `priority_queue`, always run highest-priority task
- [ ] `csv_parser.cpp` — read CSV, sort by column, write result, `fstream`, `stringstream`
- [ ] `unique_ptr_list.cpp` — stage 3 linked list rewritten with `unique_ptr<Node>`
- [ ] `parallel_wordcount.cpp` — word count across file chunks on threads, merge with `mutex`

---

## Stage 6 · Systems & algorithms → `systems_algorithms/`

- [ ] `allocator.cpp` — bump allocator over fixed buffer, free-list, coalesce blocks
- [ ] `constexpr_fib.cpp` — Fibonacci at compile time, `constexpr`, `static_assert`
- [ ] `lockfree_stack.cpp` — lock-free stack with `std::atomic` and compare-exchange
- [ ] `coroutine_gen.cpp` — infinite Fibonacci generator with C++20 `co_yield`
- [ ] `mini_ecs.cpp` — entity-component system, component arrays, `std::bitset`

---

## Build

```bash
g++ -std=c++20 -Wall -o bin/<name> <name>.cpp
```

Stage 5+ may need `-lpthread`. Stage 6 requires GCC 11+ or Clang 13+.
