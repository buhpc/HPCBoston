from numpy import load
import time
import threading
from numpy import split



splitindices = [[0] * 3500, [0] * 3500, [0] * 3500, [0] * 3500, [0] * 3500, [0] * 3500, [0] * 3500, [0] * 3500]



def mainThread():
	start_time = time.time()
	data = load('hpcrecipe.npz' , allow_pickle=True)
	lst = data.files
	indices = [0] * 3500
	ingredients = data['ingredients']

	print("finished loading data")
	print("Data Load Time %s seconds ---" % (time.time() - start_time))
	start_time = time.time()

	#print(len(data['recipes']))
	# dividedrecipes = split(data['recipes'], [266889, 533778, 800667])
	# print("done splitting recipe array")

	recipes = data['recipes']  ############################################taking the Longest

	print("Counting Length")
	recipeLen=len(recipes)
	print("Recipe Length %d"%recipeLen)

	recipesSplitIndex = [ 0, int(recipeLen/8), int(recipeLen/8)*2, int(recipeLen/8)*3, int(recipeLen/8)*4, int(recipeLen/8)*5, int(recipeLen/8)*6, int(recipeLen/8)*7,  recipeLen];
	# recipesSplitIndex = [ 0, 266889, 533778, 800667,  1067557];


	print("Data split time %s seconds ---" % (time.time() - start_time))
	start_time = time.time()

	ts = []
	threadnum = 0
	# for recipechunk in dividedrecipes:
	for ind in range(len(recipesSplitIndex)-1):
		# t = threading.Thread(target=countingreds, args=(recipechunk, threadnum))
		t = threading.Thread(target=countingreds_index, args=(recipes, recipesSplitIndex[ind], recipesSplitIndex[ind+1], threadnum))
		threadnum += 1
		ts.append(t)
		t.start()
		print("starting thread", threadnum)

	for t in ts:
		t.join()

	print("all threads done")
	for eachlist in splitindices:
		for i in range(len(eachlist)):
		    indices[i] += eachlist[i]




	print("Count time %s seconds ---" % (time.time() - start_time))
	start_time = time.time()

	print("calculating top indices")
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

	print("find Max %s seconds ---" % (time.time() - start_time))


def countingreds(recipes, threadnum):
	for recipe in recipes:
		for ingred in recipe:
			splitindices[threadnum][ingred] += 1


def countingreds_index(recipes, startInd, endInd, threadnum):
	for ind in range(startInd, endInd):
		for ingred in recipes[ind]:
			splitindices[threadnum][ingred] += 1


mainThread()
