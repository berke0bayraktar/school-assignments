import java.util.SortedMap;

class Market {

    private ItemOffering[] itemOfferings; // keeps track of deals on the market

    Market(ItemOffering[] itemOfferings) {
        this.itemOfferings = itemOfferings;
    }

    void billCustomer(Customer customer) {

        double overallTotal = 0;

        System.out.println(String.format("---%s---", customer.getFullName()));

        for (SortedMap.Entry<String, Integer> order : customer.getOrder().entrySet()) {
            double price = determinePrice(order.getKey(), customer.getMemberShip(), customer.getPurchaseDate());
            double itemTotal = price*order.getValue();
            overallTotal += itemTotal;
            System.out.println(String.format("%s\t%.1f\t%d\t%.1f", order.getKey(), price, order.getValue(), itemTotal));
        }
        System.out.println(String.format("Total %.1f", overallTotal));
    }

    // determines the price of an item with respect to membership and purchase date

    private double determinePrice(String itemName, String customerMembership, String purchaseDate) {

        double applyingPrice = -1;

        for (ItemOffering itemOffering : this.itemOfferings) {
            boolean nameMatch = itemOffering.getName().equals(itemName);
            boolean membershipMatch = itemOffering.getMembership().equals(customerMembership);

            String startDate = itemOffering.getPriceStartDate();
            String endDate = itemOffering.getPriceEndDate();

            boolean dateMatch = Constants.isWithinDateRange(purchaseDate,startDate,endDate);

            if (nameMatch && membershipMatch && dateMatch){
                applyingPrice = itemOffering.getPrice();
            }
        }
        return applyingPrice;
    }



}
