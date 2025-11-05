/*
Name: Egide Muhire
Admission Number: 219728
DBT 1301 - Practical Assignment 1
*/

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

/*
Class implementation of a singly linked list.
*/
class SinglyLinkedList {
    // Type alias for 'int' used throughout class.
    using Type = int;

public:
    /*
    Internal class to represent a node in a singly linked list.
    */
    struct Node {
        Type data;
        Node* next;
    };

    /*
    Inserts the given data at the front the list.
    */
    void insertAtFront(Type data) {
        // Create a new node with the given data.
        Node* node = new Node;
        node->data = data;

        // The new node should be head, so point it to the current head.
        node->next = head;

        // Update the current head to be the new node.
        head = node;

        cout << "Inserted [" << data << "] at front of SinglyLinkedList.\n";
    }

    /*
    Inserts the given data at the end of the list as a tail / end node.
    */
    void insertAtBack(Type data) {
        // Create a new tail node with the given data.
        Node* node = new Node;
        node->data = data;
        node->next = nullptr;

        // List is empty, so make the new node head.
        if (!head) {
            head = node;
        } else {
            // List is not empty - traverse it to reach the tail node.
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }

            // Make the current tail node point to our new tail node.
            temp->next = node;
        }

        cout << "Inserted [" << data << "] at back of SinglyLinkedList.\n";
    }

    /*
    Deletes the current front / head node from the list, assigning the next node
    to be head (if possible).
    */
    void deleteFromFront() {
        // List is already empty, so no need to delete anything.
        if (!head) {
            cerr << "Cannot delete from front - SinglyLinkedList is empty.\n";
            return;
        }

        // Store the current head in a temp value
        Node* temp = head;

        // Update head to be the next node in the list.
        head = temp->next;

        // Delete the old head.
        delete temp;

        cout << "Deleted value from front of SinglyLinkedList.\n";
    }

    /*
    Deletes the current tail node from the list, assigning the second-last node
    to be tail (if possible).
    */
    void deleteFromBack() {
        // List is already empty, so no need to delete anything.
        if (!head) {
            cerr << "Cannot delete from back - SinglyLinkedList is empty.\n";
            return;
        }

        // There's only one node in the list (head), so just delete it.
        if (!head->next) {
            delete head;
            head = nullptr;    // assign nullptr to avoid a dangling pointer.
        } else {
            Node* temp = head; // current node
            Node* prev = temp; // previous node (before current)

            // Traverse to the last node
            while (temp->next) {
                prev = temp;
                temp = temp->next;
            }

            // Second last node should be tail, so assign nullptr to its next.
            prev->next = nullptr;

            // Delete the last node.
            delete temp;
        }

        cout << "Deleted value from back of SinglyLinkedList.\n";
    }

    /*
    Show the entire list.

    Front is at the left of the list, and back is at the right of the list.
    */
    void show() {
        Node* current = head;
        while (current) {
            cout << current->data << " → ";
            current = current->next;
        }
        cout << "NULL" << "\n\n";
    }

private:
    // The current head node, defaults to nullptr.
    Node* head = nullptr;
};

/*
An implementation of a stack structure using an array.

- The 'top' zero-index variable keeps track of the current top position.
- The 'array' variable keeps track of stack elements.
*/
class Stack {
    using Type = int;           // Type alias for items in the stack.
    static const int SIZE = 10; // Stack size.

public:
    /*
    Pushes the given data item to the stack, if it's not already full.
    */
    void push(Type data) {
        // Stack is full, so no need to push anything.
        if (top >= SIZE - 1) {
            cerr << "Cannot push [" << data << "] to Stack - stack overflow.\n";
            return;
        }

        // Increment top to point to next empty slot, and assign it the data.
        ++top;
        array[top] = data;

        cout << "Pushed [" << data << "] onto Stack\n";
    }

    /*
    Pops the item from the stack, if it's not already empty.
    */
    void pop() {
        // Stack is empty, so no need to pop anything.
        if (isEmpty()) {
            cerr << "Cannot pop Stack - Stack is empty.\n";
            return;
        }

        // Read the current value at the top, and decrement top.
        Type data = array[top];
        --top;

        cout << "Popped [" << data << "] from Stack\n";
    }

    /*
    Checks the current item on top of the stack (if it's not empty) without
    removing it or changing 'top'.
    */
    void peek() {
        if (isEmpty()) {
            cerr << "Cannot peek Stack - Stack is empty.\n";
            return;
        }

        cout << "Peek value at top of Stack: [" << array[top] << "]\n";
    }

    /*
    Returns true if the stack is empty (pointing to just below the first
    element), false otherwise.
    */
    bool isEmpty() { return top == -1; }

    /*
    Shows the stack elements (if the stack is not empty) vertically.

    The item at the top of the stack shows up at the top, and the bottom at the
    bottom.

    The top item (if it exists) shows '<< TOP >>' next to it.
    */
    void show() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }

        for (int i = top; i > -1; --i) {
            cout << "[ " << array[i] << " ]";
            if (top == i) {
                cout << "<< TOP >>";
            }
            cout << "\n";
        }
    }

private:
    Type array[SIZE];
    int top = -1;
};

/*
An implementation of a queue using an array as the underlying structure.

- The 'front' and 'rear' variables keep track of the front and rear of queue.
- The 'array' structure keeps track of elements in the queue.
*/
class Queue {
    using Type = int;           // Type alias for items in the queue
    static const int SIZE = 10; // Maximum size of queue.

public:
    /*
    Inserts / enqueues an element into the queue, if it's not already full.
    */
    void enqueue(Type value) {
        // The rear has reached max capacity, so queue is full.
        if (rear == SIZE - 1) {
            cerr << "Cannot enqueue [" << value << "] - Queue is full.\n";
            return;
        }

        // The insertion is an initial one, so position front to zero.
        if (front == -1) {
            front = 0;
        }

        // Increment rear and assign the value to its position in the array.
        rear++;
        array[rear] = value;

        cout << "Enqueued [" << value << "].\n";
    }

    /*
    Dequeues / removes an element from the queue (if it's not already empty).
    */
    void dequeue() {
        if (isEmpty()) {
            cerr << "Cannot dequeue - Queue is empty.\n";
            return;
        }

        // Read the current value at the front of the queue and decrement it.
        Type value = array[front];
        ++front;

        // Front has exceeded rear (through dequeueing), so reset queue.
        if (front > rear) {
            front = -1;
            rear = -1;
        }

        cout << "Dequeued [" << value << "].\n";
    }

    /*
    Checks the current value at the front of the queue (if it's not empty)
    without removing it.
    */
    void peek() {
        if (isEmpty()) {
            cerr << "Cannot peek - Queue is empty.\n";
            return;
        }

        cout << "Peek value at front of Queue: [" << array[front] << "]\n";
    }

    /*
    Returns true if the queue is empty, false otherwise.

    A queue is deemed empty if the front has exceeded the rear (through
    dequeueing) or if front is in its initial position of -1.
    */
    bool isEmpty() { return front == -1 || front > rear; }

    /*
    Show the queue (if it's not empty).
    */
    void show() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        for (int i = front; i <= rear; ++i) {
            cout << array[i] << " ";
        }
        cout << '\n';
    }

private:
    int front = -1;
    int rear = -1;
    Type array[SIZE];
};

/*
Shows a menu title (with an underline decoration).
*/
void showTitle(std::string_view title) {
    cout << '\n' << title << '\n';
    for (int i = 0; i < title.size(); ++i) {
        cout << '-';
    }
    cout << "\nEnter:\n";
}

/*
Reads and returns input from the keyboard (as an int).

This is used by menus to read user choices as well as values to feed into the
data structure classes.

The input is read as a raw string and converted into an int value.
If conversion fails, -1 is returned.
*/
int getInput() {
    cout << ">: "; // show input prompt

    string input;
    try {
        getline(cin, input);
        return stoi(input);
    } catch (std::exception& e) { // catch all by reference
        return -1;
    }
}

/*
Returns 'true' if the given 'choice' is between the provided 'min' and 'max'
values (valid); 'false' otherwise (invalid).

This is used by menu functions to validate an entered menu choice.
*/
bool isValid(int choice, int min, int max) {
    if (choice < min || choice > max) {
        cerr << "Invalid choice [" << choice << "]. Please try again.\n";
        return false;
    }

    return true;
}

/*
Forward declaration of 'showMainMenu'.
*/
void showMainMenu();

/*
Displays a menu for operations related to a SinglyLinkedList.

The SinglyLinkedList value is static to allow values to persist through
multiple menu calls.
*/
void showSinglyLinkedListMenu() {
    // Show a menu and repeatedly prompt user to enter a valid choice.
    int choice = -1;
    do {
        showTitle("SinglyLinkedList");
        cout << "\t1 - Insert at front.\n";
        cout << "\t2 - Insert at back.\n";
        cout << "\t3 - Delete from front.\n";
        cout << "\t4 - Delete from back.\n";
        cout << "\t5 - View list.\n";
        cout << "\t0 - Back.\n";

        choice = getInput();
    } while (!isValid(choice, 0, 5));

    static SinglyLinkedList list;

    // Select the respective operation and relist the menu at the end.
    switch (choice) {
        case 1: { // Insert a value at the front.
            cout << "Enter a value to insert at front\n";
            int value = getInput();
            list.insertAtFront(value);
            list.show();
            showSinglyLinkedListMenu();
            break;
        }
        case 2: { // Insert a value the back.
            cout << "Enter a value to insert at back\n";
            int value = getInput();
            list.insertAtBack(value);
            list.show();
            showSinglyLinkedListMenu();
            break;
        }
        case 3: { // Delete a value from the front.
            list.deleteFromFront();
            list.show();
            showSinglyLinkedListMenu();
            break;
        }
        case 4: { // Delete a value from the back.
            list.deleteFromBack();
            list.show();
            showSinglyLinkedListMenu();
            break;
        }
        case 5: { // Show the list
            list.show();
            showSinglyLinkedListMenu();
            break;
        }
        case 0: // Reset the list and go back to the main menu.
            list = SinglyLinkedList();
            showMainMenu();
            return;
    }
}

/*
Displays a menu for operations on a Stack.

The 'Stack' is stored as a static variable in the function to allow repeated
usages of the same stack through different calls.
*/
void showStackMenu() {
    // Show a menu and repeatedly prompt user to enter a valid choice.
    int choice = -1;
    do {
        showTitle("Stack");

        cout << "\t1 - Push.\n";
        cout << "\t2 - Pop.\n";
        cout << "\t3 - Peek.\n";
        cout << "\t4 - Is Empty.\n";
        cout << "\t0 - Back.\n";

        choice = getInput();
    } while (!isValid(choice, 0, 4));

    static Stack stack;

    // Select the respective operation.
    switch (choice) {
        case 1: { // Push a value onto the stack.
            cout << "Enter a value to push onto stack\n";
            int value = getInput();
            stack.push(value);
            stack.show();
            showStackMenu();
            break;
        }
        case 2: { // Pop a value from the stack.
            stack.pop();
            stack.show();
            showStackMenu();
            break;
        }
        case 3: { // Peek the top value (without removing it).
            stack.peek();
            stack.show();
            showStackMenu();
            break;
        }
        case 4: { // Checks if the stack is empty.
            if (!stack.isEmpty()) {
                cout << "Stack is not empty.\n";
            }
            stack.show();
            showStackMenu();
            break;
        }
        case 0: // Reset the stack and go back to the main menu.
            stack = Stack();
            showMainMenu();
            break;
    }
}

/*
Displays a menu for Queue operations.

The 'Queue' variable is static to allow stack values to persist across multiple
menu calls.
*/
void showQueueMenu() {
    // Show a menu and repeatedly prompt user to enter a valid choice.
    int choice = -1;
    do {
        showTitle("Queue");
        cout << "\t1 - Enqueue.\n";
        cout << "\t2 - Dequeue.\n";
        cout << "\t3 - Peek.\n";
        cout << "\t4 - Is Empty.\n";
        cout << "\t0 - Back.\n";

        choice = getInput();
    } while (!isValid(choice, 0, 4));

    static Queue queue;

    // Select the respective operation based on the choice selected.
    switch (choice) {
        case 1: { // Enqueue / insert a value on the queue.
            cout << "Enter a value to enqueue\n";
            int value = getInput();
            queue.enqueue(value);
            queue.show();
            showQueueMenu();
            break;
        }
        case 2: { // Dequeue / remove a value from the queue.
            queue.dequeue();
            queue.show();
            showQueueMenu();
            break;
        }
        case 3: { // Peek / show the current front value, without removing it.
            queue.peek();
            queue.show();
            showQueueMenu();
            break;
        }
        case 4: { // Checks if the queue is empty or not.
            if (!queue.isEmpty()) {
                cout << "Queue is not empty.\n";
            }
            queue.show();
            showQueueMenu();
            break;
        }
        case 0: // Resets the queue and goes back to the main menu.
            queue = Queue();
            showMainMenu();
            break;
    }
}

/*
Displays the main menu.

This is the entry menu where other operations can be selected.
*/
void showMainMenu() {
    // Show the menu and prompt the user for a valid choice.
    int choice = -1;
    do {
        showTitle("Main Menu");

        cout << "\t1 - SinglyLinkedList.\n";
        cout << "\t2 - Stack.\n";
        cout << "\t3 - Queue.\n";
        cout << "\t0 - Exit.\n";

        choice = getInput();
    } while (!isValid(choice, 0, 3));

    switch (choice) {
        case 1: // Displays menu for SinglyLinkedList operations.
            showSinglyLinkedListMenu();
            break;
        case 2: // Displays menu for Stack operations.
            showStackMenu();
            break;
        case 3: // Displays menu for Queue operations.
            showQueueMenu();
            break;
        case 0: // Exits the program.
            cout << "Goodbye.\n";
            exit(0);
            break;
    }
}

// Main entry program.
int main() {
    showMainMenu();
    return 0;
}