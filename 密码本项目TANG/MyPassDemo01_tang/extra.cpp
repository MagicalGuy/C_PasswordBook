#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"data.h"
#include"ctrl.h"

//读取密码本操作密码
char* readPass(char* str) {
	FILE* fp;

	if (fopen_s(&fp, "pass.i", "r") != 0) {
		printf("第一次使用，初始化文件中！！\n");
		//exit(1);
	}


	else {
		fscanf_s(fp, "%s", str, 20);
		for (int i = 0; str[i] != '\0'; i++) str[i] ^= 5;//读取解密
		fclose(fp);
		return str;
	}
	return NULL;
}

//保存密码本操作密码
void savePass(char * str1) {
	FILE* fp;

	if (fopen_s(&fp, "pass.i", "w") != 0) {
		printf("打开数据失败\n");
		system("pause");
		exit(1);
	}
	for (int i = 0; str1[i] != '\0'; i++) str1[i] ^= 5;  //写进文件加密
	fprintf(fp, "%s", str1);
	fclose(fp);
}

//修改密码本操作密码
void modifyPass() {
	char str[20];
	char* pass = readPass(str);

	int flag = 1;
	while (flag) {
		char str1[20];
		printf("原操作密码为：%s\n", pass);
		printf("请输入新的操作密码：\n");
		scanf_s("%s", str1, 20);
		char str2[20];
		printf("请再次输入确认密码：\n");
		scanf_s("%s", str2, 20);
		//gets_s(str2);
		if (str1 == "" || str2 == "") { printf("输入为空，修改失败！"); flag = 0; }
		else if (strcmp(str1, str2) == 0) {
			savePass(str1);
			printf("修改成功！");
			flag = 0;
		}
		else { printf("请重新输入\n"); flag = 1; }
	}

	system("pause");
	system("cls");
}


void initPlayPass() {
	FILE* fp;
	char str[20] = "1234";
	if (fopen_s(&fp, "pass.i", "w") != 0) {
		printf("打开数据失败\n");
		system("pause");
		exit(1);
	}
	for (int i = 0; str[i] != '\0'; i++) str[i] ^= 5;
	fprintf(fp, "%s", str);
	fclose(fp);
}


//登录界面
void loginOS() {

	printf("=====《欢迎使用个人密码本》=====\n");

	printf("请使用输入密码本操作密码(初始密码：1234)：\n");
	char _ch[20];
	//scanf_s("%s", _ch, 20);
	gets_s(_ch);
	char str[20];

	if (readPass(str) == NULL) {
		initPlayPass();
	}

	if (strcmp(_ch, readPass(str)) != 0) {
		//	printf("%s\n", readPass());
		printf("密码不正确退出系统！！！\n");
		system("pause");
		return;
	}

	system("pause");
	system("cls");
	printf("登录成功！");
	initPassword();
}

//修改密码本容量
void alterVolume(PASSWORD* ppwd, int *ncount) {
	printf("原始密码本容量大小为：%d\n", g_nNum);
	printf("请输入您想修改的大小:\n");

	scanf_s("%d", &g_nNum);

	if (g_nNum == 0) { printf("输入为空，修改失败！\n"); return; }

	savePwd(ppwd, ncount);
	system("pause");
	system("cls");
	printf("修改成功！");
}

//进入密码本操作界面
void initPassword() {
	//PASSWORD pPwd[NUM];
	PASSWORD*  pPwd = nullptr;
	int pnCount = 0;//当前密码个数
	g_nNum = 0;//当前密码本容量
	PASSWORD * ppPwd = readPwd(pPwd, &pnCount);//初始化密码本
	//readPwd(pPwd, &pnCount);
	printf("当前密码个数：%d\n", pnCount);
	printf("当前容量：%d\n", g_nNum);
	int flag = 1;
	while (flag) {
		printf("================================================\n");
		printf("1 查看全部密码   2 新增密码   3 删除密码\n");
		printf("4 修改密码       5 查询密码   6 保存文本\n");
		printf("7 修改操作密码   8 修改容量   9 退出\n");
		printf("请输入您的操作选项：\n");
		printf("================================================\n");
		int option;

		scanf_s("%d", &option);
		while ('\n' != getchar());

		switch (option) {
		case 查看所有:
			searchAllPwd(ppPwd, pnCount);
			break;
		case 新增密码:
			insertPwd(ppPwd, &pnCount);
			break;
		case 删除密码:
			deletePwd(ppPwd, &pnCount);
			break;
		case 修改密码:
			alterPwd(ppPwd, &pnCount);
			break;
		case 查询密码:
			searchPwd(ppPwd, pnCount);
			break;
		case 保存文本:
			savePwd(ppPwd, &pnCount);
			break;
		case 修改操作密码:
			modifyPass();
			break;
		case 修改容量:
			alterVolume(ppPwd, &pnCount);
			break;
		case 退出:
			flag = 0;
			printf("谢谢使用\n");
			break;
		default:
			flag = 0;
			printf("输入错误，自动退出！\n");
			break;
		}
	}
}