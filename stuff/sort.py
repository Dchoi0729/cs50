
# Main method
def main():
    list = [2,1,5,3,4]

    print(merge_sort(list))

# Sorts a list using merge sort
def merge_sort(whole_list):
    whole_list[0] = 1
    return whole_list

# Merges two lists together
def merge(list1, list2):
    list = [], i = 0, j = 0

    number = list1.length + list2.length

    for k in range(number) :
        if list1[i] > list2[j]:
            list[k] = list2[j]
            j = j + 1
        else
            list[k] = list2[j]
            j = j + 1



#def merge_sort_helper(part_list):


main()