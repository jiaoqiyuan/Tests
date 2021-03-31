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

int insert_data(khash_t(map_char_set) *m_char_set, char *key, char *value) {
	khiter_t k = 0;
	int ret = 0;
	if ((k = kh_get(map_char_set, m_char_set, key)) == kh_end(m_char_set)) {
		k = kh_put(map_char_set, m_char_set, key, &ret);
		assert(ret != -1);
		kh_value(m_char_set, k) = value;
	}
	assert(kh_exist(m_char_set, k));

	return 0;
}

int main()
{
	khash_t(map_char_set) *m_char_set = kh_init(map_char_set);


	//insert_data(m_char_set, "key1", "value1");
	//insert_data(m_char_set, "key2", "value2");
	//insert_data(m_char_set, "key3", "value3");
	//insert_data(m_char_set, "key4", "value4");
	//insert_data(m_char_set, "key5", "value5");
	//insert_data(m_char_set, "key6", "value6");
	//insert_data(m_char_set, "key7", "value7");
	//insert_data(m_char_set, "key8", "value8");
	//insert_data(m_char_set, "key9", "value9");
	//insert_data(m_char_set, "key10", "value10");

    for (int i = 0; i < 30; i++) {
        char *key = malloc(32);
        snprintf(key, 32, "key%d", i);
        char *value = malloc(32);
        snprintf(value, 32, "value%d", i);
        insert_data(m_char_set, key, value);
    }

	khiter_t iter = 0;
	for(iter = kh_begin(m_char_set); iter != kh_end(m_char_set); iter++) {
		if(!kh_exist(m_char_set, iter)) {
            continue;
        }
        char *key = kh_key(m_char_set, iter);
        char *value = kh_value(m_char_set, iter);
        printf("key = %s, value = %s\n", key, value);
	}

	
	free_my_kh(m_char_set);
	return 0;
}
