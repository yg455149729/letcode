def two_sum(nums,target):
    result = []
    lens = len(nums)
    for i in range(lens):
        for j in range(i+1, lens):
            if(nums[i]+nums[j]==target):
                result.extend([i, j])
    print(result)
    return result

"""
## the hashmap method refer to the comment of leetcode;  from the effciency we can conclude that find the index is more
effective than find the value then get the index
"""
def two_sum_hashmap(nums,target):
    hashmap = {}
    result = []
    for index, value in enumerate(nums):
        hashmap[value] = index
    for i, num in enumerate(nums):
        j = hashmap.get(target - num)
        if j is not None and i != j:
            result.extend([i, j])
        print(result)
        return result

# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    two_sum([-1,-2,-3,-4,-5], -8)
