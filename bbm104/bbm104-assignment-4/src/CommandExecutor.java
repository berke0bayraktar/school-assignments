import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

class CommandExecutor {
    private BufferedReader commandReader;


    CommandExecutor(String commandFilePath) throws IOException {
        this.commandReader = new BufferedReader(new FileReader(commandFilePath));
    }

    void fillStructure(Mutable<Integer> mutable, String structureFilePath) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(structureFilePath));
        String[] elements = reader.readLine().split(" ");
        for (String element : elements) {
            mutable.push(Integer.parseInt(element));
        }
    }

    String getNextCommand() throws IOException {
        return commandReader.readLine();
    }

    void executeCommand(MyStack<Integer> stack, MyQueue<Integer> queue, String command) throws IOException {

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
                    Operations.removeGreaterNumber(stack, operationParameter);
                    logger.logSpecifiedElementRemoval(stack, String.valueOf(operationParameter));
                }
                else if (dataStructureType.equals("Q")) {
                    Operations.removeGreaterNumber(queue, operationParameter);
                    logger.logSpecifiedElementRemoval(queue, String.valueOf(operationParameter));
                }
                break;
            case "calculateDistance":
                int distance;
                if (dataStructureType.equals("S")) {
                    distance = Operations.calculateDistance(stack);
                    logger.logDistanceCalculation(stack, String.valueOf(distance));
                }
                else if (dataStructureType.equals("Q")) {
                    distance = Operations.calculateDistance(queue);
                    logger.logDistanceCalculation(queue, String.valueOf(distance));
                }
                break;

            case "addOrRemove":
                if (dataStructureType.equals("S")) {
                    Operations.addOrRemoveElements(stack, operationParameter);
                    logger.logAdditionOrRemoval(stack, String.valueOf(operationParameter));
                }
                else if (dataStructureType.equals("Q")) {
                    Operations.addOrRemoveElements(queue, operationParameter);
                    logger.logAdditionOrRemoval(queue, String.valueOf(operationParameter));
                }
                break;

            case "reverse":
                if (dataStructureType.equals("S")) {
                    Operations.reverse(stack, operationParameter);
                    logger.logReversal(stack, String.valueOf(operationParameter));
                }
                else if (dataStructureType.equals("Q")) {
                    Operations.reverse(queue, operationParameter);
                    logger.logReversal(queue, String.valueOf(operationParameter));
                }
                break;
            case "sortElements":
                if (dataStructureType.equals("S")) {
                    Operations.sort(stack);
                    logger.logSort(stack);
                }
                else if (dataStructureType.equals("Q")) {
                    Operations.sort(queue);
                    logger.logSort(queue);
                }
                break;
            case "distinctElementNumber":
                int distinctElementNumber;
                if (dataStructureType.equals("S")) {
                    distinctElementNumber = Operations.getDistinctElementNumber(stack);
                    logger.logDistinctElementNumber(stack, String.valueOf(distinctElementNumber));
                }
                else if (dataStructureType.equals("Q")) {
                    distinctElementNumber = Operations.getDistinctElementNumber(queue);
                    logger.logDistinctElementNumber(queue, String.valueOf(distinctElementNumber));
                }
        }
    }
}
