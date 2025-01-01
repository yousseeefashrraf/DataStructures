#include <iostream>
using namespace std;
class cNode {
public:
    char ** board;
    int currRow;
    cNode * pNext;


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
cNode * giveIitialState(int n){
    cNode * pnn;
    pnn = new cNode();
    pnn ->currRow = 0;

    pnn -> pNext = NULL;
    pnn -> board = new char * [n];
    for(int r=0; r<n; r++){
        pnn -> board[r] = new char[n];
    }
    for(int r=0; r<n; r++){
        for(int c=0; c<n; c++){
            pnn->board[r][c] = ' ';
        }
    }
    return pnn;
}
void copyState(cNode * & currState,cNode * & newState,int n){
    for(int r = 0; r<n; r++){
        for (int c = 0; c<n; c++) {
            newState -> board[r][c] = currState -> board[r][c];
        }
    }
}
int checkIfSafe(cNode * & currState, int n, int column){
    int isSafe = 1;
//    check row
    for(int c = column+1; c<n; c++){
        if(currState->board [currState->currRow][c] == 'Q'){
            isSafe = 0;
        }
    }
    for(int c = column-1; c>=0; c--){
        if(currState->board [currState->currRow][c] == 'Q'){
            isSafe = 0;
        }
    }
//    end check row
    
    
//    check column
    for(int r = currState->currRow+1; r<n; r++){
        if(currState-> board [r][column] == 'Q'){
            isSafe = 0;
        }
    }
    for(int r = currState->currRow-1; r>=0; r--){
        if(currState-> board [r][column] == 'Q'){
            isSafe = 0;
        }
    }
//    end check column

    for(int r = currState->currRow+1, c = column+1; r<n && c<n; r++,c++){
        if(currState-> board [r][c] == 'Q'){
            isSafe = 0;
        }
    }
    
    for(int r = currState->currRow-1, c = column-1; r>=0 && c>=0; r--, c--){
        if(currState-> board [r][c] == 'Q'){
            isSafe = 0;
        }
    }
//check left Diagonal
    
    for(int r = currState->currRow+1, c = column-1 ; r<n && c>=0; r++, c--){
        if(currState-> board [r][c] == 'Q'){
            isSafe = 0;
        }
    }
    
    for(int r = currState->currRow-1, c = column+1 ; r>=0 && c<n; r--, c++){
        if(currState-> board [r][c] == 'Q'){
            isSafe = 0;
        }
    }
    
    return isSafe;
}

int solutionIsDone(char ** x, int n){
    int isDone = 0;
    int ct = 0;
    for(int r = 0; r< n; r++){
        for (int c = 0; c<n; c++) {
            if(x[r][c] == 'Q'){
                ct++;
            }
        }
    }
    if(ct == n){
        isDone = 1;
    }
    return isDone;
}
void DrawBoard(char ** x, int n){
    for(int i = 0; i<n*3+n+1;i++){
        cout<<"-";
    }
    cout<<endl;
    for (int r = 0; r<n; r++) {
        for (int c = 0; c<n; c++) {
            cout<<"| "<<x[r][c]<<" ";

        }
        cout<<"|";
        cout<<endl;
        for(int i = 0; i<n*3+n+1;i++){
            cout<<"-";
        }
        cout<<endl;

    }

    cout<<endl;
}
void initBoard(cNode * & pnn, int n ){
    pnn -> board = new char * [n];
    for(int r=0; r<n; r++){
        pnn -> board[r] = new char[n];
    }
}
void expand(cNode * & currState,cStack & x, int n){
    cNode * pnn;
    for(int i=0; i<n;i++){
        pnn = new cNode();
        pnn-> pNext = NULL;
        pnn->currRow = currState->currRow;
        initBoard(pnn, n);
        copyState(currState, pnn, n);
        pnn->board[currState->currRow][i] = 'Q';
        pnn->currRow++;
        if (checkIfSafe(currState, n, i)) {
            x.push(pnn);
            if(solutionIsDone(pnn->board, n)){
                DrawBoard(pnn->board, n);
                x.pop();
            }
        }
    }
}
int main(){
    cStack x;
    int n;
    cin>>n;
    cNode * pnn;
    cNode * currState;
    
    pnn = giveIitialState(n);
    x.push(pnn);
    
    while (x.head != NULL) {
        currState = x.pop();
        expand(currState, x, n);

    }
    
}
