import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

// This class provides CRUD functionality for admissions

public class AdmissionDataAccessor implements DataAccessor {

    private final ArrayList<Admission> admissions = new ArrayList<>();

    public AdmissionDataAccessor() throws IOException {
        this.importData();
    }

    @Override
    public Object getById(int id) {
        Admission requestedAdmission = null;

        for (Admission admission : admissions) {
            if (admission.getId() == id) requestedAdmission = admission;
        }
        return requestedAdmission;
    }

    @Override
    public Object deleteById(int id) {
        Admission admissionToDelete = null;

        for (Admission admission : admissions) {
            if (admission.getId() == id) admissionToDelete = admission;
        }
        this.admissions.remove(admissionToDelete);
        return admissionToDelete;
    }

    @Override
    public void add(Object o) {
        Admission admissionToAdd = (Admission) o;
        this.admissions.add(admissionToAdd);
    }

    @Override
    public ArrayList<Object> getAll() {
        return new ArrayList<>(this.admissions);
    }

    // Creates admission objects by using the data from 'admissions.txt'
    private void importData() throws IOException {
        BufferedReader admissionFileReader = new BufferedReader(new FileReader("admission.txt"));

        ArrayList<String> admissionFileLines = new ArrayList<>();
        String admissionFileLine;
        while ((admissionFileLine = admissionFileReader.readLine()) != null) {
            admissionFileLines.add(admissionFileLine);
        }

        List<String> admissionsStr = parseAdmissionFile(admissionFileLines);

        for (String admissionStr: admissionsStr) {

            String[] admissionStrLines = admissionStr.split("\n");

            String admissionHeader = admissionStrLines[0];

            int admissionId = Integer.parseInt(admissionHeader.split("\t")[0]);
            int patientId = Integer.parseInt(admissionHeader.split("\t")[1]);

            Admission admission = new Admission(admissionId, patientId);
            for (int i = 1; i < admissionStrLines.length; i++) {

                String examinationStr = admissionStrLines[i];
                String[] examinationParameters = examinationStr.split("\t");
                String examinationType = examinationParameters[0];
                String[] examinationOperations = examinationParameters[1].split(" ");

                admission.addExamination(examinationType, examinationOperations);
            }
            this.admissions.add(admission);
        }

    }

    /* A helper function for reading admissions from txt file. The number of examinations an admission
    * can have is not static this function contains the logic for importing all admissions and their
    * corresponding examinations correctly*/
    private List<String> parseAdmissionFile(ArrayList<String> admissionFileLines) {

        List<String> admissionsStr = new ArrayList<>();

        int firstLineIdx = 0;
        int secondLineIdx = 1;

        while (secondLineIdx < admissionFileLines.size())  {

            String firstLine = admissionFileLines.get(firstLineIdx);
            String secondLine = admissionFileLines.get(secondLineIdx);

            String[] firstLineExpressions = firstLine.split("\t");
            String[] secondLineExpressions = secondLine.split("\t");

            boolean firstLineIsNumeric = stringIsNumeric(firstLineExpressions[0]);
            boolean secondLineIsNumeric = stringIsNumeric(secondLineExpressions[0]);

            if (firstLineIsNumeric && secondLineIsNumeric) {
                admissionsStr.add(firstLine);
                admissionsStr.add(secondLine);
            }
            else {
                while (!secondLineIsNumeric && secondLineIdx + 1 < admissionFileLines.size()) {
                    secondLine = admissionFileLines.get(++secondLineIdx);
                    secondLineExpressions = secondLine.split("\t");
                    secondLineIsNumeric = stringIsNumeric(secondLineExpressions[0]);
                }

                StringBuilder admissionStrBuilder = new StringBuilder();

                while (!firstLine.equals(secondLine)) {
                    admissionStrBuilder.append(firstLine).append("\n");
                    firstLine = admissionFileLines.get(++firstLineIdx);
                }
                admissionsStr.add(admissionStrBuilder.toString());
            }
            secondLineIdx++;
        }
        String lastAdmission = admissionsStr.get(admissionsStr.size() - 1);
        lastAdmission =  lastAdmission.concat(admissionFileLines.get(admissionFileLines.size()-1));
        admissionsStr.remove(admissionsStr.size() - 1);
        admissionsStr.add(lastAdmission);
        return admissionsStr;
    }

    /*Another helper function related with admission importation logic*/
    private boolean stringIsNumeric(String s) {
        try {
            Integer.parseInt(s);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }

    /*After all CRUD operations this function updates the 'admissions.txt' just before program termination*/
    @Override
    public void close() throws IOException {

        admissions.sort(Comparator.comparing(Admission::getId));

        BufferedWriter admissionFileWriter = new BufferedWriter(new FileWriter("admission.txt"));
        StringBuilder admissionOutputBuilder = new StringBuilder();

        for (Admission admission : admissions) {
            String admissionHeader = String.format("%d\t%d", admission.getId(), admission.getPatientId());
            admissionOutputBuilder.append(admissionHeader).append("\n");

            for (Examination examination : admission.getExaminations()) {
                admissionOutputBuilder.append(examination.getDescription().trim()).append("\n");
            }
        }
        admissionFileWriter.write(admissionOutputBuilder.toString());
        admissionFileWriter.close();
    }

}
