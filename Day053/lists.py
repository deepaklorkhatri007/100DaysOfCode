# list comprehension
odd = [i for i in range(10) if i%2 !=0]
even = [i for i in range(10) if i%2 == 0]

# getting value via index
odd[0]
even[0]

# appending and extensing
# appends the object at the end
odd.append(11)
odd.append(13)
# extend with iterable object 
even.extend([10, 12])

# getting the index
odd.index(9)
even.index(10)

# inserting at a specific location
even.insert(2, 10)
# index of 10 after 3rd position
even.index(10, 3)
# remove first encounter of object
even.remove(10)

# pop element from the end
odd.pop()
even.pop()

# creating random number list
from random import randint
randomNums = []
for value in range(5):
    randomNums.append(randint(1, 10))

# sorting the list
randomNums.sort()
# reverse sorting the list
randomNums.sort(reverse=True)

# reversing the list
randomNums.reverse()

# generating list
myList = []
for i in range(10):
    myList.append(randint(1, 60))

# operators
# adding one object
myList += [34]
# adding a list
myList += [22, 65]
# adding similar objects
# again at the end
myList = myList*2

# slicing
# [start:stop:step]
myList[0:13]
# genrate similar list
# beause list is doubled
myList[2::13]

# filtering
[e*2 for e in myList if e>1][0:13]

# lists as stacks
# LIFO data strucutre
stack = ['a', 'b', 'c', 'd']
# appending -> push
stack.append('e')
stack.append('f')
# pop
stack.pop()

# list as queues
# FIFO data structure
queue = ['a', 'b', 'c', 'd']
# append
queue.append('e')
queue.append('f')
# pop
queue.pop(0)

# copy vs refrencing
# refrencing
myListRef = myList
# copy
from copy import copy
from copy import deepcopy
myListCopy = copy(myList)
myListDeepCopy = deepcopy(myList)

# inserting items into sorted list
sortedNums = deepcopy(randomNums)
from bisect import insort
from bisect import bisect
# inserting without changing the sortness
# list will be insort after insertion
insort(sortedNums, 45)
# checking where it will lead if we insert it
# gives the index where it will be if insort()
bisect(sortedNums, 76)

# count method
sortedNums.count(45)
