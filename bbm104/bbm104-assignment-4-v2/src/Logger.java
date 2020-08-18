import java.io.FileWriter;
import java.io.IOException;

// This class logs the performed operations to their corresponding files.

class Logger {
    private static final String  STACK_OUTPUT_FILE = "stackOut.txt";
    private static final String  QUEUE_OUTPUT_FILE = "queueOut.txt";


    private void writeToFile(Object dataStructure, String output) throws IOException {

        FileWriter writer;

        if (dataStructure instanceof Stack) {
            writer = new FileWriter(STACK_OUTPUT_FILE, true);
        }

        else {
            writer = new FileWriter(QUEUE_OUTPUT_FILE, true);
        }
        writer.append(output);
        writer.close();
    }


    void logRemoveGreater(Object dataStructure, String rangeStr) throws IOException {
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
