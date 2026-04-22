# Problem 107 - 小恶魔的单循环链表

**ACMOJ Problem ID**: 1058

## Table of Contents

- [Problem 107 - 小恶魔的单循环链表](#problem-107-小恶魔的单循环链表)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
    - [Background](#background)
  - [Assignment Description](#assignment-description)
    - [Grade Composition](#grade-composition)
  - [Assignment Requirements](#assignment-requirements)
    - [Input Format](#input-format)
    - [Output Format](#output-format)
    - [Samples](#samples)
    - [Data Constraints](#data-constraints)
  - [Per-Testcase Resource Limits](#per-testcase-resource-limits)
  - [Test Data](#test-data)
  - [Submission Requirements](#submission-requirements)
    - [OJ Git Repository Compilation Process](#oj-git-repository-compilation-process)
    - [Git Configuration Requirements](#git-configuration-requirements)
    - [Submission Guidelines](#submission-guidelines)
    - [Evaluation Notes](#evaluation-notes)
    - [Academic Integrity](#academic-integrity)

## Introduction

### Background

This problem tests algorithmic problem-solving skills.

## Assignment Description

### Grade Composition

| Grading Component | Percentage |
| :--: | :--: |
| Pass **1058. 小恶魔的单循环链表** | 80% |
| Code Review | 20% |

Here are several points that need clarification:

- In the Code Review, we will **strictly examine your code style and repository organization structure, etc.**

- This assignment provides some sample data for testing, stored in the `/workspace/data/107/data_test/` directory. Note that these are not the test cases on the Online Judge. Passing all local test cases does not guarantee that you will pass the OJ tests.

- Besides the provided sample data, we also encourage you to design your own test data based on your program logic to assist debugging.

## Assignment Requirements

### Problem Description

助教是个小恶魔，她不知道要出什么机考题，然后她发现大家已经学完了指针和结构体，欣喜若狂。她想让你写一个单循环链表，即最后一个结点的下一个结点是头结点的单链表。你需要实现以下六种操作，分别标号为操作0~5：（注意这里的$i$都为**0-base**）

+ 0 返回链表长度；
+ 1 在位置$i$插入一个数。注意这里是指插入的数在插入后处于位置$i$，即插入在现在位置$i$数字的前面；
+ 2 输出位置$i$的数。如果$i$超出链表长度，请输出-1；
+ 3 删除位置$i$的数，整个链表长度减1；
+ 4 删除位置$i$的数并将它插入至链表的尾端；
+ 5 输出链表中最大的数。如果表为空请输出-1；

注意：为防止内存泄漏，你需要在程序最后删除整个列表。

### sample.cpp

```c++
#include <iostream>
#include <cstdio>
using namespace std;

namespace LIST
{

    struct NODE {
        // TODO
    };

    NODE *head = nullptr;
    int len = 0;

    void init() {
        // TODO
    }
    NODE* move(int i) {
        // TODO
    }
    void insert(int i, int x) {
        // TODO
    }
    void remove(int i) {
        // TODO
    }
    void remove_insert(int i) {
        //TODO
    }
    void get_length() {
        // TODO
    }
    void query(int i) {
        // TODO
    }
    void get_max() {
        // TODO
    }
    void clear() {
        // TODO
    }

}
int n;
int main()
{
    cin >> n;
    int op, x, p;
    LIST::init();
    for (int _ = 0; _ < n; ++_)
    {
        cin >> op;
        switch(op) {
            case 0:
                LIST::get_length();
                break;
            case 1:
                cin >> p >> x;
                LIST::insert(p,x);
                break;
            case 2:
                cin >> p;
                LIST::query(p);
                break;
            case 3:
                cin >> p;
                LIST::remove(p);
                break;
            case 4:
                cin >> p;
                LIST::remove_insert(p);
                break;
            case 5:
                LIST::get_max();
                break;
        }
    }
    LIST::clear();
    return 0;
}
```

列表的要求如下：

+ 必须使用**指针**和**结构体**；
+ 在单链表中，每个结点由一个数据元素、一个后继指针组成，后继指针指向存储该元素直接后继的结点；
+ 存储一个单链表只需要一个指向头结点的指针；
+ 可以使用单独的变量记录链表长度；
+ **请不要修改给定的部分**；
+ 此题需要你注意提交代码的代码风格，极为糟糕的代码风格（例如改变语法的某些宏定义）会酌情扣分！！！

请严格按照以上要求完成此题。我们会检查你提交的代码。虽然有其他的实现方式，但如果你未按照要求写代码，我们不会给你分数。(比如，你没有使用指针和结构体或在每个结点中记录了要求以外的内容等都会判为0分)。

### Input Format

第一行一个数$n$表示操作数。

之后$n$行，每行第一个数$op(op = 0, 1, ..., 5)$代表操作编号，分别对应前文中的编号。

如果$op$为1，其后会输入两个整数$p$,$x$，表示在$p$位置插入的数值为$x$；

如果$op$为2，其后会输入一个整数$p$，表示你需要输出链表中$p$位置结点的值；

如果$op$为3或4，其后会输入一个整数$p$，表示你需要删除链表中$p$位置的值。

数据保证插入删除操作不会操作无效位置。

### Output Format

对于操作1,3,4你不用输出任何东西；

对于操作0，输出一个整数，表示链表长度；

对于操作2，输出一个整数，表示第$i$个数；

对于操作5，输出一个整数，表示链表中最大的数；

每一个操作输出后要求换行。

### Samples

#### Sample 1

**Input:**
```
12
0
1 0 1
1 0 2
1 2 3
5
4 1
2 1
5
3 0
3 0
5
0
```

**Output:**
```
0
3
3
3
1
1
```

### Data Constraints

$n≤1000$

对于10%的数据，只会涉及0、1操作；

对于20%的数据，只会涉及0、1、2操作；

对于40%的数据，只会设计0、1、2、3操作；

对于60%的数据，只会涉及0、1、2、3、5操作；

对于100%的数据，会涉及所有操作。

保证链表中所有数字为`int`范围内正整数。保证所给部分和所给要求不会产生超时问题。

## Per-Testcase Resource Limits

- **Time Limit (per test case)**: 1000 ms
- **Memory Limit (per test case)**: 256 MiB
- **Disk Usage**: No disk usage is permitted.

## Test Data

The test data for this problem is located at `/workspace/data/107/data_test/`.

## Submission Requirements

### OJ Git Repository Compilation Process

For Git compilation, we will first clone the repository using a command similar to:
```bash
git clone <repo_url> . --depth 1 --recurse-submodules --shallow-submodules --no-local
```

Then we check if there is a `CMakeLists.txt` file. If it exists, we run (if not, a warning message will be displayed):
```bash
cmake .
```

Finally, we check if there is any of `GNUmakefile`/`makefile`/`Makefile` (if cmake was run previously, this will be the generated Makefile). If it exists, we run (if not, a warning message will be displayed):
```bash
make
```

After this process is complete, we will use the `code` file in the project root directory as the compilation result.

A `CMakeLists.txt` file is provided in the project. You can use or modify it as needed. The local environment has gcc-13 and g++-13 available.

### Git Configuration Requirements

**IMPORTANT**: You must create a `.gitignore` file in your project root directory to avoid OJ evaluation conflicts.

The `.gitignore` file should include at least the following entries:

```gitignore
CMakeFiles/
CMakeCache.txt
```

### Submission Guidelines

- The submitted code must be able to compile successfully through the above compilation process
- The compiled executable file name must be `code`
- The program needs to be able to read data from standard input and write results to standard output
- Please ensure the code runs correctly within the given time and space limits
- **You must use C++ or C language** to implement this assignment

### Evaluation Notes

- The evaluation system will test your program using the provided test data
- The program output must exactly match the expected output (including format)
- Exceeding time or memory limits will be judged as the corresponding error type
- Please pay attention to the overall time performance of your code and the time complexity of each part of your algorithm.

### Academic Integrity

If any violations are found during evaluation or code review (including but not limited to using unconventional methods to pass test cases), your final score may be significantly reduced or become **0 points**.
