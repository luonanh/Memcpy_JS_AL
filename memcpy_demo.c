// https://www.youtube.com/watch?v=NqUTiJPgBn8
#include <stdio.h>
#include <string.h>

#define NODE_OFFSET	10
#define BUFFER_SIZE	4096

typedef struct node {
	unsigned int isvalid : 1;
	unsigned int size : 15;
	struct node *next;
} node_t;

int main()
{
	node_t n = {.isvalid = 1, .size = 367, .next = NULL};
	node_t n2;
	node_t n3;
	node_t *n4;
	char buf[BUFFER_SIZE];

	n2 = n;
	printf("n2 = %d, %d, %p\n", n2.isvalid, n2.size, n2.next);

	memcpy(&n3, &n, sizeof(node_t));
	printf("n3 = %d, %d, %p\n", n3.isvalid, n3.size, n3.next);

	memset(buf, 0xA5, BUFFER_SIZE);
	n4 = (node_t *)(buf + NODE_OFFSET);
	printf("n4 = %d, %d, %p\n", n4->isvalid, n4->size, n4->next);
	memcpy(buf + NODE_OFFSET, &n, sizeof(n));
	n4 = (node_t *)(buf + NODE_OFFSET);
	printf("n4 = %d, %d, %p\n", n4->isvalid, n4->size, n4->next);

	return 0;
}
