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

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], NULL);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node* getkthnode(Node* temp, int k){
    k-=1;
    while(temp!=NULL && k>0){
        k--;
        temp = temp->next;
    }
    return temp;
}

Node* rotateLLbyk(Node* head, int k){
    if(head==NULL || k==0){
        return head;
    }
    int len = 1;
    Node* tail = head;
    while(tail->next!=NULL){
        len++;
        tail = tail->next;
    }
    if(k%len==0){
        return head;
    }
    k = k%len;
    tail->next = head;
    Node* newNode = getkthnode(head, len-k);
    head = newNode->next;
    newNode->next = NULL;
    return head;
}

int main(){
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    Node* head = convertArr2LL(v);
    head = rotateLLbyk(head, 3);
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;
}