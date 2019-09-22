/* チェイン法によるハッシュ（ソース部） */
#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "ChainHash.h"

/* ハッシュ関数（keyのハッシュ値を返す） */
static int hash(int key, int size)
{
  return key % size;
}

/* ノードの各メンバに値を設定 */
static void SetNode(Node *n, const Member *x, const Node *next)
{
  n->data = *x;   /* データ */
  n->next = next; /* 後続ノードへのポインタ */
}

/* ハッシュ表を初期化 */
int Initialize(ChainHash *h, int size)
{
  int i;
  if ((h->table = calloc(size, sizeof(Node *))) == NULL) {/* ハッシュ表は「Node型ポインタの配列」だった！！ */
    h->size = 0;
    return 0;
  }
  h->size = size;
  for (i = 0; i < size; i++) /* すべてのバケットを空にする */
    h->table[i] = NULL;
  return 1;
}

/* 探索 */
Node *Search(const ChainHash *h, const Member *x)
{
  
}

/* データの追加 */
int Add(ChainHash *h, const Member *x);

/* データの削除 */
int Remove(ChainHash *h, const Member *x);

/* ハッシュ表をダンプ */
void Dump(const ChainHash *h);

/* 全データの削除 */
void Clear(ChainHash *h);

/* ハッシュ表を後始末 */
void Terminate(ChainHash *h);