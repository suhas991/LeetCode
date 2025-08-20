# Java Collections Framework - Detailed Notes with Examples

## 1. List Interface

### ArrayList

**Definition**:\
A **dynamic array** that resizes automatically compared to fixed-size
arrays in Java.

**Internal Working**:\
- Starts empty.\
- First insertion → internal array of size `10`.\
- If full → grows to `(n + n/2 + 1)`.\
- Old array copied into new larger array.

**Example:**

``` java
import java.util.*;

public class ArrayListExample {
    public static void main(String[] args) {
        ArrayList<String> list = new ArrayList<>();

        // Adding elements
        list.add("Apple");
        list.add("Banana");
        list.add("Mango");

        // Adding at index
        list.add(1, "Orange");

        // Accessing elements
        System.out.println("Element at index 2: " + list.get(2));

        // Removing elements
        list.remove("Banana"); // by element
        list.remove(0);        // by index

        // Updating value
        list.set(1, "Pineapple");

        // Checking
        System.out.println("Contains Mango? " + list.contains("Mango"));
        System.out.println("List size: " + list.size());

        // Iterating
        System.out.println("For-each loop:");
        for (String s : list) {
            System.out.println(s);
        }

        // Iterator
        System.out.println("Using Iterator:");
        Iterator<String> it = list.iterator();
        while (it.hasNext()) {
            System.out.println(it.next());
        }
    }
}
```

------------------------------------------------------------------------

### Stack

**Definition**:\
Implements **LIFO** (Last-In, First-Out).

**Example:**

``` java
import java.util.*;

public class StackExample {
    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();

        // Push elements
        stack.push(10);
        stack.push(20);
        stack.push(30);

        // Peek top element
        System.out.println("Top element: " + stack.peek());

        // Pop elements
        System.out.println("Removed: " + stack.pop());
        System.out.println("Removed: " + stack.pop());

        System.out.println("Current stack: " + stack);
    }
}
```

------------------------------------------------------------------------

### LinkedList (as List)

**Definition**:\
Implements the **List interface**. Elements are stored in nodes, so
insertion/removal in the middle is faster than ArrayList.

**Example:**

``` java
import java.util.*;

public class LinkedListAsListExample {
    public static void main(String[] args) {
        List<String> list = new LinkedList<>();

        list.add("A");
        list.add("B");
        list.add("C");

        // Add at index
        list.add(1, "D");

        // Remove element
        list.remove("B");

        // Access element
        System.out.println("Element at index 2: " + list.get(2));

        // Iterate
        for (String s : list) {
            System.out.println(s);
        }
    }
}
```

------------------------------------------------------------------------

## 2. Queue Interface

### LinkedList (as Queue)

**Definition**:\
Implements **FIFO** (First-In, First-Out).

**Example:**

``` java
import java.util.*;

public class LinkedListQueueExample {
    public static void main(String[] args) {
        Queue<String> queue = new LinkedList<>();

        queue.offer("Task1");
        queue.offer("Task2");
        queue.offer("Task3");

        System.out.println("Front: " + queue.peek());

        System.out.println("Removed: " + queue.poll());
        System.out.println("Removed: " + queue.poll());

        System.out.println("Queue after removals: " + queue);
    }
}
```

------------------------------------------------------------------------

### PriorityQueue

**Definition**:\
- By default: **Min-Heap**.\
- Can be turned into a **Max-Heap** using a comparator.

**Example:**

``` java
import java.util.*;

public class PriorityQueueExample {
    public static void main(String[] args) {
        // Min-Heap
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        minHeap.offer(50);
        minHeap.offer(10);
        minHeap.offer(30);
        System.out.println("Min-Heap Poll: " + minHeap.poll()); // 10

        // Max-Heap
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());
        maxHeap.offer(50);
        maxHeap.offer(10);
        maxHeap.offer(30);
        System.out.println("Max-Heap Poll: " + maxHeap.poll()); // 50
    }
}
```

------------------------------------------------------------------------

### ArrayDeque

**Definition**:\
Double-ended queue supporting insertions/removals from both ends.

**Example:**

``` java
import java.util.*;

public class ArrayDequeExample {
    public static void main(String[] args) {
        Deque<String> deque = new ArrayDeque<>();

        deque.offerFirst("A");
        deque.offerLast("B");
        deque.offerLast("C");

        System.out.println("Front: " + deque.peekFirst());
        System.out.println("Back: " + deque.peekLast());

        deque.pollFirst();
        deque.pollLast();

        System.out.println("Remaining Deque: " + deque);
    }
}
```

------------------------------------------------------------------------

## 3. Set Interface

### HashSet

**Definition**:\
Stores **unique elements** without order.

**Example:**

``` java
import java.util.*;

public class HashSetExample {
    public static void main(String[] args) {
        Set<String> set = new HashSet<>();

        set.add("Apple");
        set.add("Banana");
        set.add("Apple"); // Duplicate ignored

        System.out.println("Set: " + set);

        set.remove("Banana");
        System.out.println("Contains Apple? " + set.contains("Apple"));
    }
}
```

------------------------------------------------------------------------

### LinkedHashSet

**Definition**:\
Maintains **insertion order** + uniqueness.

**Example:**

``` java
import java.util.*;

public class LinkedHashSetExample {
    public static void main(String[] args) {
        Set<String> set = new LinkedHashSet<>();

        set.add("C");
        set.add("A");
        set.add("B");

        System.out.println("LinkedHashSet (insertion order): " + set);
    }
}
```

------------------------------------------------------------------------

### TreeSet

**Definition**:\
Stores **unique elements in sorted order**.

**Example:**

``` java
import java.util.*;

public class TreeSetExample {
    public static void main(String[] args) {
        Set<Integer> set = new TreeSet<>();

        set.add(40);
        set.add(10);
        set.add(30);

        System.out.println("TreeSet (sorted): " + set);
    }
}
```

------------------------------------------------------------------------

## 4. Map Interface

### HashMap

**Definition**:\
Stores **key-value pairs** (keys must be unique).

**Example:**

``` java
import java.util.*;

public class HashMapExample {
    public static void main(String[] args) {
        Map<Integer, String> map = new HashMap<>();

        map.put(1, "One");
        map.put(2, "Two");
        map.put(3, "Three");

        map.putIfAbsent(2, "Duplicate"); // Won't overwrite
        map.remove(3);

        System.out.println("Keys: " + map.keySet());
        System.out.println("Values: " + map.values());

        for (Map.Entry<Integer, String> entry : map.entrySet()) {
            System.out.println(entry.getKey() + " -> " + entry.getValue());
        }
    }
}
```

------------------------------------------------------------------------

### TreeMap

**Definition**:\
Stores key-value pairs in **sorted order of keys**.

**Example:**

``` java
import java.util.*;

public class TreeMapExample {
    public static void main(String[] args) {
        Map<String, Integer> map = new TreeMap<>();

        map.put("Banana", 2);
        map.put("Apple", 1);
        map.put("Cherry", 3);

        System.out.println("TreeMap (sorted keys): " + map);
    }
}
```

------------------------------------------------------------------------

## 5. Utility Classes

### Arrays Class

**Example:**

``` java
import java.util.*;

public class ArraysClassExample {
    public static void main(String[] args) {
        int[] arr = {5, 2, 8, 1, 9};

        Arrays.sort(arr);
        System.out.println("Sorted: " + Arrays.toString(arr));

        int index = Arrays.binarySearch(arr, 8);
        System.out.println("Index of 8: " + index);

        Arrays.fill(arr, 0);
        System.out.println("After fill: " + Arrays.toString(arr));
    }
}
```

------------------------------------------------------------------------

### Collections Class

**Example:**

``` java
import java.util.*;

public class CollectionsClassExample {
    public static void main(String[] args) {
        List<Integer> list = Arrays.asList(3, 1, 4, 1, 5, 9);

        System.out.println("Min: " + Collections.min(list));
        System.out.println("Max: " + Collections.max(list));
        System.out.println("Frequency of 1: " + Collections.frequency(list, 1));

        Collections.sort(list);
        System.out.println("Sorted List: " + list);

        Collections.sort(list, Comparator.reverseOrder());
        System.out.println("Reverse Sorted List: " + list);
    }
}
```
