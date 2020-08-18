public class ImagingOperation extends ExaminationDecorator {

    public ImagingOperation(Examination newExamination) {
        super(newExamination);
    }

    @Override
    public String getDescription() {
        return super.getDescription() + "imaging ";
    }

    @Override
    public double getCost() {
        return super.getCost() + 10;
    }
}
