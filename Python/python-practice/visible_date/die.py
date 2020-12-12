from random import randint

class Die():
    """表示一个筛子的类"""
    def __init__(self, num_sizes=6):
        """筛子默认为六面"""
        self.num_sides = num_sizes

    def roll(self):
        """返回一个位于1和筛子面数之间的随机值"""
        return randint(1, self.num_sides)
