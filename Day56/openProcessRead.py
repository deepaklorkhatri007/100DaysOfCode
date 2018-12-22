# opening a file in appending mode
# this will create if not present
todo = open('todo.txt', mode='a')
print('bring 5 eggs', file=todo)
print('complete 100DaysOfCode work', file=todo)
todo.close()

# reaing from file
work = open('todo.txt')
for task in work:
    print(task, end='')