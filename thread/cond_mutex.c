//
// Created by ctracerpp on 2022-10-21.
//

#include <stdio.h>

int main(int argc, char** argv)
{
    // 条件变量必须配合锁使用
    // 条件变量的作用是当条件不满足时，线程阻塞，当条件满足时，线程解除阻塞
    printf("cond_mutex");
    return 0;
}