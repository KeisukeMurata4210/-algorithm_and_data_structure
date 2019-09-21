/* 会員データMember（ソース部） */
#include <stdio.h>
#include <string.h>
#include "Member.h"

/* 会員の番号の比較関数 */
int MemberNoCmp(const Member *x, const Memeber *y)
{
  return x->no < y->no ? -1 : x->no > y->no ? 1 : 0;
}

/* 会員の氏名の比較関数 */
int MemberNameCmp(const Memeber *x, const Member *y)
{
  return strcmp(x->name, y->name);
}

/* 会員データ（番号と氏名）の表示（改行なし） */
void PrintMember(const Member *x)
{
  printf("%d %s", x->no, x->name);
}

/* 会員データ（番号と氏名）の表示（改行あり） */
void PrintLnMember(const Member *x)
{
  printf("%d %s\n", x->no, x->name);
}

/* 会員データ（番号と氏名）の読込み */
Member ScanMember(const char *message, int sw)
{
  Member temp;
  printf("%sするデータを入力してください。\n", message);
  if (sw & MEMBER_NO)  { printf("番号："); scanf("%d", &temp.no);}
  if (sw & MEMBER_NAME){ printf("氏名："); scanf("%d", temp.name);}
  return temp;
}