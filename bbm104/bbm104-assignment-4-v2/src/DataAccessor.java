import java.io.*;

//Data Accessor class for reading and writing (updating) stack.txt and queue.txt

class DataAccessor {

    int[] getData(String dataPath) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(dataPath));
        String[] params = reader.readLine().split(" ");
        int[] intParams = new int[params.length];
        for (int i = 0; i < params.length; i++) {
            intParams[i] = Integer.parseInt(params[i]);
        }
        return intParams;
    }

    void setData(Object o, String outputPath) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(outputPath));
        bufferedWriter.write(o.toString());
        bufferedWriter.close();
    }
}
