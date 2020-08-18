public class TestOperation extends ExaminationDecorator {

    TestOperation(Examination newExamination) {
        super(newExamination);
    }

    @Override
    public String getDescription() {
        return super.getDescription() + "tests ";
    }

    @Override
    public double getCost() {
        return super.getCost() + 7;
    }
}
