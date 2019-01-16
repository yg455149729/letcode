#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int m = nums1.size();
	int n = nums2.size();
	if (m > n) {
		vector<int> temp = nums1;
		nums1 = nums2;
		nums2 = temp;
		int tmp = m;
		m = n;
		n = tmp;
	}
	int i = 0;
	int j = 0;
	int function = ((m + n) % 2) ? (m + n+1) / 2 : (m + n ) / 2;
	int start = 0; int end = m ;
	while (start <=end) {
		i = (end + start) / 2;
		j = function - i;

		if (i<end&&nums1[i] < nums2[j-1]) {
			start = i + 1;
	}
		else if (i>start&&nums1[i - 1] > nums2[j]) {
			end = i - 1;
		}
		
		else {
			break;
		}

	}
	//此时已得到i，j
	int max_left = 0;
	if (i == 0) max_left = nums2[j - 1];
	else if (j == 0)max_left = nums1[i - 1];
	else max_left = (nums1[i - 1] >= nums2[j - 1]) ? nums1[i - 1] : nums2[j - 1];
	int min_right = 0;
	if (i == m) { min_right = nums2[j]; }
		else if (j == n) { min_right = nums1[i]; }
		else { min_right = (nums1[i]<nums2[j])? nums1[i]:nums2[j]; }
	if ((m + n) % 2) {
			//奇数返回左最大值
		return max_left;
	}
	else {//偶数返回平均值
		return (max_left + min_right) / 2.0;
	}
}
//double findMedianSortedArrays(vector<int>& A, vector<int> B) {
//	int m = A.size();
//	int n = B.size();
//	if (m > n) { // to ensure m<=n
//		vector<int> temp = A; A = B; B = temp;
//		int tmp = m; m = n; n = tmp;
//	}
//	int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
//	while (iMin <= iMax) {
//		int i = (iMin + iMax) / 2;
//		int j = halfLen - i;
//		if (i < iMax && B[j - 1] > A[i]) {
//			iMin = i + 1; // i is too small
//		}
//		else if (i > iMin && A[i - 1] > B[j]) {
//			iMax = i - 1; // i is too big
//		}
//		else { // i is perfect
//			int maxLeft = 0;
//			if (i == 0) { maxLeft = B[j - 1]; }
//			else if (j == 0) { maxLeft = A[i - 1]; }
//			else { maxLeft = (A[i-1]>B[j-1])? A[i-1]:B[j-1]; }
//			if ((m + n) % 2 == 1) { return maxLeft; }
//
//			int minRight = 0;
//			if (i == m) { minRight = B[j]; }
//			else if (j == n) { minRight = A[i]; }
//			else { minRight = (A[i]<B[j])? A[i]:B[j]; }
//
//			return (maxLeft + minRight) / 2.0;
//		}
//	}
//	return 0.0;
//}
int main(void) {
	vector<int> a = {1 };
	vector<int> b = { 1};
	double d = findMedianSortedArrays(a, b);
	cout << d;
	getchar();
	return 0;
}