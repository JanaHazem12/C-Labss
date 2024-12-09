#include <iostream>

using namespace std;

// STATIC MEMBERS --> function di ynfa3 astakhdemha b esm el class mesh lazem a-create obj w mel obj da astakhdemha

template <class T>

class Stack{
    private:
    int top;
    int size;
    T * elements;
    // create array of structs when doing MENU
    public:
    Stack(int size){ // CONSTRUCTOR
        this->size=size;
        top=-1;
        elements= new T[size];
    }
    ~Stack(){ // DESTRUCTOR
        //cout<<"Destructor"<<endl;
    }

    T push(T data){ // check if stack is FULL, then I CAN'T PUSH
        if(top == size-1){ // FULL STACK
            return 0;
        }
        // NOT FULL STACK
        top++; // increment top so I can add next input in the next index
        elements[top]=data; // put the data in the index mentioned
        return 1;
    }

    T pop(){ // check if stack is EMPTY, then I CAN'T POP, if I want to store the data I popped I've to put data as reference
        if(top == -1){
            throw runtime_error("EXCEPTION");
            //return 0;
        }
        //int data = elements[top];
        T storedData = elements[top];
        // CORRECT int storedData = elements[top];
        //elements[top]=0;
        top--;
        return storedData;
    } // nhott pop inside a try catch, if catch then ERROR

    void display(){ // display all stack elements
        if(top == -1){// CHECK IF STACK IS EMPTY, THEN PRINT "EMPTY STACK"
            cout<<"Empty Stack!!";
        }
        else{ // STACK IS NOT EMPTY
            for(int i=0; i<=top;i++){
                cout<<elements[i]<<endl;
            }
        }
    }
};

int main()
{
    //T storedData;
    int sizee;
    cout<<"Please Enter Stack Size: ";
    cin>>sizee;
    Stack<float>sF(sizee);
    sF.push(5.5);
    sF.push(10.8);
    sF.push(15.6);
    sF.display();
    /*Stack<int>sI(sizee);
    sI.push(5);
    sI.push(10);
    sI.push(15);
    sI.display();
    cout<<endl;*/

    try{
        /*s.pop()?cout<<"Popped Element: "<<endl:cout<<"NO POPPED ELEMENT!!"<<endl;
        s.pop()?cout<<"Popped Element: "<<endl:cout<<"NO POPPED ELEMENT!!"<<endl;
        s.pop()?cout<<"Popped Element: "<<endl:cout<<"NO POPPED ELEMENT!!"<<endl;*/

         cout<<"Popped Element: "<<sF.pop()<<endl;
         //cout<<"Popped Element: "<<sF.pop()<<endl;
         cout<<"Elements after popping: "<<endl;
         sF.display();

         /*cout<<"Popped Element: "<<sI.pop()<<endl;
         //cout<<"Popped Element: "<<sI.pop()<<endl;
         cout<<"Elements after popping: "<<endl;
         sI.display();*/

        //s.display();
    }
    catch(const exception& e){
        cout<<"Exception Caught!!"<<endl;
    }

    return 0;
}

