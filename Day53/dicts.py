# Dictionaries
# {key:value} pairs
numbers = {1:'one', 2:'two', 3:'three'}
# output keys
numbers.keys()
# output values
numbers.values()

# acessing via key
# you can net have duplicate keys
# dictionary have no concept of order among elements
numbers[1]

# items
numbers.items()

# to find if dict has a key
# key in dic -> true/false
1 in numbers

# getting the value with a key
numbers.get(2)

# pop method
numbers.pop(1)

# pop item without key from end
numbers.popitem()

# setting default velue of none is geven
numbers.setdefault('third', '')
numbers['third']

# dectionary with set of keys
numbers.fromkeys(['first', 'second'])
{}.fromkeys(['first', 'second'])

# combinging dictionaries
d1 = {'a':1}
d2 = {'a':2, 'b':2}
d1.update(d2)

# iterators
numbers = {1:'one', 2:'two', 3:'three'}
[x for x in numbers.values()]
[x for x in numbers.keys()]
[x for x in numbers.items()]
# key value seprately
for key, value in numbers.items():
    print(key, '->', value)

# deleting everything
numbers.clear()
del numbers