public abstract class ExaminationDecorator implements Examination {

    private final Examination examination;

    public ExaminationDecorator(Examination newExamination) {
        this.examination = newExamination;
    }

    @Override
    public String getDescription(){
        return this.examination.getDescription();
    }

    @Override
    public double getCost() {
        return this.examination.getCost();
    }

}
