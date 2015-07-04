package socket;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintStream;
import java.net.Socket;

public class Client {

    public Client() {
    }

    public static void main(String[] args) {
        Socket socket = null;
        InputStream is = null;
        OutputStream os = null;
        PrintStream ps = null;
        BufferedReader br = null;
        try {
            socket = new Socket("127.0.0.1", 8888);
            System.out.println("已链接服务器");

            is = socket.getInputStream();
            os = socket.getOutputStream();
            ps = new PrintStream(os);

            while (true) {

                br = new BufferedReader(new InputStreamReader(System.in));
                ps.println(br.readLine());

                BufferedReader reader = new BufferedReader(new InputStreamReader(is));
                System.out.println("server said:" + reader.readLine());
            }

        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                br.close();
                ps.close();
                is.close();
                os.close();
                socket.close();

            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}