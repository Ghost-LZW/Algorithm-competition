package util;

public class Range {
    public static int[] range(int begin, int end) {
        int[] result = new int[end - begin];
        for (int i = 0; i < end - begin; i++)
            result[i] = begin + i;
        return result;
    }

    public static void main(String[] args) {
        TTT pp;
    }
}

class Test {
    void print() {
        System.out.print("error");
    }
}