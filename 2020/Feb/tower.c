#if 0
#include <stdio.h>

struct st_park {
	int isFull;
	int price;
} parkingLot[101];

struct st_car {
	int loc;
	int weight;
} cars[2001];

int n, m;
int waitingQueue[4000000];
int qHead = 0, qTail = 0;

void waitingIn(void) {
	int carNo;
	carNo = waitingQueue[qHead++];
	carIn(carNo);
}

int carIn(int carNo) {
	for (int i = 1; i <= n; i++) {
		if (parkingLot[i].isFull == 0) {
			parkingLot[i].isFull = 1;
			cars[carNo].loc = i;
			//printf("car no: %d, loc no: %d, price: %d\n", carNo, i, parkingLot[i].price * cars[carNo].weight);
			return 0;
		}
	}
	waitingQueue[qTail++] = carNo;
	return 0;
}

int carOut(int carNo) {
	int indx;
	indx = cars[carNo].loc;
	parkingLot[indx].isFull = 0;
	if (qHead < qTail) waitingIn();
	return parkingLot[indx].price * cars[carNo].weight;
}

void start(int testCase) {
	int i, input, sum = 0;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d", &parkingLot[i].price);
	}
	for (i = 1; i <= m; i++) {
		scanf("%d", &cars[i].weight);
	}

	for (i = 0; i < m * 2; i++) {
		scanf("%d", &input);
		if (input > 0) {
			carIn(input);
		}
		else {
			sum += carOut(input * -1);
		}
	}
	printf("#%d %d\n", testCase, sum);
}

int main(void) {
	int TC;
	scanf("%d", &TC);

	for (int t = 1; t <= TC; t++) {
		start(t);
	}

	return 0;
}
#endif