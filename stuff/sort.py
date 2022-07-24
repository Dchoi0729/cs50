
# Main method
def main():
    list = [2,1,5,3,4]

    print(merge_sort(list))

# Sorts a list using merge sort
def merge_sort(whole_list):
    whole_list[0] = 1
    return whole_list

# Merges two lists together
def merge(left_list, right_list):
    list = []

    left_size = left_list.length, left_counter = 0
    right_size = right_list.length, right_counter = 0

    while left_counter < left_size and right_counter < right_size:
        if left_list[left_counter] > right_list[right_counter]:
            list.append(right_list[right_counter])
            right_counter = right_counter + 1
        else:
            list.append(left_list[left_counter])
            left_counter = left_counter + 1

    

#def merge_sort_helper(part_list):


main()