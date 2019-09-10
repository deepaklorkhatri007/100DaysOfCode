class CountFromBy:
    # init dunder
    # constructor for python
    def __init__(self, v:int = 0, i:int = 1) -> None:
        self.val = v
        self.incr = i
    
    # method definition
    def increase(self) -> None:
        self.val += self.incr

    # representation of object
    # what to output when >>> object
    def __repr__(self) -> str:
        return str(self.val)