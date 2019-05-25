/* ユークリッドの互除法によって最大公約数を求める */
#include <stdio.h>

/* 整数値x、yの最大公約数を返却する */
int gcd(int x, int y)
{
  if (y == 0)
    return x;
  else
    return gcd(y, x % y);/* x >= y という前提の元組まれているのか */
}

int main(void)
{
  int x, y;
  puts("二つの整数の最大公約数を求めます。");
  printf("整数を入力せよ：");
  scanf("%d", &x);
  printf("整数を入力せよ：");
  scanf("%d", &y);
  printf("最大公約数は%dです。\n", gcd(x, y));
  return 0;
}