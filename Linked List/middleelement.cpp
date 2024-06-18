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

int lengthLL(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

int middleElement(Node* head){
    if(head==NULL || head->next==NULL){
        return 0;
    }
    int len = lengthLL(head);
    Node* temp = head;
    for(int i=0; i<len/2; i++){
        temp = temp->next;
    }
    return temp->data;
}

int middleElementop(Node* head){
    if(head==NULL || head->next==NULL){
        return 0;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = convertArr2ll(arr);
    cout<<middleElement(head)<<endl;
    // cout<<middleElementop(head);
    return 0;
}