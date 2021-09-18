#include<iostream>
#include<memory>

using namespace std;

class Dog{
	string name_;
public:
	Dog(string name){
		cout<<"Created: "<<name<<endl;
		name_ = name;
	}

	Dog(){
		cout<<"Nameless Created"<<endl;
	}

	~Dog(){
		cout<<"destroyed"<<endl;
	}

	void bark(){
		cout<<"Dog: "<<name_<<" rules!"<<endl;
	}
};


int main(){
	/*two steps 1. Dog create 2. make it shared   hence it is not exception safe*/
	shared_ptr<Dog> p (new Dog("Gunner")); // count =1
	{
		shared_ptr<Dog> p2 = p; // count =2
		p2->bark();
		cout << p.use_count()<<endl;

	}// count =1
	p->bark();

	cout << p.use_count()<<endl;


	/*BAD PRACETICE*/
	/*if p goes out of scope both dog TANK is destroyed, same for p2*/
	Dog* d = new Dog("Tank");
	shared_ptr<Dog> p1(d); // p count =1
	shared_ptr<Dog> p2(d); // p2 count =2;


	/*GOOD PRACTICE*/
	/*fast and safer*/
	shared_ptr<Dog> q = make_shared<Dog>("Runner");
	return 0;
} // count =0


 //throw std::logic_error("Waiting to be implemented");