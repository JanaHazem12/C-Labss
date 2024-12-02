#include <iostream>
using namespace std;

class Complex{
public:
    int real;
    int img;
    void setReal(int realData){
        real = realData;
    }
    int getReal(){
        return real;
    }
    void setImg(int imgData){
        img = imgData;
    }
    int getImg(){
        return img;
    }

    void print(){ // NEEDS TO OPTIMIZE // real=0 img=0 - real>0 img>0 - real<0 img<0
        // if gowaha else if .. w if lwahdaha

        /*if(real == 0 && img == 0){ // 3+5j - 4+1j
            cout<<"Nothing to print"<<endl;
        }
        else if(real == 0 && (img > 0 || img < 0)){ // 0+2j OR 0-2j
            cout<<img<<'j'<<endl;
        }
        else if(img == 0 && (real > 0 || real < 0)){ // 2+0j OR 2+-j
            cout<<real<<endl;
        }
        else{ // real && img > 0
            cout<<real<<'+'<<img<<'j'<<endl;
        }*/

        if(real != 0){ // real is -ve or +ve
            if(img>0){
             cout<<real<<'+'<<img<<'j'<<endl;
        }
            else if(img<0){
             cout<<real<<img<<'j'<<endl;
        }
        else{
             cout<<real<<endl;  // img = 0
        }
    }
}
};

Complex add(Complex myComp1, Complex myComp2){
        Complex resultComp;
        resultComp.setReal(myComp1.getReal() + myComp2.getReal());
        resultComp.setImg(myComp1.getImg() + myComp2.getImg());
        return resultComp;
}
Complex subtract(Complex myComp1, Complex myComp2){ // CHECK ON -ve NUMBERS
        Complex resultComp;
        resultComp.setReal(myComp1.getReal() - myComp2.getReal());
        resultComp.setImg(myComp1.getImg() - myComp2.getImg());
        return resultComp;
}


int main(){
    int number1;
    cout<<"Enter Real 1: "<<endl;
    cin>>number1;
    int number2;
    cout<<"Enter Img 1: "<<endl;
    cin>>number2;
    int number3;
    cout<<"Enter Real 2: "<<endl;
    cin>>number3;
    int number4;
    cout<<"Enter Img 2: "<<endl;
    cin>>number4;

    Complex myComp1, myComp2, resultComp;
    myComp1.setReal(number1);
    myComp1.setImg(number2);
    myComp2.setReal(number3);
    myComp2.setImg(number4);
    // Read Real & Img parts for myComp1 & myComp2 from the user
    myComp1.print();
    myComp2.print();

    resultComp = add(myComp1, myComp2);
    resultComp.print();

    resultComp = subtract(myComp1, myComp2);
    resultComp.print();

    return 0;
}
