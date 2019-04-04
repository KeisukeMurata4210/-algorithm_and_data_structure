/* 配列の要素の最大値を求める（値を読み込む） */
# include <stdio.h>
# include <stdlib.h>

int maxof(const int a[], int n)/* a[]は*aと解釈され、実引数のアドレスで初期化される。（a[]と書くのは慣習か？）　constは書き込み不可にする。→編集する意図がないときはconstをつけよう */
{
  int i;
  int max = a[0]; /* まず先頭を最大値とする */
  for (i = 0; i < n; i++)
    if (a[i] > max) max = a[i];
  return max;
}

int main(void)
{
  int i;
  int *height;  /* 配列の先頭要素へのポインタ */
  int number;  /* 人数=配列heightの要素数 */

  printf("人数：");
  scanf("%d", &number);

  height = calloc(number, sizeof(int));

  printf("%d人の身長を入力してください。\n", number);
  for (i = 0; i < number; i++) {
    printf("height[%d]：", i);
    scanf("%d", &height[i]);
  }

  printf("最大値は%dです。\n", maxof(height, number));
  free(height);
  return 0;
}

/* 配列の要素を一つずつなぞっていく手続き：「走査」 */