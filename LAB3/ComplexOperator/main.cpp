#include <iostream>
#include <iomanip>
using namespace std;

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
        //cout<<"DESTRUCTOR"<<endl;
    }


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

    Complex operator+(Complex c2){ // c3 = c1 + c2
        cout<<"c3 = c1 + c2"<<endl;
        Complex c3;
        c3.real=this->real+c2.real;
        c3.img=this->img+c2.img;
        return c3;
    }
    Complex operator-(Complex c2){ // c3 = c1 - c2
        cout<<"c3 = c1 - c2"<<endl;
        Complex c3;
        c3.real=this->real-c2.real;
        c3.img=this->img-c2.img;
        return c3;
    }
    Complex operator+(int x){ // c3 = 5 + c2
        cout<<"c3 = 5 + c2"<<endl;
        Complex c3;
        c3.real=this->real+x;
        c3.img=this->img+x;
        return c3;
    }
    Complex operator-(int x){ // c3 = 5 - c2
        cout<<"c3 = 5 - c2"<<endl;
        Complex c3;
        c3.real=this->real-x;
        c3.img=this->img-x;
        return c3;
    }
    Complex operator=(Complex c2){ // c1 == c2 , c1.operator==(c2)
        this->real=c2.real; // this of c1
        this->img=c2.img;
        return c2;
    }
    bool operator==(Complex c2){ // c1 == c2 , c1.operator==(c2)
        cout<<"c1 == c2"<<endl;
        if(this->real==c2.real && this->img==c2.img){ // this of c1
            //cout<<"true"<<endl;
            return true;
        }
        else{
            //cout<<"false"<<endl;
            return false;
        }
    }
    Complex operator+=(Complex c2){ // c1 += c2 , c1 = c1 + c2 , c1.operator+=(c2)
        cout<<"c1 += c2"<<endl; // there's sth wrong in c1 real & img, c2 real & img are correct
        //Complex c3=*this; // of c1
        //c1=1+2j , c2=3+4j --> c1.real = 1+3=4 , c.img = 2j+4j=6j
        cout<<"c1 real: "<<this->real<<endl; // there's sth wrong in c1 real & img, c2 real & img are correct
        cout<<"c2 real: "<<c2.real<<endl;
        this->real=this->real+c2.real; // this of c1
        this->img=this->img+c2.img;
        return *this;
    }
    Complex operator++(){ // PREFIX ++c1, operation THEN assign
        this->real++; // this of c1
        this->img++;
        return *this;
    }
    Complex operator--(){ // PREFIX ++c1, operation THEN assign
        this->real--; // this of c1
        this->img--;
        return *this;
    }
    Complex operator++(int x){ // POSTFIX c1++, assign THEN operation
        Complex c3 = *this;
        this->real++;
        this->img++;
        return c3;
    }
    Complex operator--(int y){ // POSTFIX
        Complex c = *this;
        this->real--;
        this->img--;
        return c;
    }
      operator float(){ // (float)c1
        //Complex c = *this;
        std::cout << std::fixed << std::setprecision(2);
        /*static_cast<float>(this->real);
        static_cast<float>(this->img);*/
        this->real=float(this->real);
        this->img=float(this->img);
        return this->real;
    }
    friend Complex operator+(int x,Complex c1);
    friend Complex operator-(int x, Complex c1);
};

// friend function is a must c3 = 5 + c1 , c3 = 5.operator+(c1) AND c3 = 5 - c1
Complex operator+(int x,Complex c1){
        /*Complex c3;
        c3.setReal(x+c1.getReal());
        c3.setImg(x+c1.getImg());
        return c3;*/ // this is valid without making it a friend
        // BUT if I want to access it without getters & setters
        // THEN add friend Complex operator+(int x,Complex c1); inside CLASS
        //& implement outside class w/o getters & setters
        Complex c3;
        c3.real=x+c1.real;
        c3.img=x+c1.img;
        return c3;
}
Complex operator-(int x, Complex c1){
        Complex c3;
        c3.real=x-c1.real;
        c3.img=x-c1.img;
        return c3;
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

    //Complex myComp1(number1, number2), original(number3, number4), resultComp; // resultComp() but I can't put () in C++
    // Read Real & Img parts for myComp1 & original from the user
    /*myComp1.setComplex(number1, number2);
    original.setComplex(number3, number4);
    myComp1.print();
    original.print();*/

    // c3 = c1 + c2 , c3 = c1.operator+(c2)
    Complex c1(number1, number2),c2(number3, number4),c3;
    c1.setComplex(number1, number2);
    c2.setComplex(number3, number4);
    c3 = c1 + c2;
    c3.print();
    // c3 = c1 + c2 , c3 = c1.operator-(c2)
    c3 = c1 - c2;
    c3.print();
    // c3 = c1 + 5 , c3 = c1.operator+(int x)
    c3 = c1 + 5;
    c3.print();
    // c3 = c1 - 5 , c3 = c1.operator-(int x)
    c3 = c1 - 5;
    c3.print();
    // c3 = 5 + c1 , c3 = 5.operator+(int x) WRONGG NO CALLING OBJECT
    c3 = 5 + c1;
    c3.print();
    // c3 = 5 - c1 , c3 = 5.operator-(int x) WRONGG NO CALLING OBJECT
    c3 = 5 - c1;
    c3.print();
    //c1 == c2; // if c1 == c2 return true else false
    if(c1.operator==(c2)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    cout<<"c1 = c2"<<endl;
    cout<<"c1 before"<<endl;
    c1.print();
    cout<<"c2 before"<<endl;
    c2.print();
    c1 = c2;
    cout<<"c1 after"<<endl;
    c1.print();
    cout<<"c2 after"<<endl;
    c2.print();
    c1 += c2;
    c1.print();
    cout<<"PRE-FIX ++c1"<<endl;
    ++c1;
    c1.print();
    cout<<"PRE-FIX --c"<<endl;
    --c1;
    c1.print();
    cout<<"POSTFIX c1++"<<endl;
    c1++;
    c1.print();
    cout<<"POSTFIX c1--"<<endl;
    c1--;
    c1.print();
    cout<<"(float)c1"<<endl;
    (float)c1; // NOT DONE YET
    c1.print();


    /*resultComp = original.add(myComp1);
    resultComp.print();

    resultComp = original.subtract(myComp1);
    resultComp.print();*/

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
