from numpy import load
import time
import threading

start_time = time.time()

data = load('hpcrecipe.npz')
lst = data.files
indices = [0] * 3500
ingredients = data['ingredients']
length = len(data['recipes'])
print("--- 1: %s seconds ---" % (time.time() - start_time))

'''for item in lst:
    print(item)
print((data['recipes'][0]))'''
#t1 = threading.Thread(target=countit, args=())

print("--- 2: %s seconds ---" % (time.time() - start_time))

print(type(data), type(data['recipes']))
print(length)

'''
for i in range(20):
    for recipe in data['recipes'][i]:
        print(recipe)
        print('')

#keep both and keep topindices sorted for faster runtime
topindices = []
for i in range(20):
    curmax = 0
    curmaxind = 0
    for j in range(len(indices)):
        if indices[j] > curmax:
            curmax = indices[j]
            curmaxind = j
    indices[curmaxind] = 0
    topindices += [curmaxind]

for topindex in topindices:
    print(data['ingredients'][topindex])

print("--- 3: %s seconds ---" % (time.time() - start_time))

def countit(start,end):
    for i in range(start,end):
        for ingred in data['recipes']:
            indices[ingred] += 1'''