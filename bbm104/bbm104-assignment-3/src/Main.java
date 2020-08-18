import java.io.IOException;


class Main {

    public static void main(String[] args) {
        try {
            InstructionExecutor ie = new InstructionExecutor();
            ie.executeInstructions(args[0]);
            ie.finish();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
