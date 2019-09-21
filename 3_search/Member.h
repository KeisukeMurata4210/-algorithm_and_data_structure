/* 会員データMember（ヘッダ部） */
#ifndef ___Member
#define ___Member

/* 会員データ */
typedef struct {
  int no;        /* 番号 */
  char name[20]; /* 氏名 */
} Member;

#define MEMBER_NO   1/* 番号を表す定数値 */
#define MEMBER_NAME 2/* 使命を表す定数値 */

/* 会員の番号の比較関数 */
int MemberNoCmp(const Member *x, const Memeber *y);

/* 会員の氏名の比較関数 */
int MemberNameCmp(const Memeber *x, const Member *y);

/* 会員データの表示（改行なし） */
void PrintMember(const Member *x);

/* 会員データの表示（改行あり） */
void PrintLnMember(const Member *x);

/* 会員データの読込み */
Member ScanMember(const char *message, int sw);

#endif