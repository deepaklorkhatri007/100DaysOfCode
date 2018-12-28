import csv
with open('buzzdata.csv') as data:
    for line in csv.DictReader(data):
        print(line)