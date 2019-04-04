/* 配列の要素の最大値を求める（値は乱数で生成） */
# include <time.h>
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
  int *height;
  int number;

  printf("人数：");
  scanf("%d", &number);
  height = calloc(number, sizeof(int));

  srand(time(NULL));
  for (i = 0; i < number; i++) {
    height[i] = 100 + rand() % 90;/* 100 + 0~89 */
    printf("height[%d] = %d\n", i, height[i]);
  }
  printf("最大値は%dです。\n", maxof(height, number));
  free(height);
  return 0;
}