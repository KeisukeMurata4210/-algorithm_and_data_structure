/* bsearch関数を利用した構造体の配列からの探索 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[10];/* 名前 */
  int height;   /* 身長 */
  int weight;   /* 体重 */
} Person;

/* Person型の比較関数（名前昇順） */
int npcmp(const Person *x, const Person *y)
{
  return strcmp(x->name, y->name);
}

int main(void)
{
  Person x[] = {
    {"ABE",      179, 79},
    {"NANGOH",   172, 79},
    {"SHIBATA",  176, 52},
    {"SUGIYAMA", 165, 51},
    {"TAKAOKA",  181, 73},
    {"TSURUMI",  172, 84}
  };
  int nx = sizeof(x) / sizeof(x[0]);/* 配列xの要素数 */
  int retry;

  puts("名前による探索を行います。");

  do {
    Person temp, *p;
    printf("名前：");
    scanf("%s", temp.name);

    p = bsearch(&temp, x, nx, sizeof(Person),
                (int (*)(const void *, const void *))npcmp);
    if (p == NULL)
      puts("探索に失敗しました。");
    else {
      puts("探索成功!! 以下の要素を見つけました。");
      printf("x[%d]：%s %dcm %dkg\n",
              (int)(p - x), p->name, p->height, p->weight);
    }
    printf("もう一度探索しますか？(1)はい／(2)いいえ：");
    scanf("%d", &retry);
  } while (retry == 1);
  return 0;
}