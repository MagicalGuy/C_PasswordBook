#pragma once
//�鿴��������

void searchAllPwd(PASSWORD* pwd, int pnCount);//�鿴����վ��������Ϣ
void insertPwd(PASSWORD* pwd, int * pnCount);//����������Ϣ
void deletePwd(PASSWORD* pwd, int * pnCount);//ɾ������
void alterPwd(PASSWORD* pwd, int* pnCount);//�޸�����
void searchPwd(PASSWORD* pwd, int pnCount);//��ѯ����
void savePwd(PASSWORD * pwd, int *pnCount);//��������
PASSWORD* readPwd(PASSWORD * ppwd, int *pnCount);//��ʼ����ȡһЩ���뱾����
void savePass(char * str1);  //����������뱾�Ĳ�������
void modifyPass();//�޸ĸ������뱾�Ĳ�������
void loginOS();//�ò��������¼���뱾
void alterVolume(PASSWORD* ppwd, int *pnCount);//���뱾����
void initPassword();//�������뱾ϵͳ
void initPlayPass();//��ʼ����������