/* ２分探索 */
# include <stdio.h>
# include <stdlib.h>

/* 要素数nの配列aからkeyと一致する要素を２分探索 */
int bin_search(const int a[], int n, int key)
{
  int pl = 0;     /* 探索範囲先頭の添字 */
  int pr = n - 1; /* 探索範囲末尾の添字 */
  int pc;         /* 探索範囲中央の添字 */
  do {
    pc = (pl + pr) / 2;/* 割り切れない時　＝　末尾の添字が奇数　＝　要素数が偶数　＝　真ん中２つのうち小さい方がpcになる */
    if (a[pc] == key)
      return pc;
    else if (a[pc] < key)/* 値を更新するのは、先頭か末尾のどちらかひとつ */
      pl = pc + 1;
    else
      pr = pc - 1;
  } while (pl <= pr); /* 先頭が末尾を追い越したら終わり。=なら、先頭=末尾がkeyである可能性があるのでもう1ループ */
  return -1;
}

int main(void)
{
  int i, nx, ky, idx;
  int *x;
  puts("線形探索");
  printf("要素数：");
  scanf("%d", &nx);
  x = calloc(nx, sizeof(int)); /* 要素数nxのint型配列 */
  printf("昇順に入力してください。\n");
  printf("x[0]：");
  scanf("%d", &x[0]);
  for (i = 1; i < nx; i++) {
    do {
      printf("x[%d]：", i);
      scanf("%d", &x[i]);
    } while (x[i] < x[i - 1]); /* ひとつ前より小さければ再入力 */
  }
  printf("探す値：");
  scanf("%d", &ky);
  idx = bin_search(x, nx, ky);
  if (idx == -1)
    puts("探索に失敗しました。");
  else
    printf("%dはx[%d]にあります。\n", ky, idx);
  free(x);
  return 0;
}