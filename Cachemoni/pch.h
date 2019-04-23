// 1 .几乎所有全局变量的声明。
// 2 .几乎所有结构的定义。
// 3 .几乎编译器选项的描述。
// 4 .几乎所有函数的声明。

#ifndef PCH_H
#define PCH_H


#include <iostream>
#include <fstream>
#include <bitset>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <ctime>

#define QUICK
//#define DirectMapped_None_WriteBack
//#define FullAssociative_Random_WriteBack
#define SetAssociative_Random_WriteBack

#ifdef QUICK
#define MAX_CACHE_LINE 65536 // 65536(2^16)
#endif
#ifndef QUICK
#define MAX_CACHE_LINE 268435456 // gcc阵列支持的最大数量 268435456(2^28)
#endif

/******************************************/

// 内存地址与Cache地址的关联方式：直接映射、组相联、全相联
enum associativity_way { direct_mapped = 1, set_associative, full_associative };

// 替换策略：none（直接替换），FIFO（先进先出算法），LRU（最近最少用算法），LFU（最不经常用算法），Random（随机替换算法）
enum replacement_way { none, FIFO = 1, LRU, LFU, Random };

// 写策略：write_through（全写法），write_back（回写法）
enum write_way { write_through = 1, write_back };
#endif // STRUCT_TYPE


typedef enum associativity_way ASSOC;
typedef enum replacement_way REPLACE;
typedef enum write_way WRITE;

/******************************************/
extern unsigned int long i_cache_size; //缓存大小
extern unsigned int long i_cache_line_size; //缓存line大小
extern unsigned int long i_cache_set; //缓存组

extern unsigned int long i_num_line; //缓存中有多少行
extern unsigned int long i_num_set; //缓存组的数量

extern ASSOC t_assoc; //内存地址与Cache地址的关联方式
extern REPLACE t_replace; //替换策略
extern WRITE t_write; //写策略
/******************************************/

/******************************************/
extern short unsigned int bit_block; //block多少位.
extern short unsigned int bit_line; //line多少位.
extern short unsigned int bit_tag; //tag多少位.
extern short unsigned int bit_set; //set多少位.
/******************************************/

/******************************************/
extern unsigned long int i_num_access; //缓存访问次数
extern unsigned long int i_num_load; //缓存加载次数
extern unsigned long int i_num_store; //缓存存储的数量
extern unsigned long int i_num_space; //空间行数

extern unsigned long int i_num_hit; //缓存命中次数
extern unsigned long int i_num_load_hit; //负载命中次数
extern unsigned long int i_num_store_hit; //存储命中率

extern float f_ave_rate; //平均缓存命中率
extern float f_load_rate; //加载的缓存命中率
extern float f_store_rate; //存储的缓存命中率
/******************************************/

extern std::bitset<32> cache_item[MAX_CACHE_LINE]; // [31]:valid,[30]:hit,[29]:dirty,[28]-[0]:data
extern unsigned long int LRU_priority[MAX_CACHE_LINE]; //对于LRU政策的优先考虑
extern unsigned long int current_line; // 正在执行的line num
extern unsigned long int current_set; // 正在执行的set num
extern unsigned long int i, j; //For loop
extern unsigned long int temp; //A temp varibale

/*****************函数声明*************************/

bool GetHitNum(char *address);
void GetHitRate(void);
bool IsHit(std::bitset<32> flags);
void GetReplace(std::bitset<32> flags);
void GetRead(std::bitset<32> flags);
void GetWrite();

void InitVariables(void);//初始化变量
void GetInput(void);
void CalcInfo(void);
void CreateCache(void);
void FileTest(void);
void PrintOutput(void);

void LruHitProcess();
void LruUnhitSpace();
void LruUnhitUnspace();

