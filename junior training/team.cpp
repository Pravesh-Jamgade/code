
#include<iostream>
#include<cstring>
using namespace std;
 
class String
{
private:
    char *s;
    int size;
public:
    String(const char *str = NULL); // constructor
    ~String() { delete [] s;  }// destructor
    void print() { cout << s << endl; }
    void change(const char *);  // Function to change
};
 
String::String(const char *str)
{
    size = strlen(str);
    s = new char[size+1];
    strcpy(s, str);
}
 
void String::change(const char *str)
{
    delete [] s;
    size = strlen(str);
    s = new char[size+1];
    strcpy(s, str);
}

class A{
    char* p;
public: 
    A(char* str){
        p= new char[strlen(str)];
        strcpy(p,str);
    }

    void up(char* sn){
        delete []p;
        p= new char[strlen(sn)];
        strcpy(p, sn);
    }

    void print(){
        cout<<p<<endl;
    }
};
 
int main()
{   
    char *c = new char[20];
    strcpy(c, "helloAnna");
     A a("helloAnna");
     A b = a;

     a.print();
     b.print();

     delete [] c;
     c= new char[20];
     strcpy(c, "helloJames");
     a.up(c);

     a.print();
     b.print();

    // String str1("GeeksQuiz");
    // String str2 = str1;
 
    // str1.print(); // what is printed ?
    // str2.print();
 
    // str2.change("GeeksforGeeks");
 
    // str1.print(); // what is printed now ?
    // str2.print();
    // return 0;
}