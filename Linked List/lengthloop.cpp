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

int lengthloopLLbf(Node* head){
    unordered_map<Node*, int> mp;
    Node* temp = head;
    int timer = 1;
    while(temp!=NULL){
        if(mp.find(temp)!=mp.end()){
            int value = mp[temp];
            return timer-value;
        }
        mp[temp] = timer;
        timer++;
        temp = temp->next;
    }
    return 0;
}

int findlength(Node* slow, Node* fast){
    int count = 1;
    fast = fast->next;
    while(slow!=fast){
        count++;
        fast = fast->next;
    }
    return count;
}

int lengthloopLL(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            return findlength(slow, fast);
        }
    }
    return 0;
}

int main(){

}