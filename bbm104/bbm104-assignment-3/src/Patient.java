class Patient {
    private final int id;
    private final String firstName;
    private final String lastName;
    private final String phoneNumber;
    private final String address;

    Patient(int id, String firstName, String lastName, String phoneNumber, String address) {
        this.id = id;
        this.firstName = firstName;
        this.lastName = lastName;
        this.phoneNumber = phoneNumber;
        this.address = address;
    }

    int getId() {
        return id;
    }

    String getFirstName() {
        return firstName;
    }

    String getLastName() {
        return lastName;
    }

    String getPhoneNumber() {
        return phoneNumber;
    }

    String getAddress() {
        return address;
    }

}
