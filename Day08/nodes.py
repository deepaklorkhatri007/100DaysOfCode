#!/usr/bin/env python3
class puppies:
    def __init__(self, dataval=None):
        self.dataval = dataval
        self.nextval = None

puppy1 = puppies('bolt')
puppy2 = puppies('fluffy')
puppy3 = puppies('silky')
puppy4 = puppies('curly')

puppy1.nextval = puppy3
puppy3.nextval = puppy2
puppy2.nextval = puppy4

thisvalue = puppy1
while thisvalue:
    print(thisvalue.dataval)
    thisvalue = thisvalue.nextval