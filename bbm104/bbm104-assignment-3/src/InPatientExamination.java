public class InPatientExamination implements Examination{

    @Override
    public String getDescription() {
        return "Inpatient\t";
    }

    @Override
    public double getCost() {
        return 10;
    }

}
