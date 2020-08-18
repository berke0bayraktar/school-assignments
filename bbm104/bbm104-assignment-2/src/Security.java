public class Security extends Personnel {

    //static values provided in the problem specification.

    private static final int DAILY_TRANSPORTATION_FEE = 5;
    private static final int DAILY_FOOD_FEE = 10;
    private static final int WEEKLY_WORKING_DAY_NUMBER = 6;
    private static final int WEEKLY_WORK_HOUR_UPPER_LIMIT = 9 * WEEKLY_WORKING_DAY_NUMBER;
    private static final int WEEKLY_WORK_HOUR_LOWER_LIMIT = 5 * WEEKLY_WORKING_DAY_NUMBER;
    private static final int HOURLY_WORK_FEE = 10;

    public Security(String firstName, String lastName, String registerNumber, int yearOfStart) {
        super(firstName, lastName, registerNumber, yearOfStart);
        this.setPosition("SECURITY");
    }

    @Override
    public double getWeeklySalary(int weeklyWorkingHour) {

        int weeklyApplicableWorkingHour;

        if (weeklyWorkingHour >= WEEKLY_WORK_HOUR_UPPER_LIMIT) {
            weeklyApplicableWorkingHour = WEEKLY_WORK_HOUR_UPPER_LIMIT;
        }
        else if (weeklyWorkingHour < WEEKLY_WORK_HOUR_LOWER_LIMIT) {
            return 0; // If he works lower than minimum hour he gets nothing.
        }
        else {
            weeklyApplicableWorkingHour = weeklyWorkingHour;
        }

        double weeklyWorkingFee = weeklyApplicableWorkingHour * HOURLY_WORK_FEE;

        double weeklyTransportationFee = DAILY_TRANSPORTATION_FEE * WEEKLY_WORKING_DAY_NUMBER;
        double weeklyFoodFee = DAILY_FOOD_FEE * WEEKLY_WORKING_DAY_NUMBER;

        return weeklyWorkingFee + weeklyTransportationFee + weeklyFoodFee;
    }
}
