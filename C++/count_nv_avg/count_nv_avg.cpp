#include <iostream>

using namespace std;

int main()
{
	int num;
	int count1 = 0;
	int count2 = 0;
	float sum = 0;
	while(cin >> num) {
		if(num < 0) {
			count1++;
		} else {
			sum += num;
			count2++;
		}
	}
	printf("%d\n%.1f\n", count1, (float)sum/count2);
	return 0;
}
