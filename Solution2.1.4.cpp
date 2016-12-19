/*LeetCode2.1.4
Follow up for ”Search in Rotated Sorted Array”: What if duplicates are allowed?
Would this affect the run-time complexity? How and why?
Write a function to determine if a given target is in the array.
*/

#include<iostream>
#include<vector>
using namespace  std;
class Solution {
	public:
		int search(const vector<int>& nums, int target) {
			int first = 0, last = nums.size();
			while (first != last) {
				const int mid = first + (last - first) / 2;
				if (nums[mid] == target)
					return mid;
				if (nums[first] < nums[mid]) {
						if (nums[first] <= target && target < nums[mid])
							last = mid;
						else
							first = mid + 1;
				} else if (nums[first] > nums[mid]) {
							if (nums[mid] < target && target <= nums[last-1])
									first = mid + 1;
							else
									last = mid;
				} else
						//skip duplicate one
						first++;
			}
			return -1;
		}
};

int main(){
	Solution solution;
	int a[8] = {1,1,2,3,4,5,6,6};
	vector<int> va(a,a+8);
	for(int i = 0;i < va.size();i++)
		cout<<a[i]<<" ";
	cout<<endl;
	for(vector<int>::iterator it = va.begin();it != va.end();++it)
		cout<<*it<<" ";
	cout<<endl;
	int b = solution.search(va,3);
	cout<<endl;
	cout<<b<<endl;
	return 0;
	
}

//运行后：

//1 1 2 3 4 5 6 6 
//1 1 2 3 4 5 6 6 
//
//3
