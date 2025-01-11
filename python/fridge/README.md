### **Program Functionality**:

1. **Manual Addition of Items (function `add`)**  
   Adds a new item or updates the information of an existing item.  
   - **Parameters:**  
     - `title` — item name;  
     - `amount` — quantity (using `Decimal` for precision);  
     - `expiration_date` — expiration date.  
   - Example usage:  
     ```python
     add(goods, "Milk", 2, "2024-12-31")
     ```

2. **Adding Items from a Text Note (function `add_by_note`)**  
   Adds an item using a text note in the format:  
   `"ItemName Quantity Date"`.  
   - The program splits the note into parts and adds the data to the items dictionary.  
   - Example note:  
     ```
     Milk 2 2024-12-31
     ```

3. **Search for Items by Name (function `find`)**  
   Returns a list of items containing the specified keyword in their name (case-insensitive).  
   - Example search:  
     ```python
     find(goods, "water")  # ['Water']
     ```

4. **Calculating Total Item Quantity (function `amount`)**  
   Returns the total quantity of all available items that match the specified keyword.  
   - Example usage:  
     ```python
     amount(goods, "dumplings")  # Decimal('2.5')
     ```

5. **Checking Expiration Dates (function `expire`)**  
   Returns a list of items whose expiration date is today or within the next few days.  
   - **Parameters:**  
     - `in_advance_days` — number of days before expiration.  
   - Example usage:  
     ```python
     expire(goods, 7)  # Items expiring within a week
     ```

---

### **Example Data Structure**:

The `goods` dictionary represents items as follows:  
```python
goods = {
    'Universal Dumplings': [
        {'amount': Decimal('0.5'), 'expiration_date': date(2023, 7, 15)},
        {'amount': Decimal('2'), 'expiration_date': date(2023, 8, 1)},
    ],
    'Water': [
        {'amount': Decimal('1.5'), 'expiration_date': None}  # Item with no expiration date
    ],
}
```

---

### **Key Implementation Features**:  
- The use of `Decimal` for handling numbers to avoid rounding errors.  
- Dates are processed using `datetime` and `date` for calendar-related calculations.  
- Supports items without expiration dates (`expiration_date = None`).  
- The functions can be extended — for example, to add notifications for expiration alerts or to create inventory reports.
