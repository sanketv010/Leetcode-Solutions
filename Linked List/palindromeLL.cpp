#include<bits/stdc++.h>
using namespace std;

// Brute force is using stack and two passes with TC of O(2n) and SC of O(n)

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

bool ispalindrome(Node* head){
    if(head==NULL || head->next==NULL){
        return true;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* newhead = reverseLL(slow->next);
    Node* first = head;
    Node* second = newhead;
    while(second!=NULL){
        if(first->data!=second->data){
            reverseLL(newhead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseLL(newhead);
    return true;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    Node* head = convertArr2ll(arr);
    cout<<ispalindrome(head);
    return 0;
}