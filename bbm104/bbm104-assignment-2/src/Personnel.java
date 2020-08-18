public abstract class Personnel {

    static final double SEVERANCE_PAY_MULTIPLIER = 20*0.8;
    static final int CURRENT_YEAR = 2020;

    private double monthlySalary;
    private String firstName;
    private String lastName;
    private String registerNumber;
    private String position;
    int yearOfStart;

    public Personnel(String firstName, String lastName, String registerNumber, int yearOfStart) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.registerNumber = registerNumber;
        this.yearOfStart = yearOfStart;
    }

    /*In all subclasses of this class which is not abstract this method is overridden, with respect to the
    * specific way of calculating the salary of that personnel.*/

    /*Some of the personnel have monthly base salaries and other monthly payments but I divided them to 4 (number
    of weeks) so they add up to the monthly value while calculating the total salary. This way of salary calculation
    has eliminated the need for other functions that would incorporate the monthly payments to overall salary.*/

    public abstract double getWeeklySalary(int weeklyWorkingHour);

    /*This methods sums weekly salaries of the personnel over the course of 4 weeks*/

    public void calculateMonthlySalary(int[] weeklyWorkingHours) {
        double monthlySalary = 0;

        for (int currentWeek : weeklyWorkingHours) {
            monthlySalary += this.getWeeklySalary(currentWeek);
        }

        double monthlySeverancePay = (CURRENT_YEAR - this.yearOfStart) * SEVERANCE_PAY_MULTIPLIER;
        monthlySalary += monthlySeverancePay; // every personnel has severance pay

        this.monthlySalary = monthlySalary;
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public String getRegisterNumber() {
        return registerNumber;
    }

    public double getMonthlySalary() {
        return monthlySalary;
    }

    public String getPosition() {
        return position;
    }

    public void setPosition(String position) {
        this.position = position;
    }

    public int getYearOfStart() {
        return yearOfStart;
    }
}
