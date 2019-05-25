/* 階乗値を再帰的に求める */
#include <stdio.h>

/* 整数値nの階乗を返却 */
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
/* 「自分と同じ関数」の呼び出し、と理解する */