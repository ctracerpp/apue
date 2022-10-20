//
// Created by ctracerpp on 2022-10-20.
//



#include <stdio.h>

int main(int argc, char** argv)
{
    // 打印argv
    for (int i = 0; i < argc; i++)
    {
        printf("argv[%d]: %s \n", i, argv[i]);
    }
    // 打开文件并读取
    // Creating output file
    FILE* file = fopen("myfile.txt", "rw+");
    if (file == NULL)
    {
        printf("Cannot open file!\n");
        return 1;
    }
    // 打印文本内容
    for (char c = fgetc(file); c != EOF; c = fgetc(file)) {
        putchar(c);
    }
    fprintf(file, "Please write this to a file.\n");
    fclose(file);

    return 0;
}
