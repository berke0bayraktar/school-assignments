import java.io.FileWriter;
import java.io.IOException;


class Logger {
    private static final String  STACK_OUTPUT_FILE = "stackOut.txt";
    private static final String  QUEUE_OUTPUT_FILE = "queueOut.txt";

    private void writeToFile(Object dataStructure, String output) throws IOException {
        FileWriter writer = null;
        if (dataStructure instanceof MyStack) {
            writer = new FileWriter(STACK_OUTPUT_FILE, true);
        }

        if (dataStructure instanceof MyQueue) {
            writer = new FileWriter(QUEUE_OUTPUT_FILE, true);
        }
        writer.append(output);
        writer.close();
    }

    void logSpecifiedElementRemoval(Object dataStructure, String rangeStr) throws IOException {
        String output = String.format("After removeGreater %s:\n%s\n", rangeStr, dataStructure);
        writeToFile(dataStructure, output);
    }
    void logDistanceCalculation(Object dataStructure, String distance) throws IOException {
        String output = String.format("After calculateDistance:\nTotal distance=%s\n", distance);
        writeToFile(dataStructure, output);
    }
    void logReversal(Object dataStructure, String rangeStr) throws IOException {
        String output = String.format("After reverse %s:\n%s\n", rangeStr, dataStructure);
        writeToFile(dataStructure, output);
    }
    void logSort(Object dataStructure) throws IOException {
        String output = String.format("After sort:\n%s\n", dataStructure);
        writeToFile(dataStructure, output);
    }
    void logAdditionOrRemoval(Object dataStructure, String rangeStr) throws IOException {
        String output = String.format("After addOrRemove %s:\n%s\n", rangeStr, dataStructure);
        writeToFile(dataStructure, output);
    }
    void logDistinctElementNumber(Object dataStructure, String distinctElementCount) throws IOException {
        String output = String.format("After distinctElements:\n" +
                "Total distinct element=%s\n", distinctElementCount);
        writeToFile(dataStructure, output);
    }
}
