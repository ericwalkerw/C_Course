#include <stdio.h>

#define MAX_ROW 9
#define MAX_COLUMN 9
#define MAX 100

typedef struct POINT {
    int row;      // Toa do X
    int column;   // Toa do y
    int value;    // Gia tri cua nut
    bool visited; // danh dau da di qua hay chua
    struct POINT* prev; // con tro chi den nut lien truoc do truoc khi di den diem nay
} point_t;

point_t matrix[MAX_ROW][MAX_COLUMN];

typedef struct {
    point_t data[MAX];  // luu tru cac nut
    int front;          // dau hang doi
    int rear;         // cuoi hang doi
} Queue;


void initQueue(Queue *q) { // Khoi tao hang doi 
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue q) { //Kiem tra hang doi rong hay khong
    return (q.rear < q.front);
}

int isFull(Queue q) { //Kiem tra hang doi co day hay chua
    if((q.rear - q.front) == MAX - 1) {
    	return 1;
    }
    else {
		return 0;
    }
}

void enQueue(Queue *q, point_t x) { //Them phan tu vao hang rear
    if (!isFull(*q)) {
        if(q->rear == MAX - 1) {
            for(int i = q->front; i <= q->rear; i++){
                    q->data[i - q->front] = q->data[i];
                }
            q->rear = MAX - q->front - 1;
            q->front = 0;
        }
        q->rear = q->rear + 1;
        q->data[q->rear] = x;
    }
}

point_t deQueue(Queue *q) { //Lay phan tu ra khoi hang
    point_t d;   
    if (!isEmpty(*q)) {
       	d = q->data[q->front];
       	q->front = q->front +1;
    }
    if (q->front > q->rear) {
    	initQueue(q);
    }
    return d;
}

bool checkCoordinate(int row, int col) {
    bool ret = false;
    if ((0 <= row ) && (0 <= col)) {
        ret = true;
    }
    return ret;
}

void findSurroundingPoint(int row, int col, point_t surroundingPnt[4], int *count){
	int rowIndex[4] = {-1, 0, 0, 1};
	int colIndex[4] = {0, -1, 1, 0};
	int tempCnt = 0; //Khoi tao bien dem so luong cac nut co the di quanh 1 vi tri
	for(int i = 0; i < 4; i++){
		int row_i = row + rowIndex[i];
		int col_i = col + colIndex[i];
		if (checkCoordinate(row_i, col_i) && matrix[row_i][col_i].value == 1) {
    		surroundingPnt[tempCnt] = matrix[row_i][col_i];
    		tempCnt++;
		}
	}
	*count = tempCnt;
}

void findShortestPath (int row, int col) {
	Queue queue; //khai bao hang doi
	initQueue(&queue); //khoi tao hang doi
	matrix[0][0].visited = true; //danh dau diem da qua
	enQueue(queue, matrix[0][0]); //them vao hang doi
	bool found = false;
	
	while (!isEmpty(queue) && !found) {
        point_t p = deQueue(&queue);// lay ra phan tu dau tien
        point_t surroundingPnt[4]; //Mang luu tru cac nut xung quanh
        int count;
        findSurroundingPoint(p.row, p.column, surroundingPnt, &count); //Tim cac nut xung quanh cua nut p
		//=> ket qua se tra ra 4 nut xung quanh nut p
        for (int i = 0; i < count; i++) { //Duyet lan luot cac nut xung quanh cua p
            point_t next = surroundingPnt[i]; //nut i trong cac nut xung quanh p
            if (!next.visited) { //Kiem tra xem da di qua nut nay chua => chua di qua 
                next.visited = true;
                next.prev = &p; //luu tru nut truoc do
                if (next.row == row && next.column == col) {
                    found = true;
                    break;
                } else {
                    enQueue(&queue, next);
                }
            }
        }
    }

    if (found) {
        //Truy nguoc va in ra duong di
        point_t *current = &matrix[dong][cot];
        printf("Duong di tu vi tri (0,0) toi (%d,%d):\n", row, col);
        while (current != NULL) {
            printf("(%d,%d) ", current->row, current->column);
            current = current->prev;
        }
        printf("\n");
    } else {
        printf("Không có duong di tu (0,0) den (%d,%d)\n", dong, cot);
    }
}

void input(){
	
}

int main(){
	
	return 0;
}
