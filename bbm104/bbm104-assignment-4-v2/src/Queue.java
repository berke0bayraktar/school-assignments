import java.util.HashSet;
import java.util.Random;
import java.util.Set;

// at least one of 4 functions (enqueue, dequeue, push, pop) is used for every 'operation'

public class Queue {

    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    private Node first, last;
    private int size;

    Queue() {
        first = last = null;
        size = 0;
    }

    boolean isEmpty() {return this.size == 0;}

    int size() {return this.size;}

    int front() {
        if (isEmpty()) return -1;
        else return first.data;
    }

    void enqueue(int data) {
        Node temp = new Node(data);
        if (isEmpty()) first = last = temp;
        else {
            last.next = temp; //  link previous last node to new last node (enqueued node)
            last = temp; // shift the 'last' pointer to current last
        }
        size++;
    }

    // this function is only used while reading from file
    void enqueueAll(int[] values) {
        for (int value : values) {
            this.enqueue(value);
        }
    }

    int dequeue() {
        if (isEmpty()) return -1;

        int dataToReturn = first.data;

        if (this.size() == 1) { // if size was 1 queue is now empty
            first = last = null;
            size = 0;
        }
        else {
            first = first.next; // reference lost for first node
            size--;
        }
        return dataToReturn;
    }

    private void clear() {
        first = null;
        last = null;
        size = 0;
    }

    void removeGreaterNumber(int boundary) {
        Queue queue = new Queue();
        Node temp = first;
        while (temp != null) {
            if (temp.data <= boundary) {
                queue.enqueue(temp.data);
            }
            temp = temp.next;
        }

        this.clear();

        int size = queue.size();
        for (int i = 0; i < size; i++) {
            this.enqueue(queue.dequeue());
        }
    }

    /*calculate every ordered pair, this includes both (a, b) and (b, a)
    * therefore we have to divide the overall result by 2. */
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
                this.dequeue();
            }
        }
        else {
            Random random = new Random();
            for (int i = 0; i < count; i++) {
                int randomNumber = Math.abs(random.nextInt()) % 50; // mod is to ensure number is smaller than 50
                this.enqueue(randomNumber);
            }
        }
    }

    /* actual sorting logic resides in stack class
    to sort the queue we benefit from sort method of the stack
     */
    void sort() {
        Stack stack = new Stack();
        int size = this.size();
        for (int i = 0; i < size; i++) {
            stack.push(this.dequeue());
        }
        stack.sort();
        for (int i = 0; i < size; i++) {
            this.enqueue(stack.pop());
        }
    }

    void reverse(int boundary) {
        Queue queue = new Queue();
        Stack stack = new Stack();
        int size = this.size();

        // push all elements up to boundary inside a stack
        for (int i = 0; i < boundary; i++) {
            stack.push(this.dequeue());
        }

        // enqueue the part from boundary until end of queue to a new queue
        for (int i = boundary; i < size; i++) {
            queue.enqueue(this.dequeue());
        }

        // empty temporary stack into this queue
        for (int i = 0; i < boundary; i++) {
            this.enqueue(stack.pop());
        }

        // empty temporary queue into this queue
        for (int i = boundary; i < size; i++) {
            this.enqueue(queue.dequeue());
        }

        /* this process will reverse the first N elements of 'this' queue
        * where N = boundary because of the LIFO and FIFO structure of stack and queue respectively*/
    }


   // Note: In piazza we were told that use of hash set for this function is allowed

    int getDistinctElement() {
        Set<Integer> s = new HashSet<>();
        Queue q = new Queue();
        Node temp = first;

        while (temp != null) {
            q.enqueue(temp.data);
            temp = temp.next;
        }

        int size = q.size();
        for (int i = 0; i < size; i++) {
            s.add(q.dequeue());
        }
        return s.size();
    }

    /*overriding this method so writing to output files are more convenient*/
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
