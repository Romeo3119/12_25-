#include <iostream>

using namespace std;
typedef int DLDataType;

typedef struct DLinkListNode{
	DLDataType data;
	struct DLinkListNode* p_next;
	struct DLinkListNode* p_prev;
}DLinkListNode;

typedef DLinkListNode DLinkList;


//��ʼ��˫������
void initDLinkList(DLinkListNode* pHead)
{
	pHead->p_next = pHead;
	pHead->p_prev = pHead;
	cout << "˫�������ʼ�����!" << endl;
}

//�����½ڵ�
DLinkListNode* buyNewNode()
{
	DLinkListNode* newNode = new DLinkListNode();
	return newNode;
}

//β������
void insertBackDataToDLinkList(DLinkListNode* pHead, DLDataType data)
{
	//������һ��ͷ�ڵ�
	if (pHead->p_next == pHead && pHead->p_prev == pHead)
	{
		DLinkListNode* newNode = buyNewNode();
		newNode->data = data;
		pHead->p_next = newNode;
		pHead->p_prev = newNode;
		newNode->p_prev = pHead;
		newNode->p_next = pHead;
		return;
	}
	DLinkListNode* newNode = buyNewNode();
	newNode->data = data;
	//����ʱҪ�ҵ����һ���ڵ㣬��Ϊ��˫������,���һ���ڵ㼴ΪpHead->p_prev;
	DLinkListNode* lastNode = pHead->p_prev;
	lastNode->p_next = newNode;
	newNode->p_prev = lastNode;
	newNode->p_next = pHead;
	pHead->p_prev = newNode;
}

//ͷ������
void insertFrontDataToDLinkList(DLinkListNode* pHead, DLDataType data)
{
	//������Ϊ�գ�ͷ�弴Ϊβ��
	if (pHead->p_next == pHead && pHead->p_prev == pHead)
	{
		insertBackDataToDLinkList(pHead, data);
		return;
	}

	//����Ϊ��
	DLinkListNode* newNode = buyNewNode();
	newNode->data = data;

	newNode->p_next = pHead->p_next;
	pHead->p_next->p_prev = newNode;
	pHead->p_next = newNode;
	newNode->p_prev = pHead;

}

//βɾ����
void delBackData(DLinkListNode* pHead)
{
	//����Ϊ��
	if (pHead->p_next == pHead && pHead->p_prev == pHead)
	{
		cout << "����Ϊ��!" << endl;
		return;
	}

	//��Ϊ��
	DLinkListNode* lastNode = pHead->p_prev;
	pHead->p_prev = lastNode->p_prev;
	lastNode->p_prev->p_next = pHead;
	delete lastNode;
	lastNode = nullptr;
}

//ͷɾ����
void delFrontData(DLinkListNode* pHead)
{
	//����Ϊ��
	if (pHead->p_next == pHead && pHead->p_prev == pHead)
	{
		cout << "����Ϊ��!" << endl;
		return;
	}

	//������һ����Ч�ڵ㣬ͷɾ��βɾ
	if (pHead->p_next->p_next == pHead && pHead->p_prev == pHead->p_next)
	{
		delBackData(pHead);
	}

	//�����ɸ��ڵ�
	DLinkListNode* firstNode = pHead->p_next;
	pHead->p_next = firstNode->p_next;
	firstNode->p_next->p_prev = firstNode->p_prev;
	delete firstNode;
	firstNode = nullptr;
}

//����˫������
void destroyDLinkList(DLinkListNode* pHead)
{
	//�����Ѿ�Ϊ�գ�����ֻ��һ��pHead��û��������ЧԪ�أ�
	if (pHead->p_next == pHead && pHead->p_prev == pHead)
	{
		//�˴�����ʹ�� delete pHead,��ΪpHeadΪջ�ڴ棬��deleteֻ���ͷŶ��ڴ档
		pHead = nullptr;
		cout << "�������ٳɹ�!" << endl;
		return;
	}

	//����������Ԫ��
	while (pHead->p_next != pHead && pHead->p_prev != pHead)
	{
		//һֱβɾ����ͷɾ���˴�����βɾ
		delBackData(pHead);
	}
	//�ٽ�����ͷ�ڵ��ͷŵ�
	pHead = nullptr;
	cout << "�������ٳɹ�!" << endl;
}

//��ӡ����
void printDLinkListData(DLinkListNode* pHead)
{
	//������Ϊ��
	if (pHead->p_next == pHead && pHead->p_prev == pHead)
	{
		cout << "����Ϊ��!" << endl;
		return;
	}
	//��Ϊ��
	DLinkListNode* pCur = pHead->p_next;
	while (pCur != pHead)
	{
		cout << pCur->data << "-->";
		pCur = pCur->p_next;
	}
	cout << pHead->p_next->data;  //����˫��ѭ��
	cout << endl;
}