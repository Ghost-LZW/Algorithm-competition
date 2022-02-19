import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.charset.StandardCharsets;
import java.util.Arrays;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class SleepingTask implements Runnable {
    private static int count = 0;
    private final int id = count++;
    private static int countNum = 5;

    public void run() {
        try {
            while (countNum-- > 0) {
                System.out.println("#" + id + "(" + countNum + ") " + Thread.currentThread());
                //Thread.yield();
            }
        } catch (Exception e) {
            System.err.println("error happen");
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        byte res = 0; int tt = 0;
        for (int i = 0; i < 8; i++) {
            res |= (1 << i); tt |= (1 << i);
        }
        System.out.println(res);
        for (int i = 0; i < 32; i++) tt ^= (1 << i);
        System.out.println(tt);
        byte[] t = ByteBuffer.allocate(2).order(ByteOrder.BIG_ENDIAN).putInt(tt).array();
        System.out.println(Arrays.toString(t));
        int val = ByteBuffer.wrap(t).order(ByteOrder.LITTLE_ENDIAN).getInt();
        System.out.println(val);

        ExecutorService exec = Executors.newCachedThreadPool();
        for (int i = 0; i < 5; i++) exec.execute(new SleepingTask());
        exec.shutdown();
    }
}
