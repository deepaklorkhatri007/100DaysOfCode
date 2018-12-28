from datetime import datetime
import pprint

# 12:00 to 12:00 AM/PM
def convert2ampm(time24: str) -> str:
    return datetime.strptime(time24, '%H:%M').strftime('%I:%M%p')

# read data
with open('buzzdata.csv') as data:
    ignore = data.readline()
    flights = {}
    for line in data:
        k, v = line.strip().split(',')
        flights[k] = v

# pretty print list
pprint.pprint(flights)
print()

fts = {convert2ampm(k): v.title() for k, v in flights.items()}
pprint.pprint(fts)
print()

when = {dest: [k for k,v in fts.items() if v == dest] for dest in set(fts.values())}
pprint.pprint(when)
print()