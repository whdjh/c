#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct {
	int key;
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} heaptype;

heaptype *create()
{
	return (heaptype *)malloc(sizeof(heaptype));
}

void init(heaptype *h)
{
	h -> heap_size = 0;
}

//현재요소의 개수가 heap_size인 히프에 item삽입!
void insert_max_heap(heaptype *h, element item)
{
	int i;
	i = ++(h -> heap_size);

	while((i != 1) && (item.key > h -> heap[i / 2].key))	//트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	{
		h -> heap[i] = h -> heap[i / 2];
		i /= 2;
	}
	h -> heap[i] = item;									//새로운 노드 삽입
}

element delete_max_heap(heaptype *h)
{
	int parent, child;
	element item, tmp;

	item = h -> heap[1];
	tmp = h -> heap[(h -> heap_size)--];
	parent = 1;
	child = 2;
	while(child <= h -> heap_size)				//현재 노드의 자식 중 더 큰 자식노드를 찾는다.
	{
		if((child < h -> heap_size) && (h -> heap[child].key) < h -> heap[child + 1].key)
			child++;
		if(tmp.key >= h -> heap[child].key)
			break;
		h -> heap[parent] = h -> heap[child];	//한단계 아래로 이동.
		parent = child;
		child *= 2;
	}
	h -> heap[parent] = tmp;
	return item;
}

int main()
{
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 };
	element e4, e5, e6;
	heaptype *heap;

	heap = create();
	init(heap);

	insert_max_heap(heap, e1);
	insert_max_heap(heap, e2);
	insert_max_heap(heap, e3);

	e4 = delete_max_heap(heap);
	printf("< %d > ", e4.key);
	e5 = delete_max_heap(heap);
	printf("< %d > ", e5.key);
	e6 = delete_max_heap(heap);
	printf("< %d > ", e6.key);
	free(heap);
	return 0;
}