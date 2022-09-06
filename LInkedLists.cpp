#include<iostream>
using namespace std;

struct Node{
    int data;
    // this will hold our data 
    Node* Next;
    // This will be used to point to the next node
};

struct Node* head =NULL;
// This is used to tell the pointer that the head is empty at the moment
void insert(int temp){
    struct Node* new_node =(struct Node*)malloc(sizeof(struct Node));
    new_node->data = temp;
    new_node->Next = head;
    head = new_node;
}
void remove(){

    if(head == NULL){
        cout << "Stack underflow" << endl;
    }
        else{
            cout << "Removed from linked List: " << head->data << endl;
            head= head->Next;
            
        }
}
Node* removelastNode(struct Node* head){
    if(head == NULL){
        return NULL;
    }
    if (head->Next == NULL){
        delete head;
        return NULL;
    }

    Node* second_last = head;
    while( second_last->Next->Next != NULL)
        second_last = second_last->Next;
    delete (second_last->Next);
    second_last->Next = NULL;
    return head;
}
void display(){
    struct Node* ptr;
    if(head == NULL){
        cout << "stack is empty" << endl;
    }
    else{
        ptr = head;
        cout<< "Linked list items are: ";
        while (ptr != NULL){
            cout << ptr->data << " ";
            ptr = ptr -> Next;
        }
    }
    cout<<endl;
}

int main() {
    insert(60);
    insert(40);
    insert(20);
    display();
    remove();
    display();
    head = removelastNode(head);
    display();



    return 0;
}