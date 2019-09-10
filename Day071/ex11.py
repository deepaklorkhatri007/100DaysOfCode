# fluent python exercise - example 1.1
import collections

Card = collections.namedtuple('Card', ['rank', 'suit'])

class FrenchDeck:
    ranks = [str(n) for n in range(2, 11)] + list('JKQA')
    suits = 'spades diamonds clubs hearts'.split()

    def __init__(self):
        self._card = [Card(rank, suit) for rank in self.ranks for suit in self.suits]
    
    def __len__(self):
        return len(self._card)
    
    def __getitem__(self, position):
        return self._card[position]

