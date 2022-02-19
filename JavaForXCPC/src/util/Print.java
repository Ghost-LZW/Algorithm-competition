package util;

import static util.Range.range;

class TTT {
    void bao() {
        System.out.println("Hello");
    }
}

public class Print {
    void test() {
        Test tt = new Test();
        Range ran = new Range();
        tt.print();
        for (int i : range(1, 4))
            System.out.print(i);
    }
    public static void print(Object obj) {
        System.out.print(obj);
    }
}
