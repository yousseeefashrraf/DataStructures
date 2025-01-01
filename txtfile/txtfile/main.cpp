

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    ofstream myFile;
    myFile.open("lab 6.txt");
    if(myFile.is_open()){
        cout<<"File is open";
        myFile<<"Hello world!\n";
    }
    myFile.close();
    
}
