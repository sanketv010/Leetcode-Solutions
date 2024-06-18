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

Node* intersectionLLbf(Node* head1, Node* head2){
    unordered_map<Node*, int> mp;
    Node* temp1 = head1;
    Node* temp2 = head2;
    while(temp1!=NULL){
        mp[temp1] = 1;
        temp1 = temp1->next;
    }
    while(temp2!=NULL){
        if(mp.find(temp2) != mp.end()){
            return temp2;
        }
        temp2 = temp2->next;
    }
    return NULL;
}

int LengthLL(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

Node* intersectionLLbetter(Node* head1, Node* head2){
    int l1 = LengthLL(head1);
    int l2 = LengthLL(head2);
    Node* temp1 = head1;
    Node* temp2 = head2;
    if(l1==l2){
        while(temp1!=NULL && temp2!=NULL){
            if(temp1==temp2){
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    else if(l1<l2){
        for(int i=0; i<l2-l1; i++){
            temp2 = temp2->next;
        }
        while(temp1!=NULL && temp2!=NULL){
            if(temp1==temp2){
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    else{
        for(int i=0; i<l1-l2; i++){
            temp1 = temp1->next;
        }
        while(temp1!=NULL && temp2!=NULL){
            if(temp1==temp2){
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    return NULL;
}

Node* intersectionLLop(Node* head1, Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    if(head1==NULL || head2==NULL){
        return NULL;
    }
    while(temp1!=temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;
        if(temp1==temp2){
            return temp1;
        }
        if(temp1==NULL){
            temp1 = head2;
        }
        if(temp2==NULL){
            temp2 = head1;
        }
    }
    return temp1;
}

int main(){
    return 0;
}