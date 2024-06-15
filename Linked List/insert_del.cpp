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

Node* deletehead(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* deletelast(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return head; 
}

Node* deleteindex(Node* head, int index){
    if(head==NULL){
        return NULL;
    }
    if(index==0){
        return deletehead(head);
    }
    Node* temp = head;
    for(int i=0; i<index-1; i++){
        temp = temp->next;
    }   
    Node* temp1 = temp->next;
    temp->next = temp1->next;
    delete temp1;
    return head; 
}

Node* deletevalue(Node* head, int value){
    if(head==NULL){
        return NULL;
    }
    if(head->data==value){
        return deletehead(head);
    }
    Node* temp = head;
    while(temp->next->data!=value){
        temp = temp->next;
    }
    Node* temp1 = temp->next;
    temp->next = temp1->next;
    delete temp1;
    return head;
}

Node* insertathead(Node* head, int data){
    Node* temp = new Node(data, head);
    return temp;
}

Node* insertatend(Node*head, int data){
    if(head==NULL){
        return new Node(data);
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = new Node(data);
    return head;
}

Node* insertatindex(Node* head, int data, int index){
    if (head == NULL || index == 0){
        return insertathead(head, data);
    }
    Node* temp = head;
    for(int i=0; i<index-1; i++){
        temp = temp->next;
    }
    Node* temp1 = new Node(data, temp->next);
    temp->next = temp1;
    return head;
}

int main(){ 
    vector<int> v = {2,5,8,7};
    Node* head = convertArr2ll(v);
    head = insertatindex(head, 1, 3);
    // Node *newhead = deletevalue(head, 3);
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}