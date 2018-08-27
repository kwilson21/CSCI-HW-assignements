// asgn BY Kazon Wilson,  CSCI 2170-5
// PROGRAM ID:  change.cpp / Change counter
// AUTHOR:  Kazon Wilson
// INSTALLATION:  MTSU
// REMARKS:   Reads in the change value from a data file and takes 
// one change value (between 1 and 99) and prints out what coins 
// can be used to make that change.

#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

void computeCoin(int coinValue, int& number, int& amountLeft);

int main(){
    // Declare variables
    ifstream myIn;
    int coinValue;
    int number;
    int amountLeft;

    // Open and verify the file
    myIn.open("coins.dat");
    assert(myIn);

    /* Read in each line from the file as an int.
       The 3 coins used are quarters (25 cents), dimes (10 cents), and pennies (1 cent).
       Subtract the max amount of coins from the total amount as possible then print
       the amount of each coin that was used.
       Once the total amount has been fulfilled, read the next line. */
    while(myIn >> amountLeft){
        cout << amountLeft << " cents can be changed using ";
        int count = 0;
        while (amountLeft != 0){
            
            if (amountLeft >= 25){
                computeCoin(25, number, amountLeft);
                if (number > 1){
                    cout << number << " quarters";
                }
                else{
                    cout << number << " quarter";
                }
                count++;
            }
            else if (amountLeft >= 10){
                computeCoin(10, number, amountLeft);
                if (count == 1 && number > 1){
                    cout << ", " << number << " dimes";
                }
                else if (count == 1 && number == 1){
                    cout << ", " << number << " dime";
                }
                else if (count == 0 && number > 1){
                    cout << number << " dimes";
                }
                else if (count == 0 && number == 1){
                    cout << number << " dime";
                }
                count++;
            }
            else if (amountLeft >= 1){
                computeCoin(1, number, amountLeft);
                if (count == 1 && number > 1){
                    cout << ", and " << number << " cents";
                }
                else if (count == 1 && number == 1){
                    cout << ", and " << number << " cent";
                }
                else if (count == 2 && number > 1){
                    cout << ", and " << number << " cents";
                }
                else if (count == 2 && number == 1){
                    cout << ", and " << number << " cent";
                }
                else if (count == 0 && number > 1){
                    cout << number << " cents";
                }
                else if (count == 0 && number == 1){
                    cout << number << " cent";
                }
                count++;
            }
        }
        cout << "." << endl;
    }
    myIn.close();
}

void computeCoin(int coinValue, int& number, int& amountLeft){
    number = 0;
    if (coinValue < 0 || coinValue > 100){
        cout << "ERROR: Coin value must be 25, 10, or 1!" << endl;
    }
    if (amountLeft <= 0 || amountLeft > 100){
        cout << "ERROR: Amount left must be between 0 and 99!" << endl;
    }

    while (amountLeft >= coinValue){
        amountLeft = amountLeft - coinValue;
        number++;
    }
}