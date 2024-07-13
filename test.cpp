#include<iostream>
using namespace std;
int main(){
    int op;
    do{
        cout << "Enter a choice\n1.\n2.\n3.";
        cin >> op;
        switch(op){
            case 1 :
                // code for case 1
                break;
            case 2:
                // code for case 2
                break;
            default:
                cout << "Invalid Choice. Enter correct choice: ";
        }
    }while(op != 0);
    return 0;
}