public class FacultyMember extends Academician {

    //static values provided in the problem specification.

    private static final int HOURLY_ADDITIONAL_COURSE_FEE = 20;
    private static final int WEEKLY_ADDITIONAL_COURSE_HOUR_LIMIT = 8;
    private static final double SPECIAL_SERVICE_BENEFIT_MULTIPLIER = 135.0/100.0;
    private static final int WEEKLY_BASE_WORKING_HOUR = 40;

    public FacultyMember(String firstName, String lastName, String registerNumber, int yearOfStart) {
        super(firstName, lastName, registerNumber, yearOfStart);
        this.setPosition("FACULTY_MEMBER");
    }

    @Override
    public double getWeeklySalary(int weeklyWorkingHour) {
        double weeklyBaseSalary = MONTHLY_BASE_SALARY/4.;
        double weeklySpecialServiceBenefit = MONTHLY_BASE_SALARY * SPECIAL_SERVICE_BENEFIT_MULTIPLIER/4.;

        int weeklyApplicableAdditionalCourseHour;

        if (weeklyWorkingHour > WEEKLY_BASE_WORKING_HOUR + WEEKLY_ADDITIONAL_COURSE_HOUR_LIMIT) {
            weeklyApplicableAdditionalCourseHour = WEEKLY_ADDITIONAL_COURSE_HOUR_LIMIT;
        }
        else {
            weeklyApplicableAdditionalCourseHour = weeklyWorkingHour - WEEKLY_BASE_WORKING_HOUR;
        }

        double weeklyAdditionalCourseFee = weeklyApplicableAdditionalCourseHour * HOURLY_ADDITIONAL_COURSE_FEE;

        return weeklyBaseSalary + weeklySpecialServiceBenefit + weeklyAdditionalCourseFee;

    }
}
