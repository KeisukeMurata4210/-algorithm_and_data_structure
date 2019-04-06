/* 1,000以下の素数を列挙（第1版） */
# include <stdio.h>

int main(void)
{
  int i, n;
  unsigned long counter = 0;  /* 除算の回数 */

  for (n = 2; n <= 1000; n++) {/* nが2-1000までの整数で、 */
    for (i = 2; i < n; i++) {  /* このループで一つ一つ、素数かどうかを検証していく */
      counter++;
      if (n % i == 0)           /* 割り切れたら素数ではない。このnの検証は終了 */
        break;
    }
    if (n == i)                 /* 割り切れなかったら */
      printf("%d\n", n);
  }
  printf("除算を行った回数：%lu\n", counter);
  return 0;
}
/* 
素数：2からn-1までのいずれの整数でも割り切れない　という判定でアルゴリズムを組んだ
↓
素数：2からn-1までのいずれの素数でも割り切れない　ので、こちらの方がアルゴリズムとして優秀
 */