from datetime import datetime, date
from decimal import Decimal

DATE_FORMAT = '%Y-%m-%d'

def add(items, title, amount, expiration_date=None):
    new_date = datetime.strptime(expiration_date , DATE_FORMAT)
    
    
    if title in items:
        items[title].append({
            'amount': Decimal(str(amount)),
            'expiration_date': datetime.date(new_date)
        })
    else:
        items[title] = {
            'amount': Decimal(str(amount)),
            'expiration_date': datetime.date(new_date)
        }


def add_by_note(items, note):
    splited_info = str.split(note, ' ')
    note_date = splited_info[len(splited_info) - 1]
    note_date_format = datetime.strptime(note_date, DATE_FORMAT)
    
    
    
    splited_info.pop()
    note_amount = splited_info[len(splited_info) - 1]
    splited_info.pop()
    note_name = ' '.join(splited_info)
        
    if note_name in items:
        items[note_name].append({
            'amount': Decimal(str(note_amount)),
            'expiration_date': datetime.date(note_date_format)
        })
        
    else:
        items[note_name] = {
            'amount': Decimal(str(note_amount)),
            'expiration_date': datetime.date(note_date_format)
        }


def find(items, needle):
    ...


def amount(items, needle):
    ...


def expire(items, in_advance_days=0):
    ...
    
goods = {
    'Пельмени Универсальные': [
        {'amount': Decimal('0.5'), 'expiration_date': date(2023, 7, 15)},
        {'amount': Decimal('2'), 'expiration_date': date(2023, 8, 1)},
    ],
    'Вода': [
        {'amount': Decimal('1.5'), 'expiration_date': None}
    ],
}

add_by_note(goods, 'Pelmeni piska 27 2028-9-11')
print(goods)