from datetime import datetime, date
from decimal import Decimal

def add(items, title, amount, expiration_date=None):
    new_date = datetime.strptime(expiration_date ,'%Y-%m-%d')
    
    
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
    ...


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