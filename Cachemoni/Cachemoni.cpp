﻿// Cachemoni.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

/**************************初始化变量****************************/
void InitVariables(void)
{
	for (i = 0; i < i_num_line; i++)
	{
		cache_item[i].reset(); // [31]:valid,[30]:hit,[29]:dirty,[28]-[0]:data

		if (t_replace == LRU)
		{
			LRU_priority[i] = 0; //对于LRU政策的优先考虑
		}
	}

	i_cache_size = 64; 
	i_cache_line_size = 32; 
	i_cache_set = 0; 
#ifdef SetAssociative_Random_WriteBack
	i_cache_set = 4; //cache set
#endif // SetAssociative_Random_WriteBack
	i_num_line = 0;
	i_num_set = 0; 
#ifdef DirectMapped_None_WriteBack
	t_assoc = direct_mapped; 
	t_replace = none; 
	t_write = write_back; 
#endif // DirectMapped_None_WriteBack
#ifdef FullAssociative_Random_WriteBack
	t_assoc = full_associative; 
	t_replace = Random; 
	t_write = write_back; 
#endif // FullAssociative_Random_WriteBack
#ifdef SetAssociative_Random_WriteBack
	t_assoc = set_associative; 
	t_replace = Random; 
	t_write = write_back; 
#endif // SetAssociative_Random_WriteBack
	bit_block = 0; 
	bit_line = 0; 
	bit_tag = 0; 
	bit_set = 0; 
	i_num_access = 0; 
	i_num_load = 0; 
	i_num_store = 0; 
	i_num_space = 0; 
	i_num_hit = 0;
	i_num_load_hit = 0; 
	i_num_store_hit = 0; 
	f_ave_rate = 0.0; 
	f_load_rate = 0.0; 
	f_store_rate = 0.0;
	current_line = 0; 
	current_set = 0; 
	i = 0;
	j = 0; 
}
/*************************建立Cache****************************/
void CreateCache()
{
	temp = i_num_line;

	for (i = 0; i < temp; i++)
	{
		cache_item[i][31] = true;
	}

}


int main()
{
	char ch = '\0';
	do
	{
		InitVariables();//初始化变量
		GetInput();//得到输入信息

		CreateCache();





		std::cout << "Continue(继续)/Exit(退出)(C/E)" << std::endl;
		std::cin >> ch;
	} while ((ch != 'e') && (ch != 'E'));

		return 0;
}
