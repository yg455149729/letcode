string intToRoman(int num) {
	int remain = num;
	int division = 1000;
	int flag = 0;//可以当作下标，和求除数 的关键
	string p = "MDCLXVI";
	string result = "";
	while (remain!=0) {
		
		//判断体
		int tmp = 2 - flag / 2;
		if (remain>=division - pow(10,tmp)&&tmp>=0&&remain<division) {//能够直接表示的，跳量级
			/*cout << "aini" << endl;*/
			int temp = flag % 2 == 0 ? 2 : 1;
			remain = remain -division+pow(10,tmp);
			result.append(1, p[flag + temp]);
			result.append(1, p[flag]);
			
			if (flag%2==0) division = division / 10;
			else {
				division = division / 5;

			}
			flag = flag + temp;
		}
		else {//正常情况
			int temp = flag % 2 == 0 ? 2 : 5;
			/*cout << "jiayou" << endl;*/
			result.append(remain / division, p[flag]);
			remain = remain %division;
			
			if (remain < division - pow(10, tmp)) { division = division / temp; flag = flag + 1;
			}
		}
		
		/*cout << flag << "  " << remain << "  " << division << endl;*/

	}
	return result;
}
