#include<iostream>
#include<cmath>
#include<string>
using namespace std;
string longestPalindrome(string s) {//反转S求 S和S反转的最长公共子串
	double len = s.length();
	string s_reverse="" ;
	string result="" ;
	if (len > 0) {
		for (double i = len - 1; i >= 0; i--) {
			s_reverse += s[i];
		}
		//s_reverse 初始化完成
		//求公共最长字串
		for (double i = 0; i <= s.length() - 1&&s.length()-i+1>result.length(); i++) {
			for (double j = i; j <= s.length() - 1; j++) {
				string temp = "";
				for (double t = i; t <= j; t++) {
					temp += s[t];
				}
				if (s_reverse.find(temp) != string::npos) {
					//找到
					double k;
					for ( k = 0; k <= temp.length() / 2; k++) {
						if (temp[k] != temp[temp.length() - k-1])
							break;
					}
					if(k==temp.length()/2+1)
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
