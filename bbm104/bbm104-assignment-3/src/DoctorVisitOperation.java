public class DoctorVisitOperation extends ExaminationDecorator {

    public DoctorVisitOperation(Examination newExamination) {
        super(newExamination);
    }

    @Override
    public String getDescription() {
        return super.getDescription() + "doctorvisit ";
    }

    @Override
    public double getCost() {
        return super.getCost() + 15;
    }
}
