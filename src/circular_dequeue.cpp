#include <print>

constexpr int MAX_SIZE = 5;
int queue[MAX_SIZE];

int front = -1;
int back = -1;

bool isEmpty() {
    return front == -1;
}

bool isFull() {
    return (back + 1) % MAX_SIZE == front;
}

// Add an element to the queue
void enqueue(int value) {
    if (isFull()) {
        std::println("Queue overflow! Cannot enqueue {}", value);
        return;
    }

    if (isEmpty()) {
        front = 0;
        back = 0;
    } else {
        back = (back + 1) % MAX_SIZE;
    }
    queue[back] = value;
    std::println("{} enqueued to queue", value);
}

void dequeue() {
    if (isEmpty()) {
        std::println("Queue underflow! Cannot dequeue");
        return;
    }

    std::println("{} dequeued from queue", queue[front]);
    if (front == back) {
        // Queue has only one element, reset queue after dequeue
        front = back = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
}

// Return the front element of the queue
int getFront() {
    if (isEmpty()) {
        std::println("Queue is empty");
        return -1;
    }

    return queue[front];
}

int getBack() {
    if (isEmpty()) {
        std::println("Queue is empty");
        return -1;
    }

    return queue[back];
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);    // Should show overflow

    std::println("Front element: {}", getFront());
    std::println("Back element: {}", getBack());

    dequeue();
    dequeue();
    
    std::println("Front element: {}", getFront());
    std::println("Back element: {}", getBack());

    return 0;
}