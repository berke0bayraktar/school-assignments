
import org.junit.Assert;
import org.junit.jupiter.api.Test;

class OperationsTest {

    MyStack<Integer> s = new MyStack<>();
    MyQueue<Integer> q = new MyQueue<>();

    {
        s.push(8); s.push(2); s.push(3); s.push(10); s.push(0); s.push(5);
        q.push(1); q.push(7); q.push(2); q.push(3); q.push(3); q.push(6);
        // stack: 5 0 10 3 2 8
        // queue: 1 7 2 3 3 6
    }

    @Test
    void removeGreaterNumber() {
        Operations.removeGreaterNumber(s, 4);
        Operations.removeGreaterNumber(q, 6);
        Assert.assertEquals("0 3 2 ", s.toString());
        Assert.assertEquals("1 2 3 3 6 ", q.toString());
    }

    @Test
    void calculateDistance() {
        Assert.assertEquals(70, Operations.calculateDistance(s));
        Assert.assertEquals(42, Operations.calculateDistance(q));
    }

    @Test
    void reverse() {
        Operations.reverse(s, 6);
        Assert.assertEquals("8 2 3 10 0 5 ", s.toString());
        Operations.reverse(q, 4);
        Assert.assertEquals("3 2 7 1 3 6 ", q.toString());
    }

    @Test
    void sort() {
        Operations.sort(s);
        Assert.assertEquals("0 2 3 5 8 10 ", s.toString());
        Operations.sort(q);
        Assert.assertEquals("1 2 3 3 6 7 ", q.toString());
    }

    @Test
    void addOrRemoveElements() {
        Operations.addOrRemoveElements(s, -3);
        Assert.assertEquals(3, s.size());
        System.out.println(s);
        Operations.addOrRemoveElements(q, 5);
        Assert.assertEquals(11, q.size());
        System.out.println(q);
    }

    @Test
    void getDistinctElementNumber() {
        Assert.assertEquals(6, Operations.getDistinctElementNumber(s));
        Assert.assertEquals(5, Operations.getDistinctElementNumber(q));
    }
}