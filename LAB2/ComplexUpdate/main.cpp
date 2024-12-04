#include <iostream>
using namespace std;

// constructor
// destructor
// setComplex()

class Complex{
public:
    int real;
    int img;

    Complex(){ // default

    }

    Complex(int real, int img){ // parametrized
        this->real=real;
        this->img=img;
    }

    ~Complex(){
        cout<<"DESTRUCTOR"<<endl;
    }


    /*void setReal(int realData){
        real = realData;
    }*/
    int getReal(){
        return real;
    }
    /*void setImg(int imgData){
        img = imgData;
    }*/
    int getImg(){
        return img;
    }

    // hakhod real w img w hahot value lel real wel img
    void setComplex(int realData, int imgData){
        real=realData;
        img=imgData;
    }

    void print(){ // NEEDS TO BE OPTIMIZED // real=0 img=0 - real>0 img>0 - real<0 img<0
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
    Complex add(Complex myComp1){ // myComp1 is the user input numbers, el tany el amalna el howa original
            Complex resultComp;
            resultComp.real= this->real + myComp1.real;
            // this refers to 'original' (the one that made the call --> original.add(myComp1))
            // el function el amaltelha call (object.X) bttaba2 3alaya
            resultComp.img= this->img + myComp1.img;
            return resultComp;
    }
    Complex subtract(Complex myComp1){
            Complex resultComp;
            resultComp.real= this->real - myComp1.real;
            resultComp.img= this->img - myComp1.img;
            return resultComp;
    }

    /*Complex add(Complex myComp1, Complex myComp2){ // myComp1 is the user input numbers, el tany el amalna el howa original
            Complex resultComp;
            resultComp.real= myComp1.real + myComp2.real;
            // this refers to 'original' (the one that made the call --> original.add(myComp1))
            // el function el amaltelha call (object.X) bttaba2 3alaya
            resultComp.img= myComp1.img + myComp2.img;
            return resultComp;
    }
    Complex subtract(Complex myComp1, Complex myComp2){
            Complex resultComp;
            resultComp.real= myComp1.real - myComp2.real;
            resultComp.img= myComp1.img - myComp2.img;
            return resultComp;

    }*/ // 2 PARAMS
};



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

    Complex myComp1(number1, number2), original(number3, number4), resultComp; // resultComp() but I can't put () in C++
    //myComp1.setReal(number1);
    //myComp1.setImg(number2);
    myComp1.setComplex(number1, number2);
    //original.setReal(number3);
    //original.setImg(number4);
    original.setComplex(number3, number4);

    // Read Real & Img parts for myComp1 & original from the user

    myComp1.print();
    original.print();

    resultComp = original.add(myComp1);
    resultComp.print();

    resultComp = original.subtract(myComp1);
    resultComp.print();

    /*Complex myComp1, myComp2, resultComp;
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

    myComp1.setReal(number1);
    myComp1.setImg(number2);
    myComp2.setReal(number3);
    myComp2.setImg(number4);

    myComp1.print();
    myComp2.print();

    resultComp = resultComp.add(myComp1, myComp2);
    resultComp.print();

    resultComp = resultComp.subtract(myComp1, myComp2);
    resultComp.print();*/ // 2 PARAMS

    return 0;
}
