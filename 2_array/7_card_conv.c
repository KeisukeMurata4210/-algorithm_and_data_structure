/* 整数を2進数~36進数に基数変換 */
# include <stdio.h>

/* 整数を2進数~36進数に基数変換 */
int card_convr(unsigned x, int n, char d[])
{
  char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";/* ○進数といったとき、添字に対応した数字を文字で取り出せるようにしてある！！ 数字→文字にそのまま変換できる！！ */
  int digits = 0; /* 変換後の桁数 */
  if (x == 0)
    d[digits++] = dchar[0];  /* digitsは桁数だから、演算後にインクリメントする */
  else
    while (x) {
      d[digits++] = dchar[x % n]; /* nが基数（○進数の○） */
      x /= n;
    }
  return digits;
}

int main(void)
{
  int       i;     
  unsigned  no;      /* 変換する整数 */   /* int ←→ unsigned。「unsigned int」というのはないらしい */
  int       cd;      /* 基数 */
  int       dno;     /* 変換後の桁数 */
  char      cno[512];/* 変換後の数値の各桁の数値を格納する文字の配列 */
  int       retry;

  puts("10進数を基数変換します。");
  do {
    printf("変換する非負の整数：");
    scanf("%u", &no);
    do {
      printf("何進数に変換しますか（2~36）：");
      scanf("%d", &cd);
    } while (cd < 2 || cd > 36);
    dno = card_convr(no, cd, cno);  /* noをcd進数に変換。実行した時点でcnoが更新されている */
    printf("%d進数では", cd);
    for (i = dno - 1; i >= 0; i--)
      printf("%c", cno[i]);     /* cnoの並びは逆になっているから、添字を逆向きのループにする */
    printf("です。\n");

    printf("もう一度しますか（1…はい / 0…いいえ）：");
    scanf("%d", &retry);
  } while (retry == 1);

  return 0;
}