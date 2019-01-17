#include<iostream>
#include<cmath>
#include<string>
using namespace std;
string convert(string s, int numRows) {
	if (numRows==1) {
		return s;
	} 
	else {
		int numCols = (s.length() / (2 * numRows - 2))*(numRows - 1);
		cout << numCols << endl;;
		if (s.length() % (2 * numRows - 2) <= numRows && s.length() % (2 * numRows - 2) != 0) {
			numCols += 1;
		}

		else if (s.length() % (2 * numRows - 2) == 0) {

		}
		else numCols = 1 + numCols + (s.length() - numRows) % (2 * numRows - 2);
		cout << numCols;
		char**(Matrix) = new char*[numRows];
		for (int i = 0; i < numRows; i++) {
			Matrix[i] = new char[numCols];
		}
		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numCols; j++) {
				Matrix[i][j] = ' ';
			}
		}
		int size = 0;
		int i = 0;
		for (int col = 0; col < numCols; col++) {
			if (col % (numRows - 1) == 0) size = numRows;
			else size = 1;
			for (int row = 0; row < size&&i<s.length(); row++) {
				if (size == numRows) {
					Matrix[row][col] = s[i];
					
					i = i + 1;

				}
				else {
					Matrix[numRows - 1 - i % (numRows - 1)][col] = s[i];
				
					i = i + 1;
				}
			}
		}
		string result = s;
		i = 0;
		
		char sign = ' ';
		for (int row = 0; row < numRows; row++) {
			for (int col = 0; col < numCols; col++) {
				if (Matrix[row][col] != sign) {
					/*cout << row << "  " << col << endl;*/
					result[i] = Matrix[row][col];
					i++;
				}
			}
		}
		delete[] Matrix;
		return result;
	}
}
int main(void) {
	string a = "PAYPALISHIRING";
	cout <<convert(a,5);
	getchar();
	return 0;
}
//class Solution {
//public:
//	string convert(string s, int numRows) {
//
//		if (numRows == 1) return s;
//
//		string ret;
//		int n = s.size();
//		int cycleLen = 2 * numRows - 2;
//
//		for (int i = 0; i < numRows; i++) {
//			for (int j = 0; j + i < n; j += cycleLen) {
//				ret += s[j + i];
//				if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
//					ret += s[j + cycleLen - i];
//			}
//		}
//		return ret;
//	}
//};