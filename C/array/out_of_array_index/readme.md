测试数组越界以及函数内变量在内存存放问题

程序输入：

```
hello world
hello world
hello world
......
hello world
hello world
hello world
```

无限循环

因为栈内的数据是从高往低存的，而函数内变量的压栈顺序决定了变量i先入栈，然后是int数组，当遍历到数组下表为3的时候已经超出了数组范围，找到了变量i的存储地址，也就是把变量i置0，那么循环就会继续，从而导致死循环。

   	  低地址
   	|	|
   |	|	|
   |	| a[0]	| <-
   |	| a[1]	|
   |	| a[2]	|
   |	|  i	|
   V	|	|
	|       |
	  高地址
