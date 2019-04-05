/* 配列の要素の並びを反転する */
# include <stdio.h>
# include <stdlib.h>

# define swap(type, x, y)  do {type t = x; x = y; y = t;} while(0) /* 読んだ部分を置き換えるだけ。 */

/* 要素数nの配列a、その要素の並びを反転 */
void ary_reverse(int a[], int n)
{
  int i;
  for (i = 0; i < n/2; i++)
    swap(int, a[i], a[n - i - 1]);/* -1するのは添字がn-1までだから */
}

int main(void)
{
  int i;
  int *x;  /* 配列の先頭要素へのポインタ */
  int nx;  /* 配列xの要素数 */

  printf("要素数：");
  scanf("%d", &nx);
  x = calloc(nx, sizeof(int));
  printf("%dの整数を入力してください。\n", nx);
  for (i = 0; i < nx; i++) {
    printf("x[%d]：", i);
    scanf("%d", &x[i]);
  }
  ary_reverse(x, nx);
  printf("配列の要素の並びを反転しました。\n");
  for (i = 0; i < nx; i++)
    printf("x[%d] = %d\n", i, x[i]);
  free(x);  /* 忘れない */
  return 0;
}