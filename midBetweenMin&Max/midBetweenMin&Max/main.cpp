#include <iostream>
using namespace std;
class cNode {
public:
    int info;
    cNode * pNext;
    cNode * pExtra;

};
class list{
public:
    cNode * head;
    cNode * tail;
    list(){
        head = tail = NULL;
    }
    ~list(){
        cNode * pTrav = head;
        while(pTrav != NULL){
            head = pTrav->pNext;
            pTrav->pNext = NULL;
            delete pTrav;
            pTrav = head;
        }
    }

    
    void attach(cNode * newcNode){
        if (head == NULL){
            head = newcNode;
            tail = newcNode;
        } else {
            tail->pNext = newcNode;
            tail = newcNode;
        }
    }
    void attachByValue (int value){
        cNode * newNode = new cNode();
        newNode-> info = value;
        newNode->pNext = NULL;
        newNode->pExtra = NULL;
        
        if (head == NULL){
            head = newNode;
            tail = newNode;
        } else {
            tail->pNext = newNode;
            tail = newNode;
        }
    
    }
};
    
    

void listOut (list &main){
    cNode * pTrav = main.head;
    cout<<"[";
    while (pTrav!=NULL) {
        if (pTrav->pNext!=NULL){
            cout<<pTrav->info<<" ,";
        } else { cout<<pTrav->info; }
        pTrav=pTrav->pNext;
    }
    cout<<"]\n";
}
cNode * inBetween(list & l){
    cNode * pTrav = l.head;
    cNode * midMin = l.head;
    cNode * midMax = l.head;
    cNode * currMid = l.head;
    cNode * pMax, * pMin;
    int isInMin = 0, isInMax = 0;
    int min = 99999;
    int max = -99999;
    int i = 0;
    while (pTrav != NULL){
        isInMax = 0;

        if (pTrav->info > max){
            isInMax = 1;
            pMax = pTrav;
            max = pTrav->info;
            midMax = pMax;

            currMid = midMin;
        }
        
        if (pTrav->info < min){
            pMin = pTrav;
            min = pTrav->info;
            midMin = pMin;
            currMid = midMax;

        }

        i++;
        if (i % 2 == 0 && i>1){
            midMax = midMax ->pNext;
            midMin = midMin -> pNext;
        }


        pTrav = pTrav -> pNext;
    }
    
    cout<<"[Min: "<<pMin->info<<" ,";
    cout<<"Max: "<<pMax->info<<"]\n";
    
    return currMid;
}

int main() {
    list l;
    l.attachByValue(350);
    l.attachByValue(12);
    l.attachByValue(56);
    l.attachByValue(35);
    l.attachByValue(95);

    l.attachByValue(14);

    l.attachByValue(34);



    l.attachByValue(57);

    l.attachByValue(240);

    l.attachByValue(180);

    l.attachByValue(17);

    l.attachByValue(60);
    l.attachByValue(11);
    listOut(l);
    cout<< inBetween(l)->info<<endl;

    
    
}
