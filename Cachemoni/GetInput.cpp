#include "pch.h"

using namespace std;

void getCacheSize()
{
	puts("\n请输入缓存大小的数字(单位:千字节)");
	puts("\n\t(for example:1,2,4,8,16,32,64...2^18)");
	cin >> i_cache_size;
	if (cin.fail())//错误信息的处理
	{
		cin.clear();
		cin.sync();
	}
	if (i_cache_size < 1 || i_cache_size >= 262144
		|| (i_cache_size & (~i_cache_size + 1)) != i_cache_size)
	{
		getCacheSize();//重新输入
	}
}

void getCacheLineSize()
{
	puts("\n请输入缓存行大小的数字(单位:字节)");
	puts("\n\t(for example:1,2,4,8,16,32,64...2^18)");
	cin >> i_cache_line_size;
	if (cin.fail())
	{
		cin.clear();
		cin.sync();
	}
	if (i_cache_line_size < 1 || i_cache_line_size >= 262144
		|| (i_cache_line_size & (~i_cache_line_size + 1))
		!= i_cache_line_size)
	{
		getCacheLineSize();//重新输入
	}
}

void getMappingMethod()
{
	short temp = 0;
	puts("\n:请输入主存与缓存关联的方法");
	puts("\n\t直接映射:输入 1");
	puts("\n\t 组相联映射:输入 2");
	puts("\n\t 全相联映射:输入 3");
	cin >> temp;
	if (cin.fail())
	{
		cin.clear();
		cin.sync();
	}
	switch (temp)
	{
	case 1:
		t_assoc = direct_mapped;
		break;
	case 2:
		t_assoc = set_associative;
		break;
	case 3:
		t_assoc = full_associative;
		break;
	default:
		getMappingMethod();
	}
}

void getLineCountEachSet()
{
	puts("\n请输入每组有多少行:");
	puts("\n\t(for example:1,2,4,8,16,32,64...2^18)");
	cin >> i_cache_set;
	if (cin.fail())
	{
		cin.clear();
		cin.sync();
	}
	if (i_cache_set < 1 || i_cache_set >= 262144
		|| (i_cache_set & (~i_cache_set + 1)) != i_cache_set)
	{
		getLineCountEachSet();
	}
}

void getReplacePolicy()
{
	short temp;
	puts("\n请输入替换策略:");
	puts("\n\t FIFO(First In First Out):输入 1");
	puts("\n\t LRU(Least Recently Used):输入 2");
	puts("\n\t LFU(Least Frequently Used):输入 3");
	puts("\n\t Random:输入 4");
	cin >> temp;
	if (cin.fail())
	{
		cin.clear();
		cin.sync();
	}
	switch (temp)
	{
	case 1:
		t_replace = FIFO;
		break;
	case 2:
		t_replace = LRU;
		break;
	case 3:
		t_replace = LFU;
		break;
	case 4:
		t_replace = Random;
		break;
	default:
		getReplacePolicy();
	}
}

void getWritePolicy()
{
	short temp;
	puts("\n 请输入写入策略:");
	puts("\n\t 写直达法:输入 1");
	puts("\n\t 写回法:输入 2");
	cin >> temp;
	if (cin.fail())
	{
		cin.clear();
		cin.sync();
	}
	switch (temp)
	{
	case 1:
		t_write = write_through;
		break;
	case 2:
		t_write = write_back;
		break;
	default:
		getWritePolicy();
	}
}

void GetInput(void)
{
	getCacheSize();
	getCacheLineSize();
	getMappingMethod();
	if (t_assoc == direct_mapped) //If the associativity_way is direct_mapped,the replacement polacy can be none only;
	{
		t_replace = none;
		getWritePolicy();
	}
	else if (t_assoc == full_associative)
	{
		getReplacePolicy();
		getWritePolicy();
	}
	else if (t_assoc == set_associative)
	{
		getLineCountEachSet();
		getReplacePolicy();
		getWritePolicy();
	}

}
