#include <stdio.h>

#define MAX_LINKED_LIST_NUM 5
#define TRUE 1
#define FALSE 0


typedef struct _LINKED_LIST_NODE_TYPE_
{
	struct _LINKED_LIST_NODE_TYPE_* pNext;

	int Value;
}LINKED_LIST_NODE_TYPE, *PLINKED_LIST_NODE_TYPE;

PLINKED_LIST_NODE_TYPE NODE_ALLOC()
{
	PLINKED_LIST_NODE_TYPE ptNode = (PLINKED_LIST_NODE_TYPE)malloc(sizeof(LINKED_LIST_NODE_TYPE));
	memset(ptNode, 0x0, sizeof(LINKED_LIST_NODE_TYPE));

	return  ptNode;
}

int main()
{
	PLINKED_LIST_NODE_TYPE ptHeadNode = NULL;
	PLINKED_LIST_NODE_TYPE ptSearchNode = NULL;
	PLINKED_LIST_NODE_TYPE ptPrevNode = NULL;
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

			ptNewNode = NODE_ALLOC();
			
			if (ptNewNode == NULL)
			{
				printf("Node alloc error\r\n");
				break;
			}

			ptNewNode->Value = inputValue;
			
			if (ptHeadNode == NULL)
			{
				ptHeadNode = ptNewNode;
			}
			else
			{
				ptSearchNode = ptHeadNode;
				while (ptSearchNode)
				{
					if (ptSearchNode->pNext == NULL)
					{
						break;
					}

					ptSearchNode = ptSearchNode->pNext;
				}

				ptSearchNode->pNext = ptNewNode;
			}

			break;
		case 2:
			printf("enter delete value\r\n");
			scanf_s("%d", &inputValue);

			if (ptHeadNode == NULL)
			{
				printf("list is empty");
				break;
			}

			ptSearchNode = ptHeadNode;
			ptPrevNode = ptHeadNode;
			while (ptSearchNode)
			{				
				if (ptSearchNode->Value == inputValue)
				{
					if (ptSearchNode == ptHeadNode)
					{
						ptHeadNode = ptSearchNode->pNext;
					}
					else
					{
						ptPrevNode->pNext = ptSearchNode->pNext;
					}

					free(ptSearchNode);

					break;
				}

				ptPrevNode = ptSearchNode;
				ptSearchNode = ptSearchNode->pNext;
			}


			break;
		case 3:
			ptSearchNode = ptHeadNode;
			while (ptSearchNode)
			{
				printf("%d\r\n", ptSearchNode->Value);

				ptSearchNode = ptSearchNode->pNext;
			}

			break;
		}

	}

	return 0;
}