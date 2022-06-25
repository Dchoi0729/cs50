# Determines whether a credit card number is valid
# And if so, what type of card it is

def main():
    card_num = get_user_input()
    card = CreditCard(card_num)
    print(card.get_type())


# Gets a valid user input that consists only of numbers
def get_user_input():
    while True:
        try:
            number = int(input("Number: "))
            break
        except:
            pass
    return str(number)


# Credit Card object
class CreditCard:
    def __init__(self, number):
        self.number = number

    # Returns the type of credit card
    def get_type(self):
        if self.luhn_alg():
            n = self.number
            length = len(n)
            first_two = int(n[0:2])

            if length == 15 and (first_two == 34 or first_two == 37):
                return "AMEX\n"
            elif length == 16 and first_two > 50 and first_two < 56:
                return "MASTERCARD\n"
            elif (length == 13 or length == 16) and first_two // 10 == 4:
                return "VISA\n"
        return "INVALID\n"

    # Returns whether the credit card is a valid number using luhn's algorithm
    def luhn_alg(self):
        n = self.number
        sum = 0

        # For every other number beginning from second to last digit
        start1 = 0 if len(n) % 2 == 0 else 1
        for i in n[start1::2]:
            tmp = int(i)*2
            if tmp > 9:
                sum += (tmp % 10) + 1
            else:
                sum += tmp

        # Add remaining numbers
        start2 = 1 if len(n) % 2 == 0 else 0
        for j in n[start2::2]:
            sum += int(j)

        return sum % 10 == 0


main()
