#include <iostream>

using namespace std;

void SwapR(int &x, int &y){ // CALL BY REFERENCE
    int temp = x;
    x = y;
    y = temp;
}

void SwapV(int x, int y){ // CALL BY VALUE
    int temp = x;
    x = y;
    y = temp;
}

void SwapA(int *x, int *y){ // CALL BY ADDRESS
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int x;
    cout<<"Enter 1st number: ";
    cin>>x;
    int y;
    cout<<"Enter 2nd number: ";
    cin>>y;
    SwapR(x,y);
    //SwapV(x,y);
    //SwapA(&x,&y);
    cout<<"x = "<<x<<endl;
    cout<<"y = "<<y;
    return 0;
}
