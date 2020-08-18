import java.io.IOException;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;

/* This class is the client for DAO pattern it manipulates both patient and admission data by using
* their corresponding 'data accessor' objects*/
class HospitalController {
    private DataAccessor patientDataAccessor;
    private DataAccessor admissionDataAccessor;
    private Logger logger;

    public HospitalController() throws IOException {
        patientDataAccessor = new PatientDataAccessor();
        admissionDataAccessor = new AdmissionDataAccessor();
        logger = new Logger();
    }

    public void addPatient(int id, String firstName, String lastName, String phoneNumber, String address) throws IOException {
        Patient patient = new Patient(id, firstName, lastName, phoneNumber, address);
        patientDataAccessor.add(patient);

        logger.logPatientAction(patient, true);
    }

    public void removePatient(int id) throws IOException {
        Patient patient = (Patient) patientDataAccessor.deleteById(id);

        for (Object o : admissionDataAccessor.getAll()) {
            Admission admission = (Admission) o;
            if (admission.getPatientId() == patient.getId()) {
                admissionDataAccessor.deleteById(admission.getId());
            }
        }
        logger.logPatientAction(patient, false);
    }

    public void listPatients() throws IOException {

        List<Patient> patientList = new LinkedList<>();

        for (Object o : patientDataAccessor.getAll()) {
            Patient patient = (Patient) o;
            patientList.add(patient);
        }

        patientList.sort(Comparator.comparing(Patient::getFirstName)
                .thenComparing(Patient::getLastName));  // sorts the patient list by their name

        logger.listPatients(patientList);
    }

    public void addAdmission(int admissionId, int patientId) throws IOException {
        Admission admission = new Admission(admissionId, patientId);
        admissionDataAccessor.add(admission);
        logger.logAdmissionAddition(admission);
    }

    public void addExamination(int admissionId, String examinationType, String[] operations) throws IOException {
        Admission admission = (Admission) admissionDataAccessor.getById(admissionId);
        admission.addExamination(examinationType, operations);
        logger.logExaminationAddition(admissionId, examinationType);
    }

    public void totalCost(int admissionId) throws IOException {
        Admission admission = (Admission) admissionDataAccessor.getById(admissionId);
        logger.logTotalCost(admission);
    }
    // This method is responsible for all writing operations to complete
    public void finish() throws IOException {
        patientDataAccessor.close();
        admissionDataAccessor.close();
        logger.saveAll();
    }
}
