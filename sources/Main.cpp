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
    Matrix mat1{{1, 2, 3, 4}, 2, 2};
    while(flag) {//when the user decides we exit the loop
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
            int binary_option;
            cout << "For Scalar multiplication enter 1" << endl;
            cout << "For comparisons enter 2" << endl;
            cout << "For binary operations which will change your matrix enter 3" << endl;
            cout << "For binary operations which will not change your matrix enter 4" << endl;
            cin>>binary_option;
            if(binary_option ==0 ){
                flag = 0;
                break;
            }
            else if(binary_option ==1){
                int scalar;
                cout << "Enter a Scalar to multiply by" << endl;
                cin >> scalar;
                mat1*=scalar;
                cout<< "this is your matrix!\n" << mat1<< endl;
            }
            else if(binary_option ==2 ){
                Matrix mat2{{1, 2, 3, 4}, 2, 2};
                cout << "Enter a Matrix in the same format as before to compare to your matrix.\n"
                        "Note: make sure its the same dimensions as your matrix." << endl;
                cin >> mat2;
                int comp_option;
                cout << "What would you like to test?" << endl;
                cout << "For : Your matrix>another matrix. enter 1" << endl;
                cout << "For : Your matrix>=another matrix. enter 2" << endl;
                cout << "For : Your matrix<another matrix. enter 3" << endl;
                cout << "For : Your matrix<=another matrix. enter 4" << endl;
                cout << "For : Your matrix==another matrix. enter 5" << endl;
                cout << "For : Your matrix!=another matrix. enter 6" << endl;
                cin>>comp_option;
                try {
                    switch (comp_option) {
                        case 1:
                            cout << (mat1>mat2) << endl;
                            break;
                        case 2:
                            cout << (mat1>=mat2) << endl;
                            break;
                        case 3:
                            cout << (mat1<mat2) << endl;
                            break;
                        case 4:
                            cout << (mat1<=mat2) << endl;
                            break;
                        case 5:
                            cout << (mat1==mat2) << endl;
                            break;
                        case 6:
                            cout << (mat1!=mat2) << endl;
                            break;
                    }
                }
                catch (exception &ex) {
                    cout << "Wrong sizes , caught exception: " << ex.what() << endl;
                }
            }
            else if(binary_option ==3 ){
                Matrix mat2{{1, 2, 3, 4}, 2, 2};
                cout << "Enter a Matrix in the same format as before.\n"
                        "Note: make sure its the correct dimensions." << endl;
                cin >> mat2;
                int operation_option;
                cout << "How would you like to change your matrix?" << endl;
                cout << "For : Your matrix*another matrix. enter 1" << endl;
                cout << "For : Your matrix-another matrix. enter 2" << endl;
                cout << "For : Your matrix+another matrix. enter 3" << endl;
                cin>>operation_option;
                try {
                    switch (operation_option) {
                        case 1:
                            cout << (mat1>mat2) << endl;
                            break;
                        case 2:
                            cout << (mat1>=mat2) << endl;
                            break;
                        case 3:
                            cout << (mat1<mat2) << endl;
                            break;
                    }
                }
                catch (exception &ex) {
                    cout << "Wrong sizes , caught exception: " << ex.what() << endl;
                }
                cout<< "this is your matrix!\n" << mat1<< endl;
            }
        }

        cout << "\nIf you wish to do more operations on your matrix enter 1, if you wish to exit enter 0" << endl;
        cin>>flag;
        if (!flag){//if he is done we break the loop and exit the program.
            break;
        }
    }
    return 1;

}

