//
// Created by ctracerpp on 2022-10-21.
//

#include <stdio.h>

int main(int argc, char** argv)
{
    // 栅栏的作用是让线程在栅栏处等待，直到所有线程都到达栅栏处，才继续执行
    // 打印程序路径
    printf(argv[0] );
    // 程序被阻塞
    printf(argv[1] );
    printf("\n");
    printf("barrier");
    return 0;
}