#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int num;
    while(cin >> num) {
        int num3;
        num3 = num * num * num;
        int mid = num3 / num;
        char result[512] = {0};
        if(mid % 2 == 0) {
            for(int i = num / 2; i > 0; i--){
                //char tmp[8] = {0};
                //snprintf(tmp, sizeof(tmp), "%d", mid - 1 - 2*(i-1));
                //strcat(result, tmp);
                //strcat(result, "+");
                cout << (mid - 1 - 2*(i-1));
                cout << "+";
            }

            for(int i = 0; i< num/2; i++){
                //char tmp[8] = {0};
                //snprintf(tmp, sizeof(tmp), "%d", mid + 1 + 2 * i);
                //strcat(result, tmp);
                cout << (mid + 1 + 2 * i);
                if(i != num /2 -1) {
                    cout << "+";
                    //strcat(result, "+");
                }
            }
        } else {
            for(int i = (num - 1) / 2; i > 0; i--) {
                //char tmp[8] = {0};
                //snprintf(tmp, sizeof(tmp), "%d", mid - 2*i);
                //strcat(result, tmp);
                //strcat(result, "+");
                cout << (mid - 2*i);
                cout << "+";
            }
            cout << mid;
            cout << "+";
            //char tmp[8] = {0};
            //snprintf(tmp, sizeof(tmp), "%d", mid);
            //strcat(result, tmp);
            //strcat(result, "+");
            for(int i = 1; i <= (num-1)/2; i++) {
                //char tmp[8] = {0};
                //snprintf(tmp, sizeof(tmp), "%d", mid+2*i);
                //strcat(result, tmp);
                cout << (mid + 2*i);
                if(i != (num-1)/2) {
                    cout << "+";
                    //strcat(result, "+");
                }
            }
        }
	cout << endl;
        //cout << result << endl;
    }
    return 0;
}
