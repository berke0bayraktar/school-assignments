import java.io.*;

public class PersonnelIO {

    /*Buffered readers are provided as class fields and not local variables to methods
    * so that we can read the file line by line when requested.*/

    private BufferedReader personnelReaderBuffer;
    private BufferedReader monitorReaderBuffer;

    public PersonnelIO(String personnelFilePath, String monitoringFilePath) throws IOException {
        this.personnelReaderBuffer = new BufferedReader(new FileReader(personnelFilePath));
        this.monitorReaderBuffer = new BufferedReader (new FileReader(monitoringFilePath));
    }

    public Personnel getPersonnel() throws IOException {

        String personnelLine = this.personnelReaderBuffer.readLine();

        if (personnelLine == null) return null;

        Personnel personnel = null;

        String[] personnelInfo = personnelLine.split("\t");
        String personnelFullName = personnelInfo[0];
        String personnelFirstName = personnelFullName.split(" ")[0];
        String personnelLastName = personnelFullName.split(" ")[1];
        String personnelRegisterNumber = personnelInfo[1];
        String personnelPosition = personnelInfo[2];
        int personnelStartYear = Integer.parseInt(personnelInfo[3]);

        switch (personnelPosition) {
            case "FACULTY_MEMBER":
                personnel = new FacultyMember(personnelFirstName,personnelLastName,
                        personnelRegisterNumber, personnelStartYear);
                break;
            case "RESEARCH_ASSISTANT":
                personnel = new ResearchAssistant(personnelFirstName,personnelLastName,
                        personnelRegisterNumber, personnelStartYear);
                break;
            case "OFFICER":
                personnel = new Officer(personnelFirstName,personnelLastName,
                        personnelRegisterNumber, personnelStartYear);
                break;
            case "CHIEF":
                personnel = new Chief(personnelFirstName, personnelLastName,
                        personnelRegisterNumber, personnelStartYear);
                break;
            case "WORKER":
                personnel = new Worker(personnelFirstName, personnelLastName,
                        personnelRegisterNumber, personnelStartYear);
                break;
            case "PARTTIME_EMPLOYEE":
                personnel = new PartTimeEmployee(personnelFirstName, personnelLastName,
                        personnelRegisterNumber, personnelStartYear);
                break;
            case "SECURITY":
                personnel = new Security(personnelFirstName, personnelLastName,
                        personnelRegisterNumber, personnelStartYear);
        }
        return personnel;
    }

    /*reads all working hours week by week of a personnel and returns a array containing them.*/

    int[] getMonthlyWorkingHours() throws IOException {

        String workingHoursLine = this.monitorReaderBuffer.readLine();

        if (workingHoursLine == null) return null;

        String[] workingHours = workingHoursLine.split("\t");

        int[] monthlyWorkingHours = new int[4];
        for (int i = 1; i < workingHours.length; i++) {
            String workingHourStr = workingHours[i];
            monthlyWorkingHours[i-1] = Integer.parseInt(workingHourStr);
        }
        return  monthlyWorkingHours;
    }

    /*outputs the personnel in the correct format*/

    void printPersonnel(Personnel personnel, String fileName) throws IOException {
        String output = String.format("Name : %s\nSurname : %s\nRegistration Number : %s\n" +
                "Position : %s\nYear of Start : %d\nTotal Salary : %.2f TL",
                personnel.getFirstName(), personnel.getLastName(), personnel.getRegisterNumber(),
                personnel.getPosition(), personnel.getYearOfStart(), personnel.getMonthlySalary());

        BufferedWriter writer = new BufferedWriter(new FileWriter(fileName + ".txt"));
        writer.write(output);
        writer.close();
    }


}
