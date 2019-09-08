/*
先頭の再帰の除去には、
・nの値を一時的に保存する
・保存していたnを取り出して、その値を表示する
という処理が必要
*/
#include <stdio.h>
#include "IntStack.h"

void recur(int n)
{
  IntStack stk; /* スタック */
  Initialize(&stk, 100);
Top:
  if (n > 0) {
    recur(n - 1);
    printf("%d\n", n);
    n = n - 2;
    goto Top;
  }

  if (!IsEmpty(&stk)) {
    Pop(&stk, &n);
    printf("%d\n", n);
    n = n - 2;
    goto Top;
  }
  Terminate(&stk);
}

int main(void)
{
  int x;
  printf("整数を入力せよ：");
  scanf("%d", &x);
  recur(x);
  return 0;
}