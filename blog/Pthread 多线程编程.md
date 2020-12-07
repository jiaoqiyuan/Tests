## Pthread 多线程编程

最近突然又接触了 `生产者和消费者` 问题，用到了多线程编程，这里总结一下。

在多处理器体系结构中，线程可用来实现并行性，对于 `Unix` 系统，`IEEE POSIX 1003.1c` 标准已指定了标准化的 C 语言线程编程接口，遵守该标准的实现成为 `POSIX` 线程或 `Pthread`。

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

### 为什么要使用 Pthreads

#### 轻量级

#### 高效

#### 其他原因

### 设计线程程序

#### 并行编程

#### 共享内存模型

#### 线程安全

#### 线程限制

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

有几种线程的种植方法：

- 线程通常从其启动的程序中返回
- 线程调用 `pthread_exit` 终止，无论线程工作是否完成
- 该线程被另一个线程通过 `pthread_cancel` 取消
- 整个程序调用 `exec()` 或 `exit()` 终止
- 如果 `main()` 先结束，无需显示调用 `pthread_exit` 线程也会结束









参考链接：

[POSIX Threads Programming](https://computing.llnl.gov/tutorials/pthreads/)