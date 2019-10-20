/* int型集合IntSet（ヘッダ部） */
#ifndef ___IntSet
#define ___IntSet

/* int型の集合を実現する構造体 */
typedef struct {
  int max; /* 集合の容量 */
  int num; /* 集合の要素数 */
  int *set; /* 集合本体の配列（の先頭要素へのポインタ） */
} IntSet;

/* 集合の初期化 */
int Initialize(IntSet *s, int max);

/* 集合sにnが入っているか */
int IsMember(const IntSet *s, int n);

/* 集合sにnを追加 */
void Add(IntSet *s, int n);

/* 集合sからnを削除 */
void Remove(IntSet *s, int n);

/* 集合sが格納できる最大の要素数 */
int Capacity(const IntSet *s);

/* 集合sの要素数 */
int Size(const IntSet *s);

/* 集合s2をs1に代入 */
void Assign(IntSet *s1, const IntSet *s2);

/* 集合s1と集合s2は等しいか */
int Equal(const IntSet *s1, const IntSet *s2);

/* 集合s2とs3の和集合をs1に代入 */
IntSet *Union(IntSet *s1, const IntSet *s2, const IntSet *s3);

/* 集合s2とs3の積集合をs1に代入 */
IntSet *Intersection(IntSet *s1, const IntSet *s2, const IntSet *s3);

/* 集合s2からs3を引いた集合をs1に代入 */
IntSet *Difference(IntSet *s1, const IntSet *s2, const IntSet *s3);

/* 集合sの全要素を表示 */
void Print(const IntSet *s);

/* 集合sの全要素を表示（改行付き） */
void PrintLn(const IntSet *s);

/* 集合の後始末 */
void Terminate(IntSet *s);

#endif