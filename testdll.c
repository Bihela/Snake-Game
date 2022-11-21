#define MAX_LENGTH 10
#DEFINE UP 0

void testdll(){


	typedef struct Node{
		int x;
		int y;
		int dir;	
	}Node;

    DoubleLinkedListNode* lastVal; 
    DoubleLinkedList* list;
    list = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
    list->head = NULL;
	list->tail = NULL;

	Node snake[MAX_LENGTH]; 
	snake[0].x = 5;
	snake[0].y = 5;
	snake[0].dir = UP;
	
	
	snake[1].x = 5;
	snake[1].y = 4;
	snake[1].dir = UP;
	
	snake[2].x = 4;
	snake[2].y = 4;
	snake[2].dir = RIGHT;

	insertFirst(list,(void *) &snake[0]);
	insertFirst(list,(void *) &snake[1]);
	insertFirst(list,(void *) &snake[2]);

	DoubleLinkedListNode* current;
	current = list->head;
	while(current == list->tail){
		
		Node * snakeC = (Node *) current->data;
		printf("x:%d y: %d dir:%d\n",snakeC->x,snakeC->y,snakeC->dir);
		
		current = list-> next;
	}
	
return 0;
}