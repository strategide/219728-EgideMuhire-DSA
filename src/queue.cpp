#include <print>

constexpr int MAX = 100;
int queue[MAX];

int front = -1;
int rear = -1;

bool isFull() {
    return rear == MAX - 1;
}

bool isEmpty() {
    return front == -1 || front > rear;
}

void enqueue(int item) {
    if (isFull()) {
        std::println("Queue is full. Cannot enqueue {}", item);
        return;
    }

    if (front == -1) {
        front = 0;  // first element insertion
    }

    rear++;
    queue[rear] = item;
    std::println("Enqueued: {}", item);
    std::println("  Front: {}\n  Rear: {}\n", front, rear);
}

void displayQueue() {
    if (isEmpty()) {
        std::println("Queue is empty");
        return;
    }

    std::println("Queue elements:");
    for (auto i = front; i <= rear; ++i) {
        std::print("{} ", queue[i]);
    }
    std::println();
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    displayQueue();
    
    return 0;
}