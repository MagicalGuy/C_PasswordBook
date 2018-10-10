#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"data.h"
#include"ctrl.h"

//查询所有密码，参数为密码本类型指针，当前密码个数
void searchAllPwd(PASSWORD* pPwd, int nCount) {
	printf("=========您查询的结果一共返回以下 %3d 条记录=========\n", nCount);
	for (int i = 0; i < nCount; i++) {
		printf("--ID: %d-------------------\n", i);
		printf("目标：%s \n", pPwd[i].website);
		printf("用户名：%s \n", pPwd[i].userName);
		printf("密码：%s \n", pPwd[i].passWord);
		printf("备注：%s \n", pPwd[i].note);
	}
	printf("\n");
	system("pause");
	system("cls");

}

//插入密码，参数为密码本类型指针，当前密码个数的指针
void insertPwd(PASSWORD* pPwd, int * pnCount) {
	int i = *pnCount;
	if (i < 0 || i >= g_nNum) {
		printf("插入位置异常： %d \n", i);
		return;
	}

	char website[200];
	char userName[200];
	char passWord[200];
	char note[200];
	printf("请输入<目标站点>：\n");
	//scanf_s("%s",website,200);
	gets_s(website);                 //可以带有空格输入
	printf("请输入<用户名>：\n");
	gets_s(userName);
	//scanf_s("%s",userName,200);
	printf("请输入<密码>：\n");
	gets_s(passWord);
	//scanf_s("%s",passWord, 200);
	printf("请输入<备注信息>：\n");
	gets_s(note);
	//scanf_s("%s",note, 200);



	strcpy_s(pPwd[i].website, strlen(website) + 1, website);
	strcpy_s(pPwd[i].userName, strlen(userName) + 1, userName);
	strcpy_s(pPwd[i].passWord, strlen(passWord) + 1, passWord);
	strcpy_s(pPwd[i].note, strlen(note) + 1, note);

	(*pnCount)++;

	savePwd(pPwd, pnCount);

	printf("\n");
	system("pause");
	system("cls");

}

//删除密码，参数为密码本类型指针，当前密码个数的指针
void deletePwd(PASSWORD* pPwd, int * pnCount) {
	int i = -1;
	int flag = 1;
	while (flag) {
		getchar();
		printf("请输入待删除项<密码ID>\n");
		scanf_s("%d", &i);

		if (i < 0 || i >= *pnCount) {
			printf("删除位置异常： %d \n", i);
			return;
		}
		getchar();
		printf("请确认是否删除！（y是n否）:\n");
		char dele = getchar();

		if (dele == 'y' || dele == 'Y') {

			for (size_t j = i; j < *pnCount - 1; j++) {
				//pPwd[j] = pPwd[j + 1];
				strcpy_s(pPwd[j].website, strlen(pPwd[j + 1].website) + 1, pPwd[j + 1].website);//复制目标，复制长度，复制源
				strcpy_s(pPwd[j].userName, strlen(pPwd[j + 1].userName) + 1, pPwd[j + 1].userName);
				strcpy_s(pPwd[j].passWord, strlen(pPwd[j + 1].passWord) + 1, pPwd[j + 1].passWord);
				strcpy_s(pPwd[j].note, strlen(pPwd[j + 1].note) + 1, pPwd[j + 1].note);
			}

			(*pnCount)--;

			savePwd(pPwd, pnCount);
			printf("修改成功！\n");
			printf("\n");
			flag = 0;
		}
		else if (dele == 'n' || dele == 'N') { flag = 0; printf("退出\n"); }
		else {
			printf("输入错误，请重新输入！\n");
			flag = 0;
		}
		system("pause");
		system("cls");
	}
}

//修改密码，参数为密码本类型指针，当前密码个数的指针
void alterPwd(PASSWORD* pPwd, int* pnCount) {
	int i = -1;
	int flag = 1;

	while (flag) {
		getchar();
		printf("请输入待修改项<密码ID>\n");
		scanf_s("%d", &i);

		if (i < 0 || i >= *pnCount) {
			printf("修改位置异常： %d \n", i);
			return;
		}

		printf("--ID: %d-------------------\n", i);
		printf("目标：%s \n", pPwd[i].website);
		printf("用户名：%s \n", pPwd[i].userName);
		printf("密码：%s \n", pPwd[i].passWord);
		printf("备注：%s \n", pPwd[i].note);

		printf("～修改～\n");

		getchar();
		printf("请确认是否修改！（y是n否）:\n");
		char modi = getchar();

		if (modi == 'y' || modi == 'Y') {
			PASSWORD pass;
			printf("请输入<目标站点>\n");
			//	scanf_s("%s", pass.website, 100);
			gets_s(pass.website);
			strcpy_s(pPwd[i].website, strlen(pass.website) + 1, pass.website);
			printf("请输入<用户名>\n");
			//	scanf_s("%s", pass.userName, 100);
			gets_s(pass.userName);
			strcpy_s(pPwd[i].userName, strlen(pass.userName) + 1, pass.userName);
			printf("请输入<密码>\n");
			//	scanf_s("%s", pass.passWord, 100);
			gets_s(pass.passWord);
			strcpy_s(pPwd[i].passWord, strlen(pass.passWord) + 1, pass.passWord);
			printf("请输入<备注信息>\n");
			//	scanf_s("%s", pass.note, 100);
			gets_s(pass.note);
			strcpy_s(pPwd[i].note, strlen(pass.note) + 1, pass.note);
			savePwd(pPwd, pnCount);
			flag = 0;
			printf("修改成功！\n");
		}
		else if (modi == 'n' || modi == 'N') {
			flag = 1;
			printf("退出！！\n");
		}
		else {
			printf("输入错误，请重新操作！！\n");
			flag = 1;
		}
	}

	printf("\n");
	system("pause");
	system("cls");
}

//查询某密码，参数为密码本类型指针，当前密码个数
void searchPwd(PASSWORD*  pPwd, int nCount) {
	char key[100] = { 0 };
	printf("请输入查找密码的关键字：\n");
	scanf_s("%s[^\n]", key, 100);

	int findPwd[100] = { 0 };

	int nfindCount = 0;

	for (size_t i = 0; i < nCount; i++) {
		if (strcmp(pPwd[i].website, key) == 0) {
			findPwd[nfindCount++] = i;
			continue;
		}
		else if (strcmp(pPwd[i].userName, key) == 0) {
			findPwd[nfindCount++] = i;
			continue;
		}
		else if (strcmp(pPwd[i].passWord, key) == 0) {
			findPwd[nfindCount++] = i;
			continue;
		}
		else if (strcmp(pPwd[i].note, key) == 0) {
			findPwd[nfindCount++] = i;
			continue;
		}
		else printf("查找不到匹配项\n");

	}

	printf("======共计匹配：%3d 条记录==================\n", nfindCount);

	for (size_t i = 0; i < nfindCount; i++) {
		int pos = findPwd[i];

		printf("--ID: %3d-------------------\n", i);
		printf("目标：%s \n", pPwd[i].website);
		printf("用户名：%s \n", pPwd[i].userName);
		printf("密码：%s \n", pPwd[i].passWord);
		printf("备注：%s \n", pPwd[i].note);

		printf("\n");
		system("pause");
		system("cls");
	}
}


//保存整个密码本数据，参数为密码本类型指针，当前密码个数的指针
void savePwd(PASSWORD* pPwd, int* pnCount) {
	FILE* pFile;
	int ret = 0;
	ret = fopen_s(&pFile, "data.i", "wb");

	if (ret != 0) { printf("打开文件失败！"); return; }

	printf("当前保存的个数是:%d\n", *pnCount);
	fwrite(pnCount, sizeof(pnCount), 1, pFile);
	fwrite(&g_nNum, sizeof(g_nNum), 1, pFile);


	int byteSize = sizeof(PASSWORD)*g_nNum;
	char* buf = (char*)malloc(byteSize);
	memcpy_s(buf, byteSize, pPwd, byteSize);
	for (size_t i = 0; i < byteSize; i++) {   //加密
		buf[i] ^= (i + *pnCount + g_nNum);
		//buf[i] ^= 5;
	}
	//g_nNum = nCount;

	size_t rlen = fwrite(buf, sizeof(PASSWORD), g_nNum, pFile);
	if (rlen != g_nNum) {
		printf("写入文件密码错误\n");
	}
	else { printf("写入成功！！\n"); }


	fclose(pFile);
	free(buf);
}

//初始化读取密码本数据，返回值为密码本类型指针，参数为密码本类型指针，当前密码个数的指针
PASSWORD* readPwd(PASSWORD *pPwd, int* pnCount) {
	FILE* pFile;
	errno_t err = fopen_s(&pFile, "data.i", "rb");

	if (err != 0) {//打开失败
		pPwd = (PASSWORD*)malloc(sizeof(PASSWORD)*NUM);//定义密码本堆空间
		g_nNum = NUM;
		return pPwd;
	}
	g_nNum = NUM;
	//pnCount = 0;
	fread(pnCount, sizeof(int), 1, pFile);//当前密码个数

	//if (pnCount == nullptr) { pnCount = 0; }

	fread(&g_nNum, sizeof(g_nNum), 1, pFile);//当前密码本容量个数

	if (g_nNum == 0) { g_nNum = NUM; }

	pPwd = (PASSWORD*)malloc(sizeof(PASSWORD)*g_nNum);//定义密码本堆空间
	memset(pPwd, 0, sizeof(PASSWORD)*g_nNum);//初始化堆空间

	size_t rlen = fread_s(pPwd, sizeof(PASSWORD)*g_nNum, sizeof(PASSWORD), g_nNum, pFile);//读取密码数组
	if (rlen != g_nNum) {
		printf("读取文件密码错误或者文件为空\n");
		fclose(pFile);
		return pPwd;
	}

	int byteSize = sizeof(PASSWORD)*g_nNum;
	char* buf = (char*)pPwd;//加密数组


	for (size_t i = 0; i < byteSize; i++) {   //解密
		buf[i] ^= (i + *pnCount + g_nNum);
		//buf[i] ^= 5;
	}
	pPwd = (PASSWORD*)buf;//转密码本数组
	fclose(pFile);
	return pPwd;
}