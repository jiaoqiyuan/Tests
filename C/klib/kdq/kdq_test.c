#include "kdq.h"
#include "stdio.h"
#include <inttypes.h>

KDQ_INIT(uint64_t);

kdq_t(uint64_t) *get_kdq(){
    kdq_t(uint64_t) *ip_sums = kdq_init(uint64_t);
    for (int i = 0; i < 300; i++) {
        kdq_push(uint64_t, ip_sums, i);
    }
    return ip_sums;
}

void show_kdq(kdq_t(uint64_t) *ip_sums){
    int size = kdq_size(ip_sums);
    printf("size = %d\n", size);
    for (int i = size - 1; i >= 0; --i) {
        int value = kdq_at(ip_sums, i);
        printf("value = %d\n", value);
    }
}

int main(){
    kdq_t(uint64_t) *ip_sums = get_kdq();
    show_kdq(ip_sums);
    return 0;
}