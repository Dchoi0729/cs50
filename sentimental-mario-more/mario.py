# Recreates pyramids in mario with #s

while True:
    try:
        height = int(input("Height: "))
        if height > 8 or height < 1:
             print("Please input an integer between 1 and 8")
        else:
            break
    except ValueError:
        print("Please input an integer between 1 and 8")

for i in range(height):
    left_space = height - i + 1
    print(" " * left_space + "#" * i + "  " + "#" * i)
