phrase = "Don't panic!"
plist = list(phrase)
print(phrase)
print(plist)

# removing last 4 letters
for i in range(4):
    plist.pop()
# remove first letter
plist.pop(0)
# remove inverted comma
plist.remove("'")
# swap a<->p
plist.extend([plist.pop(), plist.pop()])
# replace the space from index 3 to 2
plist.insert(2, plist.pop(3))
# create new_phrase
new_phrase = ''.join(plist)

print(plist)
print(new_phrase)