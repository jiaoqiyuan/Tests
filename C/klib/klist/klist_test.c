#include <stdio.h>
#include "klist.h"

#define list_bs_elem_destroy(x) free((void *)x->data)

KLIST_INIT(list_bs_elems, char *, list_bs_elem_destroy);
KLIST_INIT(list_int_set, int, list_bs_elem_destroy);

void copy_klist(klist_t(list_bs_elems) *l_src, klist_t(list_bs_elems) *l_dest) {
    kliter_t(list_bs_elems) *iter_list = NULL;
    for (iter_list = kl_begin(l_src); iter_list != kl_end(l_src); iter_list = kl_next(iter_list)) {
        char *value = kl_val(iter_list);
        *kl_pushp(list_bs_elems, l_dest) = value;
    }

}

int klist_test() {
    klist_t(list_bs_elems) *l_bs_elems = kl_init(list_bs_elems); 
    char *value1 = malloc(16);        
    char *value2 = malloc(16);        
    char *value3 = malloc(16);        
    char *value4 = malloc(16);        
    char *value5 = malloc(16);        
    snprintf(value1, 16, "value1");
    snprintf(value2, 16, "value2");
    snprintf(value3, 16, "value3");
    snprintf(value4, 16, "value4");
    snprintf(value5, 16, "value5");
    *kl_pushp(list_bs_elems, l_bs_elems) = value1;
    *kl_pushp(list_bs_elems, l_bs_elems) = value2;
    *kl_pushp(list_bs_elems, l_bs_elems) = value3;
    *kl_pushp(list_bs_elems, l_bs_elems) = value4;
    *kl_pushp(list_bs_elems, l_bs_elems) = value5;
    kliter_t(list_bs_elems) *iter_list = NULL;
    for (iter_list = kl_begin(l_bs_elems); iter_list != kl_end(l_bs_elems); iter_list = kl_next(iter_list)) {
        char *value = kl_val(iter_list);
        printf("value = %s\n", value);
    }
    
    klist_t(list_bs_elems) *l_bs_elems_bak = kl_init(list_bs_elems); 
    copy_klist(l_bs_elems, l_bs_elems_bak);
    
    kl_destroy(list_bs_elems, l_bs_elems);
//    for (iter_list = kl_begin(l_bs_elems); iter_list != kl_end(l_bs_elems); iter_list = kl_next(iter_list)) {
//        char *value = kl_val(iter_list);
//        printf("value = %s\n", value);
//    }


    kl_destroy(list_bs_elems, l_bs_elems_bak);
    return 0;
}

void list_iter_test() {
    klist_t(list_int_set) *int_set = kl_init(list_int_set);
    for(int i = 0; i < 100; i++) {
        *kl_pushp(list_int_set, int_set) = i;
    }
    kliter_t(list_int_set) *iter_list = NULL;
    kliter_t(list_int_set) *iter_list1 = NULL;
    kliter_t(list_int_set) *iter_list2 = NULL;
    kliter_t(list_int_set) *iter_list3 = NULL;
    for(iter_list = kl_begin(int_set); iter_list != kl_end(int_set); iter_list = kl_next(iter_list)) {
        int value = kl_val(iter_list);
        if (value == 0) {
            iter_list1 = iter_list;
        } else if (value == 33) {
            iter_list2 = iter_list;
        } else if (value == 66) {
            iter_list3 = iter_list;
        }
    }

    for(iter_list = iter_list2; iter_list != iter_list3; iter_list = kl_next(iter_list)) {
        int value = kl_val(iter_list);
        printf("value = %d\n", value);
    }
}

int main() {
    klist_test();
    //list_iter_test();
}
