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
    
    void listOut (){
        cNode * pTrav = head;
        cout<<"[";
        while (pTrav!=NULL) {
            if (pTrav->pNext!=NULL){
                cout<<pTrav->info<<" ,";
            } else { cout<<pTrav->info; }
            pTrav=pTrav->pNext;
        }
        cout<<"]\n";
    }
    
    void Cut_Paste_Two_largest_Values(list & l){
        int ct = 0;
        cNode * PB2 = head;
        cNode * pTrav = head;
        cNode * pB = head;
        cNode * pB2 = NULL;
        cNode * pBefore = NULL;
        
        int max1 = -99999;
        cNode * pmax1 = NULL;
        int max2 = -99999;
        cNode * pmax2 = NULL;

        
        cNode * pKG;
        pKG = pBefore->pNext;
        pBefore->pNext = pmax1->pNext;
        tail->pNext = pmax2->pNext;
        tail = pmax2;
        pmax2->pNext = NULL;
        pmax1->pExtra->pNext = head;
        head = pKG;
        
    }

};

void Cut_Paste_Two_largest_Values(list & l){
    cNode * pTrav = l.head;
    int max1 = -99999;
    int posM1;
    int posM2;
    cNode * pTravBackByFour = l.head;
    cNode * M1BackByFour=NULL;
    cNode * M2BackByFour=NULL;
    cNode * currentBackByFour=NULL;
    cNode * pMax1;
    int ct = 0;
    cNode * pBack = NULL;
    
    int max2 = max1+1;
    cNode * pMax2;

    while(pTrav != NULL){
        if(pTrav->info > max2){
            max1 = max2;
            pMax1 = pMax2;
            posM1 = posM2;
            M1BackByFour = M2BackByFour;
            max2 = pTrav->info;
            pMax2 = pTrav;
            posM2 = ct;
            M2BackByFour = pTravBackByFour;
            currentBackByFour = M1BackByFour;
        } else {
            if (pTrav->info > max1){
                max1 = pTrav->info;
                pMax1 = pTrav;
                posM1 = ct;
                M1BackByFour = pTravBackByFour;
                currentBackByFour = M2BackByFour;
            }
        }
        
        if (ct>=4){
            pTravBackByFour = pTravBackByFour->pNext;
        }
        pTrav->pExtra = pBack;
        pBack = pTrav;
        pTrav = pTrav->pNext;
        ct++;
    }
    
    if(posM1>posM2){
        cNode * z = pMax1;
        pMax1 = pMax2;
        pMax2 = z;
    }
    
    pMax1->pExtra->pNext = pMax2->pNext;
    l.tail->pNext = pMax1;
    pMax2->pNext = NULL;
    l.tail = pMax2;
    currentBackByFour->pExtra->pNext = pMax1->pExtra->pNext;
    pMax1->pExtra->pNext = l.head;
    l.head = currentBackByFour;
    
    

    
}
enum testCase{
    LargestValueFirst,
    LargestValueSecond,
};
void MakeLinkedList(testCase test, list & l){
    switch (test) {
        case LargestValueFirst:
            l.attachByValue(12);
            l.attachByValue(56);
            l.attachByValue(35);
            l.attachByValue(95);
            l.attachByValue(14);
            l.attachByValue(51);
            l.attachByValue(13);
            l.attachByValue(62);
            l.attachByValue(82);
            l.attachByValue(16);
            l.attachByValue(33);
            l.attachByValue(98);
            l.attachByValue(240);
            l.attachByValue(11);
            l.attachByValue(34);
            l.attachByValue(57);
            l.attachByValue(350);
            l.attachByValue(180);
            l.attachByValue(17);
            l.attachByValue(66);
            l.attachByValue(39);
            l.attachByValue(91);
            break;
            
        default:
            l.attachByValue(12);
            l.attachByValue(56);
            l.attachByValue(35);
            l.attachByValue(95);
            l.attachByValue(14);
            l.attachByValue(51);
            l.attachByValue(13);
            l.attachByValue(62);
            l.attachByValue(82);
            l.attachByValue(16);
            l.attachByValue(33);
            l.attachByValue(98);
            l.attachByValue(350);
            l.attachByValue(11);
            l.attachByValue(34);
            l.attachByValue(57);
            l.attachByValue(240);
            l.attachByValue(180);
            l.attachByValue(17);
            l.attachByValue(66);
            l.attachByValue(39);
            l.attachByValue(91);
            break;
    }
}

int main(){
    list l;
    
    //Hey, if you would like to test different test cases just use one of the case below:
    //LargestValueFirst OR largestValueSecond
    //If you would like to add other test cases or edit a bug that i've missed please go ahead and make sure to pull request the edit! :>
    
    
    MakeLinkedList(LargestValueSecond, l);
    Cut_Paste_Two_largest_Values(l);
    l.listOut();
    
}
