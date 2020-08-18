public class MeasurementOperation extends ExaminationDecorator {

    MeasurementOperation(Examination newExamination) {
        super(newExamination);
    }

    @Override
    public String getDescription() {
        return super.getDescription() + "measurements ";
    }

    @Override
    public double getCost() {
        return super.getCost() + 5;
    }
}
