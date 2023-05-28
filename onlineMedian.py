# Not Working as expected: Logical Error
import heapq

def online_median(sequence):
    min_heap = []
    max_heap = []

    result = []

    for x in sequence:
        heapq.heappush(max_heap, -heapq.heappushpop(min_heap, x))
        if (len(max_heap) > len(min_heap)):
            heapq.heappush(min_heap, -heapq.heappop(max_heap))
        
        result.append(0.5 * (min_heap[0] + max_heap[0])) if len(min_heap) == len(max_heap) else min_heap[0]
    
    return result



def main():
    stream = [2,1,5,7,2,0,5]
    for x in online_median(stream):
        print(x, end="  ")
    print()


if __name__ == "__main__":
    main()