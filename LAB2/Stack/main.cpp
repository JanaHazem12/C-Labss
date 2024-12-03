#include <iostream>

using namespace std;

// STATIC MEMBERS --> function di ynfa3 astakhdemha b esm el class mesh lazem a-create obj w mel obj da astakhdemha




class Stack{
    private:
    int top;
    int size;
    int * elements;
    // create array of structs when doing MENU
    public:
    Stack(int size){ // CONSTRUCTOR
        this->size=size;
        top=-1;
        elements= new int[size];
    }
    ~Stack(){ // DESTRUCTOR
        //cout<<"Destructor"<<endl;
    }

    int push(int data){ // check if stack is FULL, then I CAN'T PUSH
        if(top == size-1){ // FULL STACK
            return 0;
        }
        // NOT FULL STACK
        top++; // increment top so I can add next input in the next index
        elements[top]=data; // put the data in the index mentioned
        return 1;
    }

    int pop(int *storedData){ // check if stack is EMPTY, then I CAN'T POP, if I want to store the data I popped I've to put data as reference
        if(top == -1){
            throw runtime_error("EXCEPTION");
            //return 0;
        }
        //int data = elements[top];
        *storedData = elements[top];
        // CORRECT int storedData = elements[top];
        //elements[top]=0;
        top--;
        return 1;
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
    int storedData;
    int sizee;
    cout<<"Please Enter Stack Size: ";
    cin>>sizee;
    Stack s(sizee);
    s.push(5);
    s.push(10);
    s.push(15);
    s.display();
    cout<<endl;

    try{
        s.pop(&storedData)?cout<<"Popped Element: "<<storedData<<endl:cout<<"NO POPPED ELEMENT!!"<<endl;
        s.pop(&storedData)?cout<<"Popped Element: "<<storedData<<endl:cout<<"NO POPPED ELEMENT!!"<<endl;
        s.pop(&storedData)?cout<<"Popped Element: "<<storedData<<endl:cout<<"NO POPPED ELEMENT!!"<<endl;

        s.display();
    }
    catch(const exception& e){
        cout<<"Exception Caught!!"<<endl;
    }

    return 0;
}
