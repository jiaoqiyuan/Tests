#include "kdq.h"
#include "stdio.h"
#include <inttypes.h>
#include <assert.h>
#include <stdbool.h>

KDQ_INIT(uint64_t);
KDQ_INIT(int);

typedef struct map_data_s {
    uint64_t ip_sum;
    int count;
    struct map_data_s *next;
} map_data_t;

map_data_t *init() {
    map_data_t *head = malloc(sizeof(map_data_t));
    assert(head != NULL);
    head->next = NULL;
    return head;
}

int put(map_data_t *head, uint64_t key, int value) {
    // 如果不存在就创建，如果存在就直接更新值
    if (!head) {
        return -1;
    }
    map_data_t *pre = head;
    head = head->next;
    while (head) {
        if (head->ip_sum == key) {
            head->count += 1;
            // printf("update it!\n");
            return head->count;
        }
        pre = head;
        head = head->next;
    }

    if (head == NULL) {
        map_data_t *elem = malloc(sizeof(map_data_t));
        elem->ip_sum = key;
        elem->count = value;
        elem->next = NULL;
        pre->next = elem;
        // printf("insert it!\n");
    }

    
    return value;
}

bool exist(map_data_t *head, uint64_t key) {
    if (!head || !head->next) {
        return false;
    }
    head = head->next;
    while (head) {
        if (head->ip_sum == key) {
            return true;
        }
        head = head->next;
    }
    return false;
}

int get(map_data_t *head, uint64_t key) {
    if (!head) {
        return -1;
    }
    head = head->next;
    while (head != NULL) {
        int elem_key = head->ip_sum;
        if (elem_key == key) {
            return head->count;
        }
        head = head->next;
    }
    return 0;
}

void destroy(map_data_t *head) {
    while(head != NULL) {
        map_data_t *elem = head;
        head = head->next;
        free(elem);
        elem = NULL;
    }
}

kdq_t(uint64_t) *get_kdq(){
    kdq_t(uint64_t) *ip_sums = kdq_init(uint64_t);
    for (int i = 1; i < 30; i++) {
        kdq_push(uint64_t, ip_sums, i % 6);
    }
    return ip_sums;
}

void show_kdq(kdq_t(uint64_t) *ip_sums){
    int size = kdq_size(ip_sums);
    // printf("size = %d\n", size);
    for (int i = size - 1; i >= 0; --i) {
        int value = kdq_at(ip_sums, i);
        printf("value = %d\n", value);
    }
    printf("======================\n");
}

kdq_t(int) *get_kdq_int(){
    kdq_t(int) *ip_sums_int = kdq_init(int);
    for (int i = 0; i < 34; i++) {
        kdq_push(int, ip_sums_int, i % 4);
    }
    return ip_sums_int;
}

void show_kdq_int(kdq_t(int) *ip_sums){
    int size = kdq_size(ip_sums);
    // printf("size = %d\n", size);
    for (int i = size - 1; i >= 0; --i) {
        int value = kdq_at(ip_sums, i);
        printf("value = %d\n", value);
    }
    printf("======================\n");
}

void test_map(kdq_t(uint64_t) *ip_sums) {
    map_data_t *head = init();
    size_t dq_size = kdq_size(ip_sums);
    printf("dq_size is %zu\n", dq_size);
    // 存储数据到 map 中
    for (int i = dq_size - 2; i >= 0; --i) {
        uint64_t ip_sum = kdq_at(ip_sums, i);
        // int count = exist(head, ip_sum) ? get(head, ip_sum) + 1 : 1;
        int count = get(head, ip_sum) + 1;
        printf("ip_sum = %ld, count = %d\n", ip_sum, count);
        assert(count != 0);
        put(head, ip_sum, count);
    }
    // 获取map中数量最多的key
    int max_count = 0, max_ip_sum = 0;
    map_data_t *elem = head->next;
    while (elem) {
        printf("ip_sum is %ld, elem count is %d\n", elem->ip_sum, elem->count);
        if (elem->count > max_count) {
            max_ip_sum = elem->ip_sum;
            max_count = elem->count;
            printf("max change, max_ip_sum is %d\n", max_ip_sum);
        }
        elem = elem->next;
    }
    printf("max_ip_sum is %d\n", max_ip_sum);
    destroy(head);
}

int main(){
    kdq_t(uint64_t) *ip_sums = get_kdq();
    show_kdq(ip_sums);
    test_map(ip_sums);
    test_map(ip_sums);
    // 删除第一个元素
    uint64_t *shift_elem = kdq_shift(uint64_t, ip_sums);
    // test free
    // free(shift_elem);
    // show_kdq_int(ip_sums);
    // 恢复删除的元素
    // kdq_unshiftp(int, ip_sums);
    // show_kdq_int(ip_sums);
    kdq_destroy(uint64_t, ip_sums);
    return 0;
}