from datetime import datetime
import random
import time
# list comprehension
oddMinute = [i for i in range(60) if i%2 != 0]

steps = 5

for steps in range(steps):
    minute = datetime.today().minute
    randomSeconds = random.randint(1, 30)
    if minute in oddMinute:
        print(minute, "is an odd minute")
    else:
        print(minute, "is not an odd minute")
    if steps < list(range(steps))[-1]:
        time.sleep(randomSeconds)