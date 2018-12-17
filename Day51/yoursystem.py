import os
import sys
import datetime
import time
cwd = os.getcwd() # currently working directory
system = sys.platform
home = os.getenv('HOME')
date = datetime.date.isoformat(datetime.date.today())
day = time.strftime("%A")
time = time.strftime("%H:%M %p")
print("Hello user,")
print("Today is ", day)
print("Date is ", date)
print("time is ", time)
print("you are working on a \"", system, "\" machine")
print("you executed the program from \"", cwd, "\" directory")
print("your home directory is \"", home, "\"")