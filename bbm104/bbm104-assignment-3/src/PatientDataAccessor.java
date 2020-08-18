import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;

// This class is responsible for all CRUD operations related to patients
public class PatientDataAccessor implements DataAccessor {

    private final ArrayList<Patient> patients = new ArrayList<>();

    PatientDataAccessor() throws IOException {
        this.importData();
    }

    @Override
    public Object getById(int id) {
        Patient requestedPatient = null;

        for (Patient patient : patients) {
            if (patient.getId() == id) requestedPatient = patient;
        }
        return requestedPatient;
    }

    @Override
    public Object deleteById(int id) {
        Patient patientToDelete = null;

        for(Patient patient : patients) {
            if (patient.getId() == id) patientToDelete = patient;
        }
        this.patients.remove(patientToDelete);
        return patientToDelete;
    }

    @Override
    public void add(Object o) {
        Patient patientToAdd = (Patient) o;
        this.patients.add(patientToAdd);
    }

    @Override
    public ArrayList<Object> getAll() {
        return new ArrayList<>(this.patients);
    }

    /*Contains the logic for for importing all patients correctly*/
    private void importData() throws IOException {
        BufferedReader patientFileReader = new BufferedReader(new FileReader("patient.txt"));

        String patientFileLine;

        while ((patientFileLine = patientFileReader.readLine()) != null) {

            int id;
            String firstName, lastName, phoneNumber, address;

            String[] parameters = patientFileLine.split("\t");

            id = Integer.parseInt(parameters[0]);
            firstName = parameters[1].split(" ")[0];
            lastName = parameters[1].split(" ")[1];
            phoneNumber = parameters[2];
            address = parameters[3];
            address = address.substring(9);
            Patient patient = new Patient(id, firstName, lastName, phoneNumber, address);
            this.patients.add(patient);
        }

    }

    @Override
    public void close() throws IOException{

        patients.sort(Comparator.comparing(Patient::getId));

        BufferedWriter patientFileWriter = new BufferedWriter(new FileWriter("patient.txt"));

        for(Patient patient : this.patients) {
            patientFileWriter.write(String.format("%d\t%s %s\t%s\tAddress: %s\n",
                    patient.getId(), patient.getFirstName(), patient.getLastName(),
                    patient.getPhoneNumber(), patient.getAddress()));
        }
        patientFileWriter.close();
    }
}
