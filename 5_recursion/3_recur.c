/* 再帰に対する理解を深めるための真に再帰的な関数 */
#include <stdio.h>

/* 真に再帰的な関数recur */
void recur(int n)
{
  if (n > 0) {
    recur(n - 1);
    printf("%d\n", n);
    recur(n - 2);
  }
}

int main(void)
{
  int x;
  printf("整数を入力せよ：");
  scanf("%d", &x);
  recur(x);
  return 0;
}

/* 実行される順番に、上から下へ枝分かれさせて調べる　トップダウン解析 */