import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

class CommandExecutor {
    private BufferedReader commandReader;


    CommandExecutor(String commandFilePath) throws IOException {
        this.commandReader = new BufferedReader(new FileReader(commandFilePath));
    }

    String getNextCommand() throws IOException {
        return commandReader.readLine();
    }

    void executeCommand(Stack stack, Queue queue, String command) throws IOException {

        if (command == null) return;

        String[] commandParameters = command.split(" ");
        String dataStructureType = commandParameters[0];
        String operationType = commandParameters[1];
        int operationParameter = 0;

        if (commandParameters.length > 2) {
            operationParameter = Integer.parseInt(commandParameters[2]);
        }

        Logger logger = new Logger();

        switch (operationType) {
            case "removeGreater":
                if (dataStructureType.equals("S")) {
                    stack.removeGreaterNumber(operationParameter);
                    logger.logRemoveGreater(stack, String.valueOf(operationParameter));
                }
                else if (dataStructureType.equals("Q")) {
                    queue.removeGreaterNumber(operationParameter);
                    logger.logRemoveGreater(queue, String.valueOf(operationParameter));
                }
                break;
            case "calculateDistance":
                int distance;
                if (dataStructureType.equals("S")) {
                    distance = stack.calculateDistance();
                    logger.logDistanceCalculation(stack, String.valueOf(distance));
                }
                else if (dataStructureType.equals("Q")) {
                    distance = queue.calculateDistance();
                    logger.logDistanceCalculation(queue, String.valueOf(distance));
                }
                break;

            case "addOrRemove":
                if (dataStructureType.equals("S")) {
                    stack.addOrRemove(operationParameter);
                    logger.logAdditionOrRemoval(stack, String.valueOf(operationParameter));
                }
                else if (dataStructureType.equals("Q")) {
                    queue.addOrRemove(operationParameter);
                    logger.logAdditionOrRemoval(queue, String.valueOf(operationParameter));
                }
                break;

            case "reverse":
                if (dataStructureType.equals("S")) {
                    stack.reverse(operationParameter);
                    logger.logReversal(stack, String.valueOf(operationParameter));
                }
                else if (dataStructureType.equals("Q")) {
                    queue.reverse(operationParameter);
                    logger.logReversal(queue, String.valueOf(operationParameter));
                }
                break;
            case "sortElements":
                if (dataStructureType.equals("S")) {
                    stack.sort();
                    logger.logSort(stack);
                }
                else if (dataStructureType.equals("Q")) {
                    queue.sort();
                    logger.logSort(queue);
                }
                break;
            case "distinctElements":
                int distinctElementNumber;
                if (dataStructureType.equals("S")) {
                    distinctElementNumber = stack.getDistinctElement();
                    logger.logDistinctElementNumber(stack, String.valueOf(distinctElementNumber));
                }
                else if (dataStructureType.equals("Q")) {
                    distinctElementNumber = queue.getDistinctElement();
                    logger.logDistinctElementNumber(queue, String.valueOf(distinctElementNumber));
                }
        }
    }
}
