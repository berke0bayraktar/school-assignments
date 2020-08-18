public class Officer extends Personnel {

    //static values provided in the problem specification.

    private static final int MONTHLY_BASE_SALARY = 2600;
    private static final double SPECIAL_SERVICE_BENEFIT_MULTIPLIER = 65/100.;
    private static final int WEEKLY_OVERWORK_HOUR_LIMIT = 10;
    private static final int HOURLY_OVERWORK_FEE = 20;
    private static final int WEEKLY_BASE_WORKING_HOUR = 40;

    public Officer(String firstName, String lastName, String registerNumber, int yearOfStart) {
        super(firstName, lastName, registerNumber, yearOfStart);
        this.setPosition("OFFICER");
    }

    @Override
    public double getWeeklySalary(int weeklyWorkingHour) {
        double weeklyBaseSalary = MONTHLY_BASE_SALARY / 4.;
        double weeklySpecialServiceBenefit = MONTHLY_BASE_SALARY * SPECIAL_SERVICE_BENEFIT_MULTIPLIER / 4.;

        int weeklyApplicableOverWorkHour;

        if (weeklyWorkingHour > WEEKLY_BASE_WORKING_HOUR + WEEKLY_OVERWORK_HOUR_LIMIT) {
            weeklyApplicableOverWorkHour = WEEKLY_OVERWORK_HOUR_LIMIT;
        }
        else {
            weeklyApplicableOverWorkHour = weeklyWorkingHour - WEEKLY_BASE_WORKING_HOUR;
        }

        double weeklyOverworkFee = weeklyApplicableOverWorkHour * HOURLY_OVERWORK_FEE;

        return weeklyBaseSalary + weeklySpecialServiceBenefit + weeklyOverworkFee;
    }
}
