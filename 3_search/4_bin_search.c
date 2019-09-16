/* 2分探索 */
#include <stdio.h>
#include <stdlib.h>

/* 要素数nの配列aからkeyと一致する要素を2分探索 */
int bin_search(const int a[], int n, int key)
{
  int pl = 0;    /* 探索範囲先頭の添字 */
  int pr = n -1; /* 探索範囲末尾の添字 */
  int pc;        /* 探索範囲中央の添字 */

  do {
    pc = (pl + pr) / 2;/* 正確な位置を知ることにあまり意味はない。ざっくり真ん中を基準にすることに意味がある */
    if (a[pc] == key) /* 真ん中とした要素がkeyと同じならそれでOK */
      return pc;
    else if (a[pc] < key)
      pl = pc + 1;  /* keyが末尾側にあり、かつ基準とは一致しないから基準（a[pl]）+1を先頭としてループ */
    else
      pr = pc - 1;  /* keyが先頭側にあり、かつ基準とは一致しない　＝　先頭〜(基準より先頭側に一つ戻した位置)のどこかにある */
  } while (pl <= pr);/* 計算の結果、先頭を中間が追い抜いてしまったらなかったということ */
  return -1;
}

int main(void)
{
  int i, nx, ky, idx;
  int *x;/* 配列の先頭要素へのポインタ */

  puts("２分探索");
  printf("要素数：");
  scanf("%d", &nx);
  x = calloc(nx, sizeof(int));/* 要素数nxのint型配列を生成 */

  printf("昇順に入力してください。\n");/* forでちゃんとチェックしているのは流石だと思う。 */
  printf("x[0]：");
  scanf("%d", &x[0]);

  for (i = 1; i < nx; i++) {/* なるほど、一ループに対してその都度do-whileループが回るんだ。 */
    do {
      printf("x[%d]：", i);
      scanf("%d", &x[i]);
    } while (x[i] < x[i - 1]);/* なるほど、ここでエラーを出さないためにx[0]を最初に入力させたのか */
  }
  printf("探す値：");
  scanf("%d", &ky);

  idx = bin_search(x, nx, ky);
}