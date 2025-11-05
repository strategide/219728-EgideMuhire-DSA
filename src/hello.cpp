#include <print>

// Implementation of a stack
constexpr auto MAX = 10;
int stack[MAX];
int top = -1;

void push(int value) {
    if (top >= MAX - 1) {
        std::println("Stack overflow");
        return;
    }
    stack[++top] = value;
    std::println("{} pushed onto stack", value);
}

void showStack() {
    if (top < 0) {
        std::println("Stack is empty");
        return;
    }

    for (auto i = 0; i <= top; ++i) {
        std::println("{} -> {}", i, stack[i]);
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    push(70);
    push(80);
    push(90);
    push(100);
    push(110);
    
    std::println();

    showStack();

    return 0;
}