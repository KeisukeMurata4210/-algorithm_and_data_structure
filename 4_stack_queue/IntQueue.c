/* Int型キューIntQueue（ソース部） */
#include <stdio.h>
#include <stdlib.h>
#include "IntQueue.h"

/* キューの初期化 */
int Initialize(IntQueue *q, int max)
{
  q->max = q->front = q->rear = 0;/* maxを0にすることで、生成失敗したにも関わらず他の関数がqueにアクセスするのを防ぐ */
  if ((q->que = calloc(max, sizeof(int))) == NULL) {
    q->max = 0;
    return -1;
  }
  q->max = max;
  return 0;
}

/* キューにデータをエンキュー */
int Enque(IntQueue *q, int x)
{
  if (q->num >= q->max)
    return -1;
  else {
    q->num++;/* 要素数を+1 */
    q->que[q->rear++] = x;
    if (q->rear == q->max)
      q->rear = 0;
    return 0;
  }
}

/* キューからデータをでキュー */
int Deque(IntQueue *q, int *x)
{
  if (q->num <= 0)
    return -1;
  else {
    q->num--;
    *x = q->que[q->front++];
    if (q->front == q->max)
      q->front = 0;
    return 0;
  }
}

/* キューからデータをピーク */
int Peek(const IntQueue *q, int *x)
{
  if (q->num <= 0)
    return -1;
  *x = q->que[q->front];
  return 0;
}

/* 全データを削除 */
void Clear(IntQueue *q)
{
  q->num = q->front = q->rear = 0; /* スタックと同じで本体の削除はTerminateで行う。ただ空にするだけ。 */
}

/* キューの容量 */
int Capacity(const IntQueue *q)
{
  return q->max;
}

/* キュー上のデータ数 */
int Size(const IntQueue *q)
{
  return q->num;
}

/* キューは空か */
int IsEmpty(const IntQueue *q)
{
  return q->num <= 0;
}

/* キューは満杯か */
int IsFull(const IntQueue *q)
{
  return q->num >= q->max;
}

/* キューからの探索 */
int Search(const IntQueue *q, int x)
{
  int i, idx;
  for (i = 0; i < q->num; i++) {
    if (q->que[idex = (i + q->front) % q->max] == x)
      return idx;
  }
  return -1;
}

/* 全データの表示 */
void Print(const IntQueue *q)
{
  int i;
  for (i = 0; i < q->num; i++)
    printf("%d ", q->que[(i + q->front) % q->max]);/* ここも、frontから表示させるためにこのコード */
  putchar('\n');
}

/* キューの後始末 */
void Terminate(IntQueue *q)
{
  if (q->que != NULL)
    free(q->que);
  q->max = q->num = q->front = q->rear = 0;
}