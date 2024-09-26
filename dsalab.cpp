#include <iostream>
using namespace std;

// declaring a nose class
class ListNode {
public:
    int data;
    ListNode *next;

    // constructor to initialize data and next pointer
    ListNode(int value) : data(value), next(nullptr) {}
};

// declaring class linked list
class LinkedList {
public:
    ListNode *start; // Pointer to the head node
    ListNode *last;  // Pointer to the last node
    ListNode *PredLoc_; // Pointer for logical predecessor during search
    ListNode *Loc_;     // Pointer for the searched node

    // Constructor to create a linked list
    LinkedList() {
        start = nullptr;    // Initialize start to NULL
        last = nullptr;     // Initialize last to NULL
        PredLoc_ = nullptr; // Initialize PredLoc_ to NULL
        Loc_ = nullptr;     // Initialize Loc_ to NULL
    }

    // checks if the list is empty
    bool IsEmpty() {
        return start == nullptr; // returns true if empty
    }

    // inserts a value at the front of the  
    //creates a new node, points to the prev first node, updates head to be the new node
    void InsertAtFront(int value) {
        ListNode *newnode = new ListNode(value); 
        newnode->next = start; 
        start = newnode; 
        if (last == nullptr) {
            last = newnode; // if the list was empty update last
        }
    }

    // inserts a value at the end of the list
    // creates a newnode that will be the last node
    void InsertAtEnd(int value) {
        ListNode *newnode = new ListNode(value);
        newnode->next = nullptr; // newnode points to the last node

        if (IsEmpty()) {
            start = newnode; // if it is empty, set start to the new node
            last = newnode;  // sets last to the new node
        } else {
            last->next = newnode; // linking the last node to the new node
            last = newnode; // updating last to new
        }
    }

    // prints all elements of the linked list
    // starts from the head node, traverses until the end and prints the data
    void PrintList() {
        ListNode *temp = start; 
        while (temp != nullptr) { 
            cout << temp->data << " "; 
            temp = temp->next; 
        }
        cout << endl; 
    }

    // searches for a value from the head, and traverses until the value to next address pointed until value is reached
    void Search(int value) {
        Loc_ = start; 
        PredLoc_ = nullptr; 
        while (Loc_ != nullptr && Loc_->data < value) {
            PredLoc_ = Loc_; 
            Loc_ = Loc_->next;
        }
    }

    // inserts a value in a sorted manner
    void InsertSorted(int value) {
        Search(value); // checks if it exits
        if (Loc_ != nullptr) {
            cout << "value already exists in the list!!!" << endl;
            return; //does not insert
        }

        ListNode *newnode = new ListNode(value);

        // logic to insert at the correct position
        if (PredLoc_ == nullptr) {
            // if it is the smallest value, points to the old head, updates head to be the new node, and if list was empty also updates last
            newnode->next = start; 
            start = newnode; 
            if (last == nullptr) {
                last = newnode;
            }
        } else {
            // inserting middle/end--> point to the node that was found and link pred to newnode, then update last oif inseritgn at end
            newnode->next = Loc_; 
            PredLoc_->next = newnode; 

            if (Loc_ == nullptr) {
                last = newnode; 
            }
        }
    }

    // deletes a value --> finds the node and deletes it
    void Delete(int value) {
        Search(value); 
        //if val not dound
        if (Loc_ == nullptr) {
            cout << "Value not found!!! " << endl; 
            return;
        }

        //if value is found--> if deletion is at the head (update head to next node) or later (goes to the next address to delete)
        if (PredLoc_ == nullptr) {
            start = Loc_->next;
        } else {
            // bypasses the node to be deleted
            PredLoc_->next = Loc_->next;
        }
        delete Loc_; // for memory leak??
        Loc_ = nullptr; // !!! reset Loc_ to prevent dangling pointer
    }

    // destroys the linked list by traversing and using current as memory to move foward
    void DestroyList() {
        ListNode *current = start;
        while (current != nullptr) {
            ListNode *temp = current; 
            current = current->next; 
            delete temp; 
        }
        //resets
        start = nullptr; 
        last = nullptr; 
    }
};

int main() {
    LinkedList list; //creating an instance 
    int value;

    // 1. Insert at Front
    cout << "enter value to insert at front: ";
    cin >> value;
    list.InsertAtFront(value);

    // 2. Insert at End
    cout << "enter value to insert at end: ";
    cin >> value;
    list.InsertAtEnd(value);

    // 3. Insert Sorted
    cout << "enter value to insert sorted: ";
    cin >> value;
    list.InsertSorted(value);

    // 4. Print List
    cout << " -- Current List: ";
    list.PrintList();

    // 5. Check if Empty
    if (list.IsEmpty()) {
        cout << "The list is empty!!!" << endl;
    } else {
        cout << "The list is not empty!!!" << endl;
    }

    // 6. Delete a Value
    cout << "enter value to delete: ";
    cin >> value;
    list.Delete(value);

    // 7. Print List again
    cout << " -- Current List after deletion: ";
    list.PrintList();

    // 8. Destroy List
    list.DestroyList();
    cout << "-- List destroyed :( " << endl;

    return 0; 
}