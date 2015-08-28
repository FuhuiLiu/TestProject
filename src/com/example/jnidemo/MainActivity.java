package com.example.jnidemo;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		JNIDemo obj = new JNIDemo();
		
		Toast.makeText(this, "" + obj.MyAdd(1, 2), Toast.LENGTH_LONG).show();
		
		Button btn = (Button)findViewById(R.id.button1);
		btn.setOnClickListener(new View.OnClickListener()
		{
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				//JNIDemo.NdkCallJava();
				JNIDemo obj = new JNIDemo();
				obj.NdkCallJava();
			}
		});

	}
	

	public int MainAdd(int n1, int n2)
	{
		return n1 + n2;
	}
	
}
