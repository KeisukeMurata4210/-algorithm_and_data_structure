/* bsearch関数を利用した昇順に並んだ配列からの探索 */
# include <stdio.h>
# include <stdlib.h>

/* 整数を比較する関数（昇順用） */
int int_cmp(const int *a, const int *b)
{
  if (*a < *b)
    return -1;
  else if (*a > *b)
    return 1;
  else
    return 0;
}
/* 引数void *型の関数、へのキャストを避けるならこう書く */
/* 
int int_cmp(const void *a, const void *b)
{
  if (*(int *)a < *(int *)b)
    return -1;
  else if (*(int *)a > *(int *)b)
    return 1;
  else
    return 0;
}
 */

int main(void)
{
  int i, nx, ky;
  int *x;  /* 配列の先頭要素へのポインタ */
  int *p;  /* 探索された要素へのポインタ */
  puts("bsearch関数による探索");
  printf("要素数：");
  scanf("%d", &nx);
  x = calloc(nx, sizeof(int));

  printf("昇順に入力してください。\n");
  printf("x[0]：");
  scanf("%d", &x[0]);
  for (i = 1; i < nx; i++) {
    do {
      printf("x[%d]：", i);
      scanf("%d", &x[i]);
    } while (x[i] < x[i - 1]);
  }
  printf("探す値：");
  scanf("%d", &ky);
  p = bsearch(&ky,
              x,
              nx,
              sizeof(int),
              (int (*)(const void * , const void *))int_cmp /* bseach()の引数が受け取る関数ポインタは、引数がvoid * */
              );
  if (p == NULL)
    puts("探索に失敗しました。");
  else
    printf("%dはx[%d]にあります。\n", ky, (int)(p - x));/* ポインタ同士の引き算は、アドレスを引いた後要素型のバイト数（intなら4）で割る */
  free(x);
  return 0;
}


/*
・関数へのポインタ
double func(int) ：「int型の引数を受け取って、double型の戻り値を返す関数func」
double (*fp)(int)：「int型の引数を受け取って、double型の戻り値を返す関数」へのポインタfp

()を省略すると、double *fp(int) ：「int型の引数を受け取って、double型へのポインタを返す関数fp」
となってしまうためカッコは必須

31行目について


*/