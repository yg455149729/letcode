#include<iostream>
#include<cmath>
#include<string>
using namespace std;
bool isMatch(string s, string p) {//不匹配：1.正则表达式错误（s[flag_s]!=s[flag_p] 2.正则表达式表达了一部分；）
	int flag_s = 0, flag_p = 0;
	for (; flag_p <= p.length() - 1||s[flag_s]!='\0'; flag_p++) {
		if (p[flag_p] != '.'&&p[flag_p] != '*') {
			if (p[flag_p] != s[flag_s]) { 
				if (p[flag_p + 1] != '*')return false;
			}
			else flag_s++;
		}
		else if (p[flag_p] == '.') flag_s++;
		else if (p[flag_p] == '*') {
			if (p[flag_p - 1] != '.') {
				for (; s[flag_s] == p[flag_p - 1]; flag_s++);

			}
			
			else flag_s=s.length();
		}

	}
	cout << flag_p << endl;
	if (flag_s == s.length()&&p[flag_p]=='\0') return true;
	else
		return false;


}
int main(void) {
	cout << isMatch("ab", ".*c") << endl;
	getchar();
	return 0;
}