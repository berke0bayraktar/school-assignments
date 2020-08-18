public interface ForwardIterable<T> extends Iterable<T> {
    ForwardIterator<T> iterator();
}
