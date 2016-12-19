/*LeetCode2.1.5
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted
arrays. The overall run time complexity should be O(log(m + n))
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

class Solution {
	public:
			int findMedianSortedArrays(const vector<int>& A, const vector<int>& B,int k) {
				const int m = A.size();
				const int n = B.size();
					return find_kth(A.begin(), m, B.begin(), n, k);
			}
	private:
			static int find_kth(std::vector<int>::const_iterator A, int m,
				std::vector<int>::const_iterator B, int n, int k) {
				//always assume that m is equal or smaller than n
				if (m > n) return find_kth(B, n, A, m, k);
				if (m == 0) return *(B + k - 1);
				if (k == 1) return min(*A, *B);
					//divide k into two parts
					int ia = min(k / 2, m), ib = k - ia;
				if (*(A + ia - 1) < *(B + ib - 1))
					return find_kth(A + ia, m - ia, B, n, k - ia);
				else if (*(A + ia - 1) > *(B + ib - 1))
					return find_kth(A, m, B + ib, n - ib, k - ib);
				else
					return A[ia - 1];
			}
};

int main(){
	Solution solution;
	int a[6] = {1,2,3,4,5,6};
	int b[6] = {1,3,4,7,8,12};
	vector<int> va(a,a+6);
	vector<int> vb(b,b+6);
	cout<<endl;
	for(vector<int>::iterator it = va.begin();it != va.end();++it)
		cout<<*it<<" ";
	cout<<endl;
	for(vector<int>::iterator it = vb.begin();it != vb.end();++it)
		cout<<*it<<" ";
	cout<<endl;
	int c = solution.findMedianSortedArrays(va,vb,11);
	cout<<c<<endl;
	return 0;
	
}
//运行后：
//1 2 3 4 5 6 
//1 3 4 7 8 12 
//8


//代码二

#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

class Solution {
	public:
			double findMedianSortedArrays(const vector<int>& A, const vector<int>& B) {
				const int m = A.size();
				const int n = B.size();
				int total = m + n;
				if (total & 0x1)
					return find_kth(A.begin(), m, B.begin(), n, total / 2 + 1);
				else
					return (find_kth(A.begin(), m, B.begin(), n, total / 2)
							+ find_kth(A.begin(), m, B.begin(), n, total / 2 + 1)) / 2.0;
			}
	private:
			static int find_kth(std::vector<int>::const_iterator A, int m,
				std::vector<int>::const_iterator B, int n, int k) {
				//always assume that m is equal or smaller than n
				if (m > n) return find_kth(B, n, A, m, k);
				if (m == 0) return *(B + k - 1);
				if (k == 1) return min(*A, *B);
					//divide k into two parts
					int ia = min(k / 2, m), ib = k - ia;
				if (*(A + ia - 1) < *(B + ib - 1))
					return find_kth(A + ia, m - ia, B, n, k - ia);
				else if (*(A + ia - 1) > *(B + ib - 1))
					return find_kth(A, m, B + ib, n - ib, k - ib);
				else
					return A[ia - 1];
			}
};

int main(){
	Solution solution;
	int a[6] = {1,2,3,4,5,6};
	int b[6] = {1,3,4,7,8,12};
	vector<int> va(a,a+6);
	vector<int> vb(b,b+6);
	cout<<endl;
	for(vector<int>::iterator it = va.begin();it != va.end();++it)
		cout<<*it<<" ";
	cout<<endl;
	for(vector<int>::iterator it = vb.begin();it != vb.end();++it)
		cout<<*it<<" ";
	cout<<endl;
	double c = solution.findMedianSortedArrays(va,vb);
	cout<<c<<endl;
	return 0;
	
}

//运行后

//1 2 3 4 5 6 
//1 3 4 7 8 12 
//4
