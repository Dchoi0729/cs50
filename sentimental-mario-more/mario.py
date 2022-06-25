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
    left_space = height - i - 1
    hash_num = i + 1

    # Print left space, then hashes, then middle gap, then right hashes
    print(" " * left_space + "#" * hash_num + "  " + "#" * hash_num)
