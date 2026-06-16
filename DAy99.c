/*Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
Sort cars by position in descending order and calculate time to reach target.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int position;
    int speed;
} Car;

// Sort by position descending
int compare(const void *a, const void *b) {
    return ((Car *)b)->position - ((Car *)a)->position;
}
int main() {
    int n, target;
    scanf("%d %d", &n, &target);

    Car cars[MAX];

    for (int i = 0; i < n; i++) {
        scanf("%d", &cars[i].position);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &cars[i].speed);
    }

    // Step 1: Sort by position descending
    qsort(cars, n, sizeof(Car), compare);

    int fleets = 0;
    double lastTime = 0;

    // Step 2: Process cars
    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].position) / cars[i].speed;

        if (time > lastTime) {
            fleets++;
            lastTime = time;
        }
    }

    printf("%d\n", fleets);

    return 0;
}
