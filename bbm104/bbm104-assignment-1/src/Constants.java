import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeFormatterBuilder;

class Constants {

    private static final String DATE_PATTERN = "dd.MM.yyyy";
    static final String PARAM_SEPARATOR = "\t";

    // A utility function to check whether a date is between two start and end dates

    static boolean isWithinDateRange(String dateToCheckStr, String startDateStr, String endDateStr) {
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern(DATE_PATTERN);

        LocalDate dateToCheck = LocalDate.parse(dateToCheckStr, dtf);
        LocalDate startDate = LocalDate.parse(startDateStr, dtf);
        LocalDate endDate = LocalDate.parse(endDateStr, dtf);

        boolean edgeCase = dateToCheck.isEqual(endDate) || dateToCheck.isEqual(startDate);

        return edgeCase || (dateToCheck.isAfter(startDate) && dateToCheck.isBefore(endDate));
    }

}
