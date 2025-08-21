# 📘 Java Multithreading – Detailed Notes

---

## 🔹 1. Java Multithreading Overview

**Multithreading** is a process of executing multiple threads simultaneously.

* Each **thread** is a lightweight sub-process (a unit of execution).
* Multithreading improves performance by allowing concurrent execution.

✅ **Key Benefits:**

* Better CPU utilization
* Concurrent execution
* Non-blocking UI in applications

---

## 🔹 2. Thread Life Cycle

Threads in Java go through several states:

```
New → Runnable → Running → (Waiting / Timed Waiting / Blocked) → Terminated
```

### **Diagram:**

```
   New
    ↓ start()
 Runnable → Running
    ↑         ↓
 Waiting/Blocked/Timed Waiting
    ↓
 Terminated
```

### **Example:**

```java
class MyThread extends Thread {
    public void run() {
        System.out.println(Thread.currentThread().getName() + " is running...");
    }
}

public class ThreadLifeCycleExample {
    public static void main(String[] args) throws InterruptedException {
        MyThread t1 = new MyThread();
        System.out.println("State after creation: " + t1.getState());

        t1.start(); // moves to Runnable → Running
        System.out.println("State after start(): " + t1.getState());

        Thread.sleep(100);
        System.out.println("State after sleep: " + t1.getState());
    }
}
```

---

## 🔹 3. Creating a Thread

There are **two ways** to create a thread:

### **(a) Extending Thread class**

```java
class MyThread extends Thread {
    public void run() {
        System.out.println("Thread running by extending Thread class");
    }
}

public class ThreadExample1 {
    public static void main(String[] args) {
        MyThread t = new MyThread();
        t.start();
    }
}
```

### **(b) Implementing Runnable interface**

```java
class MyRunnable implements Runnable {
    public void run() {
        System.out.println("Thread running by implementing Runnable");
    }
}

public class ThreadExample2 {
    public static void main(String[] args) {
        Thread t = new Thread(new MyRunnable());
        t.start();
    }
}
```

---

## 🔹 4. Starting a Thread

```java
class MyThread extends Thread {
    public void run() {
        System.out.println("Thread is running...");
    }
}

public class StartThreadExample {
    public static void main(String[] args) {
        MyThread t1 = new MyThread();
        t1.start(); // correct way

        // t1.run(); // ❌ Wrong: Executes like a normal method
    }
}
```

---

## 🔹 5. Joining Threads

`join()` allows one thread to wait for another to complete.

```java
class MyThread extends Thread {
    public void run() {
        for(int i = 1; i <= 5; i++) {
            System.out.println(Thread.currentThread().getName() + " - " + i);
            try { Thread.sleep(500); } catch(Exception e) {}
        }
    }
}

public class JoinExample {
    public static void main(String[] args) throws InterruptedException {
        MyThread t1 = new MyThread();
        MyThread t2 = new MyThread();

        t1.start();
        t1.join(); // main waits for t1 to finish

        t2.start();
    }
}
```

---

## 🔹 6. Naming Threads

```java
public class NamingThreadExample {
    public static void main(String[] args) {
        Thread t1 = new Thread(() -> System.out.println("Thread: " + Thread.currentThread().getName()));
        t1.setName("Worker-1");
        t1.start();

        System.out.println("Main thread name: " + Thread.currentThread().getName());
    }
}
```

---

## 🔹 7. Thread Scheduler

* The **Thread Scheduler** decides which thread runs at a given time.
* Scheduling is **JVM + OS dependent**.
* Uses **Preemptive Scheduling** or **Time-Slicing**.

```java
class Task extends Thread {
    public void run() {
        System.out.println("Running: " + Thread.currentThread().getName());
    }
}

public class SchedulerExample {
    public static void main(String[] args) {
        for (int i = 1; i <= 5; i++) {
            new Task().start();
        }
    }
}
```

---

## 🔹 8. Thread Pools

`ExecutorService` manages a pool of threads.

```java
import java.util.concurrent.*;

class Task implements Runnable {
    public void run() {
        System.out.println("Executed by: " + Thread.currentThread().getName());
    }
}

public class ThreadPoolExample {
    public static void main(String[] args) {
        ExecutorService executor = Executors.newFixedThreadPool(3);

        for(int i=0; i<6; i++) {
            executor.execute(new Task());
        }

        executor.shutdown();
    }
}
```

---

## 🔹 9. Main Thread

* Every Java program has a **main thread**.
* JVM starts execution with `main()`.

```java
public class MainThreadExample {
    public static void main(String[] args) {
        Thread t = Thread.currentThread();
        System.out.println("Main thread: " + t.getName());
    }
}
```

---

## 🔹 10. Thread Priority

* Each thread has a **priority (1 to 10)**.
* Default = `5` (NORM\_PRIORITY).
* Higher priority **may** get preference in execution.

```java
class PriorityThread extends Thread {
    public void run() {
        System.out.println(getName() + " with priority " + getPriority());
    }
}

public class PriorityExample {
    public static void main(String[] args) {
        PriorityThread t1 = new PriorityThread();
        PriorityThread t2 = new PriorityThread();

        t1.setPriority(Thread.MIN_PRIORITY); // 1
        t2.setPriority(Thread.MAX_PRIORITY); // 10

        t1.start();
        t2.start();
    }
}
```

---

## 🔹 11. Synchronization

Used to prevent **race conditions** when multiple threads access shared data.

```java
class Counter {
    int count;
    synchronized void increment() { count++; }
}

public class SyncExample {
    public static void main(String[] args) throws InterruptedException {
        Counter c = new Counter();

        Thread t1 = new Thread(() -> {
            for(int i=0; i<1000; i++) c.increment();
        });

        Thread t2 = new Thread(() -> {
            for(int i=0; i<1000; i++) c.increment();
        });

        t1.start(); t2.start();
        t1.join(); t2.join();

        System.out.println("Final Count: " + c.count);
    }
}
```

---

## 🔹 12. Deadlock

Occurs when two or more threads are waiting on each other forever.

```java
class Resource {}

public class DeadlockExample {
    public static void main(String[] args) {
        final Resource r1 = new Resource();
        final Resource r2 = new Resource();

        Thread t1 = new Thread(() -> {
            synchronized(r1) {
                System.out.println("Thread 1 locked r1");
                try { Thread.sleep(100); } catch(Exception e) {}
                synchronized(r2) {
                    System.out.println("Thread 1 locked r2");
                }
            }
        });

        Thread t2 = new Thread(() -> {
            synchronized(r2) {
                System.out.println("Thread 2 locked r2");
                try { Thread.sleep(100); } catch(Exception e) {}
                synchronized(r1) {
                    System.out.println("Thread 2 locked r1");
                }
            }
        });

        t1.start(); t2.start();
    }
}
```

### **Deadlock Prevention Techniques:**

1. **Avoid Nested Locks** – Don’t lock one resource inside another.
2. **Lock Ordering** – Acquire locks in a fixed order.
3. **Timeouts** – Use `tryLock()` with timeout.
4. **Deadlock Detection** – Monitor threads.

---

# ✅ Summary

* Java Multithreading allows concurrent execution.
* Thread lifecycle: New → Runnable → Running → Waiting/Blocked → Terminated.
* Threads can be created using **Thread** or **Runnable**.
* `start()`, `join()`, `setName()`, priorities control execution.
* Synchronization ensures thread safety.
* Deadlocks must be avoided with proper lock handling.

---
