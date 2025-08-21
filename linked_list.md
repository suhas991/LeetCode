# Linked List in Java

## 📌 What is a Linked List?

A **Linked List** is a linear data structure where elements (nodes) are connected using pointers. Unlike arrays, linked lists do not store elements in contiguous memory locations.

* Each node consists of:

  * **Data**: the actual value
  * **Next**: reference to the next node

---

## 📌 Why Linked List?

* **Dynamic Size**: Unlike arrays, linked lists can grow or shrink at runtime.
* **Efficient Insert/Delete**: O(1) when reference is known, while arrays require shifting elements.
* **Drawback**: Accessing elements takes O(n) compared to O(1) in arrays.

---

## 📌 Types of Linked Lists

### 1. Singly Linked List

* Each node points to the **next node**.
* Last node points to `null`.

```text
Head -> [10|next] -> [20|next] -> [30|null]
```

### 2. Doubly Linked List

* Each node has **two references**: one for the next node and one for the previous node.

```text
null <- [10|prev,next] <-> [20|prev,next] <-> [30|prev,null]
```

### 3. Circular Linked List

* Last node points back to the **head**, forming a circle.

```text
Head -> [10|next] -> [20|next] -> [30|next] -> back to Head
```

---

## 📌 Node Class

```java
class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}
```

---

## 📌 Operations on Linked List

### 1. Traversal

```java
class LinkedList {
    Node head;

    void traverse() {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " -> ");
            current = current.next;
        }
        System.out.println("null");
    }
}
```

**Visual:**

```text
10 -> 20 -> 30 -> null
```

---

### 2. Insertion

#### a) At the Beginning

```java
void insertAtBeginning(int data) {
    Node newNode = new Node(data);
    newNode.next = head;
    head = newNode;
}
```

**Visual:** Insert `5` at beginning

```text
5 -> 10 -> 20 -> 30 -> null
```

#### b) At the End

```java
void insertAtEnd(int data) {
    Node newNode = new Node(data);
    if (head == null) {
        head = newNode;
        return;
    }
    Node current = head;
    while (current.next != null) {
        current = current.next;
    }
    current.next = newNode;
}
```

**Visual:** Insert `40` at end

```text
10 -> 20 -> 30 -> 40 -> null
```

#### c) At a Specific Position

```java
void insertAtPosition(int data, int position) {
    Node newNode = new Node(data);
    if (position == 0) {
        newNode.next = head;
        head = newNode;
        return;
    }
    Node current = head;
    for (int i = 0; i < position - 1 && current != null; i++) {
        current = current.next;
    }
    if (current == null) return; // Invalid position
    newNode.next = current.next;
    current.next = newNode;
}
```

**Visual:** Insert `15` at position 1

```text
10 -> 15 -> 20 -> 30 -> null
```

---

### 3. Deletion

#### a) At the Beginning

```java
void deleteAtBeginning() {
    if (head == null) return;
    head = head.next;
}
```

**Visual:** Delete beginning

```text
20 -> 30 -> null
```

#### b) At the End

```java
void deleteAtEnd() {
    if (head == null || head.next == null) {
        head = null;
        return;
    }
    Node current = head;
    while (current.next.next != null) {
        current = current.next;
    }
    current.next = null;
}
```

**Visual:** Delete end

```text
10 -> 20 -> null
```

#### c) By Value

```java
void deleteByValue(int key) {
    if (head == null) return;
    if (head.data == key) {
        head = head.next;
        return;
    }
    Node current = head;
    while (current.next != null && current.next.data != key) {
        current = current.next;
    }
    if (current.next == null) return; // Not found
    current.next = current.next.next;
}
```

**Visual:** Delete `20`

```text
10 -> 30 -> null
```

---

### 4. Searching

```java
boolean search(int key) {
    Node current = head;
    while (current != null) {
        if (current.data == key)
            return true;
        current = current.next;
    }
    return false;
}
```

**Example:** Search for `20` → Found.

---

### 5. Updating

```java
void update(int oldValue, int newValue) {
    Node current = head;
    while (current != null) {
        if (current.data == oldValue) {
            current.data = newValue;
            return;
        }
        current = current.next;
    }
}
```

**Visual:** Update `20` → `25`

```text
10 -> 25 -> 30 -> null
```

---

## 📌 Time Complexity

| Operation         | Singly LL | Doubly LL                   |
| ----------------- | --------- | --------------------------- |
| Traversal         | O(n)      | O(n)                        |
| Insertion at Head | O(1)      | O(1)                        |
| Insertion at End  | O(n)      | O(1) (if tail pointer used) |
| Deletion at Head  | O(1)      | O(1)                        |
| Deletion at End   | O(n)      | O(1) (if tail pointer used) |
| Searching         | O(n)      | O(n)                        |

---

## 📌 Real-world Use Cases

* **Music/Video playlist** navigation
* **Undo/Redo** functionality in editors
* **HashMaps** (buckets use linked lists internally)
* **Queue implementation**

---
