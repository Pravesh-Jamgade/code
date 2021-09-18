#include <bits/stdc++.h>
using namespace std;

vector<int> out;
 int cnt = 0;
bool solve(int a, int d, int sum, vector<int>& in, bool& f){
	cnt++;
	if(f) return f;
	else if(sum == 0 and d>0) return false;
	else if(sum !=0 and d==0) return false;
	else if(sum == 0 and d == 0 ) {
		f = true; return true;
	}

	for(int i=a; i < in.size(); i++){
		out.push_back(i);
		cout<<a<<"-->"<<i<<endl;
		if(solve(i+1, d-1, sum-in[i], in, f)){
			return true;
		}
		out.pop_back();

	}
	return false;
}

int main(){

	/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

	You may assume that each input would have exactly one solution, and you may not use the same element twice.

	You can return the answer in any order.*/


	/*Example 1:

	Input: nums = [2,7,11,15], target = 9
	Output: [0,1]
	Output: Because nums[0] + nums[1] == 9, we return [0, 1].
	Example 2:

	Input: nums = [3,2,4], target = 6
	Output: [1,2]*/

	string in;
	getline(cin, in);


	vector<int> nums;
	stringstream ss;
	ss << in;

	int t;
	char c;
	while(ss >> t){
		nums.push_back(t);
		ss>>c;
	}

	int sum; cin>>sum;
	int d = 2;
	int a = 0;
	bool f = false;
	solve(a, d, sum, nums, f);
	
	for(auto a: out) cout<<a<<" ";

	cout<<"\n"<<"funcions called :"<<cnt<<endl;
	return 0;
}

