#include <bits/stdc++.h>
using namespace std;

// Brute force is data replacement 2 pass solution

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

Node* sort012(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* zerohead = new Node(-1);
    Node* zero = zerohead;
    Node* onehead = new Node(-1);
    Node* one = onehead;
    Node* twohead = new Node(-1);
    Node* two = twohead;
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data==0){
            zero->next = temp;
            zero = zero->next;
        }
        else if(temp->data==1){
            one->next = temp;
            one = one->next;
        }
        else{
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    if(onehead->next){
        zero->next=onehead->next;
    }
    else{
        zero->next = twohead->next;
    }
    one->next = twohead->next;
    two->next = NULL;
    return zerohead->next;
}

int main(){
    vector<int> arr = {0, 1, 2, 0, 1, 2, 0, 1, 2};
    Node* head = convertArr2ll(arr);
    head = sort012(head);
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;
}