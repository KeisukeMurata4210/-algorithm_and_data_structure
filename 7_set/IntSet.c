/* int型集合IntSet（ソース部） */
#include <stdio.h>
#include <stdlib.h>
#include "IntSet.h"

/* 集合の初期化 */
int Initialize(IntSet *s, int max)
{
  s->num = 0;
  if ((s->set = calloc(max, sizeof(int))) == NULL) {
    s->max = 0; /* 配列の作成に失敗 */
    return -1;
  }
  s->max = max;
  return 0;
}

/* 集合sにnが入っているか */
int IsMember(const IntSet *s, int n)
{
  int i;
  for (i = 0; i < s->num; i++)
    if (s->set[i] == n)
      return i;/* 含まれる（添字を返却） */
  return -1; /* 含まれない */
}

/* 集合sにnを追加 */
void Add(IntSet *s, int n)
{  /* そう！！最低一つは空きがないと追加できない！ */
  if (s->num < s->max && IsMember(s, n) == -1)/* 含まれていなかったら */
    s->set[s->num++] = n;/* 配列の末尾に追加して、要素数を+1 */
}

/* 集合sからnを削除 */
void Remove(IntSet *s, int n)
{
  int idx;
  if ((idex = IsMember(s, n)) != -1) {/* 含まれていたらそれを削除する */
    s->set[idx] = s->set[--s->num];/* デクリメント後は末尾の添字と同じになる */
  }/* 処理の後も、末尾の要素はそのまま残っている？ */
}

/* 集合sが格納できる最大の要素数 */
int Capacity(const IntSet *s)
{
  return s->max;
}

/* 集合sの要素数 */
int Size(const IntSet *s)
{
  return s->num;
}

/* 集合s2をs1に代入 */
void Assign(IntSet *s1, const IntSet *s2)
{
  int i;
  int n = (s1->max < s2->num) ? s1->max : s2->num; /* コピーする要素数。収まりきれなかったら収まる範囲でコピー */
  for (i = 0; i < n; i++)
    s1->set[i] = s2->set[i];
  s1->num = n;
}

/* 集合s1と集合s2は等しいか */
int Equal(const IntSet *s1, const IntSet *s2)
{
  int i, j;
  if (Size(s1) != Size(s2))
    return 0;
  for (i = 0; i < s1->num; i++) {
    for (j = 0; s2->num; j++)
      if (s1->set[i] == s2->set[j])
        break;
    if (j == s2->num)/* forだけだと、見つからなくてもスルーして次に行ってしまうから、ここではじく */
      return 0;
  }
}

/* 集合s2とs3の和集合をs1に代入 */
IntSet *Union(IntSet *s1, const IntSet *s2, const IntSet *s3)
{
  int i;
  Assign(s1, s2);
  for (i = 0; i < s3->num; i++)/* s1の要素数はs2+s3以上、という前提 */
    Add(s1, s3->set[i]);
  return s1;
}

/* 集合s2とs3の積集合をs1に代入 */
IntSet *Intersection(IntSet *s1, const IntSet *s2, const IntSet *s3)
{
  
}

/* 集合s2からs3を引いた集合をs1に代入 */
IntSet *Difference(IntSet *s1, const IntSet *s2, const IntSet *s3);

/* 集合sの全要素を表示 */
void Print(const IntSet *s);

/* 集合sの全要素を表示（改行付き） */
void PrintLn(const IntSet *s);

/* 集合の後始末 */
void Terminate(IntSet *s);