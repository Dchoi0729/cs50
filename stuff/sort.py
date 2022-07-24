
# Main method
def main():
    list = [2,1,5,3,4]
    a = [2,3,4]
    b = [1,3,7]

    print(merge_sort(list))
    print(merge(a,b))

# Sorts a list using merge sort
def merge_sort(list):
    return merge_sort_helper(list)

#splits list into two parts
def merge_sort_helper(list):
    if len(list) == 1:
        return list
    else:
        print(list[0:len(list)//2+1])
        left_list = merge_sort_helper(list[0:len(list)//2])
        right_list = merge_sort_helper(list[len(list)//2:])
        return merge(left_list,right_list)

# Merges two lists together
def merge(left_list, right_list):
    list = []

    left_size = len(left_list)
    left_counter = 0
    right_size = len(right_list)
    right_counter = 0

    while left_counter < left_size and right_counter < right_size:
        if left_list[left_counter] > right_list[right_counter]:
            list.append(right_list[right_counter])
            right_counter = right_counter + 1
        else:
            list.append(left_list[left_counter])
            left_counter = left_counter + 1

    list = list + left_list[left_counter:] + right_list[right_counter:]

    return list


main()