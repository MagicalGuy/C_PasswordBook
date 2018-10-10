#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"data.h"
#include"ctrl.h"

//��ѯ�������룬����Ϊ���뱾����ָ�룬��ǰ�������
void searchAllPwd(PASSWORD* pPwd, int nCount) {
	printf("=========����ѯ�Ľ��һ���������� %3d ����¼=========\n", nCount);
	for (int i = 0; i < nCount; i++) {
		printf("--ID: %d-------------------\n", i);
		printf("Ŀ�꣺%s \n", pPwd[i].website);
		printf("�û�����%s \n", pPwd[i].userName);
		printf("���룺%s \n", pPwd[i].passWord);
		printf("��ע��%s \n", pPwd[i].note);
	}
	printf("\n");
	system("pause");
	system("cls");

}

//�������룬����Ϊ���뱾����ָ�룬��ǰ���������ָ��
void insertPwd(PASSWORD* pPwd, int * pnCount) {
	int i = *pnCount;
	if (i < 0 || i >= g_nNum) {
		printf("����λ���쳣�� %d \n", i);
		return;
	}

	char website[200];
	char userName[200];
	char passWord[200];
	char note[200];
	printf("������<Ŀ��վ��>��\n");
	//scanf_s("%s",website,200);
	gets_s(website);                 //���Դ��пո�����
	printf("������<�û���>��\n");
	gets_s(userName);
	//scanf_s("%s",userName,200);
	printf("������<����>��\n");
	gets_s(passWord);
	//scanf_s("%s",passWord, 200);
	printf("������<��ע��Ϣ>��\n");
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

//ɾ�����룬����Ϊ���뱾����ָ�룬��ǰ���������ָ��
void deletePwd(PASSWORD* pPwd, int * pnCount) {
	int i = -1;
	int flag = 1;
	while (flag) {
		getchar();
		printf("�������ɾ����<����ID>\n");
		scanf_s("%d", &i);

		if (i < 0 || i >= *pnCount) {
			printf("ɾ��λ���쳣�� %d \n", i);
			return;
		}
		getchar();
		printf("��ȷ���Ƿ�ɾ������y��n��:\n");
		char dele = getchar();

		if (dele == 'y' || dele == 'Y') {

			for (size_t j = i; j < *pnCount - 1; j++) {
				//pPwd[j] = pPwd[j + 1];
				strcpy_s(pPwd[j].website, strlen(pPwd[j + 1].website) + 1, pPwd[j + 1].website);//����Ŀ�꣬���Ƴ��ȣ�����Դ
				strcpy_s(pPwd[j].userName, strlen(pPwd[j + 1].userName) + 1, pPwd[j + 1].userName);
				strcpy_s(pPwd[j].passWord, strlen(pPwd[j + 1].passWord) + 1, pPwd[j + 1].passWord);
				strcpy_s(pPwd[j].note, strlen(pPwd[j + 1].note) + 1, pPwd[j + 1].note);
			}

			(*pnCount)--;

			savePwd(pPwd, pnCount);
			printf("�޸ĳɹ���\n");
			printf("\n");
			flag = 0;
		}
		else if (dele == 'n' || dele == 'N') { flag = 0; printf("�˳�\n"); }
		else {
			printf("����������������룡\n");
			flag = 0;
		}
		system("pause");
		system("cls");
	}
}

//�޸����룬����Ϊ���뱾����ָ�룬��ǰ���������ָ��
void alterPwd(PASSWORD* pPwd, int* pnCount) {
	int i = -1;
	int flag = 1;

	while (flag) {
		getchar();
		printf("��������޸���<����ID>\n");
		scanf_s("%d", &i);

		if (i < 0 || i >= *pnCount) {
			printf("�޸�λ���쳣�� %d \n", i);
			return;
		}

		printf("--ID: %d-------------------\n", i);
		printf("Ŀ�꣺%s \n", pPwd[i].website);
		printf("�û�����%s \n", pPwd[i].userName);
		printf("���룺%s \n", pPwd[i].passWord);
		printf("��ע��%s \n", pPwd[i].note);

		printf("���޸ġ�\n");

		getchar();
		printf("��ȷ���Ƿ��޸ģ���y��n��:\n");
		char modi = getchar();

		if (modi == 'y' || modi == 'Y') {
			PASSWORD pass;
			printf("������<Ŀ��վ��>\n");
			//	scanf_s("%s", pass.website, 100);
			gets_s(pass.website);
			strcpy_s(pPwd[i].website, strlen(pass.website) + 1, pass.website);
			printf("������<�û���>\n");
			//	scanf_s("%s", pass.userName, 100);
			gets_s(pass.userName);
			strcpy_s(pPwd[i].userName, strlen(pass.userName) + 1, pass.userName);
			printf("������<����>\n");
			//	scanf_s("%s", pass.passWord, 100);
			gets_s(pass.passWord);
			strcpy_s(pPwd[i].passWord, strlen(pass.passWord) + 1, pass.passWord);
			printf("������<��ע��Ϣ>\n");
			//	scanf_s("%s", pass.note, 100);
			gets_s(pass.note);
			strcpy_s(pPwd[i].note, strlen(pass.note) + 1, pass.note);
			savePwd(pPwd, pnCount);
			flag = 0;
			printf("�޸ĳɹ���\n");
		}
		else if (modi == 'n' || modi == 'N') {
			flag = 1;
			printf("�˳�����\n");
		}
		else {
			printf("������������²�������\n");
			flag = 1;
		}
	}

	printf("\n");
	system("pause");
	system("cls");
}

//��ѯĳ���룬����Ϊ���뱾����ָ�룬��ǰ�������
void searchPwd(PASSWORD*  pPwd, int nCount) {
	char key[100] = { 0 };
	printf("�������������Ĺؼ��֣�\n");
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
		else printf("���Ҳ���ƥ����\n");

	}

	printf("======����ƥ�䣺%3d ����¼==================\n", nfindCount);

	for (size_t i = 0; i < nfindCount; i++) {
		int pos = findPwd[i];

		printf("--ID: %3d-------------------\n", i);
		printf("Ŀ�꣺%s \n", pPwd[i].website);
		printf("�û�����%s \n", pPwd[i].userName);
		printf("���룺%s \n", pPwd[i].passWord);
		printf("��ע��%s \n", pPwd[i].note);

		printf("\n");
		system("pause");
		system("cls");
	}
}


//�����������뱾���ݣ�����Ϊ���뱾����ָ�룬��ǰ���������ָ��
void savePwd(PASSWORD* pPwd, int* pnCount) {
	FILE* pFile;
	int ret = 0;
	ret = fopen_s(&pFile, "data.i", "wb");

	if (ret != 0) { printf("���ļ�ʧ�ܣ�"); return; }

	printf("��ǰ����ĸ�����:%d\n", *pnCount);
	fwrite(pnCount, sizeof(pnCount), 1, pFile);
	fwrite(&g_nNum, sizeof(g_nNum), 1, pFile);


	int byteSize = sizeof(PASSWORD)*g_nNum;
	char* buf = (char*)malloc(byteSize);
	memcpy_s(buf, byteSize, pPwd, byteSize);
	for (size_t i = 0; i < byteSize; i++) {   //����
		buf[i] ^= (i + *pnCount + g_nNum);
		//buf[i] ^= 5;
	}
	//g_nNum = nCount;

	size_t rlen = fwrite(buf, sizeof(PASSWORD), g_nNum, pFile);
	if (rlen != g_nNum) {
		printf("д���ļ��������\n");
	}
	else { printf("д��ɹ�����\n"); }


	fclose(pFile);
	free(buf);
}

//��ʼ����ȡ���뱾���ݣ�����ֵΪ���뱾����ָ�룬����Ϊ���뱾����ָ�룬��ǰ���������ָ��
PASSWORD* readPwd(PASSWORD *pPwd, int* pnCount) {
	FILE* pFile;
	errno_t err = fopen_s(&pFile, "data.i", "rb");

	if (err != 0) {//��ʧ��
		pPwd = (PASSWORD*)malloc(sizeof(PASSWORD)*NUM);//�������뱾�ѿռ�
		g_nNum = NUM;
		return pPwd;
	}
	g_nNum = NUM;
	//pnCount = 0;
	fread(pnCount, sizeof(int), 1, pFile);//��ǰ�������

	//if (pnCount == nullptr) { pnCount = 0; }

	fread(&g_nNum, sizeof(g_nNum), 1, pFile);//��ǰ���뱾��������

	if (g_nNum == 0) { g_nNum = NUM; }

	pPwd = (PASSWORD*)malloc(sizeof(PASSWORD)*g_nNum);//�������뱾�ѿռ�
	memset(pPwd, 0, sizeof(PASSWORD)*g_nNum);//��ʼ���ѿռ�

	size_t rlen = fread_s(pPwd, sizeof(PASSWORD)*g_nNum, sizeof(PASSWORD), g_nNum, pFile);//��ȡ��������
	if (rlen != g_nNum) {
		printf("��ȡ�ļ������������ļ�Ϊ��\n");
		fclose(pFile);
		return pPwd;
	}

	int byteSize = sizeof(PASSWORD)*g_nNum;
	char* buf = (char*)pPwd;//��������


	for (size_t i = 0; i < byteSize; i++) {   //����
		buf[i] ^= (i + *pnCount + g_nNum);
		//buf[i] ^= 5;
	}
	pPwd = (PASSWORD*)buf;//ת���뱾����
	fclose(pFile);
	return pPwd;
}