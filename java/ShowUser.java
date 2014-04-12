import java.sql.*;

public class ShowUser {
	//main function
	public static void main(String[] args) {
	    //connect to mysql database
	    String driverStr = "com.mysql.jdbc.Driver";	//driver name
	    String dbUrl = "jdbc:mysql://127.0.0.1:3306/spdb1";
	    String user = "root";
	    String password = "android";
	    try {
		Class.forName(driverStr);	//load driver
		Connection con = DriverManager.getConnection(dbUrl, user, password);
		Statement sm = con.createStatement();
		ResultSet rs = sm.executeQuery("select * from users");
		while(rs.next()) {
			System.out.print("userId=" + rs.getString(1) + "\t");
			System.out.println("userName=" + rs.getString(2));
		}
		} catch(Exception e) {
			e.printStackTrace();
	    }
	}
}
