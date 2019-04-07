/* 1000以下の素数を求める（第3版） */
# include <stdio.h>

int main(void)
{
  int i, n;
  int prime[500];             /* 素数に格納する配列 */
  int ptr;                    /* すでに得られた素数の個数 */
  unsigned long counter = 0;  /* 乗除の回数 */

  prime[ptr++] = 2;
  prime[ptr++] = 3;   /* 2と3は素数 */
  for (n = 5; n <= 1000; n += 2) { /* 偶数は素数でないから除外 */
    int flag = 0;
    for (i = 1; counter++, prime[i] * prime[i] <= n; i++) { /* counter:乗算の回数 */
      counter++;    /* counter:除算の回数 */
      if (n % prime[i] == 0) {
        flag = 1;
        break;
      }
    }
    if (!flag)  /* 最後まで割り切れなかった　0のみがfalseだから、flag == 0と同じ */
      prime[ptr++] = n;
  }
  for (i = 0; i < ptr; i++)
    printf("%d\n", prime[i]);
  printf("乗除算を行なった回数：%lu\n", counter);
  return 0;
}