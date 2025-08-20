# Ducking and Rethrowing in Java Exceptions

Exception handling in Java allows us to manage errors gracefully. Two important concepts are **Ducking** and **Rethrowing** exceptions.

---

## 1. Ducking Exceptions

### Definition

Ducking means **passing the responsibility of handling an exception to the calling method**. In Java, this is done using the `throws` keyword in the method declaration.

### Why Ducking?

* The current method **does not know how to handle** the exception.
* It delegates handling responsibility to its caller.
* Common with **checked exceptions**.

### Syntax

```java
returnType methodName(params) throws ExceptionType1, ExceptionType2 {
    // method code that may throw exceptions
}
```

### Example

```java
class FileReaderDemo {
    void readFile(String fileName) throws IOException {  // Ducking exception
        FileReader fr = new FileReader(fileName);
        BufferedReader br = new BufferedReader(fr);
        System.out.println(br.readLine());
    }

    public static void main(String[] args) {
        FileReaderDemo demo = new FileReaderDemo();
        try {
            demo.readFile("test.txt");
        } catch (IOException e) {  // Caller handles exception
            System.out.println("File not found: " + e.getMessage());
        }
    }
}
```

---

## 2. Rethrowing Exceptions

### Definition

Rethrowing means **catching an exception in a method, performing some action (like logging), and then throwing it again** so that higher-level methods can handle it.

### Why Rethrow?

* To **log or wrap exception** before passing it up.
* Allows intermediate layers to add **contextual information**.
* Useful for debugging.

### Syntax

```java
try {
    // code that may throw exception
} catch (Exception e) {
    // handle/log
    throw e;  // rethrowing
}
```

### Example

```java
class DatabaseConnection {
    void connect() throws SQLException {
        throw new SQLException("Unable to connect to DB");
    }
}

class ServiceLayer {
    void process() throws SQLException {
        DatabaseConnection db = new DatabaseConnection();
        try {
            db.connect();
        } catch (SQLException e) {
            System.out.println("Logging: " + e.getMessage());
            throw e;  // Rethrowing exception
        }
    }
}

public class RethrowDemo {
    public static void main(String[] args) {
        ServiceLayer service = new ServiceLayer();
        try {
            service.process();
        } catch (SQLException e) {
            System.out.println("Handled in main: " + e.getMessage());
        }
    }
}
```

---

## 3. Key Differences: Ducking vs Rethrowing

| Feature        | Ducking                             | Rethrowing                              |
| -------------- | ----------------------------------- | --------------------------------------- |
| **Definition** | Passing responsibility to caller    | Catching and throwing again             |
| **Use Case**   | When method cannot handle exception | When method adds context/logging        |
| **Syntax**     | `throws` keyword                    | `throw` inside catch                    |
| **Control**    | Caller decides handling             | Both intermediate and caller can handle |

---

## 4. Flow of Exception Propagation

```
[Method A] --calls--> [Method B] --calls--> [Method C]

Method C throws IOException
 → If C declares throws → goes to B
 → If B ducks (throws) → goes to A
 → If A catches → handled
```

---

## 5. Best Practices

* Use **ducking** for low-level methods that shouldn’t decide how to handle.
* Use **rethrowing** when you need to add logging, custom messages, or wrap exceptions.
* Don’t swallow exceptions silently.
* Wrap checked exceptions into **custom runtime exceptions** if they are application-specific.

---

✅ **In summary:**

* **Ducking**: "I can’t handle it, you deal with it." (`throws`)
* **Rethrowing**: "I noticed this, logging it, but passing it up." (`catch + throw`)
