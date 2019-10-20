/* 度数ソート */
#include <stdio.h>
#include <stdlib.h>

/* 度数ソート（配列要素の値は0以上max以下） */
void fsort(int a[], int n, int max)
{
  int i;
  int *f = calloc(max + 1, sizeof(int)); /* 累積度数 */
  int *b = calloc(n, sizeof(int));       /* 作業用の目的配列 */

  for (i = 0;     i <= max; i++) f[i] = 0; /* step0 累積度数の配列を初期化 */
  for (i = 0;     i < n;    i++) f[a[i]]++;/* step1 まず度数分布表を作る　　すごい。。人数分ループを回して、目的配列の値が添字になっている要素をインクリメントしていく */
  for (i = 1;     i <= max; i++) f[i] += f[i - 1];/* step2 累積度数にする。なるほど。。添字1（2番目）からはじめて、一つ前の要素を足し合わせていけば累積度数になる */
  for (i = n - 1; i >= 0;   i--) b[--f[a[i]]] = a[i];/* step3 目的配列を作成  */
  for (i = 0;     i < n;    i++) a[i] = b[i];  /* step4 作業用の目的配列を目的配列にコピー */
  free(b);
  free(f);
}

int main(void)
{
  int i, nx;
  int *x; /* 配列の先頭要素へのポインタ */
  const int max = 100; /* 最大値 */

  puts("度数ソート");
  printf("要素数：");
  scanf("%d", &nx);
  x = calloc(nx, sizeof(int));

  printf("0~%dの整数を入力せよ。\n", max);
  for (i = 0; i < nx; i++) {
    do {
      printf("x[%d]：", i);
      scanf("%d", &x[i]);
    } while (x[i] < 0 || x[i] > max);
  }

  fsort(x, nx, max); /* 配列xを度数ソート */

  puts("昇順にソートしました。");
  for (i = 0; i < nx; i++)
    printf("x[%d] = %d\n", i, x[i]);
  free(x); /* 配列を破棄 */
  return 0;
}