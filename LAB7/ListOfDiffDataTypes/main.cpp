#include <iostream>

using namespace std;


class parent{
    public:
    virtual void pointsAt()=0;

};

template <class T>
class Datatypes:public parent
{
    private:
    T input;

    public:
    Datatypes(T inputt){
        input=inputt;
    }
    void pointsAt(){
        cout<<input<<"\n";
    }
};


class List{
    private:
    int size;
    //T *list1;
    parent ** parentt; // ParentClass howa el byshawer ala el Derived

    public:
    //     CONSTRUCTOR   (initial values)  //
    List(){
        this->size=0;
        parentt = nullptr;
        //list1 = new T[size];
    }
    //    DESTRUCTOR    //
    ~List(){
        for(int i=0; i<size; i++){
            delete parentt[i];
        }
        delete[] parentt;
    }

    //     PUSH    // --> values are put, size is incremented by 1

    template <class T>
    void push(T x){ // list1.push(list2,5);
        /*if(size==0){
            size++; // size = 1
            int i =0;
            //T* list3=new T[size];
            parent * newParent = new T*[size];
            //list3[i]=x;
            for(i=0; i<size-1; i++){
                newParent[i]=parent[i];
            }
            //delete[] list1;
            int sizee=size-1;
            newParent[sizee]=new Derived<T>(x); // ??
            delete [] newParent;
            //list1=list3;
            parent = newParent;
        }*/
        //else{
             int j=0;
             size++; // size = 2   // example: list1 has 1 20    20,30
             //T* list2=new T[size];
             parent ** newParentPush = new parent*[size];
             while(j<size-1){
                //list2[j]=list1[j];
                newParentPush[j]=parentt[j];
                //cout<<list1[j]<<endl;
                j++;
             }
             //list2[size-1]=x;
             newParentPush[size-1]=new Datatypes<T>(x);
             delete[] parentt;
             parentt=newParentPush;
        //}

        //this->size=size;
    }

    //     POP     // --> values are deleted, size is decremented by 1
    void pop(){
        int i=0;
        //T storedData=parentt[size-1];  // POPPED DATA
        size-=1;
        //T *list2 = new T[size]; // jana 4 size-- array fady with size 3
        parent ** newParentPop = new parent*[size];
        while(i<size){ // loop over new list
            newParentPop[i]=parentt[i];
            i++;
        }
        // j a n a 0 1 2 3 i=0 list2=jana
        delete[] parentt;
        parentt=newParentPop;
        //return storedData; // jan a=storedData
    }

    //    DISPLAY    //
    void display(){
        if(size == 0){
            cout<<"Empty List!!"<<endl;
        }
        else{
            //int i=0;
            /*for(int i=0; i<size; i++){
                cout<<list1[i]<<" ";
            }*/
            for(int i=0; i<size; i++){
                parentt[i]->pointsAt();

            }
            cout<<endl;
        }
    }

    //    operator=   //  --> list1 = list2 --> copy what's in L2 to L1 --------

    //    list1.operator=(list2) - destination = list1 , source = list2
    // TEST CASE:  NOT EQUAL/EQUAL --> MAKE A NEW ARRAY OF SIZE L2

};



int main()
{
    List listt;
    listt.push(1);
    listt.push(2);
    listt.push(3);
    listt.push("janaa");
    listt.display();
    listt.pop();
    listt.display();
    listt.pop();
    listt.display();
    return 0;
}
