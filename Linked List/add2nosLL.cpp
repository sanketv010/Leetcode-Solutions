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
        Node* temp = new Node(arr[i], NULL); 
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node* addtwolist(Node* head1, Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* dummynode = new Node(-1);
    Node* curr = dummynode;
    int carry = 0;
    while(temp1!=NULL || temp2!=NULL){
        int sum = carry;
        if(temp1) sum+=temp1->data;
        if(temp2) sum+=temp2->data;

        Node* newnode = new Node(sum%10);
        carry = sum/10;
        curr->next = newnode;
        curr = curr->next;
        if(temp1) temp1 = temp1->next;
        if(temp2) temp2 = temp2->next;
    }
    if(carry){
        Node* newnode = new Node(carry);
        curr->next = newnode;
    }
    return dummynode->next;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> arr1 = {1, 2, 3, 4, 5};
    Node* head = convertArr2ll(arr);
    Node* head1 = convertArr2ll(arr1);
    Node* sum = addtwolist(head, head1);
    Node* temp = sum;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}