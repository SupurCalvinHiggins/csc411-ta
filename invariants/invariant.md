Lily made a nice post (#28) on how to write invariants. This post complements Lily's by providing concrete examples of good and bad invariants.

# Invariants

An **invariant** is a statement about a program's state that is always true on some particular line(s) of code. An invariant is called an invariant because the truth value of the statement does not vary. It is always true. If the definition of an invariant sounds very general, it's because it is! 

For example, consider the following program
```rust
fn foo(x: i64) {
    // ...
}

fn main() {
    // ...
    let x = 2;
    // INVARIANT: x is 2.
    foo(x);
}
``` 
where the statement "`x` is `2`" is an invariant on line 8. This invariant does not necessarily hold for other lines of code. For example, `x` might not be `2` on line 6.

Any commented invariant can, in principle, be replaced with an explicit `assert` statement. Since the invariant is always true, the `assert` statement should never crash the program. For example
```rust
fn foo(x: i64) {
    // ...
}

fn main() {
    // ...
    let x = 2;
    assert!(x == 2);
    foo(x);
}
```
Since the invariant is correct (the statement "`x` is `2`" is true on line 8), the `assert` statement will never crash the program. However, the invariant is not useful. 

# Useful Invariants

An invariant is **useful** when it helps the reader understand how the program works. In general, many invariants are true but only a few invariants are useful. When an assignment asks for invariants, it is asking for useful invariants.

Useful invariants tend to fall into three main categories: 
1. **Preconditions** and **postconditions**. These invariants specify the state of the program before a function call and after a function call.
2. **Loop invariants**. These invariants specify the state of the program during a loop.
3. **Data structure invariants**. These invariants specify the state of a data structure throughout its lifetime.

## Preconditions and Postconditions

### Preconditions

Consider the following code to compute the $n$-th Fibonacci number.

```rust
fn fib(n: i64) -> i64 {
    if n <= 1 {
        n
    } else {
        fib(n - 1) + fib(n - 2)
    }
}
```

There are several possible invariants. For example, the input number `n` should always be an integer.
```rust
fn fib(n: i64) -> i64 {
    // INVARIANT: n is an integer.
    if n <= 1 {
        n
    } else {
        fib(n - 1) + fib(n - 2)
    }
}
```
Although correct, this is not a useful invariant. The fact that `n` is an integer is already encoded into the type system (`n` is of type `i64`). 

However, the invariant that `n` is non-negative is useful.
```rust
fn fib(n: i64) -> i64 {
    // INVARIANT: n is non-negative.
    if n <= 1 {
        n
    } else {
        fib(n - 1) + fib(n - 2)
    }
}
```
This invariant helps the reader understand how to correctly use the function. They should not pass any negative integers to `fib`. An invariant on an input of a function is called a **precondition** (a condition that must be met before calling the function). The caller of a function is responsible for making sure all preconditions are true. 

Like any invariant, it's good practice to explicitly check the precondition. 
```rust
fn fib(n: i64) -> i64 {
    // INVARIANT: n is non-negative.
    assert!(n >= 0);
    if n <= 1 {
        n
    } else {
        fib(n - 1) + fib(n - 2)
    }
}
```

Sometimes, preconditions can be explicitly encoded into the type system. Whenever possible, this is a good idea.
```rust
fn fib(n: u64) -> u64 {
    if n <= 1 {
        n
    } else {
        fib(n - 1) + fib(n - 2)
    }
}
```

Although it might not be obvious, this function still has a useful precondition. Values of `n` greater than `93` will cause integer overflow and the `fib` function will produce an incorrect answer. Therefore, the useful precondition is "`n` is less than or equal to `93`".
```rust
fn fib(n: u64) -> u64 {
    // INVARIANT: n is less than or equal to 93.
    assert!(n <= 93);
    if n <= 1 {
        n
    } else {
        fib(n - 1) + fib(n - 2)
    }
}
```
Unlike the invariant that `n` is non-negative, its not easy to encode this new invariant into the type system. Therefore, it should remain as an explicit invariant.

### Postconditions

Postconditions are invariants on the return value or side effects of functions. For example, consider the following code.
```rust
fn sort(vec: &mut Vec<i64>) {
    // ...
    // INVARIANT: vec is sorted.
}
```
When the sort function returns, `vec` is always sorted. It is the responsibility of the function (also known as the callee) to ensure the postcondition is true.

## Loop Invariants

Consider the following code for insertion sort.
```rust
fn sort(vec: &mut Vec<i64>) {
    for i in 1..vec.len() {
        let mut j = i;
        while j > 0 && vec[j] < vec[j - 1] {
            vec.swap(j - 1, j);
            j -= 1;
        }
    }
}
```

There are several possible invariants. For example, after the `for` loop finishes execution `vec` should be sorted.
```rust
fn sort(vec: &mut Vec<i64>) {
    for i in 1..vec.len() {
        let mut j = i;
        while j > 0 && vec[j] < vec[j - 1] {
            vec.swap(j - 1, j);
            j -= 1;
        }
    }
    // INVARIANT: vec is sorted.
}
```
This invariant is a postcondition because it is an invariant on `sort`'s output. While useful, this invariant does not explain why insertion sort produces a sorted list. 

Loop invariants explains why loops produce the correct output. For example, in insertion sort the region `vec[0..i]` is in sorted order at the start of iteration `i`. Assuming this invariant is correct, this means that `vec` will be sorted on the last iteration (`i = vec.len()`).
```rust
fn sort(vec: &mut Vec<i64>) {
    for i in 1..vec.len() {
        // INVARIANT: vec[0..i] is sorted.
        let mut j = i;
        while j > 0 && vec[j] < vec[j - 1] {
            vec.swap(j - 1, j);
            j -= 1;
        }
    }
    // INVARIANT: vec is sorted.
}
```
Loop invariants are always qualified by the iteration number `i` because they say something different about the state of the program on each iteration. That is, loop invariants are predicates not statements. For example, the postcondition is a statement "`vec` is sorted" while the loop invariant is a predicate P(`i`) = "`vec[0..i]` is sorted". 

Loop invariants allow computer scientists to use mathematical induction to prove that their algorithms work correctly. The base case corresponds to a precondition. The inductive hypothesis corresponds to the loop invariant. The conclusion corresponds to a postcondition.
```rust
fn sort(vec: &mut Vec<i64>) {
    // INVARIANT: vec[0..1] = [vec[0]] is sorted (base case).
    for i in 1..vec.len() {
        // INVARIANT: vec[0..i] is sorted (inductive hypothesis).
        let mut j = i;
        while j > 0 && vec[j] < vec[j - 1] {
            vec.swap(j - 1, j);
            j -= 1;
        }
    }
    // INVARIANT: vec[0..vec.len()] = vec is sorted (conclusion).
}
```

For CSC 411, these invariants are great. However, they are not perfect. For example, the following incorrect code still meets all the invariants.
```rust
fn sort(vec: &mut Vec<i64>) {
    // INVARIANT: vec[0..1] = [vec[0]] is sorted.
    for i in 1..vec.len() {
        // INVARIANT: vec[0..i] is sorted
        vec[i] = vec[i - 1];
    }
    // INVARIANT: vec[0..vec.len()] = vec is sorted.
}
```
This is because the invariants did not specify that the sorted region in `vec` contains the original elements in `vec`.

The following invariants fix this problem
```rust
fn sort(vec: &mut Vec<i64>) {
    // DEFINE: old is the original state of vec. 
    // INVARIANT: vec[0..1] is old[0..1] in sorted order.
    for i in 1..vec.len() {
        // INVARIANT: vec[0..i] is old[0..i] in sorted order.
        let mut j = i;
        while j > 0 && vec[j] < vec[j - 1] {
            vec.swap(j - 1, j);
            j -= 1;
        }
    }
    // INVARIANT: vec[0..vec.len()] is old[0..old.len()] in sorted order.
}
```
but this level of detail is not required for CSC 411.

## Data Structure Invariants

Consider the following code for a binary search tree (in C++ because the Rust version adds some complexity).
```cpp
class BSTNode {
    int val;
    BSTNode* left;
    BSTNode* right;
};

class BST {
    BSTNode* root;
}
```

A node is a binary search tree if and only if is `nullptr` or it obeys the following invariants:
1. Every child in the left subtree contains a value less than the node's value.
2. Every child in the right subtree contains a value greater than the node's value.
3. The left child is a binary search tree.
4. The right child is a binary search tree.

These invariants are data structure invariants. That is, they are true __whenever visible__ throughout the lifetime of the binary search tree. Data structure invariants can be violated during internal data structure operations. For example, `root` might not be a binary search tree during the middle of `insert`. However, at the start and end of every method on `BST`, `root` must be a binary search tree.
```cpp
class BSTNode {
    int val;

    // INVARIANT: `left` is a binary search tree.
    // INVARIANT: For every `child` in `left`, `child->val` < `val`. 
    BSTNode* left;

    // INVARIANT: `right` is a binary search tree.
    // INVARIANT: For every `child` in `right`, `child->val` > `val`.    
    BSTNode* right;
};

class BST {
    // INVARIANT: `root` is a binary search tree.
    BSTNode* root;
}
```

However, some of these invariants are not actually needed (in code). Because `BSTNode` is already defined recursively, the invariants that `left`, `right` and `root` are binary search trees are redundant.  
```cpp
class BSTNode {
    int val;

    // INVARIANT: For every `child` in `left`, `child->val` < `val`. 
    BSTNode* left;

    // INVARIANT: For every `child` in `right`, `child->val` > `val`.    
    BSTNode* right;
};

class BST {
    BSTNode* root;
}
```

As always, these invariants can be explicitly checked.
```cpp
bool is_bst(const BSTNode* node, int min, int max) {
    if (node == nullptr) {
        return true;
    }

    if (node->val < min || node->val > max) {
        return false;
    }

    return is_bst(left, min, node->val - 1) && is_bst(right, node->val + 1, max);
}

class BSTNode {
    int val;

    // INVARIANT: For every `child` in `left`, `child->val` < `val`. 
    BSTNode* left;

    // INVARIANT: For every `child` in `right`, `child->val` > `val`.    
    BSTNode* right;
};

class BST {
    BSTNode* root;

    void insert(int x) {
        assert(is_bst(root, INT_MIN, INT_MAX));
        // ...
        assert(is_bst(root, INT_MIN, INT_MAX));
    }

    void remove(int x) {
        assert(is_bst(root, INT_MIN, INT_MAX));
        // ...
        assert(is_bst(root, INT_MIN, INT_MAX));
    }

    void contains(int x) const {
        assert(is_bst(root, INT_MIN, INT_MAX));
        // ...
        assert(is_bst(root, INT_MIN, INT_MAX));
    }
}
```
Interestingly, when trying to explicitly `assert` the invariants, the implicit invariants on `root`, `left` and `right` become explicit again. For an assignment, its legit to leave redundant invariants implicit, but it helps the graders if you keep them explicit. Also, notice that the data structure invariant is really just an invariant that is a precondition and a postcondition for every single method. 

### Design by Contract

Note that the binary search tree invariants are not a given. Someone created these invariants to enable efficient search. The process of defining invariants and then coding them (as opposed to coding first and then defining invariants) is called **design by contract**.

Here is an outline of the general process of design by contract.
1. Decide what operations the data structure should support.
    1. For binary search trees, these are `insert`, `delete` and `contains`.
1. Define a small set of invariants that allow you to support the operations.
    1. For binary search trees, these are the aforementioned properties.
1. Write code to implement the operations while obeying the invariants.
    1. For binary search trees, this is what you did in CSC 212 lab.


# Invariant Checklist

After writing an invariant, think about the following questions.

1. Is the invariant a statement (or a predicate) about the program state? The invariant should be a fact about the program state that is either true or false.
1. Is the invariant useful? The invariant should explain an important property of the program.
1. Is the invariant actually true? The invariant should always be true on the line(s) of code it refers to regardless of user input.

Always aim to state the most important invariants in your program. What are the key insights behind why your code functions correctly?

## Examples

This invariant is not a statement. It is not either true or false. The invariant would receive a bad grade.
```rust
fn foo(x: i64) {
    // ...
}

fn main() {
    let x = 2;
    // INVARIANT: set x to 2.
    foo(x);
}
``` 

This invariant is a statement. It is either true or false. However, the statement is about the code and not the program state. The invariant would receive a bad grade.
```rust
fn foo(x: i64) {
    // ...
}

fn main() {
    let x = 2;
    // INVARIANT: the program sets x to 2.
    foo(x);
}
```

This invariant is a statement. It is either true or false. The statement is about the program state. However, the invariant is not useful. It does not explain an important property of the program.
```rust
fn foo(x: i64) {
    // ...
}

fn main() {
    let x = 2;
    // INVARIANT: x is 2.
    foo(x);
}
```

This invariant is a statement. It is either true or false. The statement is about the program state. The invariant is useful. It explains an important property of the program. However, the invariant is not correct. The function `foo` is called with `x = 2` which violates the precondition (invariant).
```rust
fn foo(x: i64) {
    // INVARIANT: x is less than or equal to 1.
    // ...
}

fn main() {
    let x = 2;
    foo(x);
}
```

In this case, either the invariant is incorrect or the calling code is incorrect. Maybe `foo` really needs `x <= 1` and a `x = 2` produces incorrect output. 
```rust
fn foo(x: i64) {
    // INVARIANT: x is less than or equal to 1.
    // ...
}

fn main() {
    let x = 1;
    foo(x);
}
```

On the other hand, maybe the invariant is incorrect and foo can actually handle `x <= 30`.  
```rust
fn foo(x: i64) {
    // INVARIANT: x is less than or equal to 30.
    // ...
}

fn main() {
    let x = 2;
    foo(x);
}
```
Both modifications yield an invariant that is a true, useful statement about the program state. They would receive a good grade.