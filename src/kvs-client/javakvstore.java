
import java.io.*;
import java.net.*;

public class javakvstore {
    public static void main(String[] args) {
        String serverAddress = "192.168.31.43"; 
        int serverPort = 2000;  

        try {
            Socket socket = new Socket(serverAddress, serverPort);

            OutputStream outputStream = socket.getOutputStream();
            InputStream inputStream = socket.getInputStream();

            String message = "set student pu";
            outputStream.write(message.getBytes());

            byte[] buffer = new byte[1024];
            int bytesRead = inputStream.read(buffer);
            if (bytesRead > 0) {
                String response = new String(buffer, 0, bytesRead);
                System.out.println("recv: " + response);
            }

			inputStream.close();
			outputStream.close();
			socket.close();

		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}



