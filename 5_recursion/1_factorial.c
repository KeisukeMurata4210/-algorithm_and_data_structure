/*
階乗n!の定義（nは非負の整数とする）
0! = 1
n > 0 ならば n! = n * (n-1)!
*/
#include <stdio.h>

int factorial(int n)
{
  if (n > 0)
    return n * factorial(n - 1);
  else
    return 1;
}

int main(void)
{
  int x;
  printf("整数を入力せよ：");
  scanf("%d", &x);
  printf("%dの階乗は%dです。\n", x, factorial(x));
  return 0;
}
/*
再帰呼び出しは「自分自身の呼び出し」ではなく、
「自分と同じ関数の呼び出し」
と理解する
*/