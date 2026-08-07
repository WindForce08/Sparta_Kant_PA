"""
This module contains the implementation of a pension lottery system. 
The first digit (group number) is chosen from 1 to 5.
And the remaining six digits are randomly generated from 000000 to 999999.
Users can generate between 1 and 10 tickets at a time.
"""
import random

while True:
    try:
        count =int(input("Enter the number of tickets to generate (1-10): "))

        if 1 > count or count > 10:
            print("Please enter a number between 1 and 10.")
            continue
        break

    except ValueError:
        print("Invalid input. Please enter a number between 1 and 10.")
        continue

print("\n=== Pension Lottery Generation Results ===")

for i in range(count):
    group = random.randint(1, 5)
    number = random.randint(0, 999999)

    print(f"{i + 1}번 복권 : {group}조 {number:06d}")