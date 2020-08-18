public class PartTimeEmployee extends Employee {

    //static values provided in the problem specification.

    private static final int WEEKLY_WORK_HOUR_LOWER_LIMIT = 10;
    private static final int WEEKLY_WORK_HOUR_UPPER_LIMIT = 20;
    private static final int HOURLY_WORK_FEE = 18;

    public PartTimeEmployee(String firstName, String lastName, String registerNumber, int yearOfStart) {
        super(firstName, lastName, registerNumber, yearOfStart);
        this.setPosition("PARTTIME_EMPLOYEE");
    }

    @Override
    public double getWeeklySalary(int weeklyWorkingHour) {
        int weeklyApplicableWorkingHour;

        if (weeklyWorkingHour >= WEEKLY_WORK_HOUR_UPPER_LIMIT) {
            weeklyApplicableWorkingHour = WEEKLY_WORK_HOUR_UPPER_LIMIT;
        }
        else if (weeklyWorkingHour < WEEKLY_WORK_HOUR_LOWER_LIMIT) {
            weeklyApplicableWorkingHour = 0;
        }
        else {
            weeklyApplicableWorkingHour = weeklyWorkingHour;
        }

        return weeklyApplicableWorkingHour * HOURLY_WORK_FEE;

    }
}
