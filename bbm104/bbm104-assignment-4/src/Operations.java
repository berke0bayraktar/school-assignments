import java.util.*;

class Operations {

    static void removeGreaterNumber(ForwardIterable<Integer> forwardIterable, int valueToCompare ) {
        ForwardIterator<Integer> it = forwardIterable.iterator();
        while (it.hasNext()) {
            int value = it.next();
            if (value > valueToCompare) {
                it.remove();
            }
        }
    }

    static int calculateDistance(ForwardIterable<Integer> forwardIterable) {
        ForwardIterator<Integer> it = forwardIterable.iterator();
        Iterator<Integer> it2;

        int total = 0;

        while (it.hasNext()) {
            int num1 = it.next();
            it2 = forwardIterable.iterator();
            while (it2.hasNext()) {
                int num2 = it2.next();
                int diff = Math.abs(num1 - num2);
                total += diff;
            }
        }
        return total / 2; // total is the distance sum of every ORDERED pair so we have to divide it by 2
    }

    static void reverse(ForwardIterable<Integer> forwardIterable, int upToIndex) {
        ForwardIterator<Integer> it = forwardIterable.iterator();
        ForwardIterator<Integer> it2 = forwardIterable.iterator();

        MyStack<Integer> elements = new MyStack<>(); // this is NOT java.utils.Stack, it is my own implementation

        // empty the portion of the "iterable" we want to reverse into a stack
        int counter = 0;
        while (it.hasNext() && counter < upToIndex) {
            elements.push(it.next());
            counter++;
        }

        it = forwardIterable.iterator(); // resetting iterator the "iterable" to initial point


        // refill the "iterable" with stack and since stacks are FIFO, the "iterable" is now reversed
        for (int i = 0; i < counter; i++) {
            it2.next();
            it.next();
            it.set(elements.pop());
        }
        while (it.hasNext()) {
            it.next();
            it.set(it2.next());
        }

    }

    static void sort(ForwardIterable<Integer> forwardIterable) {
        ForwardIterator<Integer> it;

        // computing the size of the iterable passed in
        it = forwardIterable.iterator();
        int iterableSize = 0;
        while(it.hasNext()) {
            iterableSize++;
            it.next();
        }

        /* I am creating and array passing all the content of my stack into this array
        sorting it and refilling the stack with sorted array. In piazza this was allowed
        in this follow up question: https://piazza.com/class/k71mofvhdqv12a?cid=56_f3 */

        int[] temp = new int[iterableSize];

        it = forwardIterable.iterator();
        int k = 0;
        while (it.hasNext()) {
            temp[k++] = it.next();
        }

        Arrays.sort(temp);
        k = 0;

        it = forwardIterable.iterator();
        while (it.hasNext()) {
            it.next();
            it.set(temp[k++]);
        }
    }

    static void addOrRemoveElements(Mutable<Integer> mutable, int addOrRemoveParam) {
        boolean add = addOrRemoveParam > 0;
        int addOrRemoveCount = Math.abs(addOrRemoveParam);

        if (add) {
            Random random = new Random();
            for (int i = 0; i < addOrRemoveCount; i++) {
                mutable.push(Math.abs(random.nextInt()) % 50);
            }
        }
        else {
            for (int i = 0; i < addOrRemoveCount; i++) {
                mutable.pop();
            }
        }
    }

    static int getDistinctElementNumber(ForwardIterable<Integer> forwardIterable) {
        sort(forwardIterable);

        Iterator<Integer> it1 = forwardIterable.iterator();
        Iterator<Integer> it2 = forwardIterable.iterator();

        it2.next();
        int distinctComparisonCount = 0;
        while (it2.hasNext()) {
            int first = it1.next();
            int second = it2.next();
            if (first != second) distinctComparisonCount++;
        }
        return distinctComparisonCount + 1; // n unique (a, b) comparison pair -> n+1 distinct elements
    }
}