import java.net.ServerSocket;
import java.net.Socket;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;

class SClient extends Thread {

    private Socket 		socket;
    private Integer 		serverId;
    private BufferedReader	istream;
    private PrintStream 	ostream;
    private boolean 		keepRunning;
    private static ArrayList<SClient> allServers = new ArrayList<SClient>();

    @SuppressWarnings("unused")
	private SClient() {
	// blocat
    }
	

    public SClient(Socket socket, Integer id) throws IOException {
		
	this.socket = socket;
	this.serverId = id;
	this.istream = new BufferedReader(new InputStreamReader(this.socket.getInputStream()));
	this.ostream = new PrintStream(socket.getOutputStream());
	this.keepRunning = true;
		
	allServers.add( this );
    }

    public void sendResponse(String response) {
	this.ostream.println(response);
    }
	
    private String getRequest() throws IOException {
	String line = "";

	try{
	    int c = 0;
	    while(((char)c)!='\n'){
		c= this.istream.read();
		line = line+(char)c;
		if(c==-1){
		    this.keepRunning = false;
		    break;
		}
	    }
	} catch (Exception e) {
	    e.printStackTrace();
	    this.keepRunning = false;
	}
		
	return line;
    }

    @Override
	public void run() {
	super.run();

	while(keepRunning) {
			
	    String text = "";
	    try {
		text = this.getRequest();
	    } catch (IOException e) {
		e.printStackTrace();
		text = "EROARE";
	    }
			
	    if ( text.contains("quit") || text.contains("exit") )
		{
		    System.exit(0);
		}

	    try{
			
		if ( allServers.size() >= 1 ) {
					
		    for(SClient user : allServers) {
			if(user!=null) {
			    user.sendResponse(text);
			}
		    }
		}
				
	    } catch (Exception e){
		e.printStackTrace();
		this.sendResponse("\nEROARE");
	    }
	}

	try {
	    this.socket.close();
	} catch (IOException e) {
	    e.printStackTrace();
	}
    }

}

/*

              serverul de test

*/

public class server {
	
    public static void main(String[] args){
		
	/*
	 *  in asteptarea clientilor
	 */
	int serverId=1;
	ServerSocket serverSocket;
	try {
	    serverSocket = new ServerSocket(8080);
	    for(;;){
		Socket s = serverSocket.accept();
		System.out.print("\nNew server [id="+serverId+"]");
		/*
		 *  client nou
		 */
		Thread t = new SClient(s, serverId);
		serverId++;
		t.start();
	    }
	} catch (IOException e) {
	    e.printStackTrace();
	}

    }
}
