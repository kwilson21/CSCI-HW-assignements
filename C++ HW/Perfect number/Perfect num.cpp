#include <iostream> 
using namespace std;

int main(){
    int limit;
    int n = 1;

    cout << "Please enter limit for perfect number search: ";
    cin >> limit;

    while (n<=limit){
        int sum = 0;
        int divisor = 1;
        while (divisor<n){
            if (n%divisor==0)
                sum += divisor;
            divisor++;
        }
        if (sum == n)
            cout << n << " is a perfect number" << endl;
        n++;
    }
}