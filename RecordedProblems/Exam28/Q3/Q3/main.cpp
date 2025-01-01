#include <iostream>
using namespace std;
class cNode {
public:
    int info;
    cNode * pNext;
    cNode * pDown;

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
        newNode->pDown = NULL;
        
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
    };
class cStack{
public:
    cNode * head;
    cStack(){
        head = NULL;
    }
    void push (cNode * pnn){
        pnn -> pNext = head;
        head = pnn;
    }
    
    cNode * pop(){
        cNode * pTrav = head;
        if(pTrav == NULL){
            return NULL;
        }
        head = head -> pNext;
        pTrav->pNext = NULL;
        return pTrav;
    }
    
    
};

void attachByValueDown(int value, cNode * head, int &ct, cNode *& catchNegative, cNode *& pb, int & target, cNode * &biggest, int & max){
    cNode * newNode = new cNode();
    newNode-> info = value;
    newNode->pNext = NULL;
    newNode->pDown = NULL;
    if(value < 0){
        catchNegative = newNode;
        target = -value;
    }
    if(target > max){
        biggest = catchNegative;
        max = target;
    }
    if(catchNegative == NULL){
        pb = newNode;
    }
    if(ct == target){
        catchNegative->pNext = newNode;
        catchNegative = NULL;
    }

    if (head->pDown == NULL){
        head->pDown = newNode;
        head->pDown->pNext = newNode;
        
    } else {
        head->pDown->pNext->pDown = newNode;
        head->pDown->pNext = newNode;
    }
    ct++;
}

void MakeList(list & l){
    int ct = 0;
    cNode * catchNegative = NULL, * pb = NULL, * biggest = NULL;
    int max = -99999;
   int target = -99;
    l.attachByValue(12);
    attachByValueDown(34, l.tail, ct, catchNegative, pb,target, biggest, max);
    attachByValueDown(-5, l.tail, ct, catchNegative, pb,target, biggest, max);
    attachByValueDown(11, l.tail, ct, catchNegative, pb,target, biggest, max);
    attachByValueDown(130, l.tail, ct, catchNegative, pb,target, biggest, max);
    attachByValueDown(15, l.tail, ct, catchNegative, pb,target, biggest, max);
    attachByValueDown(72, l.tail, ct, catchNegative, pb,target, biggest, max);
    attachByValueDown(81, l.tail, ct, catchNegative, pb,target, biggest, max);
    attachByValueDown(95, l.tail, ct, catchNegative, pb,target, biggest, max);
    attachByValueDown(63, l.tail, ct, catchNegative, pb,target, biggest, max);
    attachByValueDown(-2, l.tail, ct, catchNegative, pb,target, biggest, max);
    attachByValueDown(14, l.tail, ct, catchNegative, pb,target, biggest, max);
    attachByValueDown(33, l.tail, ct, catchNegative, pb,target, biggest, max);
    attachByValueDown(13, l.tail, ct, catchNegative, pb,target, biggest, max);
    l.head->pDown->pNext = biggest;
    l.attachByValue(56);
    attachByValueDown(32, l.tail, ct, catchNegative, pb,target, biggest, max);
    attachByValueDown(26, l.tail, ct, catchNegative, pb,target, biggest, max);
    attachByValueDown(93, l.tail, ct, catchNegative, pb,target, biggest, max);
    attachByValueDown(-3, l.tail, ct, catchNegative, pb,target, biggest, max);
    attachByValueDown(12, l.tail, ct, catchNegative, pb,target, biggest, max);
    attachByValueDown(843, l.tail, ct, catchNegative, pb,target, biggest, max);
    attachByValueDown(240, l.tail, ct, catchNegative, pb,target, biggest, max);
    attachByValueDown(35, l.tail, ct, catchNegative, pb,target, biggest, max);
    attachByValueDown(38, l.tail, ct, catchNegative, pb,target, biggest, max);
    l.head->pDown->pNext = biggest;
}

void hello(list &l){
    if(l.head == NULL){
        l.head = new cNode();
        l.head->info = 0;
    }else{
        l.head->info++;
    }
}

int main(){
    list l;
    int NC, NR;
    cNode * pMaster;
    cin>>NC;
    cNode * pnn;
    for(int i=0; i<NC; i++){
        cin>>NR;
        pnn = new cNode();
        cin>>pnn->info;
        cNode * pBack = NULL;
        cNode * catchNegative = NULL;
        int max = -99999;
        cNode * biggest = NULL;
        int target = -9999;
        int ct = 0;
        pMaster = pnn;
        for(int k = 1; k<NR; k++){
            pnn = new cNode();
            cin>>pnn->info;
            if(pnn->info < 0){
                catchNegative = pnn;
                target = -(catchNegative->info);
                ct = 0;
                
            }
            if(ct == target){
                catchNegative->pNext = pnn;
                pnn->pNext = pBack;

                
            }
            if(target>max){
                max = target;
                biggest = pnn;
            }
            
            if(pMaster->pDown == NULL){
                pMaster->pDown = pnn;
                pnn->pNext = pnn;

            } else{
                pMaster->pDown->pNext->pDown = pnn;
                pMaster->pDown->pNext = pnn;
            }
            
            if(catchNegative!= NULL){
                ct++;
            }
            if(catchNegative == NULL){
                pBack = pnn;
            }
            
        }
        pMaster -> pDown -> pNext = biggest;
        l.attach(pMaster);
    }
    
    
    cNode * pTrav = l.head;
    list newL;
    while (pTrav != NULL) {
        pTrav -> pDown -> pNext -> pNext ->pNext -> pDown = pTrav -> pDown -> pNext -> pNext -> pDown ;
        if(newL.head == NULL){
            newL.head = pTrav->pDown-> pNext;
            newL.tail = pTrav->pDown-> pNext->pNext;
            newL.tail -> pNext = NULL;
        } else{
            pTrav -> pDown ->pNext->pNext -> pNext = newL.head;
            newL.head = pTrav -> pDown -> pNext;
        }
        pTrav = pTrav -> pNext;
    }
    
    newL.listOut();
    cout<<newL.head->pDown->info;
    
    list listtwo;
    hello(listtwo);
    hello(listtwo);
    hello(listtwo);
    hello(listtwo);
    cout<<listtwo.head->info;
    
}


//input

//3 14 12 34 -5 11 130 15 72 81 95 63 -2 14 33 13 10 56 32 26 93 -3 12 843 240 35 38 12 24 12 176 -3 145 340 404 121 -2 120 75 25 128 315

