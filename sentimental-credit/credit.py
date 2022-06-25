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
    return number

class CreditCard:

    def __init__(self, number):
        self.number = number

    def get_type(self):
        # logic logic logic
        return "HI\n"


main()