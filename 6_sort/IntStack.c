/* int型スタックIntStack（ソース部） */
#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

/* スタックの初期化 */
int Initialize(IntStack *s, int max)
{
  s->ptr = 0;  /* 初期化時は要素数0 */
  if ((s->stk = calloc(max, sizeof(int))) == NULL) {/* サイズintで要素数max個のデータ容量を確保し、先頭ポインタをstkに入れる */
    s->max = 0;/* 生成に失敗したら容量0。他の関数が存在しない配列stkにアクセスしないための配慮 */
    return -1;
  }
  s->max = max;
  return 0;
}

/* スタックにデータをプッシュ */
int Push(IntStack *s, int *x)
{
  if (s->ptr >= s->max)
    return -1;
  s->stk[s->ptr++] = x;
  return 0;
}

/* スタックからデータをポップ */
int Pop(IntStack *s, int *x)
{
  if (s->ptr <= 0)/* ptrは「個数」＝「次に入れる位置を表す添字」 */
    return -1;
  *x = s->stk[--s->ptr];/* ポインタ変数に*をつけると、そのポインタが指しているメモリに値を代入できるんだったかな */
  return 0;
}

/* スタックからデータをピーク */
int Peek(const IntStack *s, int *x)
{
  if (s->ptr <= 0)
    return -1;
  *x = s->stk[s->ptr - 1];/* 覗き見るだけだからptrの値（要素数＝次に入れる位置）は変わらない */
  return 0;
}

/* スタックを空にする */
void Clear(IntStack *s)
{
  s->ptr = 0; /* 0にすれば空として扱われる。実際のメモリの解放はTerminateでやるからOK */
}

/* スタックの容量 */
int Capacity(const IntStack *s)
{
  return s->max;
}

/* スタック上のデータ数 */
int Size(const IntStack *s)
{
  return s->ptr;
}

/* スタックは空か */
int IsEmpty(const IntStack *s)
{
  return s->ptr <= 0;/* 0（以下）だったら空ということ */
}

/* スタックは満杯か */
int IsFull(const IntStack *s)
{
  return s->ptr >= s->max;/* maxと同じ（かそれ以上）だったら満杯ということ */
}

/* スタックからの探索 */
int Search(const IntStack *s, int x)
{
  int i;
  for (i = s->ptr - 1; i >= 0; i--)
    if (s->stk[i] == x) /* 先頭から数えて同じ要素が見つかったら */
      return i;/* その位置の添字を返す */
  return -1;
}

/* 全データの表示 */
void Print(const IntStack *s)
{
  int i;
  for (i = 0; i < s->ptr; i++) /* iは先頭＝ptr-1まで */
    printf("%d ", s->str[i]);
  putchar('\n');
}

/* スタックの後始末 */
void Terminate(IntStack *s)
{
  if (s->stk != NULL) /* 解放されてなければ */
    free(s->stk);
  s->max = s->ptr = 0; /* 容量と個数をともに0にする */
}