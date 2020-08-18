import java.io.IOException;

public class Main {

    public static void main(String[] args) throws IOException {
        MyStack<Integer> stack = new MyStack<>();
        MyQueue<Integer> queue = new MyQueue<>();

        CommandExecutor commandExecutor = new CommandExecutor("command.txt");

        commandExecutor.fillStructure(stack, "stack.txt");
        commandExecutor.fillStructure(queue, "queue.txt");

        String nextCommand;
        while ((nextCommand = commandExecutor.getNextCommand()) != null) {
            commandExecutor.executeCommand(stack, queue, nextCommand);
        }
    }
}
