#include <iostream>
using namespace std;
class node {
public:
    int val;
    node * next;
};

void makeNode (node * &head , node * &tail, int n){
    node * tmp;
    for (int i=0; i<n ; i++){
        tmp = new node();
        tmp->next = NULL;
        cout<<"Enter value for i = "<<i<<": ";
        cin>> tmp->val;
        if (head == NULL){
            head = tmp;
            tail = tmp;
        }
        else {
            tail->next = tmp;
            tail = tmp;
        }
    }
}
int main() {
    
    node * head1 = NULL;
    node * tail1 = NULL;
    int n;
    node * head2 = NULL;
    node * tail2 = NULL;
    cout<<"Enter nodes for fisrt linkedList: ";
    cin >> n;
    makeNode(head1, tail1, n);
    
    cout<<"Enter nodes for second linkedList: ";
    cin >> n;
    makeNode(head2, tail2, n);
    
    int ct = 0;
    node * current1 = head1;
    node * current2 = head2;
    int flag = 0;
    while (current1 != NULL && current2 != NULL){
        
        if(current1->val == current2->val){
            if (!flag){
                cout<<"["<<ct<<", "<<current1->val<<"] ";
                flag++;
            }
            else{
                cout<<" ,"<<"["<<ct<<", "<<current1->val<<"] ";
            }
        }

        ct++;
        current1 = current1->next;
        current2 = current2->next;
    }
}
