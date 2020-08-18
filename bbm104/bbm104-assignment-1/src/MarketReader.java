import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;

class MarketReader {

    private BufferedReader bufferedReader;

    MarketReader(String shoppingListPath) throws IOException {
        bufferedReader = new BufferedReader(new FileReader(shoppingListPath));
    }

    Customer readCustomer() throws IOException {

        String line = bufferedReader.readLine();

        if (line == null) return null;

        String[] params = line.split(Constants.PARAM_SEPARATOR);

        String customerFullName = params[0];
        String customerMembership = params[1];
        String customerPurchaseDate = params[2];
        Map<String, Integer> customerOrder = new LinkedHashMap<>();

        for (int i = 4; i < params.length; i+=2) {
            customerOrder.put(params[i - 1], Integer.parseInt(params[i]));
        }
        return  new Customer(customerFullName, customerMembership, customerPurchaseDate, customerOrder);
    }

    static ItemOffering[] readPriceList(String path) throws IOException {

        int itemOfferingCount = Files.readAllLines(Paths.get(path)).size(); // length of priceList.txt

        ItemOffering[] marketItemOfferings = new ItemOffering[itemOfferingCount];

        String productName;
        String typeOfMemberShip;
        String startDate;
        String endDate;
        double price;

        int i = 0;
        for (String line : Files.readAllLines(Paths.get(path))) {

            String[] params = line.split(Constants.PARAM_SEPARATOR);

            productName = params[0];
            typeOfMemberShip = params[1];
            startDate = params[2];
            endDate = params[3];
            price = Double.parseDouble(params[4]);

            marketItemOfferings[i++] = new ItemOffering(productName, typeOfMemberShip, startDate, endDate, price);
        }
        return marketItemOfferings;
    }
}
