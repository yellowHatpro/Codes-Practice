def calculateIncomeTax(income):
    
    if income <= 250000: 
        tax = 0
    elif income <= 500000: 
        tax = (income - 250000) * 0.05
    elif income <= 750000: 
        tax = (income - 500000) * 0.10 + 12500 
    elif income <= 1000000: 
        tax = (income - 750000) * 0.15 + 37500 
    elif income <= 1250000: 
        tax = (income - 1000000) * 0.20 + 75000 
    elif income <= 1500000: 
        tax = (income - 1250000) * 0.25 + 125000 
    else:
        tax = (income - 1500000) * 0.30 + 187500
    tax=int(tax)
    if income>5000000 and income<10000000:
        tax=tax+((tax*10)//100)
    elif income>10000000 and income<20000000:
        tax=tax+((tax*15)//100)
    elif income>20000000 and income<50000000:
        tax=tax+((tax*25)//100)
    elif income>50000000:
        tax=tax+((tax*35)//100)
    tax=(float)(tax+((tax*4)//100))
    return tax
