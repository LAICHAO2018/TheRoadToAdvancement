//
// Created by laichao on 2021/1/9.
//
// 记录一些有意思、实用的小函数

#ifndef __INTERESTING_FUNCTIONS__
#define __INTERESTING_FUNCTIONS__

/// 测量函数执行时间的复用函数
template<typename T>
void measured_function(T &&func) {
    using namespace std::chrono;
    auto start = system_clock::now();                           // 获取当前时间
    func();
    duration<double> diff = system_clock::now() - start;        // 时间差值
    cout << "elapsed " << diff.count() << " seconds" << endl;   // 执行时间
}

// 可变参数模板
template<typename ...T>
void func(T ... args) {
    //sizeof...（sizeof后面有3个小点）计算变参个数
    cout << sizeof...(args) << endl;
}

// 折半查找
template<typename T>
int binarySearch(vector<T> &a, const T &x) {
    int left = 0, right = a.size();
    while (left <= right) {
        int middle = (left + right) / 2;
        if (x == a[middle]) {
            return middle;
        }
        if (x > a[middle]) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return -1;  // 没有找到
}

// 打印一个32(默认)位数的二进制表达形式 (补码)
// 打印数字的真实存储
void dis_to_bin(int data, int i = 32) {
    while (i--) {
        if (data & (1 << i)) printf("1");
        else printf("0");

        if (i % 4 == 0)
            if (i % 8 == 0)
                printf(" ");
            else
                printf("-");
    }
}

#endif
