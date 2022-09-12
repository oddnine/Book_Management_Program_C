#pragma once

typedef struct tagbook book;
struct tagbook
{
    int flag; //도서 존재 유무 0 (X), 1(0)
    int flag1; //도서 의 상태 0 (X), 1(0)
    char name[20]; //제목
    char auth[20]; //저자
    char pub[20]; //출판사
    char classfirst[10]; //분류첫번째
    char classsecond[10]; //분류두번째
    int classnum1; //분류첫번째
    int classnum2; //분류두번째
    int classnum3; //들어온순

    char classpub[4]; //분류 출판사
    char classauth[4]; //분류저자
    char classname[10]; //분류 제목
};