
// a class to represent item prices to a specific membership and within a specific date range

class ItemOffering {
    private String name;
    private String membership;
    private String priceStartDate;
    private String priceEndDate;
    private double price;

    ItemOffering(String name, String membership, String priceStartDate, String priceEndDate, double price) {
        this.name = name;
        this.membership = membership;
        this.priceStartDate = priceStartDate;
        this.priceEndDate = priceEndDate;
        this.price = price;
    }

    String getName() {
        return name;
    }

    String getMembership() {
        return membership;
    }

    String getPriceStartDate() {
        return priceStartDate;
    }

    String getPriceEndDate() {
        return priceEndDate;
    }

    double getPrice() {
        return price;
    }
}
