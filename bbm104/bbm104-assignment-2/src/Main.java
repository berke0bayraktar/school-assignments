import java.io.IOException;

public class Main {

    public static void main(String[] args) {

        Personnel personnel;
        int[] monthlyWorkingHours;

        try {
            PersonnelIO personnelIO = new PersonnelIO(args[0], args[1]);

            while ((personnel = personnelIO.getPersonnel())!= null) {
                monthlyWorkingHours = personnelIO.getMonthlyWorkingHours();
                personnel.calculateMonthlySalary(monthlyWorkingHours);
                personnelIO.printPersonnel(personnel,personnel.getRegisterNumber());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
