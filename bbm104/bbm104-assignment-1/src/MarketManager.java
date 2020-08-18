import java.io.IOException;

class MarketManager {

    // builds the market with the given price list
    static Market buildMarket(String priceListPath) throws IOException {
        ItemOffering[] priceList = MarketReader.readPriceList(priceListPath);
        return new Market(priceList);
    }

    // commences billing of customers on a given market with respect to a given shopping list
    static void startMarket(Market market, String shoppingListPath) throws IOException {
        MarketReader marketReader = new MarketReader(shoppingListPath);

        Customer customer;
        while((customer = marketReader.readCustomer()) != null) {
            market.billCustomer(customer);
        }
    }
}
