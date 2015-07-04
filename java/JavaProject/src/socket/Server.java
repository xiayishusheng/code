package socket;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {

    public static void main(String[] args) {

        ServerSocket server = null;
        Socket socket = null;
        InputStream is = null;
        OutputStream os = null;
        PrintStream ps = null;
        BufferedReader br = null;

        try {

            server = new ServerSocket(8888);
            socket = server.accept();

            is = socket.getInputStream();
            os = socket.getOutputStream();

            ps = new PrintStream(os);

            while (true) {

                br = new BufferedReader(new InputStreamReader(is));
                ps.println("hello," + br.readLine());
                ps.flush();
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