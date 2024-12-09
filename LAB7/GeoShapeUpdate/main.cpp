#include <iostream>
#include <cmath>

using namespace std;


class GeoShape{
    protected:
    float d1;
    float d2;

    public:
    GeoShape(){
        d1=0.0;
        d2=0.0;
    }
    GeoShape(float dr){
        d1=dr;
    }
    GeoShape(float d11, float d22){
        d1=d11;
        d2=d22;
        cout<<"here";
    }
    ~GeoShape(){
        cout<<"GEOSHAPE DESTRUCTOR"<<endl;
    }
    float getD1(){
        return d1;
    }
    float getD2(){
        return d2;
    }
    void setD1(float dd1){
        d1 = dd1;
    }
    void setD2(float dd2){
        d2 = dd2;
    }
    float calculateArea(){
        return 0;
    }
    //virtual void calculateArea()=0;

};

class Triangle:public GeoShape{
    public:
    Triangle():GeoShape(){
    }
    Triangle(float b, float h):GeoShape(b,h){ //  PARAMETRIZED CONSTRUCTOR
        cout<<"PARAMETRIZED TRIANGLE CONSTRUCTOR"<<endl;
    }
    ~Triangle(){
        cout<<"TRIANGLE DESTRUCTOR"<<endl;
    }
    float calculateArea(){ // no input params as I already took them in the constructor
        float AreaT = 0.5 * d1 * d2;
        //cout<<AreaT<<endl;
        return AreaT;
    }

};

class Rectangle:public GeoShape{
    public:
    Rectangle():GeoShape(){
    }
    Rectangle(float x, float y):GeoShape(x,y){ //  PARAMETRIZED CONSTRUCTOR
        cout<<"PARAMETRIZED RECTANGLE CONSTRUCTOR"<<endl;
    }
    ~Rectangle(){
        cout<<"RECTANGLE DESTRUCTOR"<<endl;
    }
    float calculateArea(){ // no input params as I already took them in the constructor
        float AreaR = d1 * d2;
        cout<<AreaR<<endl;
        return AreaR;
    }

};

class Circle:private GeoShape{ // private in CIRCLE, but I can access it from PARENT 3ady
    public:
    Circle():GeoShape(){
    }

    Circle(float r):GeoShape(r){ //  PARAMETRIZED CONSTRUCTOR
        cout<<"PARAMETRIZED CIRCLE CONSTRUCTOR"<<endl;
    }
    ~Circle(){
        cout<<"CIRCLE DESTRUCTOR"<<endl;
    }
    /*void setRadius(float r1, float r2){
        d1=r1;
        d2=r2;
    }*/
    void setRadius(float r1){
        d1=d2=r1;
    }
    float getRadius(){
        return d1;
    }

    float calculateArea(){ // no input params as I already took them in the constructor
        float AreaC = 3.141592653589793238462643383279502884197 * d1 * d2; // 3.14 * r^2
        cout<<AreaC<<endl;
        return AreaC;
    }

};

class Square: private Rectangle{
    /*Square(): Rectangle(){

    }*/
    public:
    Square(float a): Rectangle(a,a){

    }
    float getSide(){
        return d1;
    }
    void setSide(float x){
        d1=d2=x;
    }
    float calculateArea(){
        /*float AreaS = d1 * d2;
        return AreaS;*/
        return Rectangle::calculateArea(); // I can return d1*d2 bas keda NO OVERRIDING
    }

};

int main()
{
    Triangle T(5,10);
    cout<<T.calculateArea();
    /*Rectangle R(3,2);
    R.calculateArea();
    Circle C(3);
    C.calculateArea();
    Square S(6);
    S.calculateArea();*/
    return 0;
}
