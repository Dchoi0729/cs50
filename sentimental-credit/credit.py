def main():
    card_num = get_user_input()
    card = CreditCard(card_num)
    print(card.get_type())

def get_user_input():
    while True:
        try:
            number = int(input("Number: "))
            break
        except:
            pass
    return str(number)

class CreditCard:

    def __init__(self, number):
        self.number = number

    def get_type(self):
        if self.luhn_alg():
            n = self.number
            length = len(n)

            if length == 15 and (n[0:1] == 34 or n[0:1] == 37):
                return "AMEX\n"
            elif length == 16 and n[0:1] > 50 and n[0:1] < 56:
                return "MASTERCARD\n"
            elif (length == 13 or length == 16) and n[0:1] / 10 == 4:
                return "VISA\n"
            else:
                return "INVALID\n"

    def luhn_alg(self):
        n = self.number
        start1 = 0 if len(n)%2 == 0 else 1

        sum = 0
        for i in n[start1::2]:
            tmp = int(i)*2
            if tmp > 9:
                sum += (tmp % 10) + 1
            else:
                sum += tmp

        start2 = 1 if len(n)%2 == 0 else 0
        for j in n[start2::2]:
            sum += int(j)

        print(sum)
        return sum % 10 == 0

main()