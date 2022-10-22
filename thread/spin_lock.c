//
// Created by ctracerpp on 2022-10-21.
//

#include <stdio.h>

int main(int argc, char** argv)
{
    // 自旋等待，一般用于获取锁时间比较短的场景，如果获取锁时间比较长，会导致CPU空转，浪费CPU资源
    // 一般采用先自旋，再休眠的方式，自旋次数越多，休眠时间越长
    // 混合hybrid方式，自旋次数越多，休眠时间越长
    printf("spin_lock");
    return 0;
}