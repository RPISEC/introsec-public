
// mark gadgets as naked functions to avoid prologue and epilogue
__attribute__((naked)) void foo();
__attribute__((naked)) void bar();
__attribute__((naked)) void zee();