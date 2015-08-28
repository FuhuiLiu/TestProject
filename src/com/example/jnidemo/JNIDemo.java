package com.example.jnidemo;

public class JNIDemo {

	static
	{
		System.loadLibrary("JNIDemo");
	}
	public JNIDemo(){}

	public native static void NdkCallJava();
	public native String MyGetString();
	public native static void StaticMothod();
	public native int MySub(int n1, int n2);
	public native int MyAdd(int n1, int n2);
}
