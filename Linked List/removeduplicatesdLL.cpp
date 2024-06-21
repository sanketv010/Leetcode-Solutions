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

// O(N)
Node* removeDuplicates(Node* head){
    Node* temp = head;
    while(temp!=NULL && temp->next!=NULL){
        Node* nextnode = temp->next;
        while(nextnode!=NULL && nextnode->data == temp->data){
            Node* duplicate = nextnode;
            nextnode = nextnode->next;
            delete duplicate;
        }
        temp->next=nextnode;
        if(nextnode!=NULL){
            nextnode->prev = temp;
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> v = {2,2,2,5,5,8,8,8,8,7,7};
    Node* head = convertArr2dll(v);
    head = removeDuplicates(head);
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}