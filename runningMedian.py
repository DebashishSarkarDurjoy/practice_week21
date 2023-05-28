import heapq

def get_median(max_heap, min_heap):
    if  len(min_heap) > len(max_heap):
        min_val = heapq.heappop(min_heap)
        heapq.heappush(min_heap, min_val)
        return min_val
    elif len(max_heap) > len(min_heap):
        max_val = heapq.heappop(max_heap)
        heapq.heappush(max_heap, max_val)
        return max_val
    else:
        max_val = heapq.heappop(max_heap)
        heapq.heappush(max_heap, max_val)
        min_val = heapq.heappop(min_heap)
        heapq.heappush(min_heap, min_val)
        median = (max_val + min_val) / 2
        return median

def add(num, max_heap, min_heap):
    if len(min_heap) + len(max_heap) <= 1:
        heapq.heappush(max_heap, num)
        return
    
    median = get_median(max_heap, min_heap)
    if num < median:
        heapq.heappush(max_heap, num)
    else:
        heapq.heappush(min_heap, num)

def rebalance(max_heap, min_heap):
    if len(min_heap) > len(max_heap) + 1:
        root = heapq.heappop(min_heap)
        heapq.heappush(max_heap, root)
    elif len(max_heap) > len(min_heap) + 1:
        root = heapq.heappop(max_heap)
        heapq.heappush(min_heap, root)


def print_median(max_heap, min_heap):
    print(get_median(max_heap, min_heap))

def running_median(stream):
    max_heap = []
    min_heap = []

    for num in stream:
        add(num, max_heap, min_heap)
        rebalance(max_heap, min_heap)
        print_median(max_heap, min_heap)

def main():
    numbers = [2,1,5,7,2,0,5]
    running_median(numbers)

if __name__ == "__main__":
    main()