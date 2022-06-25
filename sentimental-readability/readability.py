# Outputs reading grade of input text

from cs50 import get_string

def main():
    text = get_string("Text: ")

    letters = count_letters(text)
    sentences = count_sentences(text)

    words = count_words(text)

    avg_letters = letters / words * 100
    avg_sentences = sentences / words * 100
    index = 0.0588 * avg_letters - 0.296 * avg_sentences - 15.8

    # Print grade leverl
    if index < 1:
        print("Before Grade 1\n", end="")
    elif index > 16:
        print("Grade 16+\n", end="")
    else:
        print(f"Grade {int(index)}\n", end="")


# Counts number of letters in a text (a-z)
def count_letters(text):
    sum = 0
    for c in text:
        if c.isalpha():
            sum += 1
    return sum


# Counts number of words in a text (seperated by space)
def count_words(text):
    word_list = text.split()
    return len(word_list)


# Counts number of sentences in a text (seperated by . ? !)
def count_sentences(text):
    sum = 0
    for c in text:
        if c == "." or c == "!" or c =="?":
            sum += 1
    return sum


main()