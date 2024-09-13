#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;
// // ******************************** BITWISE OPERATOR *********************************
void bitwise_operator()
{

    int a = 2;
    int b = 3;
    cout << "A&B:- " << (a & b) << endl;
    cout << "A|B:- " << (a | b) << endl;
    cout << "~A:- " << ~a << endl;
    cout << "A^B:- " << (a ^ b) << endl;
}

// // ************************** DECIMAL TO BINARY CONVERSION ***************************
void dec_to_bin(){
    int n;
    cout<<"Enter a decimal number:- ";
    cin >> n;
    long double ans = 0;
    int i = 0;
    while (n != 0){
        int bit = n & 1;
        ans = (bit * pow(10, i)) + ans;
        n = n>>1;
        i++;}
    cout<<"Answer:- "<<ans<<endl;
}
int main(){
    bitwise_operator();
    dec_to_bin();
}