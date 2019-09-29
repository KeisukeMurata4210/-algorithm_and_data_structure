/* オープンアドレス法によるハッシュ（ヘッダ部） */
#ifndef ___ClosedHash
#define ___ClosedHash

#include "Member.h"

/* 要素の状態 */
typedef enum {
  Occupied, Empty, Deleted
} Status;

/* 要素 */
typedef struct {
  Member data; /* データ */
  Status stat; /* 要素の状態 */
} Bucket;

/* ハッシュ表 */
typedef struct {
  int size; /* ハッシュ表の大きさ */
  Bucket *table; /* ハッシュ表の先頭要素へのポインタ */
} ClosedHash; /* こっちはただ単にBucket型の配列だから、**にならない */

/* ハッシュ表を初期化 */
int Initialize(ClosedHash *h, int size);

/* 探索 */
Bucket *Search(const ClosedHash *h, const Member *x);

/* データの追加 */
int Add(ClosedHash *h, const Member *x);

/* データの削除 */
int Remove(ClosedHash *h, const Member *x);

/* ハッシュ表をダンプ */
void Dump(const ClosedHash *h);

/* 全データの削除 */
void Clear(ClosedHash *h);

/* ハッシュ表を後始末 */
void Terminate(ClosedHash *h);

#endif