/* 九九の加算と乗算 */
#include <stdio.h>

/* x1とx2の和を求める */
int sum(int x1, int x2)
{
  return x1 + x2;
}

/* x1とx2の積を求める */
int mul(int x1, int x2)
{
  return x1 * x2;
}

/* 九九の表を出力 */
void kuku(int (*calc)(int, int)) /* 面白い！ int型を2つ引数にとってint型を返却する関数へのポインタ */
{
  int i, j;
  for (i = 1; i <= 9; i++) {
    for (j = 1; j <= 9; j++)
      printf("%3d", (*calc)(i, j));/* 変数へのポインタと同じ要領で、引数付きで呼び出した時に実行される */
    putchar('\n');
  }
}

int main(void)
{
  puts("九九の加算表");
  kuku(sum);/* 関数名は、その関数へのポインタ、とみなされる！ */
  puts("\n九九の乗算表");
  kuku(mul);
  return 0;
}

/*
Rubyのダックタイプに似てるな。
「呼び出す関数を実行時に決定する動的な関数呼び出し」という点ではメタプロに似てる。

関数内では「*」と()は省略してもいい
void kuku(int calc(int, int))
{
  int i, j;
  for (i = 1; i <= 9; i++) {
    for (j = 1; j <= 9; j++)
      printf("%3d", calc(i, j));
    putchar('\n');
  }
}
*/