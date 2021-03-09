---
title: pthread-programing-1
date: 2021-01-16 17:16:55
tags:
categories: linux
thumbnail: https://gitee.com/jiaoqiyuan/pics/raw/master/blog/pthread-programing/pthread-programing-1.png
photos: https://gitee.com/jiaoqiyuan/pics/raw/master/blog/pthread-programing/pthread-programing-1.png
---


最近突然又接触了 `生产者和消费者` 问题，用到了多线程编程，这里总结一下。

在多处理器体系结构中，线程可用来实现并行性，对于 `Unix` 系统，`IEEE POSIX 1003.1c` 标准已指定了标准化的 C 语言线程编程接口，遵守该标准的实现成为 `POSIX` 线程或 `Pthread`。

<!--more-->

接下来主要介绍一下：

- Pthreads 的使用以及注意事项
- 线程管理，互斥变量，条件变量

## Pthreads 概念

### 什么是线程

从技术上讲，线程是被定义为独立的指令流，可以被操作系统调度，按照指定顺序原样执行。通俗来讲就是独立于主程序运行的 **过程**。

理解线程之前，有必要了解一下 `Unix` 的进程。进程由操作系统创建，包含一些程序资源和执行状态信息，包括：

- 进程 ID，进程组 ID，用户 ID 和组 ID
- 上下文环境 Environment
- 工作目录 Working directory
- 程序说明 Program instructions
- 寄存器 Registers
- 栈 Stack
- 堆 Heap
- 文件描述符 File descriptors
- 信号动作 Signal actions
- 共享库 Shared libraries
- 进程间通信工具（如消息队列，管道，信号量，共享内存）

![](https://computing.llnl.gov/tutorials/pthreads/images/process.gif)

![](https://computing.llnl.gov/tutorials/pthreads/images/thread.gif)

线程在这些进程资源中使用和存在，但是能够由操作系统进行调度并作为独立实体运行，这在很大程度上是因为线程仅复制使他们需要的基本资源。

线程之所以能够实现这种流程控制，是因为线程维护着自己的：

- 堆栈指针
- 寄存器
- 调度属性，如策略优先级
- 挂起和阻塞信号
- 线程特定数据

在 Unix 环境中，线程：

- 存在于进程中并使用进程资源
- 只要该线程的父进程存在且在运行，线程便拥有自己的独立控制流
- 仅复制需要独立运行的必要资源
- 可以与其他独立或非独立的线程共享进程资源
- 父进程结束，子进程也结束
- 是 `轻量级` 的，因为大多数开销已经通过创建进程的时候完成

因为同一进程中的线程共享进程资源：

- 一个线程对共享系统资源所作的改变，其他线程都可以看到
- 具有相同值得指针指向相同的数据
- 可以读写相同内存的数据，因此需要开发人员进行显式同步

### 什么是 Pthreads

从历史上看，硬件供应商已经实现了自己专有的线程版本，这些实现方式各不相同，使得开发人员难以移植。为了充分利用线程功能，需要标准化编程接口：

- 对于 Unix 系统，此接口已由 `IEEE POSIX 1003.1c` 标准指定
- 遵守该标准的实现成为 POSIX 线程或 Pthead
- 现在大多数硬件开发商除了提供自己专有的线程接口外还提供有 Pthread

Pthread 被定义为一组 C 语言编程类型和过程调用，通过 `pthread.h` 头文件和线程库实现，在有些视线中该库可能是另一个库的一部分（比如 libc）。

## 为什么要使用 Pthreads

- 轻量级: 与创建和管理进程的成本相比，可以以更少的操作系统开销创建线程。管理线程比管理进程需要更少的系统资源。

- 高效: Pthread 创建的线程之间共用主进程的地址空间，不需要内存的复制操作，因此效率更高。

- 其他原因

## 设计线程程序

#### 并行编程

现代操作系统非常适合并行编程，设计并行编程需要注意一些事项：

- 使用哪种类型的并行编程模型

- 问题分区

- 负载均衡

- 通信技术

- 数据依存关系

- 同步和竞争条件

- 内存问题

- IO 问题

- 程序复杂度

- 工作量/工作时间

有兴趣的话可以参考 [并行计算简介](https://computing.llnl.gov/tutorials/parallel_comp) 快速了解。

如果进程 1 和进程 2 可以实时互换、交错或重叠，那么他们就可以使用多线程进行处理。

![two_process](https://computing.llnl.gov/tutorials/pthreads/images/concurrent.gif)

总得来说，具有一些特征的程序比较适合多线程：

- 需要同时执行多个任务

- 可能存在很长的 IO 等待

- 某些地方使用 CPU 较多，但其他地方使用 CPU 较少

- 必须要响应异步事件

- 存在优先级（一些工作比其他工作重要）

常见的几种多线程模型：

- Manager/worker: 一个线程，Manager 将工作分配给其他线程，也就是工人。一般包含两种形式的 manager/worker 模型：静态 worker 池和动态 worker 池。

- Pipeline：任务被分成一系列子操作，每个子操作都由一个不同的线程串行处理，但同时进行。

- Peer：与 manager/worker 模型类似，但是在主线程创建其他线程后，主线程也参与到了工作中。

#### 共享内存模型

所有线程都可以访问相同的共享内存

线程也有自己的私有数据

Programer 负责同步访问（保护）全局共享数据。

![shared_mem](https://computing.llnl.gov/tutorials/pthreads/images/sharedMemoryModel.gif)

#### 线程安全

线程安全简而言之就是同时执行多个线程而不会破环共享数据或创建竞争条件的能力，比如创建了多个线程，每个线程都调用一个公共的库：

- 公共库中的函数会访问或修改内存中的全局结构或位置

- 由于每个线程调用公共库中的函数时可能会同时修改全局结构体或内存的数据。

- 如果调用过程没有同步一下调用顺序来避免冲突，那就是不安全的。

![thread_safe](https://computing.llnl.gov/tutorials/pthreads/images/threadUnsafe.gif)

外部库对用户的影响是：如果你不是百分百确定是线程安全的，那么你肯定能遇到线程安全问题，如果不能保证应用程序是线程安全的，就假设他们是线程不安全的，然后通过相关手段保证应用程序是线程安全的。

#### 线程限制

尽管 Pthread 是 ANSI/IEEE 标准，但是它的实现通常是以非标准话的形式，因此一个平台上运行良好的程序可能在两一个平台上无法运行。

设计程序时要考虑两个重要的限制是允许最大线程数和默认的线程堆栈大小。

## Pthreads API

Pthreads API 可以分为四个组：

1. 线程管理
2. 互斥体
3. 条件变量
4. 同步

命名约定都是以 `pthread_` 开头，一些示例：

| 前缀               | 功能               |
| :----------------- | ------------------ |
| pthread_           | 线程本身和其他线程 |
| pthread_attr_      | 线程属性           |
| pthread_mutex_     | 互斥体             |
| pthread_mutexattr_ | 互斥对象属性       |
| pthread_cond_      | 条件变量           |
| pthread_condattr_  | 条件变量属性       |
| pthread_key_       | 特定于线程的数据键 |
| pthread_rwlock_    | 读写锁             |
| pthread_barrier_   | 栅栏同步           |



## 线程管理

### 创建线程

创建线程使用到的 api 有：

```C
pthread_craete(thread, attr, start_routine, arg)
pthread_exit(status)
pthraed_cancle(thread)
pthread_attr_init(attr)
pthread_attr_destroy(attr)
```

程序中的 main 函数包含一个默认线程，其他所有线程必须手动创建。`pthread_create` 创建一个新线程并执行，可以多次调用来创建多个线程，他的参数：

- thread：子线程返回的唯一标识符
- attr：用于设置线程属性，可以指定线程属性对象或者指定为NULL
- start_routine: 创建线程后执行的函数
- arg：传递给 `start_routine` 的参数，必须以 `void *` 类型的指针传递进去，如果不传任何参数可以使用 NULL

进程可以创建线程的最大数量取决于系统配置，Linux 查询和显示系统限制的方法如下：

```
╭─jqy@DESKTOP-JSHG4MO ~/githubs/Tests/vim ‹master›  [20-12-07 15:53]
╰─$ ulimit -a
-t: cpu time (seconds)              unlimited
-f: file size (blocks)              unlimited
-d: data seg size (kbytes)          unlimited
-s: stack size (kbytes)             8192
-c: core file size (blocks)         0
-m: resident set size (kbytes)      unlimited
-u: processes                       50805
-n: file descriptors                1024
-l: locked-in-memory size (kbytes)  64
-v: address space (kbytes)          unlimited
-x: file locks                      unlimited
-i: pending signals                 50805
-q: bytes in POSIX msg queues       819200
-e: max nice                        0
-r: max rt priority                 0
-N 15:                              unlimited
```

线程一旦创建，线程间的关系就是平等的，而且线程也可以创建其他线程，线程之前没有隐含的层次结构或依赖性

![](https://computing.llnl.gov/tutorials/pthreads/images/peerThreads.gif)



### 线程属性

默认情况下，创建具有某些属性的线程后，可以通过线程属性对象更新其中的一些属性。

`pthread_attr_init` 和 `pthread_attr_destroy` 用于初始化或销毁属性对象。

线程属性中可查询/设置的特定属性包括：

- Detached or joinable state
- Scheduling inheritance
- Scheduling policy
- Scheduling parameters
- Scheduling contention scope
- Stack size
- Stack address
- Stack guard (overflow) size

### 线程绑定和调度

Pthreads API 提供了一些例程，用于指定如何有计划地执行线程，例如，可以将线程设置为 FIFO（先进先出），RR（循环）或 OTHRE（操作系统决定），另外还提供了设置线程的调度优先级的功能。可以参考 [`sched_setscheduler`](https://computing.llnl.gov/tutorials/pthreads/man/sched_setscheduler.txt) 了解有关 Linux 下事物工作方法。

Pthrads API 不提供绑定线程到指定 cpu 的功能，但是本地实现包含这个功能，例如[`pthread_setaffinity_np`](https://computing.llnl.gov/tutorials/pthreads/man/pthread_setaffinity_np.txt) 例程，这里的 `_np` 代表 `非便携式`。

本地操作系统可以提供一套执行此操作的方法，例如 Linux 提供了[`sched_setaffinity`](https://computing.llnl.gov/tutorials/pthreads/man/sched_setaffinity.txt) 例程

### 终止线程 pthread_exit()

有几种线程的终止方法：

- 线程通常从其启动的程序中返回
- 线程调用 `pthread_exit` 终止，无论线程工作是否完成
- 该线程被另一个线程通过 `pthread_cancel` 取消
- 整个程序调用 `exec()` 或 `exit()` 终止
- 如果 `main()` 先结束，无需显示调用 `pthread_exit` 线程也会结束

pthread_exit() 允许指定一个可选的终止 status 参数，正常执行完成的子线程中，通常可以省略调用 pthread_exit() 方法，除非你想返回一个可选的状态码。

清理：pthread_exit() 不会关闭文件，线程终止后，在线程内打开的文件保持打开状态。

main 函数调用 pthread_ext()：

- 如果 main 在没有调用 pthread_exit() 的情况下在其产生的线程之前完成，那么就会存在问题，它创建的所有线程都会终止，因为 main 已经完成，并且不再支持线程

- 通过让 main 显式调用 pthread_exit()，main 将被阻塞并保持活动状态以支持它创建的线程，直到子线程全部完成。

Pthread 创建和终止线程的示例代码：

```c
 #include <pthread.h>
 #include <stdio.h>
 #define NUM_THREADS     5

 void *PrintHello(void *threadid)
 {
    long tid;
    tid = (long)threadid;
    printf("Hello World! It's me, thread #%ld!\n", tid);
    pthread_exit(NULL);
 }

 int main (int argc, char *argv[])
 {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    for(t=0; t<NUM_THREADS; t++){
       printf("In main: creating thread %ld\n", t);
       rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
       if (rc){
          printf("ERROR; return code from pthread_create() is %d\n", rc);
          exit(-1);
       }
    }

    /* Last thing that main() should do */
    pthread_exit(NULL);
 }
```

输出内容如下：

```
In main: creating thread 0
In main: creating thread 1
Hello World! It's me, thread #0!
In main: creating thread 2
Hello World! It's me, thread #1!
Hello World! It's me, thread #2!
In main: creating thread 3
In main: creating thread 4
Hello World! It's me, thread #3!
Hello World! It's me, thread #4!
```

### 给线程传递参数

pthread_create() 允许用户传递一个参数给要启动的线程，对于需要传递多个参数的情况，通过创建一个包含所有参数的结构体，然后将该结构体的指针传递过去即可。需要注意的是：**所有参数必须通过引用并转换为(void *)**

线程参数传递示例程序：

传递一个参数：

```c
long taskids[NUM_THREADS];

for(t=0; t<NUM_THREADS; t++)
{
   taskids[t] = t;
   printf("Creating thread %ld\n", t);
   rc = pthread_create(&threads[t], NULL, PrintHello, (void *) taskids[t]);
   ...
}
```

传递多个参数：

```c
struct thread_data{
   int  thread_id;
   int  sum;
   char *message;
};

struct thread_data thread_data_array[NUM_THREADS];

void *PrintHello(void *threadarg)
{
   struct thread_data *my_data;
   ...
   my_data = (struct thread_data *) threadarg;
   taskid = my_data->thread_id;
   sum = my_data->sum;
   hello_msg = my_data->message;
   ...
}

int main (int argc, char *argv[])
{
   ...
   thread_data_array[t].thread_id = t;
   thread_data_array[t].sum = sum;
   thread_data_array[t].message = messages[t];
   rc = pthread_create(&threads[t], NULL, PrintHello, 
        (void *) &thread_data_array[t]);
   ...
}
```

### join 和 detaching 线程

方法：

```c
pthread_join (threadid,status)
pthread_detach (threadid)
pthread_attr_setdetachstate (attr,detachstate)
pthread_attr_getdetachstate (attr,detachstate)
```

#### Joining

"Joining" 是一种完成两个线程同步的方式，比如：

![join](https://computing.llnl.gov/tutorials/pthreads/images/joining.gif)

- pthread_join() 会阻塞主线程，直到指定线程终止后才程序才继续往下执行。

- 如果通过 pthread_exit() 指定了子线程的返回状态，那么就可以通过 pthrea_join 获取该状态

- 一个线程匹配一个对应的 pthread_join 调用，在一个线程上进行多个 join 是逻辑上的错误。

- 还有两个同步的方法：mutexes 和 条件变量

怎么判断是否可以 join 呢？

线程创建后，它的一个属性决定了它能否被 join，如果一个线程被创建为 detached，那么它就不能被 join。

POSIX 标准指定线程应该被创建为 joinable

为了创建一个 joinable 或者 detached 的线程，pthread_create() 中 attr 这个参数需要使用到，通常有一下 4 个步骤：

1. 声明一个 pthread_attr_t 类型的数据

2. 使用 pthread_attr_init() 初始化这个值

3. 使用 pthread_attr_setdetachstate() 设置 detached 状态

4. 一切做完后，使用 pthread_attr_destroy() 清理使用到的资源

#### Detaching

使用 pthread_detach() 可以 detach 一个指定的线程，即使这个线程被创建为 joinable。

如果线程需要 join，最好显示创建为 joinable，可以提高可移植性，因为默认情况下并非所有实现都可以将线程创建为 joinable的。

另外如果实现知道某个线程永远不会 join 到另一个线程，那么最好在创建时就创建为 detached，某些系统资源就可以被及时释放。

join 的示例程序：

```c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUM_THREADS	4

void *BusyWork(void *t)
{
int i;
long tid;
double result=0.0;
tid = (long)t;
printf("Thread %ld starting...\n",tid);
for (i=0; i<1000000; i++)
{
    result = result + sin(i) * tan(i);
}
printf("Thread %ld done. Result = %e\n",tid, result);
pthread_exit((void*) t);
}

int main (int argc, char *argv[])
{
pthread_t thread[NUM_THREADS];
pthread_attr_t attr;
int rc;
long t;
void *status;

/* Initialize and set thread detached attribute */
pthread_attr_init(&attr);
pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

for(t=0; t<NUM_THREADS; t++) {
    printf("Main: creating thread %ld\n", t);
    rc = pthread_create(&thread[t], &attr, BusyWork, (void *)t);  
    if (rc) {
        printf("ERROR; return code from pthread_create() is %d\n", rc);
        exit(-1);
        }
    }

/* Free attribute and wait for the other threads */
pthread_attr_destroy(&attr);
for(t=0; t<NUM_THREADS; t++) {
    rc = pthread_join(thread[t], &status);
    if (rc) {
        printf("ERROR; return code from pthread_join() is %d\n", rc);
        exit(-1);
        }
    printf("Main: completed join with thread %ld having a status   
            of %ld\n",t,(long)status);
    }

printf("Main: program completed. Exiting.\n");
pthread_exit(NULL);
}
```

程序输出：

```
Main: creating thread 0
Main: creating thread 1
Thread 0 starting...
Main: creating thread 2
Thread 1 starting...
Main: creating thread 3
Thread 2 starting...
Thread 3 starting...
Thread 1 done. Result = -3.153838e+06
Thread 0 done. Result = -3.153838e+06
Main: completed join with thread 0 having a status of 0
Main: completed join with thread 1 having a status of 1
Thread 3 done. Result = -3.153838e+06
Thread 2 done. Result = -3.153838e+06
Main: completed join with thread 2 having a status of 2
Main: completed join with thread 3 having a status of 3
Main: program completed. Exiting.
```

### 线程堆栈管理

接口程序有：

```C
pthread_attr_getstacksize(attr, stacksize)
pthread_attr_setstacksize(attr, stacksize)
pthread_attr_getstackaddr(attr, stackaddr)
pthread_attr_setstackaddr(attr, stackaddr)
```

- POSIX 标准不规定线程堆栈的大小，具体大小取决于不同的实现方式。

- 很容易做到超过默认堆栈限制，通常的结果是：程序终止和/或数据损坏

- 安全和可移植的程序不依赖于默认的堆栈限制，而是使用 pthread_attr_setstacksize 接口为每个线程显式分配足够的堆栈。

- 在必须将线程的堆栈放置在内存的某些特定区域的环境中时，应用程序可以使用 pthread_attr_getstackaddr 和 pthread_attr_setstackaddr 接口实现。

### 一些实际的例子

- 默认线程堆栈大小变化很大。可获得的最大值也相差很大，并且可能取决于每个节点的线程数。

- 过去和现在的硬件架构都显示了默认线程堆栈大小的波动很大。

|Node Architecture|	#CPUs| Memory (GB)| Default Size (bytes)|
|:--:|:--:|:--:|:--:|
|Intel Xeon E5-2670	| 16	| 32	| 2,097,152
|Intel Xeon 5660	| 12	| 24	| 2,097,152
|AMD Opteron	    | 8	    | 16	| 2,097,152
|Intel IA64	        | 4     | 8     |33,554,432
|Intel IA32	        | 2	    | 4	    | 2,097,152
|IBM Power5	        | 8	    | 32	| 196,608
|IBM Power4	        | 8	    | 16	| 196,608
|IBM Power3	        | 16    | 16	| 98,304


本示例演示如何查询和设置线程的堆栈大小。 

```c
 #include <pthread.h>
 #include <stdio.h>
 #define NTHREADS 4
 #define N 1000
 #define MEGEXTRA 1000000
 
 pthread_attr_t attr;
 
 void *dowork(void *threadid)
 {
    double A[N][N];
    int i,j;
    long tid;
    size_t mystacksize;

    tid = (long)threadid;
    pthread_attr_getstacksize (&attr, &mystacksize);
    printf("Thread %ld: stack size = %li bytes \n", tid, mystacksize);
    for (i=0; i<N; i++)
      for (j=0; j<N; j++)
       A[i][j] = ((i*j)/3.452) + (N-i);
    pthread_exit(NULL);
 }
 
 int main(int argc, char *argv[])
 {
    pthread_t threads[NTHREADS];
    size_t stacksize;
    int rc;
    long t;
 
    pthread_attr_init(&attr);
    pthread_attr_getstacksize (&attr, &stacksize);
    printf("Default stack size = %li\n", stacksize);
    stacksize = sizeof(double)*N*N+MEGEXTRA;
    printf("Amount of stack needed per thread = %li\n",stacksize);
    pthread_attr_setstacksize (&attr, stacksize);
    printf("Creating threads with stack size = %li bytes\n",stacksize);
    for(t=0; t<NTHREADS; t++){
       rc = pthread_create(&threads[t], &attr, dowork, (void *)t);
       if (rc){
          printf("ERROR; return code from pthread_create() is %d\n", rc);
          exit(-1);
       }
    }
    printf("Created %ld threads.\n", t);
    pthread_exit(NULL);
 }
```

### 其他各种接口

```c
pthread_self()
pthread_equal(thread1,thread2)
```

- pthread_self 返回线程自身ID。

- pthread_equal 比较两个线程 ID， 如果两个线程 ID 不同返回0，否则返回其他非零值。请注意，对于这两个例程，线程标识符对象都是不透明的，因此不容易检查。因为线程ID是不透明的对象，所以不应使用C语言等效运算符==来将两个线程ID相互比较，或将一个线程ID与另一个值进行比较

```c
pthread_once (once_control, init_routine)
```

- pthread_once在一个进程中仅执行一次init_routine。进程中的任何线程对该接口的第一次调用都会执行给定的 init_routine，而不带参数。任何后续调用均无效。

- init_routine 例程通常是一个初始化例程。

- Once_control参数是一个同步控制结构，需要在调用pthread_once之前进行初始化。例如：

    ```c
    pthread_once_t once_control = PTHREAD_ONCE_INIT;
    ```

## Mutex Variables 互斥变量

### 简介

- "Mutex" 是 "mutual exclusion" 的缩写，互斥变量是实现线程同步和在发生多次写操作时保护共享数据的主要方法之一。

- 互斥变量就像“锁”一样，保护对共享数据资源的访问。 Pthreads中使用的互斥锁的基本概念是，在任何给定时间，只有一个线程可以锁定（或拥有）互斥锁变量。因此，即使多个线程尝试锁定互斥锁，也只有一个线程会成功。在拥有线程解锁该互斥锁之前，没有其他线程可以拥有该互斥锁。线程必须“轮流”访问受保护的数据。

- 互斥体可用于防止“竞争”情况，涉及银行交易的竞争条件示例如下所示：

| Thread 1 | Thread2 | Balance |
|:-:|:-:|:-:|
| Read balance: $1000 |             | $1000 |
|  | Read balance: $1000            | $1000 |
|  | 	Deposit $200                | $1000 |
| 	Deposit $200 |                  | $1000 |
| 	Update balance $1000+$200 |     | $1200 |
| | 	Update balance $1000+$200   | $1200 |

- 在上面的示例中，当线程正在使用此共享数据资源时，应该使用互斥锁来锁定“平衡”。

- 通常，拥有互斥量的线程执行的操作是更新全局变量。这是一种安全的方法，可确保当多个线程更新同一变量时，最终值与只有一个线程执行更新时的最终值相同。被更新的变量属于“关键部分”。

使用互斥锁的典型顺序如下:

1. 创建并初始化互斥量变量

2. 多个线程试图锁定互斥锁

3. 只有一个线程成功锁定拥有互斥变量操作权

4. 拥有锁的线程执行一些操作

5. 拥有锁的线程解锁

6. 另一个线程获取互斥锁并重复该过程

7. 最终互斥体被销毁

- 当多个线程竞争一个互斥锁时，竞争失败者将在该调用时阻塞 - 通过 "trylock" 而不是 "lock" 调用可以进行无阻塞调用。

- 保护共享数据时，程序员有责任确保每个需要使用互斥锁的线程都这样做。例如，如果4个线程正在更新相同的数据，但是只有一个线程使用互斥锁，则数据仍可能被破坏。

### 创建和销毁互斥对象

```c

pthread_mutex_init(mutex,attr)
pthread_mutex_destroy(mutex)
pthread_mutexattr_init(attr)
pthread_mutexattr_destroy(attr)
```

- 用法：

- 互斥变量必须使用pthread_mutex_t类型声明，并且必须先初始化才能使用。有两种初始化互斥量变量的方法：

    1. 静态声明，例如：

        ```c
        pthread_mutex_t mymutex = PTHREAD_MUTEX_INITIALIZER;
        ```

    2. 使用 pthread_mutex_init() 动态生成，此方法允许设置互斥对象属性attr。

    互斥锁初始状态处于解锁状态。

- attr对象用于建立互斥对象的属性，并且必须使用pthread_mutexattr_t类型（如果使用）（可以将其指定为NULL以接受默认值）。Pthreads标准定义了三个可选的互斥属性：

    1. Procotol: 指定用于防止互斥量优先级倒置的协议。

    2. Prioceiling: 指定互斥锁的优先级上限。

    3. Process-shared: 指定互斥量的进程共享。

    请注意，并非所有实现都可以提供三个可选的互斥属性。

- pthread_mutexattr_init() 和 pthread_mutexattr_destroy() 例程分别用于创建和销毁互斥体属性对象。

- 应该使用 pthread_mutex_destroy() 释放不再需要的互斥对象。

### 锁定和解锁互斥锁

```c
pthread_mutex_lock (mutex)
pthread_mutex_trylock (mutex)
pthread_mutex_unlock (mutex)
```

- 线程使用 pthread_mutex_lock() 获取对指定互斥锁变量的锁定。如果互斥锁已经被另一个线程锁定，则此调用将阻塞调用线程，直到互斥锁被解锁为止。

- pthread_mutex_trylock() 将尝试锁定互斥锁。如果互斥锁已被锁定，则例程将立即返回“忙”错误代码。如在优先级倒置的情况下，此例程可能对防止死锁情况很有用。

- 如果由拥有线程调用，则 pthread_mutex_unlock() 将解锁互斥锁。如果其他线程要获取互斥量以使用受保护的数据，则在线程完成其对受保护数据的使用之后需要调用此例程。如果出现以下情况，将返回错误：

    1. 如果互斥锁已被解锁

    2. 如果互斥锁由另一个线程拥有

- 互斥锁没有什么 "magic" ……实际上，它们类似于参与线程之间的 "gentlemen's agreement"。由代码编写者来确保所有必要的线程都能正确地进行互斥锁和解锁调用。下面的情况演示了一个逻辑错误：

    ```
    Thread 1     Thread 2     Thread 3
    Lock         Lock         
    A = 2        A = A+1      A = A*B
    Unlock       Unlock  
    ```

### 例子程序

该示例程序说明了在执行点积的线程程序中互斥变量的使用。通过全局可访问的结构，主数据可用于所有线程。每个线程在数据的不同部分上工作。主线程等待所有线程完成计算，然后输出结果总和.

## 条件变量

- 条件变量为线程提供了另一种同步方式。互斥锁通过控制线程对数据的访问来实现同步时，条件变量允许线程根据数据的实际值进行同步。

- 没有条件变量，程序员将需要使线程连续轮询（可能在关键部分），以检查是否满足条件。 这可能会非常消耗资源，因为线程将在此活动中持续忙碌。条件变量是一种无需轮询即可实现相同目标的方法。

- 条件变量始终与互斥锁一起使用。

- 下面显示一种使用条件变量的典型序列：

    主线程：

    - 声明并初始化需要同步的全局数据/变量（例如“ count”）

    - 声明并初始化条件变量对象

    - 声明并初始化关联的互斥锁

    - 创建线程A和B进行工作

    线程 A：

    - 执行程序到一定的条件（例如“ count”必须达到指定值）后终止

    - 锁定关联的互斥锁并检查全局变量的值

    - 调用pthread_cond_wait() 来执行阻塞等待，以等待来自线程B的信号。请注意，对pthread_cond_wait() 的调用会自动原子地解锁相关的互斥变量，以便Thread-B可以使用它。

    - 收到信号后，被唤醒。互斥锁是自动和原子锁定的。

    - 显式解锁互斥锁

    - 继续执行程序

    线程 B ：

    - 执行线程程序

    - 锁定关联的互斥锁

    - 更改线程A正在等待的全局变量的值。

    - 检查全局Thread-A等待变量的值。如果满足所需条件，则向Thread-A发出信号。

    - 接触互斥锁

    - 继续执行程序

### 创建和销毁条件变量

```c
pthread_cond_init(condition,attr)
pthread_cond_destroy(condition)
pthread_condattr_init(attr)
pthread_condattr_destroy(attr)
```

- 用法：

    - 条件变量必须使用 pthread_cond_t 类型声明，并且必须先进行初始化，然后才能使用它们。有两种方法可以初始化条件变量：

        1. 静态声明：

            ```c
            pthread_cond_t myconvar = PTHREAD_COND_INITIALIZER;
            ```

        2. 使用 pthread_cond_init() 动态创建，通过条件参数将创建的条件变量的ID返回给调用线程。此方法允许设置条件变量对象属性attr。

    - 可选的 attr 对象用于设置条件变量属性。仅为条件变量定义了一个属性：进程共享，它允许条件变量被其他进程中的线程查看。属性对象（如果使用）必须为 pthread_condattr_t 类型（可以指定为NULL以接受默认值）。

        注意，并非所有实现都可以提供进程共享属性。

    - pthread_condattr_init() 和 pthread_condattr_destroy() 例程用于创建和销毁条件变量属性对象。

    - 应该使用pthread_cond_destroy() 释放不再需要的条件变量。

### 等待和发信号通知条件变量

```c
pthread_cond_wait(condition,mutex)
pthread_cond_signal(condition)
pthread_cond_broadcast(condition)
```

- pthread_cond_wait() 阻塞调用线程，等待指定条件的信号到来。该例程应在互斥锁被锁定时调用，并且它将在等待时自动释放互斥锁。接收到信号并唤醒线程后，互斥体将自动锁定以供线程使用。线程完成后，程序员负责解锁互斥锁。

    **建议：** 使用WHILE循环而不是IF语句（请参见下面的示例中的watch_count例程）来检查等待的条件，可以帮助解决一些潜在的问题，例如：

    1. 如果多个线程正在等待相同的唤醒信号，则它们将轮流获取互斥对象，然后它们中的任何一个都可以修改它们都等待的条件。

    1. 如果线程由于程序错误而收到错误的信号

    1. 允许Pthreads库在不违反标准的情况下向等待的线程发出虚假唤醒。

- pthread_cond_signal() 例程用于发信号（或唤醒）另一个正在等待条件变量的线程。它应该在互斥锁锁定后调用，并且必须解锁互斥锁才能完成pthread_cond_wait() 例程。

- 如果有多个线程处于阻塞等待状态，则应使用pthread_cond_broadcast() 例程而不是pthread_cond_signal() 。

- 在调用pthread_cond_wait() 之前先调用pthread_cond_signal() 是逻辑错误。

使用这些例程时，正确锁定和解锁相关的互斥变量至关重要。例如：

1. 在调用pthread_cond_wait() 之前未锁定互斥锁可能导致其未阻塞。

1. 调用pthread_cond_signal() 后未能解锁互斥锁可能无法完成匹配的pthread_cond_wait() 例程（它将保持阻塞状态）。

例子：

这个简单的示例代码演示了几个Pthread条件变量例程的用法。主例程创建三个线程。其中两个线程执行工作并更新“ count”变量。第三个线程等待，直到count变量达到指定值。

```c
 #include <pthread.h>
 #include <stdio.h>
 #include <stdlib.h>

 #define NUM_THREADS  3
 #define TCOUNT 10
 #define COUNT_LIMIT 12

 int     count = 0;
 int     thread_ids[3] = {0,1,2};
 pthread_mutex_t count_mutex;
 pthread_cond_t count_threshold_cv;

 void *inc_count(void *t) 
 {
   int i;
   long my_id = (long)t;

   for (i=0; i<TCOUNT; i++) {
     pthread_mutex_lock(&count_mutex);
     count++;

     /* 
     Check the value of count and signal waiting thread when condition is
     reached.  Note that this occurs while mutex is locked. 
     */
     if (count == COUNT_LIMIT) {
       pthread_cond_signal(&count_threshold_cv);
       printf("inc_count(): thread %ld, count = %d  Threshold reached.\n", 
              my_id, count);
       }
     printf("inc_count(): thread %ld, count = %d, unlocking mutex\n", 
	    my_id, count);
     pthread_mutex_unlock(&count_mutex);

     /* Do some "work" so threads can alternate on mutex lock */
     sleep(1);
     }
   pthread_exit(NULL);
 }

 void *watch_count(void *t) 
 {
   long my_id = (long)t;

   printf("Starting watch_count(): thread %ld\n", my_id);

   /*
   Lock mutex and wait for signal.  Note that the pthread_cond_wait 
   routine will automatically and atomically unlock mutex while it waits. 
   Also, note that if COUNT_LIMIT is reached before this routine is run by
   the waiting thread, the loop will be skipped to prevent pthread_cond_wait
   from never returning. 
   */
   pthread_mutex_lock(&count_mutex);
   while (count<COUNT_LIMIT) {
     pthread_cond_wait(&count_threshold_cv, &count_mutex);
     printf("watch_count(): thread %ld Condition signal received.\n", my_id);
     }
     count += 125;
     printf("watch_count(): thread %ld count now = %d.\n", my_id, count);
   pthread_mutex_unlock(&count_mutex);
   pthread_exit(NULL);
 }

 int main (int argc, char *argv[])
 {
   int i, rc;
   long t1=1, t2=2, t3=3;
   pthread_t threads[3];
   pthread_attr_t attr;

   /* Initialize mutex and condition variable objects */
   pthread_mutex_init(&count_mutex, NULL);
   pthread_cond_init (&count_threshold_cv, NULL);

   /* For portability, explicitly create threads in a joinable state */
   pthread_attr_init(&attr);
   pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
   pthread_create(&threads[0], &attr, watch_count, (void *)t1);
   pthread_create(&threads[1], &attr, inc_count, (void *)t2);
   pthread_create(&threads[2], &attr, inc_count, (void *)t3);

   /* Wait for all threads to complete */
   for (i=0; i<NUM_THREADS; i++) {
     pthread_join(threads[i], NULL);
   }
   printf ("Main(): Waited on %d  threads. Done.\n", NUM_THREADS);

   /* Clean up and exit */
   pthread_attr_destroy(&attr);
   pthread_mutex_destroy(&count_mutex);
   pthread_cond_destroy(&count_threshold_cv);
   pthread_exit(NULL);
 } 
```

参考链接：

[POSIX Threads Programming](https://computing.llnl.gov/tutorials/pthreads/)