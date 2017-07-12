#include <stdio.h>

#define MAX_LINKED_LIST_NUM 5
#define TRUE 1
#define FALSE 0


typedef struct _LINKED_LIST_NODE_TYPE_
{
	void* pNext;

	int Value;
}LINKED_LIST_NODE_TYPE, *PLINKED_LIST_NODE_TYPE;

int main()
{
	PLINKED_LIST_NODE_TYPE ptHeadNode = NULL;
	PLINKED_LIST_NODE_TYPE ptTailNode = NULL;
	PLINKED_LIST_NODE_TYPE ptNewNode = NULL;

	char loopCondition = TRUE;
	int inputValue = 0;

	while (loopCondition)
	{
		printf("1 : insert data\r\n");
		printf("2 : delete data\r\n");
		printf("3 : show data\r\n");
		printf("0 : exit\r\n");

		scanf_s("%d", &inputValue);

		switch (inputValue)
		{
		case 0:
			loopCondition = FALSE;
			break;
		case 1:
			printf("enter input value\r\n");
			scanf_s("%d", &inputValue);

			ptNewNode = (PLINKED_LIST_NODE_TYPE)malloc(sizeof(LINKED_LIST_NODE_TYPE));



			break;

		}
	}

	return 0;
}