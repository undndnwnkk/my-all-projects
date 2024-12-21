from gameparts import Board
from gameparts.exceptions import FieldIndexError, CellOccupiedError


def main():
    game = Board()
    current_player = 'X'
    running = True
    game.display()
    while running:
        print(f'A player {current_player} makes a move')

        while True:
            try:
                row = int(input('Enter row: '))
                if row < 0 or row >= 3:
                    raise FieldIndexError
                column = int(input('Enter column: '))
                if column < 0 or column >= 3:
                    raise FieldIndexError
                if game.board[row][column] != ' ':
                    raise CellOccupiedError
            except FieldIndexError:
                print('The value must be non-negative and less than '
                      f'{game.field_size}')
                print('Please, try again')
                continue
            except ValueError:
                print("You can't enter letters. Numbers only.'")
                print('Please re-enter the values for the row and column.')
                continue
            except CellOccupiedError:
                print('Cell occupied')
                print('Enter other coordinates.')
                continue
            except Exception as e:
                print(f'There was an error {e}')
                continue
            else:
                break

        game.make_move(row, column, current_player)
        game.display()
        if game.check_win(current_player):
            print(f'Player {current_player} wins!')
            running = False
        elif game.is_board_full():
            print('Draw')
            running = False
        current_player = 'O' if current_player == 'X' else 'X'


if __name__ == '__main__':
    main()
