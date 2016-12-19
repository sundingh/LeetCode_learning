/*LeetCode2.1.2
Follow up for ”Remove Duplicates”: What if duplicates are allowed at most twice?
For example, Given sorted array A = [1,1,1,2,2,3],
Your function should return length = 5, and A is now [1,1,2,2,3]
*/

#include<iostream>
#include<vector>
using namespace  std;
class Solution {
	public:
		int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 2) return nums.size();
		int index = 2;
		for (int i = 2; i < nums.size(); i++){
			if (nums[i] != nums[index - 2])
				nums[index++] = nums[i];
			else 
				{
					nums.erase(nums.begin()+index);
					--i;
				}
		}
		return index;
	}
};

int main(){
	Solution solution;
	int a[13] = {1,1,2,3,3,3,4,4,5,6,6,6,6};
	vector<int> va(a,a+13);
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
	cout<<b;
	return 0;
	
}
//运行后：

//1 1 2 3 3 3 4 4 5 6 6 6 6 
//1 1 2 3 3 3 4 4 5 6 6 6 6 
//1 1 2 3 3 4 4 5 6 6 
//10
