#include <iostream>

using namespace std;


class Base{
    protected:
    int a;
    int b;

    public:
    Base(){ // non-parametrized
        cout<<"BASE CONSTRUCTOR"<<endl;
    }
    Base(int a, int b){
        this->a=a;
        this->b=b;
        cout<<"Base Parametrized Constructor"<<endl;
    }
    ~Base(){
        cout<<"BASE DESTRUCTOR"<<endl;
    }
    int sum(){
        //cout<<"Base Sum: "<<a+b<<endl;
        return a+b;

    }
};

void display(){
}

class Derived:public Base{ // can NOT access a.b of BASE as they're PRIVATE (I can access them using getters OR I can make them PROTECTED)
    protected:
    int c;

    public:
    Derived(){ // non-parametrized
        cout<<"DERIVED CONSTRUCTOR"<<endl;
    }
    Derived(int a, int b, int c):Base(a,b){ // parametrized --> 3 ints
        this->c=c;
        cout<<"Derived Parametrized Constructor"<<endl;
    }
    ~Derived(){
        cout<<"DERIVED DESTRUCTOR"<<endl;
    }

    int sum(){
        //cout<<"Derived Sum: "<<Base::sum()+c<<endl;
        return Base::sum()+c; // adding the c to the result of BASE
    }

};

class secondDerived:public Derived{
    protected:
    int d;

    public:
    secondDerived(){ // non-parametrized
        cout<<"SECOND-DERIVED CONSTRUCTOR"<<endl;
    }
    secondDerived(int a, int b,int c, int d):Derived(a,b,c){ // parametrized --> 4 ints
        this->d=d;
        cout<<"SecondDerived Parametrized Constructor"<<endl;
    }
    ~secondDerived(){
        cout<<"SECOND-DERIVED DESTRUCTOR"<<endl;
    }
    int sum(){
        //cout<<"secondDerived Sum: "<<endl;
        return Derived::sum()+d; // adding the d to the result of DERIVED

    }

};


int main()
{
    /*Base b(2,5);
    int sumB=b.sum();
    cout<<"sumB = "<<sumB<<endl;*/

    /*Derived d(1,2,3);
    int sumD=d.sum();
    cout<<"SumD = "<<sumD<<endl;*/

    secondDerived sd(1,2,3,4);
    int sumSD=sd.sum();
    cout<<"SumSD = "<<sumSD<<endl;

    return 0;
}
