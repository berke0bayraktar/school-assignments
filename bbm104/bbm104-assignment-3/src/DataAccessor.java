import java.io.IOException;
import java.util.ArrayList;

interface DataAccessor {
    Object getById(int id);
    Object deleteById(int id);
    void add(Object o);
    ArrayList<Object> getAll();
    void close() throws IOException;
}
