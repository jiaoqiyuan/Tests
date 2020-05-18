#include "khash.h"
#include <stdio.h>

KHASH_MAP_INIT_INT(m32, char)        // instantiate structs and methods

int main() {
	int ret;
	khint_t k;
	khash_t(m32) *h = kh_init(m32);  // 初始化 hashtable
	k = kh_put(m32, h, 5, &ret);     // 往 hashtable 中放入一个 key
	if (!ret) kh_del(m32, h, k);
	kh_value(h, k) = 10;             // 设置 value
	k = kh_get(m32, h, 10);          // 查询 hashtable，如果查询不到就返回 kh_end();
	printf("k = %ld, kh_end = %d, value = %d\n", k, kh_end(h), kh_value(h, k));
	k = kh_get(m32, h, 5);
	printf("k = %ld, kh_end = %d, value = %d\n", k, kh_end(h), kh_value(h, k));
	kh_del(m32, h, k);               // 删除一个 key-value 键值对
	for (k = kh_begin(h); k != kh_end(h); ++k)  // 遍历
			if (kh_exist(h, k))          // 是否还存在
					kh_value(h, k) = 1;
	printf("k = %ld, kh_end = %d, value = %d\n", k, kh_end(h), kh_value(h, k));
	kh_destroy(m32, h);              // 释放 hashtable 空间
	return 0;
}
