class JniTest
{

	public native void displayHello();

	static
	{
		System.loadLibrary("hello");
	}

	public static void main(String[] args)
	{
		new JniTest().displayHello();
	}
}
