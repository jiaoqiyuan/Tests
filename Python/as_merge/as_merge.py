#!/usr/bin/env/python3
# coding = utf-8


results = []

def generate_results():
    results.append(({2, 3}, {4, 5, 6, 7}))
    results.append(({8, 9}, {10, 11}))
    results.append(({12, 13}, {7, 11}))
    results.append(({14, 15}, {17, 18}))
    results.append(({19}, {11, 20}))

def had_merged(inner_as_set, outer_as_set, merged_as):
    for merged_inner_as_set, merged_outer_as_set in merged_as:
        if inner_as_set.issubset(merged_inner_as_set):
            return True
    return False

def merge_as():
    generate_results()
    print(results)
    merged_as = []
    for inner_as_set, outer_as_set in results:
        merged_inner_as_set = set()
        merged_outer_as_set = set()
        merged_inner_as_set |= inner_as_set
        merged_outer_as_set |= outer_as_set
        if had_merged(inner_as_set, outer_as_set, merged_as):
            continue
        while True:
            need_check = False
            for inner_as_set_tmp, outer_as_set_tmp in results:
                if inner_as_set_tmp.issubset(merged_inner_as_set):
                    continue
                if len(merged_outer_as_set & outer_as_set_tmp) > 0:
                    merged_inner_as_set |= inner_as_set_tmp
                    merged_outer_as_set |= outer_as_set_tmp
                    need_check = True
                    break
            if not need_check:
                break
        # 结果存入合并后的集合
        merged_as.append((merged_inner_as_set, merged_outer_as_set))
        print("====")
    
    print(merged_as)


if __name__ == "__main__":
    print("hello")
    merge_as()
