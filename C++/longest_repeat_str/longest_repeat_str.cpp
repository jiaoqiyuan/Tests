#include <iostream>
#include <string>

using namespace std;

/* 
 *求字符串中最长连续重复字符个数并输
 * */
int main()
{
	string str;
	while(cin >> str) {
		char current_ch = str[0];
		char max_ch;
		int current_count = 1;
		int max_count = 0;
		for(int i = 1; i < str.size(); i++) {
			//printf("max_count = %d\n", max_count);
			if(current_ch == str[i]) {
				current_count++;
				if(i == (str.size() - 1)) {
					max_ch = current_ch;
					max_count = current_count;
				}
			} else {
				if((current_count > max_count) || (current_count == max_count && current_ch < max_ch)) {
					max_ch = current_ch;
					max_count = current_count;
				}
				current_ch = str[i];
				current_count = 1;
			}
		}
		for(int i = 0; i < max_count; i++) {
			cout << max_ch;
		}
		cout << endl;
	}
	return 0;
}
