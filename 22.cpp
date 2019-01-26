#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int maxArea(vector<int>& height) {
	int len = height.size();
	int i = 0,j=len-1;
	int max = 0;
	int tmp;
	while (j !=i) {
		int high = (height[i] <= height[j]) ? height[i++] : height[j--];
		tmp = (j - i+1)*high;
		max = (tmp < max) ? max : tmp;
	}
	return max;
}
//int maxArea(vector<int>& height) {//当MAX/a[i]>=vector.length-i时，才需要便利
//	int max = 0; int i = 0;
//	int len = height.size();
//	if (height[i] == 0) i = 1;
//	
//	while (i<len) {
//		for (; height[i] == 0; i++);
//		if (i<len&&max / height[i] <= (len - i - 1)) {
//			
//			int tmp;
//			for (int k = i+max / height[i]; k < len; k++) {
//				int H = (height[i] < height[k]) ? height[i] : height[k];
//				tmp = H * (k - i);
//				if (tmp > max) max = tmp;
//			}
//		}
//		i++;
//		
//	}
//	return max;
//}
int main(void) {
	int arr[4] = { 8,16,3,8 };
	vector<int> vec(arr, arr + 4);
	cout << maxArea(vec) << endl;
	getchar();
	return 0;
}