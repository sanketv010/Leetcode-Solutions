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

Node* getkthnode(Node* temp, int k){
    k-=1;
    while(temp!=NULL && k>0){
        k--;
        temp = temp->next;
    }
    return temp;
}

Node* reverseKgroup(Node* head, int k){
     Node* temp = head;
     Node* prevnode=NULL;
     while(temp!=NULL){
        Node* kthnode = getkthnode(temp, k);
        if(kthnode==NULL){
            if(prevnode) prevnode->next = temp;
            break;
        }
        Node* nextnode = kthnode->next;
        kthnode->next = NULL;
        reverseLL(temp);
        if(temp==head){
            head = kthnode;
        }
        else{
            prevnode->next = kthnode;  
        }
        prevnode = temp;
        temp = nextnode;
     }
    return head;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    Node* head = convertArr2LL(arr);
    head = reverseKgroup(head, 3);
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;
}