#include<iostream>
#include<cmath>
#include<string>
using namespace std;
string longestPalindrome(string s) {//反转S求 S和S反转的最长公共子串
	int len = s.length();
	string s_reverse="" ;
	string result="" ;
	if (len > 0) {
		for (int i = len - 1; i >= 0; i--) {
			s_reverse += s[i];
		}
		//s_reverse 初始化完成
		//求公共最长字串
		for (int i = 0; i <= s.length() - 1; i++) {
			for (int j = i; j <= s.length() - 1; j++) {
				string temp = "";
				for (int t = i; t <= j; t++) {
					temp += s[t];
				}
				if (s_reverse.find(temp) != string::npos) {
					//找到
					result = (result.length() > temp.length()) ? result : temp;
				}
				else {
					//未找到
					break;
				}
			}
		}
	}
	return result;
}
int main(void) {
	string a = "";

	cout << longestPalindrome(a);
	getchar();
	return 0;
}