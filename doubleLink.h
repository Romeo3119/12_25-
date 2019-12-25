#include <iostream>

using namespace std;
typedef int DLDataType;

typedef struct DLinkListNode{
	DLDataType data;
	struct DLinkListNode* p_next;
	struct DLinkListNode* p_prev;
}DLinkListNode;

typedef DLinkListNode DLinkList;


//初始化双向链表
void initDLinkList(DLinkListNode* pHead)
{
	pHead->p_next = pHead;
	pHead->p_prev = pHead;
	cout << "双向链表初始化完成!" << endl;
}

//申请新节点
DLinkListNode* buyNewNode()
{
	DLinkListNode* newNode = new DLinkListNode();
	return newNode;
}

//尾插数据
void insertBackDataToDLinkList(DLinkListNode* pHead, DLDataType data)
{
	//若仅有一个头节点
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
	//插入时要找到最后一个节点，因为是双向链表,最后一个节点即为pHead->p_prev;
	DLinkListNode* lastNode = pHead->p_prev;
	lastNode->p_next = newNode;
	newNode->p_prev = lastNode;
	newNode->p_next = pHead;
	pHead->p_prev = newNode;
}

//头插数据
void insertFrontDataToDLinkList(DLinkListNode* pHead, DLDataType data)
{
	//若链表为空，头插即为尾插
	if (pHead->p_next == pHead && pHead->p_prev == pHead)
	{
		insertBackDataToDLinkList(pHead, data);
		return;
	}

	//若不为空
	DLinkListNode* newNode = buyNewNode();
	newNode->data = data;

	newNode->p_next = pHead->p_next;
	pHead->p_next->p_prev = newNode;
	pHead->p_next = newNode;
	newNode->p_prev = pHead;

}

//尾删数据
void delBackData(DLinkListNode* pHead)
{
	//链表为空
	if (pHead->p_next == pHead && pHead->p_prev == pHead)
	{
		cout << "链表为空!" << endl;
		return;
	}

	//不为空
	DLinkListNode* lastNode = pHead->p_prev;
	pHead->p_prev = lastNode->p_prev;
	lastNode->p_prev->p_next = pHead;
	delete lastNode;
	lastNode = nullptr;
}

//头删数据
void delFrontData(DLinkListNode* pHead)
{
	//链表为空
	if (pHead->p_next == pHead && pHead->p_prev == pHead)
	{
		cout << "链表为空!" << endl;
		return;
	}

	//若仅有一个有效节点，头删即尾删
	if (pHead->p_next->p_next == pHead && pHead->p_prev == pHead->p_next)
	{
		delBackData(pHead);
	}

	//有若干个节点
	DLinkListNode* firstNode = pHead->p_next;
	pHead->p_next = firstNode->p_next;
	firstNode->p_next->p_prev = firstNode->p_prev;
	delete firstNode;
	firstNode = nullptr;
}

//销毁双向链表
void destroyDLinkList(DLinkListNode* pHead)
{
	//链表已经为空（本身只有一个pHead，没有其他有效元素）
	if (pHead->p_next == pHead && pHead->p_prev == pHead)
	{
		//此处不能使用 delete pHead,因为pHead为栈内存，而delete只能释放堆内存。
		pHead = nullptr;
		cout << "链表销毁成功!" << endl;
		return;
	}

	//链表有其他元素
	while (pHead->p_next != pHead && pHead->p_prev != pHead)
	{
		//一直尾删或者头删，此处采用尾删
		delBackData(pHead);
	}
	//再将最后的头节点释放掉
	pHead = nullptr;
	cout << "链表销毁成功!" << endl;
}

//打印数据
void printDLinkListData(DLinkListNode* pHead)
{
	//若链表为空
	if (pHead->p_next == pHead && pHead->p_prev == pHead)
	{
		cout << "链表为空!" << endl;
		return;
	}
	//不为空
	DLinkListNode* pCur = pHead->p_next;
	while (pCur != pHead)
	{
		cout << pCur->data << "-->";
		pCur = pCur->p_next;
	}
	cout << pHead->p_next->data;  //代表双向循环
	cout << endl;
}