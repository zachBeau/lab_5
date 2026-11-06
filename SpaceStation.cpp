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
};


Queue::Queue(int capacity) {
    this->capacity = capacity; 
    front = 0; 
    rear = -1; 
    size = 0; 
    arr = new string[capacity];
}


Queue::~Queue() {
    delete[] arr;
}

void Queue::enqueue(string shuttleName) {
    if (!isFull()) {
        rear = (rear + 1) % capacity; 
        size++;
        arr[rear] = shuttleName;   
        cout << "SHUTTLE: " << arr[rear] << "\thas been added to the docking schedule" << endl;      
    } else {
        cout << "Shuttle queue is full. SHUTTLE: " << shuttleName << " could not be added." << endl;
    }
}

string Queue::dequeue() {    
    if (!isEmpty()) {
        string temp = arr[front];
        arr[front] = " ";
        front = (front + 1) % capacity; 
        size--;
        cout << "DOCKING: " << temp << endl; 
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
        cout << "ITEM: " << arr[front] << "\thas been added to the front of the queue" << endl; 
    } else {
        cout << "The queue is full " << item << " could not be added." << endl; 
    }
}

void Deque::addRear(string item) {
    if (!isFull()) {
        rear = (rear - 1 + capacity) % capacity; 
        arr[rear] = item; 
        size++;        
        cout << "ITEM: " << arr[rear] << "\thas been added to the rear of the queue" << endl; 
    } else {
        cout << "The queue is full " << item << " could not be added."  << endl; 
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
        cout << "Deque is empty. There is nothing to be removed" << endl; 
        return "";
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
        cout << "Deque is empty. There is nothing to be removed" << endl; 
        return "";
    }
}

bool Deque::isEmpty() {
    return size == 0; 
}

bool Deque:: isFull() {
    return size == capacity; 
}

int main()
{
    /**
     * Enqueue Shuttles (Arrival at Space Station)
     * Create an instance of Queue with a capacity of 5 to represent the docking queue.
     * Enqueue the following shuttles into the queue: "Discovery," "Atlantis," "Endeavour," "Challenger," and "Enterprise."
     * Print a message each time a shuttle is added to the queue.
     */
    Queue dock(5); 
    dock.enqueue("Discovery");
    dock.enqueue("Atlantis");
    dock.enqueue("Endeavour");
    dock.enqueue("Challenger");
    dock.enqueue("Enterprise");

    /**
     * Handle Full Queue (Overflow at the Dock)
     * Attempt to enqueue another shuttle, "Columbia," and handle the case where the queue is full by printing an appropriate message.
     */
    dock.enqueue("Colombia"); 

    /**
     * Dequeue Shuttles (Docking Shuttles)
     * Dequeue shuttles from the queue as they dock at the space station.
     * Print a message each time a shuttle docks.
     */
    dock.dequeue();
    dock.dequeue();
    dock.dequeue();
    dock.dequeue();
    dock.dequeue(); 

    /**
     * Add Supplies (Restocking the Space Station)
     * Create an instance of Deque with a capacity of 5 to represent the station's supply and emergency management.
     * Add two regular supplies (e.g., "Oxygen Tanks," "Food Supplies") to the rear of the deque.
     * Print a message each time an item is added.
     */
    Deque supplies(5); 
    supplies.addRear("Oxygen Tanks"); 
    supplies.addRear("Food Supplies");


    /**
     * Handle Emergencies (Prioritizing with the Deque)
     * Add one high-priority item (e.g., "Medical Supplies") to the front of the deque, representing emergencies.
     * Print a message each time an emergency item is added.
     */
    supplies.addFront("Medical Supplies");

    /**
     * Remove Items (Using Supplies and Responding to Emergencies)
     * Remove an item from the front and then an item from the rear, simulating the use of supplies and emergency responses.
     * Print a message each time an item is removed
     */

    supplies.removeFront(); 
    supplies.removeRear();

    /**
     * Test the Deque (Full Station)
     * Attempt to add more items to the deque after it reaches capacity, and handle the overflow by printing an appropriate message.
     */
    supplies.addFront("Repair Drone");
    supplies.addFront("Space Suit");
    supplies.addRear("Personnel Mail");
    supplies.addFront("Life Support Kit");
    supplies.addRear("Potted Plant");

    /**
     * Test the Deque (Empty Station)
     * Remove an item from the front and then attempt to remove the rest of the items
     * from the rear until you've emptied the deque, and handle the underflow by printing
     * an appropriate message when you try to remove an item when the Deque is empty.
     */
    supplies.removeFront();
    supplies.removeRear();
    supplies.removeRear();
    supplies.removeRear();
    supplies.removeRear();
    supplies.removeRear(); 
}
