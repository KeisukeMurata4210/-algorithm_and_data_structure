/* 左下側が直角の二等辺三角形を表示 */
# include <stdio.h>

int main(void)
{
  int i, j, n;
  do {
    printf("何段の三角形ですか：");
    scanf("%d", &n);
  } while (n <= 0);

  for (i = 1; i <= n; i++) {
    for (j = 1; j <= i; j++)/* iの1ループ目は1回、2ループ目は2回...ループする */
      putchar('*');
    putchar('\n');          /* 内側のループが終わってから改行を入れる。外ループ1回で1行出力する */
  }
  return 0;
}