# tuple with parentheses
t = (1, 2, 3)
# without parentheses
tw = 1, 2, 3
# singleton
# tuple with one element
singleton = (1, )

# getting value with idex
t[0]

# concatenating the tuple
t += (4, )

# count and index methods
t.count(1)
t.index(2)

# tuples are faster than lists
# protect the data which is immutable
# tuples can be as keys on dictionaties

# tuples as key/value pairs to build didctionaries
d = dict([('jan', 1), ('feb', 2), ('march', 3)])
d['feb']

# signing multiple values
(x, y, z) = ('a', 'b', 'c')
(a, b, c) = range(3)

# tuple unpacking
data = (4, 5, 6)
x, y, z = data

# tuple as swap function
(x, y) = (y, x)

# len, slicing and copy
len(t)
t[::2]
u = t

# we can not copy a list with = beacuse they are mutable
# tuples are not mutable and can ber copies using =

# tuples are not fully immutable
# if a value within tuple is mutable
# then you can change it
t += ([3, 7],)
t[5][0] = 6

# converting tuple in to string
str(t)

# math operations
# pure tuples are needed no list in between like in t
max(tw)
min(tw)
