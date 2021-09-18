/*
Thread can be implemented using
1. Functions pointers
2. Lambda Expressions
3. Functors
4. Memeber Function
5. Static Memeber functions
*/
/* compile:   g++ lec1.cpp -std=c++11 -pthread*/

/*
	find sum of number from 1 to 1900000000
*/
#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>

using namespace std::chrono;
using namespace std;

typedef long long ll;

void even(ll start , ll end){
	ll sum = 0;
	while(start <= end){
		sum = sum + start;
		start += 2;
	}
	cout<<"even: "<<sum<<'\n';
}

void odd(ll start, ll end){
	ll sum = 0;
	while(start <= end){
		if(start%2!=0){
			sum += start;
		}
		start += 1;
	}
	cout<<"odd: "<<sum<<'\n';
}

int main(){

	ll start =0, end =1900000000;

	cout<<" Using Single program\n";
	auto startTime = high_resolution_clock::now();
	even(start, end);
	odd(start, end);
	auto stopTime = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stopTime - startTime);
	cout<<"duration: "<<duration.count()/1000000<<endl;

	cout<<"Using two threads\n";
	startTime = high_resolution_clock::now();
	std::thread t1(odd, start, end);
	std::thread t2(even, start, end);
	t1.join();
	t2.join();
	stopTime = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stopTime - startTime);
	cout<<"duration: "<<duration.count()/1000000<<endl;
	return 0;
}