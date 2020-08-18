import java.util.HashSet;
import java.util.Random;

/* Queue and Stack class have many common functions and they're documented in queue class
this class contains comments for only functions that are unique to this class*/

// at least one of 4 functions (enqueue, dequeue, push, pop) is used for every 'operation'

public class Stack {
    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    private Node first;
    private int size;

    Stack() {
        first = null;
        size = 0;
    }

    boolean isEmpty() {return this.size == 0;}

    int size() {return this.size;}

    int peek() {
        if (isEmpty()) return -1;
        else return first.data;
    }

    void push(int data) {
        Node temp = new Node(data);
        if (isEmpty()) first = temp;
        else {
            temp.next = first;
            first = temp;
        }
        size++;
    }

    // this function is only used while reading from file
    void pushAll(int[] values) {
        for (int i = 0; i < values.length; i++) {
            this.push(values[values.length-1-i]);
        }
    }

    int pop() {
        if (isEmpty()) return -1;
        else {
            int dataToReturn = first.data;
            first = first.next;
            size--;
            return dataToReturn;
        }
    }

    private void clear() {
        first = null;
        size = 0;
    }

    void removeGreaterNumber(int boundary) {
        Stack stack = new Stack();
        Node temp = first;
        while (temp != null) {
            if (temp.data <= boundary) {
                stack.push(temp.data);
            }
            temp = temp.next;
        }

        this.clear();

        int size = stack.size();
        for (int i = 0; i < size; i++) {
            this.push(stack.pop());
        }
    }

    int calculateDistance() {
        Queue q = new Queue();
        Node temp = first;

        while (temp != null) {
            q.enqueue(temp.data);
            temp = temp.next;
        }

        int qSize = q.size();

        int[] qArray = new int[qSize];

        for (int i = 0; i < qSize; i++) {
            qArray[i] = q.dequeue();
        }

        int total = 0;

        for (int i = 0; i < qArray.length; i++) {
            int num1 = qArray[i];
            for (int j = 0; j < qArray.length; j++) {
                int num2 = qArray[j];
                int distance = Math.abs(num1- num2);
                total += distance;
            }
        }
        return total / 2;
    }

    void addOrRemove(int count) {
        if (count < 0) {
            for (int i = 0; i < -count; i++) {
                this.pop();
            }
        }
        else {
            Random random = new Random();
            for (int i = 0; i < count; i++) {
                int randomNumber = Math.abs(random.nextInt()) % 50;
                this.push(randomNumber);
            }
        }
    }

    /*algorithm to sort using 2 stacks
    * one is the temporary stack and one is 'this' stack instance*/
    void sort() {
        Stack tempStack = new Stack();

        while (!this.isEmpty()) {
            int popped = this.pop();
            while (!tempStack.isEmpty() && tempStack.peek() > popped) {
                this.push(tempStack.pop());
            }
            tempStack.push(popped);
        }

        this.clear();
        /*algorithm sorts such that the result is left in the
        * temporary stack (in reverse order) therefore we clear this stack instance then
        * transfer temporary stack into this stack.*/

        int tempStackSize = tempStack.size();
        for (int i = 0; i < tempStackSize; i++) {
            this.push(tempStack.pop());
        }

    }

    void reverse(int boundary) {
        Queue queue = new Queue();

        for (int i = 0; i < boundary; i++) {
            queue.enqueue(this.pop());
        }

        for (int i = 0; i < boundary; i++) {
            this.push(queue.dequeue());
        }
    }

    int getDistinctElement() {
        HashSet<Integer> hs = new HashSet<>();
        Queue q = new Queue();
        Node temp = first;

        while (temp != null) {
            q.enqueue(temp.data);
            temp = temp.next;
        }

        int queueSize = q.size();

        for (int i = 0; i < queueSize; i++) {
            hs.add(q.dequeue());
        }
        return hs.size();
    }

    @Override
    public String toString() {
        StringBuilder strRepresentation = new StringBuilder();
        Node temp = first;
        while (temp != null) {
            strRepresentation.append(String.format("%d ", temp.data));
            temp = temp.next;
        }
        return strRepresentation.toString();
    }
}
