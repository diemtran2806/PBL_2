#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <windows.h>
#include "list_account.h"
#include "list.h"
#include "member.h"
using namespace std;
#define STD_OUTPUT_HANDLE ((DWORD)-11)

void del_ws(string &s);                                       //Ham xoa ki tu trang du thua
bool ascending(const member &m1, const member &m2, int key);  //tang dan
bool descending(const member &m1, const member &m2, int key); //giam dan
bool checkFile(string path);                                  //check file path có tồn tại ko?

int cursor = 0;

birthday SystemDate();
int monthStrToInt(string a);
birthday dateNow;            //lấy thời gian hiện tại

//color
void SET_COLOR(int color);

//giao dien
void gotoxy(short x, short y);
int columns, rows;
void getCol();
int uiFunSize = 52;
int uiDisplaySize = 79;
int l_uiFuns = columns / 2 - uiFunSize;
int l_uiDisplay = columns / 2 - uiDisplaySize;
//display
void uiDisplay(int n);
//delete
void uiFunc(int n);

string tk, mk;
int test = 0, d;
void login();

list_account acc;

#endif