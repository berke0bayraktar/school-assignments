import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;

class InstructionExecutor {
    private HospitalController hospitalController;

    public InstructionExecutor() throws IOException {
        hospitalController = new HospitalController();
    }

    /* This function provides 'hospital controller' all the instruction details it needs
    * from the 'input.txt' file*/
    public void executeInstructions(String inputFilePath) throws IOException {
        BufferedReader inputFileReader = new BufferedReader(new FileReader(inputFilePath));

        String instruction;
        while ((instruction = inputFileReader.readLine()) != null) {
            String[] instructionParameters = instruction.split(" ");

            String instructionOperator = instructionParameters[0];

            switch (instructionOperator) {
                case "AddPatient": {

                        int patientId = Integer.parseInt(instructionParameters[1]);
                        String firstName = instructionParameters[2];
                        String lastName = instructionParameters[3];
                        String phoneNumber = instructionParameters[4];
                        String address = "";

                        for (int i = 5; i < instructionParameters.length; i++) {
                            address = address.concat(instructionParameters[i].trim()).concat(" ");
                        }
                        address = address.trim(); // removing the last redundant whitespace

                        hospitalController.addPatient(patientId, firstName, lastName, phoneNumber, address);

                    break;
                }
                case "RemovePatient": {
                    int patientId = Integer.parseInt(instructionParameters[1]);
                    hospitalController.removePatient(patientId);
                    break;
                }
                case "CreateAdmission": {
                    int addmissionId = Integer.parseInt(instructionParameters[1]);
                    int patientId = Integer.parseInt(instructionParameters[2]);
                    hospitalController.addAdmission(addmissionId, patientId);
                    break;
                }
                case "AddExamination": {
                    int addmissionId = Integer.parseInt(instructionParameters[1]);
                    String examinationType = instructionParameters[2];
                    int firstOperationIdx = 3;
                    int lastOperationIdx = instructionParameters.length - 1;

                    String[] examinationOperations = Arrays.copyOfRange(
                            instructionParameters, firstOperationIdx, lastOperationIdx+1);

                    hospitalController.addExamination(addmissionId, examinationType, examinationOperations);
                    break;
                }
                case "TotalCost": {
                    int addmissionId = Integer.parseInt(instructionParameters[1]);
                    hospitalController.totalCost(addmissionId);
                    break;
                }
                case "ListPatients":
                    hospitalController.listPatients();
                    break;
            }
        }

    }

    void finish() throws IOException {
        hospitalController.finish();
    }
}
