#include <stdio.h>
#include <malloc.h>
#include "util.h"

typedef struct {
    int balloonTime;
    int balloonsInRow;
    int restartTime;
    int balloonsAmount;
} Worker;

void scanWorker(Worker *worker) {
    scanf("%d %d %d",
          &worker->balloonTime,
          &worker->balloonsInRow,
          &worker->restartTime
    );
}

Worker* scanWorkers(const int amount) {
    Worker* workers = (Worker*) malloc(sizeof(Worker) * amount);

    for (int i = 0; i < amount; i++) {
        scanWorker(workers + i);
    }

    return workers;
}

long long getFullWorkTime(const Worker worker) {
    return worker.balloonTime * worker.balloonsInRow + worker.restartTime;
}

long long getWork(const Worker worker, const long long time) {
    long long fullWorkTime = getFullWorkTime(worker);
    long long fullWork = time / fullWorkTime * worker.balloonsInRow;
    long long partWork = minLL((time % fullWorkTime) / worker.balloonTime,worker.balloonsInRow);

    return fullWork + partWork;
}

long long getBalloonsAmount(const Worker *workers, const size_t size, const long long time) {
    long long balloonsAmount = 0;

    for (size_t i = 0; i < size; i++) {
        balloonsAmount += getWork(workers[i], time);
    }

    return balloonsAmount;
}

long long findUpper(const Worker *workers, const size_t size, const long long balloonsTotal, long long *workerBalloonsTotal) {
    const Worker firstWorker = workers[0];

    long long left = -1;
    long long right = (long long) ((double) balloonsTotal / firstWorker.balloonsInRow * getFullWorkTime(firstWorker) + 0.5) + 1;

    while (left < right - 1) {
        const long long middle = left + ((right - left) >> 1);
        const long long workerBalloonsAmount = getBalloonsAmount(workers, size,middle);

        if (workerBalloonsAmount >= balloonsTotal) {
            *workerBalloonsTotal = workerBalloonsAmount;
            right = middle;
        } else {
            left = middle;
        }
    }

    return right;
}

int main() {
    int ballonAmount, workerAmount;

    scanf("%d %d", &ballonAmount, &workerAmount);

    Worker* workers = scanWorkers(workerAmount);

    long long workerBallonAmount;
    const long long time = findUpper(workers, workerAmount, ballonAmount, &workerBallonAmount);
    long long delta = workerBallonAmount - ballonAmount;

    printf("%lld\n", time);

    for (int i = 0; i < workerAmount; i++) {
        Worker worker = workers[i];

        worker.balloonsAmount = getWork(worker, time);

        if (delta) {
            int currentDelta = min(workers[i].balloonsAmount, delta);

            worker.balloonsAmount -= currentDelta;
            delta -= currentDelta;
        }

        printf("%d ", worker.balloonsAmount);
    }
}