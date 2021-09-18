#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>

using namespace std::chrono;
using namespace std;

void fun(int n){
	cout<<n<<endl;
}

bool isTrue(int n, void (*fun)(int)){
	if(n==2)
		fun(n);
	return true;
}

class Animal{

	public:
		string type;
		Animal(){
			cout<<"Animal type 1\n";
		}
		Animal(string type){
			cout<<"Animal type 2\n";
			this->type=type;
		}
};

class Dog: public Animal{
	
public:
	string dog;
	Dog(){
		cout<<"Dog type 1\n";
	}
	Dog(string name){
		cout<<"Dog type 2\n";
		dog=name;
	}
};



int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif


	return 0;
}