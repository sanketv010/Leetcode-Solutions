#include<bits/stdc++.h>
using namespace std;

// Brute force is data replacement

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

Node* reverseLLRecursive(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* newhead = reverseLLRecursive(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newhead;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = convertArr2ll(arr);
    head = reverseLLRecursive(head);
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;
}