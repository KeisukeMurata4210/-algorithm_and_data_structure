/* 線形探索 */
# include <stdio.h>
# include <stdlib.h>

/* 要素数nの配列aからkeyと一致する要素を線形探索 */
int search(const int a[], int n, int key)
{
/*   int i = 0;
  while (1) {
    if (i == n)
      return -1;
    if (a[i] == key)
      return i;
    i++;
  } */
  int i;
  for (i = 0; i < n; i++)
    if (a[i] == key)
      return i;
  return 0;
}

int main(void)
{
  int i, nx, ky, idx;
  int *x;
  puts("線形探索");
  printf("要素数：");
  scanf("%d", &nx);
  x = calloc(nx, sizeof(int)); /* 要素数nxのint型配列 */
  for (i = 0; i < nx; i++) {
    printf("x[%d]：", i);
    scanf("%d", &x[i]);
  }
  printf("探す値：");
  scanf("%d", &ky);

  idx = search(x, nx, ky); /* 配列xから値がkyである要素を線形探索 戻り値はkyの添字 */
  if (idx == -1)
    puts("探索に失敗しました。");
  else
    printf("%dはx[%d]にあります。\n", ky, idx);
  free(x);
  return 0;
}
/*
線形探索は、ランダムな並びの配列から探索を行う唯一の方法
*/