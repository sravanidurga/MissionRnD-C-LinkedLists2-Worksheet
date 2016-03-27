/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	struct node *prev = NULL, *curr = NULL, *temp = NULL,*newnode=NULL;
	int count = 0, i = 0;
	if (head == NULL || K <= 0)
		return NULL;
	curr = head;
	while (curr)
	{
		count++;
		curr = curr->next;
	}
	if (count < K)
		return head;
	else
	{
		temp = curr = head;
		for (i = 1; i <= count; i++)
		{
			if (i%K == 0)
			{
				newnode = (struct node *)malloc(sizeof(struct node));
				newnode->num = K;
				newnode->next = NULL;
				newnode->next = temp->next;
				temp->next = newnode;
				curr = temp;
				temp = temp->next;

			}
			curr = temp;
			temp = temp->next;
		}

	}
	return head;
}

