/* 要素型がint型で要素数が5の配列 */
# include <stdio.h>

# define N 5

int main(void)
{
  int i;
  int a[N];
  for (i = 0; i < N; i++) {
    printf("a[%d]：", i);
    scanf("%d", &a[i]);
  }
  puts("各要素の値");
  for (i = 0; i < N; i++) {
    printf("a[%d] = %d\n", i, a[i]);
  }
  return 0;
}
/*
要素型Typeで要素数nの配列　→　”Type[n]型” と表現する。　ex) int[5]型
*/