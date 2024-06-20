#include <bits/stdc++.h>
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
    int count=0;
    Node* temp = head;
    while(temp!=NULL){
        count++;
        temp = temp->next;  
    }
    return count;
}

Node* deletemiddle(Node* head){
    Node* temp = head;
    int len = lengthLL(head);
    int mid = len/2;
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    while(temp!=NULL){
        mid--;
        if(mid==0){
            Node* middle = temp->next;
            temp->next = temp->next->next;
            delete middle;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node* deletemiddleOP(Node* head){
    Node* slow = head;
    Node* fast = head->next->next;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* middle = slow->next;
    slow->next = slow->next->next;
    delete middle;
    return head;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = convertArr2ll(arr);
    head = deletemiddleOP(head);
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
    return 0;
}