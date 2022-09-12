//control.h
#pragma once

void con_printall();
void con_printall1();
void con_insert();
void con_select();
void con_update();
void con_update1();
void con_update2();
void con_delete();
void con_map();
char menuprint2();
void ex(int idx);
void con_insert0(char temp);
void con_insert1(char temp);
void con_insert2(char temp);
void con_insert3(char temp);
void con_insert4(char temp);
void con_insert5(char temp);
void con_insert6(char temp);
void con_insert7(char temp);
void con_insert8(char temp);
void con_insert9(char temp);
void readlist();
void savelist();


int nametoidx(const char* name); //name -> 배열의 idx 반환
int authtoidx(const char* name);
int pubtoidx(const char* name);
