# list : an ordered mutable collection of objects
# A list is like an array - the objects it stores are ordered sequentially in slots
myList = [1, "two", "III", "four"]
print(myList)
# ordered collection are mutable/immutable
# when an odered list-like collection is immutable, it's called a tuple
# A tuple is an immutable list
myTuple = (1, "two", "III", "four")
print(myTuple)
# An unordered data structure : Dictionary 
# Dictionary: an unordered set of key/value pairs
# A dictionary stores key/value pairs
myDictionary = {1:"one", 2:"two", 3:"three", 4:"four"}
print(myDictionary)
for key, value in myDictionary.items():
    print(key," -> ", value)

# A Data Structure that avoids duplicates: Set
# Set: an unordered set of unique objects
# A set does not allow duplicate objects
a = set([1, 2, 3, 4])
b = set([3, 4, 5, 6])

print(a)
print(b)
print("Union : ", a|b)
print("Intersection : ", a&b)
print("Subset : ", a<b)
print("Diffrence : ", a-b)
print("Symmetric Diffrence : ", a^b)

