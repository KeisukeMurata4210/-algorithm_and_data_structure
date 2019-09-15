/* Int型キューIntQueue（ヘッダ部） */
#ifndef ___IntQueue
#define ___IntQueue

/* キューを実現する構造体 */
typedef struct {
  int max;  /* キューの容量 */
  int num;  /* 現在の要素数 */ /* frontとrearが同じ場合に、空なのか満杯なのか区別するためにこの変数がいる */
  int front;/* 先頭要素カーソル */
  int rear; /* 末尾要素カーソル */
  int *que; /* キュー本体（の先頭要素へのポインタ） */
} IntQueue;

/* キューの初期化 */
int Initialize(IntQueue *q, int max);

/* キューにデータをエンキュー */
int Enque(IntQueue *q, int x);

/* キューからデータをでキュー */
int Deque(IntQueue *q, int *x);

/* キューからデータをピーク */
int Peek(const IntQueue *q, int *x);

/* 全データを削除 */
void Clear(IntQueue *q);

/* キューの容量 */
int Capacity(const IntQueue *q);

/* キュー上のデータ数 */
int Size(const IntQueue *q);

/* キューは空か */
int IsEmpty(const IntQueue *q);

/* キューは満杯か */
int IsFull(const IntQueue *q);

/* キューからの探索 */
int Search(const IntQueue *q, int x);

/* 全データの表示 */
void Print(const IntQueue *q);

/* キューの後始末 */
void Terminate(IntQueue *q);

#endif