import java.io.IOException;

public class Main {
    public static void main(String[] args) {
        try {
            Market market = MarketManager.buildMarket(args[0]);
            MarketManager.startMarket(market, args[1]);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
