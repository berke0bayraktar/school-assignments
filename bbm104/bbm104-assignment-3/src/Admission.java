import java.util.LinkedList;
import java.util.List;

class Admission {
    private final int id;
    private final int patientId;
    private final List<Examination> examinations = new LinkedList<>();

    public Admission(int id, int patientId){
        this.id = id;
        this.patientId = patientId;
    }

    /* This method is the client for the decorator pattern. It creates examinations iteratively depending on
    * a provided list of operations that examination consists of*/
    public void addExamination(String examinationType, String[] operations) {

        Examination examination = null;

        if (examinationType.equals("Inpatient")) examination = new InPatientExamination();
        else if (examinationType.equals("Outpatient")) examination = new OutPatientExamination();

        for(String operation : operations) {

            switch (operation) {
                case "imaging":
                    examination = new ImagingOperation(examination);
                    break;
                case "doctorvisit":
                    examination = new DoctorVisitOperation(examination);
                    break;
                case "tests":
                    examination = new TestOperation(examination);
                    break;
                case "measurements":
                    examination = new MeasurementOperation(examination);
                    break;
            }
        }

        this.examinations.add(examination);

    }

    public int getId() {
        return id;
    }

    public int getPatientId() {
        return patientId;
    }

    public List<Examination> getExaminations() {
        return examinations;
    }

}
