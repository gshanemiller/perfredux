# perf stats example
See `scripts` subdir for two approachs to collecting stats.

# test1
Sort 10,000,000 random integers in std::vector with stdc++. Task pinned to core #3:

```
 Performance counter stats for 'CPU(s) 3':

CPU3               3045138931      cycles                                                        (54.87%)
CPU3               2579890011      instructions              #    0.85  insn per cycle           (66.37%)
CPU3                441735566      branches                                                      (67.00%)
CPU3                106905004      branch-misses             #   24.20% of all branches          (67.41%)
CPU3               1788696354      cycle_activity.cycles_mem_any                                     (67.41%)
CPU3                475443972      cycle_activity.stalls_mem_any                                     (67.42%)
CPU3                  3337178      longest_lat_cache.miss                                        (43.86%)
CPU3                  6901931      cycle_activity.cycles_l3_miss                                     (43.45%)
CPU3                    32172      LLC-load-misses                                               (43.45%)

       0.626058287 seconds time elapsed
```

# test2
Sum 10,000,000 integers in array acessing sequentially in order. Task pinned to core #3:

```
 Performance counter stats for 'CPU(s) 3':

CPU3                 54745388      cycles                                                        (15.65%)
CPU3                 58078977      instructions              #    1.06  insn per cycle           (40.79%)
CPU3                  9857778      branches                                                      (65.94%)
CPU3                       39      branch-misses             #    0.00% of all branches          (91.09%)
CPU3                 55850102      cycle_activity.cycles_mem_any                                   
CPU3                 18036032      cycle_activity.stalls_mem_any                                   
CPU3                       26      longest_lat_cache.miss                                        (34.08%)
CPU3                        0      cycle_activity.cycles_l3_miss                                     (8.92%)
CPU3            <not counted>      LLC-load-misses                                               (0.00%)

       0.015890633 seconds time elapsed
```

# test3
Access each integer among 10,000,000 in array in random order. Task pinned to core #3:


```
 Performance counter stats for 'CPU(s) 3':

CPU3                611010640      cycles                                                        (53.75%)
CPU3                884390684      instructions              #    1.45  insn per cycle           (65.31%)
CPU3                115105446      branches                                                      (65.31%)
CPU3                  5405066      branch-misses             #    4.70% of all branches          (65.31%)
CPU3                557728681      cycle_activity.cycles_mem_any                                     (65.35%)
CPU3                281940468      cycle_activity.stalls_mem_any                                     (68.24%)
CPU3                 11597181      longest_lat_cache.miss                                        (46.25%)
CPU3                316237313      cycle_activity.cycles_l3_miss                                     (46.21%)
CPU3                  6327242      LLC-load-misses                                               (43.32%)

       0.138382209 seconds time elapsed
```
