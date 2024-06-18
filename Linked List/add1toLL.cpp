#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = NULL;
    }
};

Node* convertArr2ll(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], NULL);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node* reverseLL(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }    
    Node* prev = NULL;
    Node* temp = head;
    while(temp!=NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

// TC: O(3n) and SC: O(1)
Node* add1(Node* head){
    head = reverseLL(head);
    Node* temp = head;
    int carry = 1;
    while(temp!=NULL){
        temp->data+=carry;
        if(temp->data<10){
            carry=0;
            break;
        }
        else{
            temp->data=0;
            carry = 1;
        }
        temp = temp->next;
    }
    if(carry==1){
        Node* newnode = new Node(1);
        head = reverseLL(head);
        newnode->next = head;
        return newnode;
    }
    else{
        head = reverseLL(head);
        return head;
    }
}

int addhelper(Node* temp){
    if(temp==NULL){
        return 1;
    }
    int carry = addhelper(temp->next);
    temp->data+=carry;
    if(temp->data<10){
        return 0;
    }
    else{
        temp->data = 0;
        return 1;
    }
}

// TC: O(n) and SC: O(n)
Node* add1recursive(Node* head){
    int carry = addhelper(head);
    if(carry==0){
        return head;
    }
    else{
        Node* newhead = new Node(carry, head);
        return newhead;
    }
}

int main(){
    vector<int> arr = {9, 9, 9, 9};
    Node* head = convertArr2ll(arr);
    head = add1(head);
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;
}