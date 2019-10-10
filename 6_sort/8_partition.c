/* 配列の分割 */
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do {type t = x; x = y; y = t;} while (0)

/* 配列を分割する */
void partition(int a[], int n)
{
  int i;
  int pl = 0;      /* 左カーソル */
  int pr = n - 1;  /* 右カーソル */
  int x = a[n / 2];/* 枢軸は中央の要素。商だから奇数だったときは一つ左。 */

  do {
    while (a[pl] < x) pl++;/* そうだ！添字じゃなくて、その位置の値を比べてるんだ！ */
    while (a[pr] > x) pr--;/* 両方ともに引っかかる値を見つけたら、、 */
    if (pl <= pr) {         /* かつカーソルが交差していなければ */
      swap(int, a[pl], a[pr]);/* 入れ替えて */
      pl++;                   /* それぞれのカーソルを一つ移動させる */
      pr--;
    }
  } while (pl <= pr); /* 繰り返して、カーソルが交差したら終わり */
  
  printf("枢軸の値は%dです。\n", x);

  printf("枢軸以下のグループ\n");  /* 枢軸以下のグループ */
  for (i = 0; i <= pl - 1; i++) /* a[0] ~ a[pl - 1] */
    printf("%d ", a[i]);
  putchar('\n');

  if (pl > pr + 1) {/* そもそも同じグループがあるかどうかをチェック */
    printf("枢軸と一致するグループ\n");    /* 枢軸と同じグループ */
    for (i = pr + 1; i <= pl - 1; i++) /* a[pr + 1] ~ a[pl - 1] */
      printf("%d ", a[i]);
    putchar('\n');
  }

  printf("枢軸以上のグループ\n");   /* 枢軸以上のグループ */
  for (i = pr + 1; i < n; i++)   /* a[pr + 1] ~ a[n - 1] */
    printf("%d ", a[i]);
  putchar('\n');
}

int main(void)
{
  int i, nx;
  int *x; /* 配列の先頭要素へのポインタ */

  puts("配列を分割します。");
  printf("要素数：");
  scanf("%d", &nx);
  x = calloc(nx, sizeof(int)); /* 要素数nxのint型配列を生成 */

  for (i = 0; i < nx; i++) {
    printf("x[%d]：", i);
    scanf("%d", &x[i]);
  }

  partition(x, nx); /* 配列xを分割 */
  free(x); /* 配列を破棄 */
  return 0;
}