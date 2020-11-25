# -*- coding: utf-8 -*-
import pprint


class IntervalTree:
    def __init__(self, features, start, end):
        """
        data: an array of elements where each element contains start coodinate, end coordinate, and element id.
        start: position of the start position of the element range. Allways 1:based
        end: position of the end position of the element range. Allways 1:based
        data: 数组，数组中的每个元素包含开始坐标，结束坐标，元素 ID
        start: 元素范围的开始位置
        end: 元素范围的结束位置

        start index is allways 0 and end index allways 1
        开始索引始终是 0 结束索引始终是 1
        for example, a reference genome of a million base pairs with the following features:
            features = [[20,400,'id01'],[1020,2400,'id02'],[35891,29949,'id03'],[900000,900000,'id04'],[999000,999000,'id05']]
        to make a tree:
            myTree = IntervalTree(features, 0, 1, 1, 1000000)
        
        警告：上述例子中 id03 对应的范围数据虽然可以正确得被插入到树中，但 id03 这个值会丢失，原因是数据的大小顺序
        """
        self.start = start
        self.end = end
        self.elementary_intervals = self.get_elementary_intervals(features)
        self.tree = self.recursive_build_tree(self.elementary_intervals)
        self.insert_data(self.tree, features, start, end)
        self.trim_tree(self.tree)

    def get_elementary_intervals(self, features):
        """
        Generates a sorted list of elementary intervals
        生成一个已排序的包含基础区间的列表（单层列表，列表中的元素是每个区间的头和尾）

        注意：这里丢掉了 features 中的 id 元素，后面等树构建完后会重新插入到树中
        """
        coords = []
        try:
            for interval in features:
                if len(interval) != 3:
                    raise SyntaxError(
                        'Interval malformed %s. Allways specify start and end position for interval.' % str(interval))
                coords.extend([interval[0], interval[1]])
        except IndexError:
            raise SyntaxError(
                'Interval malformed %s. Allways specify start and end position for interval.' % str(interval))
        coords.sort()
        return coords

    def recursive_build_tree(self, intervals):
        """
        recursively builds a BST based on the elementary intervals.
        each node is an array: [interval value, left descendent nodes, right descendent nodes, [ids]].
        nodes with no descendents have a -1 value in left/right descendent positions.
        基于基础区间列表递归得构建一个 BST（二分查找树），每个节点是一个多维（嵌套）列表，后面称之为节点列表，
        如果一个节点没有子节点，则其节点列表中左右子节点的位置存入 -1 组成的节点列表

        最终结果是一个长度为 4 的列表，更多的数据在这个列表中嵌套在子节点中

        for example, a node with two empty descendents:
            [500,                               interval value
                [-1,-1,-1,['id5','id6']],       left descendent
                [-1,-1,-1,['id4']],             right descendent
                ['id1',id2',id3']]              data values
        """
        center = int(round(len(intervals) / 2))
        left = intervals[:center]
        right = intervals[center + 1:]
        node = intervals[center]

        if len(left) > 1:
            left = self.recursive_build_tree(left)
        elif len(left) == 1:
            left = [left[0], [-1, -1, -1, []], [-1, -1, -1, []], []]
        else:
            left = [-1, -1, -1, []]

        if len(right) > 1:
            right = self.recursive_build_tree(right)
        elif len(right) == 1:
            right = [right[0], [-1, -1, -1, []], [-1, -1, -1, []], []]
        else:
            right = [-1, -1, -1, []]
        return [node, left, right, []]

    def pt_within(self, pt, subject):
        """
        Accessory function to check if a point is within a range
        一个点是否在一个范围内
        """
        try:
            if pt >= int(subject[0]) and pt <= int(subject[1]):
                return True
        except ValueError:
            raise ValueError('Interval start and stop has to be integers. %s' % str(subject))
        return False

    def is_within(self, query, subject):
        """
        Accessory function to check if a range is fully within another range
        范围 query 是否完全在范围 subject 内
        """
        if self.pt_within(query[0], subject) and self.pt_within(query[1], subject):
            return True 
        return False

    def overlap(self, query, subject):
        """
        Accessory function to check if two ranges overlap
        两个范围是否有交集
        """
        if (self.pt_within(query[0], subject) or self.pt_within(query[1],
                                                                subject) or
                self.pt_within(subject[0], query) or self.pt_within(subject[1],
                                                                    query)):
            return True

        return False

    def recursive_insert(self, node, coord, data, start, end):
        """
        Recursively inserts id data into nodes
        将 id 数据插入到树中对应位置，对应位置是指：TODO
        """
        if node[0] != -1:
            left = (start, node[0])
            right = (node[0], end)

            # 左子树
            # if left is totally within coord
            if self.is_within(left, coord):
                node[1][-1].append(data)
            elif self.overlap(left, coord):
                self.recursive_insert(node[1], coord, data, left[0], left[1])

            # 右子树
            if self.is_within(right, coord):
                node[2][-1].append(data)
            elif self.overlap(right, coord):
                self.recursive_insert(node[2], coord, data, right[0], right[1])

    def insert_data(self, node, data, start, end):
        """
        loops through all the data and inserts them into the empty tree
        包装： recursive_insert
        """
        for item in data:
            self.recursive_insert(node, [item[0], item[1]], item[-1], start, end)

    def trim_tree(self, node):
        """
        trims the tree for any empty data nodes
        将无数据的节点列表使用 -1 代替
        """
        data_len = len(node[-1])

        if node[1] == -1 and node[2] == -1:
            if data_len == 0:
                return 1
            else:
                return 0
        else:
            if self.trim_tree(node[1]) == 1:
                node[1] = -1

            if self.trim_tree(node[2]) == 1:
                node[2] = -1

            if node[1] == -1 and node[2] == -1:
                if data_len == 0:
                    return 1
                else:
                    return 0

    def find(self, node, interval, start, end):
        """
        recursively finds ids within a range
        查询指定范围内包含哪些 id
        只要范围 A 与指定范围有交集则范围 A 对应的 id 数据则认为是符合条件的结果
        """
        data = []

        if len(interval) != 2:
            raise SyntaxError(
                'Interval malformed %s. Allways specify start and end position for interval.' % str(interval))

        left = (start, node[0])
        right = (node[0], end)

        if self.overlap(left, interval):
            data.extend(node[-1])
            if node[1] != -1:
                data.extend(self.find(node[1], interval, left[0], left[1]))

        if self.overlap(right, interval):
            data.extend(node[-1])
            if node[2] != -1:
                data.extend(self.find(node[2], interval, right[0], right[1]))

        return list(set(data))

    def find_range(self, interval):
        """wrapper for find"""
        return self.find(self.tree, interval, self.start, self.end)

    def pprint(self, ind):
        """pretty prints the tree with indentation"""
        pp = pprint.PrettyPrinter(indent=ind)
        pp.pprint(self.tree)

if __name__ == "__main__":
    features = [[20,400,'id01'],[1020,2400,'id02'],[35891,29949,'id03'],[900000,900000,'id04'],[999000,999000,'id05']]
    myTree = IntervalTree(features, 1, 1000000)
    print(myTree.find_range((1, 1021)))