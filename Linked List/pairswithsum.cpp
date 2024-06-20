#include<bits/stdc++.h>
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

vector<vector<int>> pairswithsumbf(Node* head, int sum){
    Node* temp1 = head;
    vector<vector<int>> res;
    while(temp1!=NULL){
        Node* temp2= temp1->next;
        while(temp2!=NULL && temp1->data + temp2->data<=sum){
            if(temp1->data + temp2->data == sum){
                vector<int> temp;
                temp.push_back(temp1->data);
                temp.push_back(temp2->data);
                res.push_back(temp);
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return res;
}

Node* findtail(Node* head){
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    return temp;
}

vector<vector<int>> pairswithsum(Node* head, int sum){
    Node* left = head;
    Node* right = findtail(head);
    vector<vector<int>> res;
    while(left->data<right->data){
        if(left->data+right->data == sum){
            vector<int> temp;
            temp.push_back(left->data);
            temp.push_back(right->data);
            res.push_back(temp);
            left = left->next;
            right = right->prev;
        }
        else if(left->data+right->data<sum){
            left = left->next;
        }
        else{
            right = right->prev;
        }
    }
    return res;
}

int main(){
    vector<int> arr = {1, 2, 4, 5, 6, 8, 9};
    Node* head = convertArr2dll(arr);
    vector<vector<int>> res = pairswithsum(head, 7);
    for(int i=0; i<res.size(); i++){
        cout<<res[i][0]<<" "<<res[i][1]<<endl;
    }
    return 0;
}