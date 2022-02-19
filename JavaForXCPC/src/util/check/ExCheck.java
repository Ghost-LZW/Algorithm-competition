package util.check;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

class testException extends Exception {}

public class ExCheck {
    public static void main(String[] args) throws IOException {
        BufferedReader t = new BufferedReader(new FileReader("../Print.java"));
        String tt = t.readLine();

        try {
            throw new testException();
        } catch (testException e) {
            System.out.println("error");
        }

        throw new RuntimeException(new testException());
    }
}
