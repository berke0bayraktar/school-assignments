public class ResearchAssistant extends Academician {
    private static final double SPECIAL_SERVICE_BENEFIT_MULTIPLIER = 105/100.;

    public ResearchAssistant(String firstName, String lastName, String registerNumber, int yearOfStart) {
        super(firstName, lastName, registerNumber, yearOfStart);
        this.setPosition("RESEARCH_ASSISTANT");
    }

    @Override
    public double getWeeklySalary(int weeklyWorkingHour) {
        double weeklyBaseSalary = MONTHLY_BASE_SALARY/4.;
        double weeklySpecialServiceBenefit = SPECIAL_SERVICE_BENEFIT_MULTIPLIER * MONTHLY_BASE_SALARY / 4.;

        return weeklyBaseSalary + weeklySpecialServiceBenefit;
    }

}
