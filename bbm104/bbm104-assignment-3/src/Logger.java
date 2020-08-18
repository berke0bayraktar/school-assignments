import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.List;

    /* This class is responsible for logging the operations 'hospital controller' executes to the 'output.txt'*/
class Logger {
    private BufferedWriter outputFileWriter;

    Logger() throws IOException {
        outputFileWriter = new BufferedWriter(new FileWriter("output.txt"));
    }

    public void listPatients(List<Patient> patients) throws IOException {
        outputFileWriter.write("Patient List:\n");
        for (Patient p : patients) {
            logPatient(p.getId(), p.getFirstName(), p.getLastName(),
                    p.getPhoneNumber(), p.getAddress());
        }
    }

    private void logPatient(int patientId, String patientName, String patientSurname,
                    String patientPhoneNumber, String patientAddress) throws IOException {

        outputFileWriter.write(String.format("%d %s %s %s Address: %s\n", patientId, patientName,
                patientSurname, patientPhoneNumber, patientAddress));
    }

    public void logPatientAction(Patient patient, boolean added) throws IOException {

        outputFileWriter.write(String.format("Patient %d %s ",
                patient.getId(), patient.getFirstName()));

        if (added) outputFileWriter.write("added\n");
        else outputFileWriter.write("removed\n");
    }

    public void logAdmissionAddition(Admission admission) throws IOException {
        outputFileWriter.write(String.format("Admission %d created\n", admission.getId()));
    }

    public void logTotalCost(Admission admission) throws IOException {
        StringBuilder admissionLogBuilder = new StringBuilder();

        List<Examination> examinations = admission.getExaminations();
        admissionLogBuilder.append(String.format("TotalCost for admission %d\n", admission.getId()));

        double totalCost = 0;
        for (Examination examination : examinations) {
            // Examination description String has to be refactored to match desired output
            String examinationDescriptionType = examination.getDescription().split("\t")[0];
            String examinationDescriptionOperations = examination.getDescription().split("\t")[1];
            String newExaminationDescription = String.format("%s %s", examinationDescriptionType,
                    examinationDescriptionOperations).trim();

            double examinationCost = examination.getCost();

            admissionLogBuilder.append(String.format("\t%s %.0f$\n",newExaminationDescription, examinationCost));

            totalCost += examinationCost;
        }
        admissionLogBuilder.append(String.format("\tTotal: %.0f$\n", totalCost));

        outputFileWriter.write(admissionLogBuilder.toString());
    }

    public void logExaminationAddition(int admissionId, String examinationType) throws IOException {
        String examinationAdditionStr = String.format(
                "%s examination added to admission %d\n", examinationType, admissionId);
        outputFileWriter.write(examinationAdditionStr);
    }

    public void saveAll() throws IOException {
        outputFileWriter.close();
    }

}
