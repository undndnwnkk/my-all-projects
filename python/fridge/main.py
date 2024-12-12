from datetime import datetime, date
from decimal import Decimal

DATE_FORMAT = '%Y-%m-%d'

def add(items, title, amount, expiration_date=None):
    new_date = datetime.strptime(expiration_date, DATE_FORMAT)
    
    if title in items:
        items[title].append({
            'amount': Decimal(str(amount)),
            'expiration_date': datetime.date(new_date)
        })
    else:
        items[title] = [{
            'amount': Decimal(str(amount)),
            'expiration_date': datetime.date(new_date)
        }]

def add_by_note(items, note):
    splited_info = str.split(note, ' ')
    note_date = splited_info[len(splited_info) - 1]
    
    splited_info.pop()
    note_amount = splited_info[len(splited_info) - 1]
    splited_info.pop()
    note_name = ' '.join(splited_info)
        
    add(items, note_name, note_amount, note_date)

def find(items, needle):
    note = str.lower(needle)
    res = []
    
    for key in items:
        if note in str.lower(key):
            res.append(key)
            
    return res

def amount(items, needle):
    note = str.lower(needle)
    to_amount = find(items, note)
    
    result = Decimal('0')
    
    for each in to_amount:
        for item in items[each]:
            result += item['amount']
        
    return Decimal(result)

def expire(items, in_advance_days=0):
    
    
    pass

goods = {
    'Пельмени Универсальные': [
        {'amount': Decimal('0.5'), 'expiration_date': date(2023, 7, 15)},
        {'amount': Decimal('2'), 'expiration_date': date(2023, 8, 1)},
    ],
    'Вода': [
        {'amount': Decimal('1.5'), 'expiration_date': None}
    ],
}

print(goods)

add(goods, 'Пельмени обычные', '0.5', '2023-07-15')
print('\n')

print(goods)
print('\n')

add_by_note(goods, 'Пельмени хуевые 115 2124-11-21')

print(goods)
print('\n')

print(find(goods, 'Пельмени'))
print('\n')

print(amount(goods, 'Пельмени'))
