def search4vowels(word:str = '') -> set:
    vowels = set('aeiou')
    if word == '':
        word = input("Provide a word to search for vowels: ")
    return vowels.intersection(set(word))

# invoking the function
# print(search4vowels())
