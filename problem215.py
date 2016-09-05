import time

width = 32
maxDepth = 10

# First build up a graph between two arbitrary rows
t1 = time.time()

graph = {}
def recursive2(parent, resultArray, state, index):
	if index == width:
		resultArray.append(state)
	elif index <= width:
		state |= (1 << index - 1)
		if (parent & state) > 0: 
			return # this means that two gaps lined up
		recursive2(parent, resultArray, state, index + 2)
		recursive2(parent, resultArray, state, index + 3)
def recursive1(state, index):
	if index == width:
		resultArray = []
		recursive2(state, resultArray, 0, 2)
		recursive2(state, resultArray, 0, 3)
		if len(resultArray) > 0:
			graph[state] = resultArray
	elif index <= width:
		state |= (1 << index - 1)
		recursive1(state, index + 2)
		recursive1(state, index + 3)

# trim down useless links
for keyRow, toRows in graph.iteritems():
	newToRows = []
	for row in toRows:
		if row in graph:
			newToRows.append(row)
	if len(newToRows) != 0:
		graph[keyRow] = newToRows

recursive1(0, 2)
recursive1(0, 3)

t2 = time.time()
print("Found " + str(len(graph)) + " start rows")

cacheAtDepth = [{} for x in range(0, maxDepth + 1)]

# a logorithmic algorithm could be created. is it worth it? maybe
def count(curDepth, fromRow):
	if curDepth == maxDepth:
		return 1

	if fromRow in cacheAtDepth[curDepth]:
		return cacheAtDepth[curDepth][fromRow]

	sum = 0
	for row in graph[fromRow]:
		sum += count(curDepth + 1, row)

	cacheAtDepth[curDepth][fromRow] = sum
	return sum

sum = 0
for key in graph:
	sum += count(1, key)

t3 = time.time()
print("answer: " + str(sum))
print("took " + str(t2 - t1) + " seconds to generate the mapping")
print("took " + str(t3 - t2) + " seconds to count the possible solutions")
print("total time was: " + str(t3 - t1))
