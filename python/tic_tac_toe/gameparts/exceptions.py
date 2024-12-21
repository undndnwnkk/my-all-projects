class FieldIndexError(IndexError):

    def __str__(self):
        return 'Entered value outside the boundaries of the playing field.'


class CellOccupiedError(Exception):

    def __str__(self):
        return 'The cell is already occupied.'
