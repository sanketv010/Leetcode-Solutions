#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

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

Node* deleteoccurencedll(Node* head, int key){
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data == key){
            if(temp==head){
                head = head->next;
            }
            Node* nextnode = temp->next;
            Node* prevnode = temp->prev;
            if(nextnode!=NULL){
                nextnode->prev = prevnode;
            }
            if(prevnode!=NULL){
                prevnode->next = nextnode;
            }
            delete temp;
            temp = nextnode;
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 3, 5, 3};
    Node* head = convertArr2dll(arr);
    head = deleteoccurencedll(head, 3);
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;
}