/* 好きな個数だけ値を読み込んで要素数Nの配列に最後のN個を格納 */
#include <stdio.h>

#define N  10

int main(void)
{
  int i;
  int a[N];   /* 読み込んだ値を格納 */
  int cnt = 0;/* 読み込んだ個数 */
  int retry;  /* もう一度？ */

  puts("整数を入力してください。");

  do {
    printf("%d個目の整数：", cnt + 1);
    scanf("%d", &a[cnt++ % N]);/* 計算してからインクリメント */

    printf("続けますか？（Yes…1／No…0）：");
    scanf("%d", &retry);
  } while (retry == 1);
  i = cnt - N;
  if (i < 0) i = 0;
  for ( ; i < cnt; i++)
    printf("%2d個目の整数 = %d\n", i + 1, a[i % N]);
  return 0;
}