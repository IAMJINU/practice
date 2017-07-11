#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define MAX_QUEUE_SIZE 5

void main()
{
	int queue_a[MAX_QUEUE_SIZE] = { 0, };
	int queue_count = 0;
	int input_value = 0;
	int front_idx = 0;
	int tail_idx = 0;
	int check_idx = 0;
	int loop_condition = TRUE;

	while (loop_condition)
	{
		//input_value = getchar();
		scanf_s("%d", &input_value);
		//input_value -= 0xa;

		switch (input_value)
		{
		case 0:
			loop_condition = FALSE;
			break;
		case 1:
			if (queue_count == 0)
			{
				printf("Queue is empty\r\n");
				break;
			}

			printf("get queue value : %d(%d)\r\n", queue_a[tail_idx], tail_idx);

			queue_count -= 1;
			tail_idx += 1;

			if (tail_idx >= MAX_QUEUE_SIZE)
			{
				tail_idx = 0;
			}

			break;
		case 2:
			if (queue_count == 0)
			{
				printf("Queue empty\r\n");
				break;
			}

			check_idx = tail_idx;

			do
			{
				printf("(%d / %d) ", check_idx, queue_a[check_idx]);

				check_idx += 1;

				if (check_idx >= MAX_QUEUE_SIZE)
				{
					check_idx = 0;
				}

			} while (front_idx != check_idx);

			printf("\r\n");
			break;
		default:
			if (queue_count == MAX_QUEUE_SIZE)
			{
				printf("Queue is full\r\n");
				break;
			}

			queue_a[front_idx] = input_value;
			queue_count += 1;
			front_idx += 1;

			if (front_idx >= MAX_QUEUE_SIZE)
			{
				front_idx = 0;
			}
			break;
		}

	}


	return;
}