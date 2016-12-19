/*LeetCode2.1.7
Given an array of integers, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, where
index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not
zero-based.
You may assume that each input would have exactly one solution.
Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

*/

#include <map>
#include <string>
#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;

class Solution {
	public:
		vector<int> twoSum(vector<int> &nums, int target) {
			map<int, int> mapping;
			vector<int> result;
			for (int i = 0; i < nums.size(); i++) {
					mapping[nums[i]] = i;
			}
			for (int i = 0; i < nums.size(); i++) {
					const int gap = target - nums[i];
					if (mapping.find(gap) != mapping.end() && mapping[gap] > i) {
							result.push_back(i + 1);
							result.push_back(mapping[gap] + 1);
							break;
					}
			}
			for(vector<int>::iterator it = result.begin();it != result.end();++it)
		     cout<<*it<<" ";
		}
};

int main(){
	Solution solution;
	int a[15] = {1,2,3,4,5,6,7,8,5,6,7,8,9,10,11};
	vector<int> va(a,a+15);
	cout<<endl;
	for(vector<int>::iterator it = va.begin();it != va.end();++it)
		cout<<*it<<" ";
	cout<<endl;
	solution.twoSum(va,9);
	cout<<endl;
	return 0;
	
}
//运行后：
//1 2 3 4 5 6 7 8 5 6 7 8 9 10 11 
//1 12
