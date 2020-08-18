public class Chief extends Employee {

    //static values provided in the problem specification.

    private static final int DAILY_WORKING_FEE = 125;
    private static final int WEEKLY_OVERWORK_HOUR_LIMIT = 8;
    private static final int HOURLY_OVERWORK_FEE = 15;
    private static final int WEEKLY_BASE_WORKING_HOUR = 40;
    private static final int WEEKLY_WORKING_DAY_NUMBER = 5;


    public Chief(String firstName, String lastName, String registerNumber, int yearOfStart) {
        super(firstName, lastName, registerNumber, yearOfStart);
        this.setPosition("CHIEF");
    }

    @Override
    public double getWeeklySalary(int weeklyWorkingHour) {
        double weeklyBaseWorkingFee = WEEKLY_WORKING_DAY_NUMBER * DAILY_WORKING_FEE;

        double weeklyApplicableOverworkHour;

        if (weeklyWorkingHour > WEEKLY_BASE_WORKING_HOUR + WEEKLY_OVERWORK_HOUR_LIMIT) {
            weeklyApplicableOverworkHour = WEEKLY_OVERWORK_HOUR_LIMIT;
        }
        else {
            weeklyApplicableOverworkHour = weeklyWorkingHour - WEEKLY_BASE_WORKING_HOUR;
        }

        double weeklyOverworkFee = weeklyApplicableOverworkHour * HOURLY_OVERWORK_FEE;

        return weeklyBaseWorkingFee + weeklyOverworkFee;
    }
}
