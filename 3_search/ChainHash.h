/* チェイン法によるハッシュ（ヘッダ部） */
#ifndef ___ChainHash
#define ___ChainHash

#include "Member.h"

/* バケットを表すノード */
typedef struct __node {
  Member         data; /* データ */
  struct __node *next; /* 後続ノードへのポインタ */
} Node;

/* ハッシュ表 */
typedef struct {
  int  size;     /* ハッシュ表の大きさ */
  Node **table;  /* ハッシュ表の先頭要素へのポインタ */
} ChainHash;

/* ハッシュ表を初期化 */
int Initialize(ChainHash *h, int size);

/* 探索 */
Node *Search(const ChainHash *h, const Member *x);

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

#endif