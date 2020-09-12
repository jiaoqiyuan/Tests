#include <stdio.h>
#include <stdbool.h>

void deal_func(bool *flag) {
    *flag = true;
}

int main() {
    bool flag = false;
    printf("flag = %d\n", flag);
    deal_func(&flag);
    printf("flag = %d\n", flag);

}
