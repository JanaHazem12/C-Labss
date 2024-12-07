#include <iostream>
#define TERM '\0'

using namespace std;

class String{
    private:
    //char str1[size]; // arr of characters (strings)
    char *str1;
    int size;

    public:
    //int StrLength(String str);
    int StrLength(String str){
        //cout<<"ccccccc";
        int i=0;
        while(str.str1[i]!=TERM){
            i++;
        }
        return i;
    }
    int StrLengthCH(char str[]){
        int i=0;
        while(str[i]!=TERM){
            i++;
        }
        return i;
    }
    String(char *str){ // CONSTRUCTOR - create dynamic memory allocation
        int i = 0;
        size = StrLengthCH(str);
        str1=new char[size];// memory alloc - *str1 (the ptr I've) = new BLOCK in heap (new yb2a in heap alatool)
        for(i=0; i<size; i++){ // j a n a 0 1 2 3 4(TERM)
            str1[i]=str[i];
        }
        str1[size]=TERM;
    }

    ~String(){ // DESTRUCTOR
        delete[] str1;
    }

    // GETTERS AND SETTERS
    char * getString(){
        return str1;
    }
    void setString(char *strr){
        str1 = strr;
    }

    int getSize(){
        return size;
    }
    void setSize(int sizee){
        size=sizee;
    }
    // StrCopy
    void StrCopy(String &source){ // dest is this-> S1.StrCopy(S2);
        int i=0;
        //cout<<"String before copy: "<<this->str1<<endl;
        char * str2 = new char[source.size]; // DYNAMIC MEMORY
            while(source.str1[i]!=TERM){
                str2[i]=source.str1[i];
                i++;
            }
        str2[i]=TERM;
        //cout<<"String after copy: "<<this->str1<<endl;
        delete[] str1;
        this->str1=str2;
        this->size=source.size;
        return;
    }
    // StrCompare
    void StrCompare(String source){
        int i=0;
        if(source.size!=this->size){
            cout<<"NOT EQUAL";
            return;
        }
        else{
        while(source.str1[i]!=TERM){
            if(source.str1[i]!=this->str1[i]){
                cout<<"NOT EQUAL";
                return;
            }
            else{
                i++;
            }
        }
        cout<<"EQUAL";
        return;
    }
}
    // StrConcat
    void StrConcat(String &source){ // source is S2, dest is S1
        //cout<<"ana hena";
        int i=0;
        int j=0;
        int sizee=source.size+this->size+1;

        //  *str1 of S1 --> "mina", *str1 after new char points at "minajana", make it a null pointer then

        char *str2=new char[sizee]; // change str1 to str2 to avoid overwriting


            //cout<<source.str1<<endl;
            //cout<<source.size<<endl;
            //cout<<this->str1<<endl; // NOT READING STR1
            while(this->str1[i]!=TERM){ // jana
                //cout<<"ana hena"<<endl;
                str2[i]=str1[i]; // adding what's in str1 to the NEW ARRAY - IMPOOOO
                i++;
            }
            //cout<<i<<endl;
            while(source.str1[j]!=TERM){ // if S2 is != TERM
                str2[i]=source.str1[j]; // str2 --> minaX
                i++;
                j++;
            }
            str2[i]=TERM;
            delete [] str1; // deletes array that points at str1 BUT keeps the pointer
            this->str1 = str2; // str1 ptr points NOW at str2 (no need to delete[] str2 as now str1 points at it)
            this->size = sizee;
            //cout<<this->str1<<endl;
            //cout<<this->size;
    }
    //     STRING DISPLAY     //
    void display(){
        for(int i=0; i<size; i++){
            cout<<str1[i];
        }
    }

    // Operator Overloading
    // Operator> --> str1>str2 THEN true else false
    bool operator >(char *S2){
        cout<<"xxxxxxxxxxxxxxxxx"<<endl;
        if((this->size)>StrLength(S2)){
            return true;
        }
        else{
            return false;
        }
    }
    // Operator< --> str1<str2 THEN true else false
    bool operator<(char *S2){
        if(this->size<StrLength(S2)){
            return true;
        }
        else{
            return false;
        }
    }
    // Operator= --> S1=S2, copy str2 to str1
    void operator=(String &source){
        int i=0;
        //cout<<"String before copy: "<<this->str1<<endl;
        char * str2 = new char[source.size]; // DYNAMIC MEMORY
            while(source.str1[i]!=TERM){
                str2[i]=source.str1[i];
                i++;
            }
        str2[i]=TERM;
        //cout<<"String after copy: "<<this->str1<<endl;
        delete[] str1;
        this->str1=str2;
        this->size=source.size;
        return;
    } // MAKE OPERATOR > & <
    bool operator>(String &source){
        cout<<this->size<<endl;
        cout<<source.size<<endl;
            if(this->size-1>source.size){
                return true;
            }
            else{
                return false;
            }
    }
    bool operator<(String &source){
            if(this->size-1<source.size){
                return true;
            }
            else{
                return false;
            }
    }

    //      resizing    //   str1 = abcd    str2= jhk  -->  newStr = jhkcd OR abcd

    void StrResize(int newSize, char c = '/'){
    // take 1 input from user which is the size of the new list (obligatory)
    // if the NEW size > OLD size --> we'll take an extra input to fill the empty slots with
        //cout<<this->size<<endl;
        int j=0;
        char *str4=new char[newSize];
        while(this->str1[j]!=TERM){ // jana
                //cout<<"ana hena"<<endl;
                str4[j]=str1[j]; // adding what's in str1 to the NEW ARRAY - IMPOOOO
                j++;
            }
        if(this->size==newSize){
            return;
        }
        else if(newSize>this->size){
            int i=0;
            while(i<newSize+1){ // newSize=8 this->size=5 malak 0123 i=012345   newStr=malak newSize=8
                //cout<<this->size<<endl;
                if(i>this->size-1){ // i=5
                    //cout<<i<<endl;
                    str4[i]=c;
                    i++;
                }
                else{
                    i++;
                }
                }
                str4[i]=TERM;
        }
        else{ //  newSize<this->size-1
            int i=0;int j=0;
            while(i<newSize){ // malak 0123 i=0123 newSize=3
                i++;
            }
            for(j=0; j<newSize;j++){
                str1[i]=TERM;
                i++;
            }
        }
         delete [] str1;
         this->str1=str4;
         this->size=newSize;
    }
    // if the new size is > this->size  ---> takes another input * for ex. & put it in the extra slots abcd 4 new size=6 abcd//
    // if the new size is = this->size  ---> print this->str1
    // if the new size is < this->size  ---> abcd newSize=2 --> ab
};


int main()
{
    char *stringInp1="nadeeen";
    //cout<<"Please Enter S1: "<<endl;
    //cin>>stringInp1;
    char *stringInp2="aminaa";
    String S1(stringInp1);
    String S2(stringInp2);
    //cout<<"Length: "<<S1.StrLength(S1)<<endl; - DONE
    //S1.StrCompare(S2); // - DONE
    //cout<<endl;
    //S1.StrConcat(S2); // - DONE
    //cout<<endl;
    //S1.display();
    //cout<<endl;
    //S2.display();
    //cout<<"String after copy: "<<endl;
    //S1.StrCopy(S2); // - DONE
    //S1.display();
    //cout<<endl;
    //S1.setString(stringInp1);
    //S2.setString(stringInp2);
    /*S1.setSize(size);
    S2.setSize(size);*/
    //S1>S2;
    /*cout<<"S1 > S2"<<endl;
    if(S1>S2){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    //S1<S2; // compare sizes
    cout<<"S1 < S2"<<endl;
    if(S1<S2){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }*/

    /*cout<<"operator ="<<endl; // - DONE
    S1=S2;
    S1.display();*/

    // RESIZING //
    char a='f';
    S1.StrResize(7);
    S1.display();
    return 0;
}
