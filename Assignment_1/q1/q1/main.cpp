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

    node * head = NULL;
    node * tail = NULL;
    node * current;
    int numberOfNodes;
    int targetedValue;
    cout<<"Enter number of nodes: ";
    cin>>numberOfNodes;
    makeNode(head, tail, numberOfNodes);
    cout<<"Enter target value: ";
    cin>>targetedValue;
    
    int ct=0;
    current = head;
    while (current!=NULL){
        if(targetedValue == current->val){
            break;
        }
        ct++;
        current = current->next;
    }
    
    current = head;
    int secondCounter = 0;
    int tot1 = 0, tot2 = 0;
    
    while (current!=NULL){
        if (secondCounter >= ct - 3 && secondCounter<ct){
            tot1 += current->val;
        }
        
        if(secondCounter > ct && secondCounter <= ct + 3){
            tot2 += current->val;
        }
        secondCounter++;
        current = current->next;
    }
    
    cout<<"total of first interval is: "<<tot1<<endl;
    cout<<"total of second interval is: "<<tot2<<endl;
    
    cout<<"total of both intervals is: "<<tot1+tot2<<endl;
}
