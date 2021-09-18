#include<bits/stdc++.h>
using namespace std;

class Text{

public:
	string s;
	virtual void add(char c){
		if(isalpha(c)) s+=c;
	}

	string getValue(){
		return s;
	}
};

class Number: public Text{
public:
	void add(char c){
		if(!isalpha(c)){
			s += c;
		}
	}
};


int main(){
	Text *t = new Number();
	t->add('1');
	t->add('a');
	t->add('0');
	cout<<'\n'<<t->getValue()<<'\n';


	Text *p = new Text();
	p->add('1');
	p->add('a');
	p->add('0');
	cout<<'\n'<<p->getValue()<<'\n';
	return 0;
}