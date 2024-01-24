
def findKthSmallest(arr:[], k: int) -> int:
    if len(arr) == 1 and k == 1:
        return arr[0]
    elif len(arr) < k:
        print("illegal input of k")
    else:
        v = [arr[0]]
        smallerThanV = []
        largerThanV = []

        for e in arr:
            if e < v[0]:
                smallerThanV.append(e)
            elif e == v[0]:
                v.append(e)
            else:
                largerThanV.append(e)
        v.pop()
        if k <= len(smallerThanV):
            return findKthSmallest(smallerThanV, k)
        elif k <= len(smallerThanV) + len(v):
            return v[0]
        else:
            return findKthSmallest(largerThanV, k - len(v) - len(smallerThanV))


arr = [1, 3, 4, 2, 5]
print(findKthSmallest(arr, 2))
