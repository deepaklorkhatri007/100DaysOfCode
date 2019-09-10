import csv

with open('buzzdata.csv') as data:
    for line in csv.reader(data):
        print(line)