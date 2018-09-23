#ifndef WORD_H
#define WORD_H

#ifndef VAR
#define MaxBookNum 1000  // 假设只对1000本书建立索引表
#define MaxKeyNum 2500   // 索引表的最大容量
#define MaxLineNum 500   // 书目串的最大长度
#define MaxWordNum 10    // 词表的最大容量
#endif                   // VAR

#ifndef BOOL
#define bool int
#define false 1
#define true 0
#endif  // BOOL

// 书目类型的定义
typedef struct Book {
  char id[10];            // 书号
  char name[MaxLineNum];  // 书名
} Book;

//书目表的定义
typedef struct BookList {
  Book book[MaxBookNum];  // 存储书目的表
  int number;             // 书目数量
} BookList;

// 关键字索引对应的书目id
typedef struct IdIndex {
  char id[10];
  struct IdIndex* next;
} IdIndex;

// 索引类型定义
typedef struct BookIndex {
  char index[50];
  IdIndex* head;
} BookIndex;

// 索引表
typedef struct BookIndexList {
  BookIndex bookindex[MaxKeyNum];  // 索引项存储信息
  int number;                      // 索引项的书目
} BookIndexList;

// 词表
typedef struct WordList {
  char Word[MaxWordNum][20];
  int number;
} WordList;

// 关键字表
typedef struct KeyWordList {
  char keyword[20][20];
  int number;
} KeyWord;

#endif  // WORD_H