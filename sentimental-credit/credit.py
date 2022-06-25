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
        str_n = str(self.number)

        return "HI\n"

    def luhn_alg(self):
        n = self.number
        

main()