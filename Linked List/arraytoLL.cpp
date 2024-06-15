#include <iostream>
#include<bits/stdc++.h>
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
        Node* temp =  new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

int search(Node* head, int key){
    Node* temp = head;
    int index = 0;
    while(temp!=NULL){
        if(temp->data==key){
            return index;
        }
        else{
            temp = temp->next;
            index++;
        }
    }
    return -1;
}

int main(){
    // Node* head = new Node(10, NULL);
    // cout<<head->data;
    vector<int> v = {2,5,8,7};
    Node* head = convertArr2ll(v);
    Node* temp = head;
    int length = 0;
    int x = search(head, 8);
    cout<<x;
    while(temp!=NULL){
        temp = temp->next;
        length++;
    }
    cout<<'\n'<<length;
    return 0;
}