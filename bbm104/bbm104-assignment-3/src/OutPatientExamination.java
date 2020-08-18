public class OutPatientExamination implements Examination {

    @Override
    public String getDescription() {
        return "Outpatient\t";
    }

    @Override
    public double getCost() {
        return 15;
    }
}
