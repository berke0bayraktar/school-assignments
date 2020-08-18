import java.util.Iterator;

/* this iterator has the functionality to:
1- iterate forward
2- set (change/edit) current element the iterator is on
3- remove the current element

Note: Because this iterator enforces the functionality to remove and change elements of a
iterable, stack's and queue's (which implement this interface) "Node"s have doubly links.
 */
public interface ForwardIterator<E> extends Iterator<E> {
    boolean hasNext();
    E next();
    void remove();
    void set(E e);
}
