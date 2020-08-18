/* this interface is implemented by both stack and queue with respect to their data structure
* that is, stack is FIFO and queue is LIFO*/

public interface Mutable<E> {
    void push(E e);
    E pop();
}
