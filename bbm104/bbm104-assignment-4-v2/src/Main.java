import java.io.IOException;

public class Main {

    private static final String STACK_PATH = "stack.txt";
    private static final String QUEUE_PATH = "queue.txt";

    public static void main(String[] args) {
        DataAccessor dataAccessor = new DataAccessor();

        Stack stack = new Stack();
        Queue queue = new Queue();

        try {
            stack.pushAll(dataAccessor.getData(STACK_PATH));
            queue.enqueueAll(dataAccessor.getData(QUEUE_PATH));

            CommandExecutor commandExecutor = new CommandExecutor(args[0]);

            String nextCommand;
            while ((nextCommand = commandExecutor.getNextCommand()) != null) {
                commandExecutor.executeCommand(stack, queue, nextCommand);
            }

            dataAccessor.setData(stack, STACK_PATH);
            dataAccessor.setData(queue, QUEUE_PATH);


        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
