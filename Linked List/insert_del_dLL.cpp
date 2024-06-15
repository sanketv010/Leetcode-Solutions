#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node *prev;

    public:
    Node(int data1, Node* next1, Node* prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }

    public:
    Node(int data1){
        data = data1;
        next = NULL;
        prev = NULL;
    }
};

Node* convertArr2dll(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], NULL, mover); 
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node* deletehead(Node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    delete temp;
    return head;
}

Node* deletelast(Node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->prev->next = NULL;
    temp->prev = NULL;
    delete temp;
    return head;
}

int main(){
    vector<int> v = {2,5,8,7};
    Node* head = convertArr2dll(v);
    head = deletelast(head);    
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}