#include <stdio.h>
#include <errno.h>
#include <sched.h>
#include <string.h>
#include <algorithm>

#include <vector>
#include <random>

const int kMAX = 10000000;
std::vector<int> data;

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

int main() {
  pinThread(3);

  data.resize(kMAX);

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(0, kMAX);

  // make random data
  for (int i=0; i<kMAX; ++i) {
    data[i] = distrib(gen);
  }

  // sort
  std::sort(data.begin(), data.end());

  return 0;
}
