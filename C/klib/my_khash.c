#include "khash.h"
#include <stdio.h>
#include <assert.h>

KHASH_MAP_INIT_INT(m32, char)        // instantiate structs and methods
KHASH_MAP_INIT_STR(map_char_set, char *);


int test1() {
	int ret;
	khint_t k;
	khash_t(m32) *h = kh_init(m32);  // 初始化 hashtable
	k = kh_put(m32, h, 5, &ret);     // 往 hashtable 中放入一个 key
	if (!ret) kh_del(m32, h, k);
	kh_value(h, k) = 10;             // 设置 value
	k = kh_get(m32, h, 10);          // 查询 hashtable，如果查询不到就返回 kh_end();
	printf("k = %u, kh_end = %d, value = %d\n", k, kh_end(h), kh_value(h, k));
	k = kh_get(m32, h, 5);
	printf("k = %u, kh_end = %d, value = %d\n", k, kh_end(h), kh_value(h, k));
	kh_del(m32, h, k);               // 删除一个 key-value 键值对
	for (k = kh_begin(h); k != kh_end(h); ++k)  // 遍历
			if (kh_exist(h, k))          // 是否还存在
					kh_value(h, k) = 1;
	printf("k = %u, kh_end = %d, value = %d\n", k, kh_end(h), kh_value(h, k));
	kh_destroy(m32, h);              // 释放 hashtable 空间
	return 0;
}

void free_str1(char* s) {
	free((void *)s);
}

void free_str2(const char* s) {
	free((void *)s);
}

void free_my_kh(khash_t(map_char_set) *m_char_set){
	kh_free_vals(map_char_set, m_char_set, free_str1);
	kh_free(map_char_set, m_char_set, free_str2);
	kh_destroy(map_char_set, m_char_set);
}

int main() {
	khash_t(map_char_set) *m_char_set = kh_init(map_char_set);

	char *key1 = (char *)malloc(32);
	snprintf(key1, 32, "This is key1.");
	printf("key1 = %s\n", key1);

	khiter_t k = 0;
	int ret = 0;
	char *value1 = (char *)malloc(32);
	if ((k = kh_get(map_char_set, m_char_set, key1)) == kh_end(m_char_set)) {
		snprintf(value1, 32, "This is value1.");
		k = kh_put(map_char_set, m_char_set, key1, &ret);
		assert(ret != -1);
		kh_value(m_char_set, k) = value1;
	}
	assert(kh_exist(m_char_set, k));
	char *result = kh_value(m_char_set, k);
	assert(result != NULL);
	printf("result = %s\n", result);
	//free_my_kh(m_char_set);
    //free(key1);
    //free(key1);
    //free(value1);
	return 0;
}
