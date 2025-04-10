#include <stdio.h>
#include <stdbool.h>

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
    return (row >= 0 && row < MAX_ROW && col >= 0 && col < MAX_COLUMN);
}

void findSurroundingPoint(int row, int col, point_t* surroundingPnt[4], int *count) {
    int rowIndex[4] = {-1, 0, 0, 1};
    int colIndex[4] = {0, -1, 1, 0};
    int tempCnt = 0;
    for (int i = 0; i < 4; i++) {
        int row_i = row + rowIndex[i];
        int col_i = col + colIndex[i];
        if (checkCoordinate(row_i, col_i) && matrix[row_i][col_i].value == 1) {
            surroundingPnt[tempCnt] = &matrix[row_i][col_i];
            tempCnt++;
        }
    }
    *count = tempCnt;
}

void findShortestPath(int row, int col) {
    Queue queue;
    initQueue(&queue);
    matrix[0][0].visited = true;
    enQueue(&queue, matrix[0][0]);
    bool found = false;

    while (!isEmpty(queue) && !found) {
        point_t p = deQueue(&queue);
        point_t* surroundingPnt[4];
        int count;
        findSurroundingPoint(p.row, p.column, surroundingPnt, &count);
        for (int i = 0; i < count; i++) {
            point_t* next = surroundingPnt[i];
            if (!next->visited) {
                next->visited = true;
                next->prev = &matrix[p.row][p.column];
                if (next->row == row && next->column == col) {
                    found = true;
                    break;
                } else {
                    enQueue(&queue, *next);
                }
            }
        }
    }

    if (found) {
        // Truy ngược và lưu đường đi vào danh sách
        point_t *current = &matrix[row][col];
        point_t *path[MAX_ROW * MAX_COLUMN]; // Mảng lưu trữ đường đi
        int path_length = 0;
    
        while (current != NULL) {
            path[path_length++] = current;
            current = current->prev;
        }
    
        // In đường đi từ điểm bắt đầu đến điểm đích
        printf("Duong di tu vi tri (0,0) toi (%d,%d): ", row, col);
        for (int i = path_length - 1; i >= 0; i--) {
            printf("(%d,%d) ", path[i]->row, path[i]->column);
        }
        printf("\n");
    } else {
        printf("Khong co duong di tu (0,0) den (%d,%d)\n", row, col);
    }
}

void input() {
    int targetRow, targetCol;
    int temp[9][9] = {
        {1,0,0,0,1,0,1,1,0},
        {1,1,0,1,1,1,0,0,1},
        {0,1,0,0,0,0,0,1,0},
        {0,1,0,0,0,0,0,0,0},
        {0,1,1,1,0,0,0,0,0},
        {0,1,0,1,0,0,0,0,0},
        {0,1,1,1,1,1,0,0,0},
        {0,1,0,1,0,1,0,0,0},
        {1,1,1,1,1,1,1,1,1}
    };

    // Khởi tạo ma trận điểm với các giá trị
    for (int i = 0; i < MAX_ROW; i++) {
        for (int j = 0; j < MAX_COLUMN; j++) {
            matrix[i][j].value = temp[i][j];
            matrix[i][j].row = i;
            matrix[i][j].column = j;
            matrix[i][j].visited = false;
            matrix[i][j].prev = NULL;
        }
    }

    do {
        printf("Nhap toa do dich (row col) (0 <= row < %d, 0 <= col < %d): ", MAX_ROW, MAX_COLUMN);
        scanf("%d %d", &targetRow, &targetCol);
    } while (!checkCoordinate(targetRow, targetCol));

    findShortestPath(targetRow, targetCol);
}


int main(){
	input();
	return 0;
}
