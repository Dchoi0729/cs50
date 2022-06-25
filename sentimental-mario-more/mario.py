# Recreates pyramids in mario with #s

while True:
    try:
        height = input("Height: ")
        if height > 8 or height < 1:
             print("Please input an integer 1-8")
        else:
            break
    except ValueError:
        print("Please input an integer 1-8")

