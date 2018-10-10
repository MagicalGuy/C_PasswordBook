#pragma once
#define 查看所有 1
#define 新增密码 2
#define 删除密码 3
#define 修改密码 4
#define 查询密码 5
#define 保存文本 6
#define 修改操作密码 7
#define 修改容量 8
#define 退出 9


#define NUM 100 //初始密码本容量

typedef struct PASSWORD {
	char website[100];  //使用密码的地方
	char userName[100];//账号或用户名
	char passWord[100];//密码
	char note[100];//备注
}PASSWORD, *PPASSWORD;

extern int g_nNum;//当前的密码本容量
//#ifdef __cplusplus
//extern "C" {
//#endif
//	int g_nNum = 0;
//#ifdef __cplusplus
//};
//#endif