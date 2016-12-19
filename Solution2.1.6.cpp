/*LeetCode2.1.6
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
For example, Given [100, 4, 200, 1, 3, 2], The longest consecutive elements sequence is [1,
2, 3, 4]. Return its length: 4.
Your algorithm should run in O(n) complexity*/

#include<iostream>
#include<vector>
using namespace  std;

class Solution {
	public:
			int longestConsecutive(const vector<int>& nums) {
				int length = 1;
				int longest = 0;
				for(int i = 0;i < nums.size();i++){
					if((nums[i+1]) == (nums[i] + 1)){
						++ length;
						if(length > longest)
								longest = length;
					}
					else
						length = 1;
				}
				return longest;
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
	int c = solution.longestConsecutive(va);
	cout<<c<<endl;
	return 0;
	
}

//运行后：

//1 2 3 4 5 6 7 8 5 6 7 8 9 10 11 
//8

//代码二
/*LeetCode2.1.6
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
For example, Given [100, 4, 200, 1, 3, 2], The longest consecutive elements sequence is [1,
2, 3, 4]. Return its length: 4.
Your algorithm should run in O(n) complexity*/

#include<iostream>
#include<vector>
#include<map>
using namespace  std;

class Solution {
	public:
		int longestConsecutive(vector<int>& nums) {
			map<int, int> map;
			int size = nums.size();
			int l = 1;
			for (int i = 0; i < size; i++) {
				if (map.find(nums[i]) != map.end())  continue;
				map[nums[i]] = 1;
				if (map.find(nums[i] - 1) != map.end()) {
					l = max(l, mergeCluster(map, nums[i] - 1, nums[i]));
				}
				if (map.find(nums[i] + 1) != map.end()) {
					l = max(l, mergeCluster(map, nums[i], nums[i] + 1));
				}
			}
			return size == 0 ? 0 : l;
		}
	private:
		int mergeCluster(map<int, int> &map, int left, int right) {
			int upper = right + map[right] - 1;
			int lower = left - map[left] + 1;
			int length = upper - lower + 1;
			map[upper] = length;
			map[lower] = length;
			return length;
		}
};

int main(){
	Solution solution;
	int a[19] = {1,2,3,3,4,4,5,5,6,7,8,9,5,6,7,8,9,10,11};
	vector<int> va(a,a+19);
	cout<<endl;
	for(vector<int>::iterator it = va.begin();it != va.end();++it)
		cout<<*it<<" ";
	cout<<endl;
	int c = solution.longestConsecutive(va);
	cout<<c<<endl;
	return 0;
	
}

//运行后：

//1 2 3 3 4 4 5 5 6 7 8 9 5 6 7 8 9 10 11 
//11
