#include <iostream>
#include <string>

using namespace std;

/**
 * Create the Queue Class (Shuttle Docking Queue)
 * Define a class Queue to represent a queue of space shuttles waiting to dock at the space station.
 * The class should have the following private attributes:
 * capacity (int): The maximum number of shuttles the queue can hold.
 * front (int): The index of the front shuttle in the queue.
 * rear (int): The index of the rear shuttle in the queue.
 * size (int): The current number of shuttles in the queue.
 * arr (dynamic array of type std::string): The array that stores the names of the shuttles.
 * Implement the following public methods:
 * enqueue(std::string shuttleName): Adds a shuttle to the rear of the queue.
 * dequeue(): Removes a shuttle from the front of the queue and returns its name.
 * isEmpty(): Returns true if the queue is empty, otherwise false.
 * isFull(): Returns true if the queue is full, otherwise false.
 * Implement a constructor that accepts a cap param to initialize private attributes.
 * Implement a deconstructor that deletes the arr.
 */
class Queue {
    int capacity;
    int front;
    int rear;
    int size;
    string* arr; 

public:
    Queue(int);
    ~Queue();
    void enqueue(string); 
    string dequeue(); 
    bool isEmpty();
    bool isFull(); 
    int getSize() const;
    int getFront() const;
    int getRear() const; 
};


Queue::Queue(int capacity) {
    this->capacity = capacity; 
    front = 0; 
    rear = -1; 
    size = 0; 
    arr = new string[capacity];
}

//destructor
Queue::~Queue() {
    delete[] arr;
}

void Queue::enqueue(string shuttleName) {
    if (!isFull()) {
        rear = (rear + 1) % capacity; 
        size++;
        arr[rear] = shuttleName;        
    } else {
        cout << "Shuttle queue is full" << endl;
    }
}

string Queue::dequeue() {    
    if (!isEmpty()) {
        string temp = arr[front];
        cout << "Docking Shuttle: " << temp << endl;;
        arr[front] = " ";
        front = (front + 1) % capacity; 
        size--;
        return temp; 
    } else {
        cout << "Shuttle queue is empty";
        return " ";
    }
}

bool Queue::isEmpty() {
    return size == 0; 
}

bool Queue::isFull() {
    return size == capacity; 
}

int Queue::getSize() const {
    return size; 
}

int Queue::getFront() const {
    return front; 
}
int Queue::getRear() const {
    return rear; 
}

/**
 * Create the Deque Class (Supply and Emergency Management)
 * Define a class Deque to represent a double-ended queue that can handle both regular supplies and high-priority emergencies at the space station.
 * The class should have the following private attributes:
 * capacity (int): The maximum number of items the deque can hold.
 * front (int): The index of the front item in the deque.
 * rear (int): The index of the rear item in the deque.
 * size (int): The current number of items in the deque.
 * arr (dynamic array of type std::string): The array that stores the items.
 * Implement the following public methods:
 * addFront(std::string item): Adds an item to the front of the deque.
 * addRear(std::string item): Adds an item to the rear of the deque.
 * removeFront(): Removes an item from the front of the deque and returns its name.
 * removeRear(): Removes an item from the rear of the deque and returns its name.
 * isEmpty(): Returns true if the deque is empty, otherwise false.
 * isFull(): Returns true if the deque is full, otherwise false.
 * Implement a constructor that accepts a a cap param to initialize private attributes.
 * Implement a deconstructor that deletes the arr.
 */
class Deque {
    int capacity; 
    int front;
    int rear;
    int size;
    string* arr;

public:
    Deque(int);
    ~Deque();
    void addFront(string);
    void addRear(string);
    string removeFront();
    string removeRear();
    bool isEmpty();
    bool isFull();
    int getSize() const;
    int getFront() const;
    int getRear() const; 
};

Deque::Deque(int capacity) {
   this->capacity = capacity;
   front = capacity - 1;
   rear = 0;
   size = 0; 
   arr = new string[capacity];    
}

Deque::~Deque() {
    delete[] arr; 
}

void Deque::addFront(string item) {
    if (!isFull()) {
        front = (front + 1) % capacity; 
        arr[front] = item;
        size++; 
    } else {
        cout << "The queue is full" << endl; 
    }
}

void Deque::addRear(string item) {
    if (!isFull()) {
        rear = (rear - 1 + capacity) % capacity; 
        arr[rear] = item; 
        size++;
    } else {
        cout << "The queue is full" << endl; 
    }
}

string Deque::removeFront() {
    if (!isEmpty()) {
        string temp = arr[front];
        arr[front] = " ";
        front = (front - 1 + capacity) % capacity;   
        size--;     
        cout << "Using: " << temp << endl;
        return temp; 
    } else {
        string temp = "Deque is empty";
        return temp;
    }
}

string Deque::removeRear() {
    if (!isEmpty()) {
        string temp = arr[rear];
        arr[rear] = " ";
        rear = (rear + 1) % capacity;
        size--;
        cout << "Using: " << temp << endl;
        return temp; 
    } else {
        string temp = "Deque is empty";
        return temp; 
    }
}

bool Deque::isEmpty() {
    return size == 0; 
}

bool Deque:: isFull() {
    return size == capacity; 
}

int Deque::getSize() const {
    return size;
}
int Deque::getFront() const {
    return front;
}
int Deque::getRear() const {
    return rear; 
} 

int main() {
    string display; 

    
    Deque d(3);

    cout << "Front: " << d.getFront() << endl << "Rear: " << d.getRear() << endl << "Size: " << d.getSize() << endl; 
 
    
    d.addRear("Oxygen");
    cout << "Item1 " << endl << "Front: " << d.getFront() << endl << "Rear: " << d.getRear() << endl << "Size: " << d.getSize() << endl; 
    d.addFront("Medical kit");
    cout << "Item2 " << endl << "Front: " << d.getFront() << endl << "Rear: " << d.getRear() << endl << "Size: " << d.getSize() << endl; 
    d.addRear("Water");        // now full
    cout << "Item3 " << endl << "Front: " << d.getFront() << endl << "Rear: " << d.getRear() << endl << "Size: " << d.getSize() << endl; 
    d.addFront("Food");        // should print "full"
    cout << "Item4 " << endl << "Front: " << d.getFront() << endl << "Rear: " << d.getRear() << endl << "Size: " << d.getSize() << endl; 
    d.removeFront();           // Using: Medical kit
    cout << "Front: " << d.getFront() << endl << "Rear: " << d.getRear() << endl << "Size: " << d.getSize() << endl;
    d.removeFront();           // Using: Oxygen   (added at rear, removed from front)
    cout << "Front: " << d.getFront() << endl << "Rear: " << d.getRear() << endl << "Size: " << d.getSize() << endl;
    d.removeRear();            // Using: Water
    cout << "Front: " << d.getFront() << endl << "Rear: " << d.getRear() << endl << "Size: " << d.getSize() << endl;
    cout << d.removeRear() << endl;  // Deque is empty
    cout << "Front: " << d.getFront() << endl << "Rear: " << d.getRear() << endl << "Size: " << d.getSize() << endl;

    Queue q(2);
    q.enqueue("Atlas");
    cout << "Ship1: " << endl << "Front: " << d.getFront() << endl << "Rear: " << d.getRear() << endl << "Size: " << d.getSize() << endl; 
    q.enqueue("Orion");
    cout << "Ship2: " << endl << "Front: " << d.getFront() << endl << "Rear: " << d.getRear() << endl << "Size: " << d.getSize() << endl; 
    q.dequeue();               // Docking Shuttle: Atlas
    q.enqueue("Dragon");       // wraps to index 0
    cout << "Ship3: " << endl << "Front: " << d.getFront() << endl << "Rear: " << d.getRear() << endl << "Size: " << d.getSize() << endl; 
    q.dequeue();               // Docking Shuttle: Orion
    q.dequeue();  
}