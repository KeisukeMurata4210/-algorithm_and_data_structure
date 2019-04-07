/* 年内の経過日数を求める */
# include <stdio.h>

/* 各月の日数 */
int mdays[][12] = {
  {31, 28, 21, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {31, 29, 21, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* 西暦yearは閏年か */
int isleap(int year)
{
  return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
  /* 閏年の条件は、①年数が4で割り切れてかつ100で割り切れない、②400で割り切れる */
}

/* 西暦y年m月d日の年内の経過日数を求める */
int dayofyear(int y, int m, int d)
{
  int i;
  int days = d;/* 経過日数 */
  for (i = 1; i < m; i++)/* 1月からm-1月までのトータル日数を足しこむ */
    days += mdays[isleap(y)][i - 1];/* 真偽値は0/1  */
  return days;
}

int main(void)
{
  int year, month, day;
  int retry;
  do {
    printf("年："); scanf("%d", &year);
    printf("月："); scanf("%d", &month);
    printf("日："); scanf("%d", &day);
    printf("年内で%d日目です。\n", dayofyear(year, month, day));

    printf("もう一度しますか（1…はい / 0…いいえ）：");
    scanf("%d", &retry);
  } while (retry == 1);
  return 0;
}