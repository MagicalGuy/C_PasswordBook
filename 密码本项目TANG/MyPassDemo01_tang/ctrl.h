#pragma once
//查看所有密码

void searchAllPwd(PASSWORD* pwd, int pnCount);//查看所有站点密码信息
void insertPwd(PASSWORD* pwd, int * pnCount);//插入密码信息
void deletePwd(PASSWORD* pwd, int * pnCount);//删除密码
void alterPwd(PASSWORD* pwd, int* pnCount);//修改密码
void searchPwd(PASSWORD* pwd, int pnCount);//查询密码
void savePwd(PASSWORD * pwd, int *pnCount);//保存密码
PASSWORD* readPwd(PASSWORD * ppwd, int *pnCount);//初始化读取一些密码本数据
void savePass(char * str1);  //保存个人密码本的操作密码
void modifyPass();//修改个人密码本的操作密码
void loginOS();//用操作密码登录密码本
void alterVolume(PASSWORD* ppwd, int *pnCount);//密码本扩容
void initPassword();//进入密码本系统
void initPlayPass();//初始化操作密码