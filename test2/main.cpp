#include <stdio.h>
#include <errno.h>
#include <vector>
#include <string.h>
#include <sys/types.h>
#include <sched.h>

const int kMAX = 10000000;
int data[kMAX] = {0};

int pinThread(int coreId) {
  cpu_set_t mask;
  CPU_ZERO(&mask);
  CPU_SET(coreId, &mask);

  if (sched_setaffinity(0, sizeof(cpu_set_t), &mask) == -1) {
    const int rc = errno;
    printf("pinThread: %s (errno=%d)\n", strerror(rc), rc);
  }
  
  return 0;
}

int work() {
  volatile int sum = -1;
  for (int i=0; i<kMAX; ++i) {
    sum += data[i];
  }
  return sum;
}

int main() {
  pinThread(3);

  int sum = work();
  if (sum!=-1) {
    printf("expected -1 got %d\n", sum);
  }

  return 0;
}
