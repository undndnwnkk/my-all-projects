from datetime import datetime, date, timedelta
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
    today = date.today()
    target_date = today + timedelta(days=in_advance_days)
    result = []

    for product_name, product_info in items.items():
        total_amount = Decimal('0')
        for item in product_info:
            expiration_date = item['expiration_date']
            if expiration_date is not None and expiration_date <= target_date:
                total_amount += item['amount']
        
        if total_amount > 0:
            result.append((product_name, total_amount))

    return result

goods = {
    'Пельмени Универсальные': [
        {'amount': Decimal('0.5'), 'expiration_date': date(2023, 7, 15)},
        {'amount': Decimal('2'), 'expiration_date': date(2023, 8, 1)},
    ],
    'Вода': [
        {'amount': Decimal('1.5'), 'expiration_date': None}
    ],
}