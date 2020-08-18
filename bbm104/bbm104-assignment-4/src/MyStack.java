class MyStack<Item> implements ForwardIterable<Item>, Mutable<Item> {

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

    MyStack() {
        first = null;
        last = null;
        size = 0;
    }

    boolean isEmpty() {return first == null;}

    int size() {return size;}

    // Returns the top (last inserted) element of stack
    Item peek() {
        if (isEmpty()) return null;
        return first.item;
    }

    // Mutable<T> interface implementation

    @Override
    public void push(Item item) {
        Node temp = new Node(item); size++;

        if (isEmpty()) first = last = temp;
        else {
            temp.next = first;
            first.prev = temp;
            first = temp;
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
                    Node nodeToChange = current.prev;
                    nodeToChange.item = item;
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