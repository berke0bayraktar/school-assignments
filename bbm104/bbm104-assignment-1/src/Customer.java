import java.util.Map;

class Customer {
    private String fullName;
    private String memberShip;
    private String purchaseDate;
    private Map<String, Integer> order;

    Customer(String fullName, String memberShip, String purchaseDate, Map<String, Integer> order) {
        this.fullName = fullName;
        this.memberShip = memberShip;
        this.purchaseDate = purchaseDate;
        this.order = order;
    }

    String getFullName() {
        return fullName;
    }

    String getMemberShip() {
        return memberShip;
    }

    String getPurchaseDate() {
        return purchaseDate;
    }

    Map<String, Integer> getOrder() {
        return order;
    }
}
