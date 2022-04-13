//
// Created by shaul on 13/04/2022.
//
#include <iostream>
#include "Matrix.hpp"
#include <string>
using namespace std;
using namespace zich;

int main(){
    //creating a simple procedure where the user can decide what size and what Matrix would he like.
    int flag=1;
    bool first= true;
    while(flag) {//when the user decides we exit the loop
        Matrix mat1{{1, 2, 3, 4}, 2, 2};
        if(first) {
            cout << "To begin please enter your matrix in the following order, for example "
                    "for the identity matrix of size 3 - \n [1 0 0], [0 1 0], [0 0 1]"
                    "\n please make sure to input correctly otherwise won't work." << endl;
            try {
                cin >> mat1;
            }
            catch (exception &ex) {
                cout << "please try again, caught exception: " << ex.what() << endl;
                break;
            }
            first = false;
        }
        else{
            cin>>mat1;
            cout << "Please enter your new matrix\n" << endl;
            try {
                cin >> mat1;
            }
            catch (exception &ex) {
                cout << "please try again, caught exception: " << ex.what() << endl;
                break;
            }
        }
        cout<< "this is your matrix!\n" << mat1 << "\n Let's show some matrix operations of you're choice." <<endl;
        cout << "For Unary operations enter 1" << endl;
        cout << "For Binary operations and comparisons enter 2" << endl;
        cout << "To exit the program at any time enter 0" << endl;
        int option;
        cin >> option;
        if (option == 0) {
            flag = 0;
            break;
        }
        if (option == 1) {
            int unary_option;
            cout << "For incrementing all entries by 1 enter 1" << endl;
            cout << "For decrementing all entries by 1 enter 2" << endl;
            cout << "For Showing the negative of your matrix enter 3" << endl;
            cin>>unary_option;
            if(unary_option ==0 ){
                flag = 0;
                break;
            }
            else if(unary_option ==1){
                 mat1++;
                 cout<< "this is your matrix!\n" << mat1<< endl;
            }
            else if(unary_option ==2 ){
                mat1--;
                cout<< "this is your matrix!\n" << mat1<< endl;
            }
            else{
                cout<< (-mat1) <<endl;
            }
        }
        else{//option ==2


        }

        cout << "\nIf you wish to create an additional matrix enter 1, if you wish to exit enter 0" << endl;
        cin>>flag;
        if (!flag){//if he is done we break the loop and exit the program.
            break;
        }
    }
    return 1;

}

