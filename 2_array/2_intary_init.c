/* 配列の要素数と各要素の値を表示 */
# include <stdio.h>

int main(void)
{
  int i;
  int a[5] = {1, 2, 3, 4, 5};
  int na = sizeof(a) / sizeof(a[0]);/* 配列全体のサイズ / 要素一つのサイズ で個数を求める。公式として覚える */
  printf("配列aの要素数は%dです。\n", na);
  for (i = 0; i < na; i++)
    printf("a[%d] = %d\n", i, a[i]);
  return 0;
}

/*
sizeof(a) / sizeof(int)
としてはいけない！　要素型が変更されるとコードを変えないといけなくなるため
*/