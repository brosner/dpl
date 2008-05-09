#!/usr/bin/env python

# for cf.net

import time, random

list = [x for x in range(1000000)]
begin = time.time()
for index in range(1000000):
        x = random.randrange(1000000)
        temp = list[x]
        list[x] = list[index]
        list[index] = temp
end = time.time()
for i in range(100):
        print list[i],
total = end - begin
print "\nRandomization took %d seconds." % total
