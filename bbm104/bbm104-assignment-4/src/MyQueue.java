class MyQueue<Item> implements ForwardIterable<Item>, Mutable<Item> {

    class Node {
        Item item;
        Node next;
        Node prev;

        Node(Item item) {
            this.item = item;
            this.next = null;
            this.prev = null;
        }
    }

    private Node first;
    private Node last;
    private int size;

    MyQueue() {
        first = null;
        last = null;
        size = 0;
    }

    boolean isEmpty() {return first == null;}

    int size() {return size;}

    // Returns the front (first inserted) element of queue
    Item front() {
        if (isEmpty()) return null;
        return first.item;
    }

    // Mutable<T> interface implementations

    /* Note: this functions are the equivalents of "enqueue" and "dequeue" how ever because I've extracted
     * the similarities between stack and queue to an interface (Mutable<T>) for extensibility purposes
     * they are also named push and pop*/

    @Override
    public void push(Item item) {
        Node temp = new Node(item); size++;

        if (isEmpty()) first = last = temp;
        else {
            last.next = temp;
            temp.prev = last;
            last = temp;
        }
    }

    @Override
    public Item pop() {
        Node temp = first;
        if (isEmpty()) return null;

        else if (size == 1) {
            first = last = null;
        }
        else {
            first = first.next;
            first.prev = null;
        }
        size--;
        return temp.item;
    }

    // ForwardIterable<T> interface implementation

    @Override
    public ForwardIterator<Item> iterator() {
        return new ForwardIterator<Item>() {
            Node current = first;

            @Override
            public boolean hasNext() {
                return current != null;
            }

            @Override
            public Item next() {
                Item item = current.item;
                current = current.next;
                return item;
            }

            @Override
            public void remove() {
                if (current == null) {
                    last = last.prev;
                    last.next = null;
                }

                else if (current.prev == first) {
                    current.prev = null;
                    first = first.next;
                }
                else {
                    Node nodeToRemove = current.prev;
                    nodeToRemove.prev.next = nodeToRemove.next;
                    nodeToRemove.next.prev = nodeToRemove.prev;
                }
            }

            @Override
            public void set(Item item) {
                if (current == null) last.item = item;
                else {
                    current.prev.item = item;
                }
            }
        };
    }

    @Override
    public String toString() {
        StringBuilder s = new StringBuilder();
        for (Item item : this) {
            s.append(item);
            s.append(' ');
        }
        return s.toString();
    }

}
