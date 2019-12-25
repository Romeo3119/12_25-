#include "doubleLink.h"

int main()
{
	DLinkList pHead;
	initDLinkList(&pHead);

	cout << "β��:" << endl;
	insertBackDataToDLinkList(&pHead, 2);
	insertBackDataToDLinkList(&pHead, 3);
	insertBackDataToDLinkList(&pHead, 4);
	insertBackDataToDLinkList(&pHead, 5);
	printDLinkListData(&pHead);

	cout << "ͷ��:" << endl;
	insertFrontDataToDLinkList(&pHead, 1);
	printDLinkListData(&pHead);

	cout << "βɾ:" << endl;
	delBackData(&pHead);
	printDLinkListData(&pHead);

	cout << "ͷɾ:" << endl;
	delFrontData(&pHead);
	printDLinkListData(&pHead);

	destroyDLinkList(&pHead);
	printDLinkListData(&pHead);

	system("pause");
	return 0;
}