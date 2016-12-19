/*LeetCode2.1.1 Remove Duplicates from Sorted Array
Given a sorted array, remove the duplicates in place such that each element appear only once
and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
For example, Given input array A = [1,1,2],
Your function should return length = 2, and A is now [1,2].*/

#include<iostream>
#include<vector>
using namespace  std;

class Solution{
public:
	int removeDuplicates(vector<int>& nums){
	if(nums.empty()) 
		return 0;
	int index = 0;
	for(int i = 1;i < nums.size();i++){
		if(nums[index] != nums[i])
			nums[++index] = nums[i];
		else 
				{
					nums.erase(nums.begin()+index);
					--i;
				}
			}
			return index + 1;
	}
};
int main(){
	Solution solution;
	int a[8] = {1,2,3,3,4,5,6,6};
	vector<int> va(a,a+8);
	for(int i = 0;i < va.size();i++)
		cout<<a[i]<<" ";
	cout<<endl;
	for(vector<int>::iterator it = va.begin();it != va.end();++it)
		cout<<*it<<" ";
	cout<<endl;
	int b = solution.removeDuplicates(va);
	for(vector<int>::iterator it = va.begin();it != va.end();++it)
		cout<<*it<<" ";
	cout<<endl;
	cout<<b<<endl;
	return 0;
	
}
//运行后

//1 2 3 3 4 5 6 6 
//1 2 3 3 4 5 6 6 
//1 2 3 4 5 6 
//6
