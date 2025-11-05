#include <print>

#include <array>

constexpr int MAX = 5;

class Vertex {
public:
    char label;
    bool visited;
};

std::array<int, MAX> stack;
int top = -1;

// Graph variables and array of vertices
std::array<Vertex*, MAX> listVertices;

// Adjacency matrix
std::array<std::array<int, MAX>, MAX> adjacentMatrix;

// Vertex count
int vertexCount = 0;

void push(int item) {
    stack[++top] = item;
}

int pop() {
    return stack[top--];
}

int peek() {
    return stack[top];
}

bool isStackEmpty() {
    return top == -1;
}

void addVertex(char label) {
    Vertex* vertex = new Vertex;
    vertex->label = label;
    vertex->visited = false;

    listVertices[vertexCount++] = vertex;
}

void addEdge(int start, int end) {
    adjacentMatrix[start][end] = 1;
    adjacentMatrix[end][start] = 1;
}

void displayVertex(int vertexIndex) {
    std::print("{} ", listVertices[vertexIndex]->label);
}

int getAdjacentUnvisitedVertex(int vertexIndex) {
    for (int i = 0; i < vertexCount; ++i) {
        if (adjacentMatrix[vertexIndex][i] == 1 && !listVertices[i]->visited) {
            return i;
        }
    }
    return -1;
}

void depthFirstSearch() {
    listVertices[0]->visited = true;
    // display the vertex
    displayVertex(0);

    // push vertex index in stack
    push(0);
    while (!isStackEmpty()) {
        // get the unvisited vertex of vertex which is at top of the stack
        int unvisitedVertex = getAdjacentUnvisitedVertex(peek());
        // no adjacent vertex found
        if (unvisitedVertex == -1) {
            pop();
        } else {
            listVertices[unvisitedVertex]->visited = true;
            displayVertex(unvisitedVertex);
            push(unvisitedVertex);
        }
    }

    // stack is empty, search is complete, reset the visited flag
    for (int i = 0; i < vertexCount; i++) {
        listVertices[i]->visited = false;
    }
}

int main() {
    for (int i = 0; i < MAX; i++) {     // set adjacency
        for (int j = 0; j < MAX; j++) { // matrix to 0
            adjacentMatrix[i][j] = 0;
        }
    }

    addVertex('S');
    addVertex('A');

    addVertex('B');
    addVertex('C');
    addVertex('D');
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(0, 3);
    addEdge(1, 4);
    addEdge(2, 4);
    addEdge(3, 4);
    std::println("Depth First Search: ");
    depthFirstSearch();

    return 0;
}