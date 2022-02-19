import org.json.JSONArray;
import org.json.JSONObject;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.nio.Buffer;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.util.*;

import static util.Print.print;

public class testJson {
    public static void main(String[] args) throws IOException {
        List[] res = new ArrayList[12];
        res[0] = new ArrayList<Integer>();
        res[0].add(12);
        System.out.println(res[0].get(0));
    }
}
