#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

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

Node* deleteNthEnd(Node* head, int n){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* fast = head;
    Node* slow = head;
    for(int i=0; i<n; i++){
        fast = fast->next;
    }
    if(fast==NULL){
        return head->next;
    }
    while(fast->next!=NULL){
        fast = fast->next;
        slow = slow->next;
    }
    Node* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
    return head;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = convertArr2ll(arr);
    head = deleteNthEnd(head, 3);
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;
}