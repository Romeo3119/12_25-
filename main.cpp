#include "doubleLink.h"

int main()
{
	DLinkList pHead;
	initDLinkList(&pHead);

	cout << "Î²²å:" << endl;
	insertBackDataToDLinkList(&pHead, 2);
	insertBackDataToDLinkList(&pHead, 3);
	insertBackDataToDLinkList(&pHead, 4);
	insertBackDataToDLinkList(&pHead, 5);
	printDLinkListData(&pHead);

	cout << "Í·²å:" << endl;
	insertFrontDataToDLinkList(&pHead, 1);
	printDLinkListData(&pHead);

	cout << "Î²É¾:" << endl;
	delBackData(&pHead);
	printDLinkListData(&pHead);

	cout << "Í·É¾:" << endl;
	delFrontData(&pHead);
	printDLinkListData(&pHead);

	destroyDLinkList(&pHead);
	printDLinkListData(&pHead);

	system("pause");
	return 0;
}