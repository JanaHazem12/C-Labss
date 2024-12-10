#include <iostream>
using namespace std;

// list of elements el size bta3ha changes every time I add an element
// PUSH example --> list size = 0 , PUSH , list size = 1 ANOTHER PUSH list size = 1 , PUSH , list size = 2
// POP example --> list size = 3 , POP , list size = 2 ANOTHER POP list size = 2 , POP , list size = 1

template <class T>
class List{
    private:
    int size;
    T *list1;

    public:
    //  GETTERS & SETTERS  //
    int getSize(){
        return size;
    }
    /*void setSize(int sizee){
        size=sizee;
    }*/
    T *getList(){
        return list1;
    }
    /*void setList(List listt){
        list1=listt;
    }*/

    //     CONSTRUCTOR   (initial values)  //
    List(){
        this->size=0;
        list1 = new T[size];
    }
    //    DESTRUCTOR    //
    ~List(){
        delete[] list1;
    }

    //     PUSH    // --> values are put, size is incremented by 1
    T push(T x){ // list1.push(list2,5);
        if(size==0){
            size++; // size = 1
            int i =0;
            T* list3=new T[size];
            list3[i]=x;
            delete[] list1;
            list1=list3;
        }
        else{
             int j=0;
             size++; // size = 2   // example: list1 has 1 20    20,30
             T* list2=new T[size];
             while(j<size-1){
                list2[j]=list1[j];
                //cout<<list1[j]<<endl;
                j++;
             }
             list2[size-1]=x;
             delete[] list1;
             list1=list2;
        }

        //this->size=size;
    }

    //     POP     // --> values are deleted, size is decremented by 1
    T pop(){
        int i=0;
        T storedData=list1[size-1];  // POPPED DATA
        size-=1;
        T *list2 = new T[size]; // jana 4 size-- array fady with size 3
        while(i<size){ // loop over new list
            list2[i]=list1[i];
            i++;
        }
        // j a n a 0 1 2 3 i=0 list2=jana
        delete[] list1;
        list1=list2;
        return storedData; // jan a=storedData
    }

    //    DISPLAY    //
    void display(){
        if(size == 0){
            cout<<"Empty List!!"<<endl;
        }
        else{
            //int i=0;
            for(int i=0; i<size; i++){
                cout<<list1[i]<<" ";
            }
            cout<<endl;
        }
    }

    //    operator=   //  --> list1 = list2 --> copy what's in L2 to L1 --------

    //    list1.operator=(list2) - destination = list1 , source = list2
    // TEST CASE:  NOT EQUAL/EQUAL --> MAKE A NEW ARRAY OF SIZE L2

    void operator=(List &list2){  // source=L2 , dest=list1
        T *list3 = new T[list2.size];
        int i=0;
        while(i<list2.size){
            //list2.display();
            //cout<<endl;
            list3[i]=list2.list1[i]; // list3 is int * , list2 is List
            //cout<<list3[i]<<" ";
            i++;
        }
        //list2.display();
        //cout<<endl;
        //cout<<list3[i]<<" ";
        delete[] list1;
        list1=list3;
        this->size=list2.size;
        /*for(int i=0; i<list2.size; i++){
            cout<<list1[i]<<" ";
        }*/
    }
};

int main()
{
    /*float num1=50.5;
    float num2=30.6;*/

    /*List<float>list1;
    List<float>list2;*/

    List<char>list1;
    List<char>list2;
    //List list2();

    /*list1.push(20.5);
    list1.push(50.4);*/

    list1.push('b');
    list1.push('a');

    cout<<"List 1: ";
    list1.display();

    /*list2.push(100.1);
    list2.push(200.2);
    list2.push(300.4);*/


    list2.push('jana');
    list2.push('mina');
    list2.push('mohamed');
    cout<<"List 2: ";
    list2.display();

    cout<<"POPPED DATA: "<<list1.pop()<<endl;
    cout<<"List 1 after pop: ";
    list1.display();

    //cout<<"operator= ";
    cout<<"List 1 before operator= : ";
    list1.display();
    list1=list2;
    cout<<"List 1 after operator= : ";
    list1.display();
    return 0;
}
